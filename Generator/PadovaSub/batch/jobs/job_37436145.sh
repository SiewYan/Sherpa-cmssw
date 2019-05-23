#!/bin/bash

WorkingDir=${CMSSW_BASE}/src/SherpaGeneration/Generator/SM_Zbj_nlo
TMPDir=/lustre/cmswork/hoh/tmp

echo "PWD:"
eval cd ${TMPDir}
#pwd
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
source $VO_CMS_SW_DIR/cmsset_default.sh
#RANDOMSEED=`od -vAn -N4 -tu4 < /dev/urandom`

if [[ -z "${CMSSW_BASE}" ]]; then
    echo "CMSSW_BASE is missing".
    exit 0
else
    echo "Copying working folder"
    scp -r ${WorkingDir} ${TMPDir}/batch_SM_Zbj_nlo_37436145
fi

eval cd ${TMPDir}/batch_SM_Zbj_nlo_37436145
#scp $WorkingDir ${TMPDir}/batch_SM_Zbj_nlo_37436145

echo "environment:"
echo
env > local.env
env

sed -i 's/1111111/37436145/g' cmsRun_cfg.py
echo "running"
cmsRun cmsRun_cfg.py
mv *GEN_SIM.root sherpa_GenSim_37436145.root 
mv sherpa_GenSim_37436145.root ${WorkingDir}
echo "Cleaning up"
#rm -rf ${TMPDir}/batch_SM_Zbj_nlo_37436145
exit $?
echo ""

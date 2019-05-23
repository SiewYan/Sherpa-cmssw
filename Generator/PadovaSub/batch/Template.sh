#!/bin/bash

WorkingDir=${CMSSW_BASE}/src/SherpaGeneration/Generator/YYYYYY
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
    scp -r ${WorkingDir} ${TMPDir}/batch_YYYYYY_XXXX
fi

eval cd ${TMPDir}/batch_YYYYYY_XXXX
#scp $WorkingDir ${TMPDir}/batch_YYYYYY_XXXX

echo "environment:"
echo
env > local.env
env

sed -i 's/1111111/XXXX/g' cmsRun_cfg.py
echo "running"
cmsRun cmsRun_cfg.py
mv sherpa_YYYYYY_MASTER_cff_py_GEN_SIM.root ${WorkingDir}/sherpa_YYYYYY_XXXX_GEN_SIM.root
#mv *GEN_SIM.root sherpa_GenSim_XXXX.root 
#mv sherpa_GenSim_XXXX.root ${WorkingDir}
echo "Cleaning up"
rm -rf ${TMPDir}/batch_YYYYYY_XXXX
exit $?
echo ""

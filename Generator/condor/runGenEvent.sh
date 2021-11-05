#!/bin/bash

export HOME=${PWD}
source inputs.sh

source /cvmfs/cms.cern.ch/cmsset_default.sh

echo " --> Start to work now"

echo " --> Setting up ${CMSSWRELEASE}"
scram -a ${SCRAMARCH} project ${CMSSWRELEASE}
scram project ${CMSSWRELEASE}
cd ${CMSSWRELEASE}/src

eval `scramv1 runtime -sh`
export TOPDIR=${PWD}

#shr=`scramv1 tool info sherpa | grep "SHERPA_BASE" | cut -f2 -d"="`
#draw=`find $shr -type f -name plot_graphs.sh`

echo " --> CMS-ADDPKG"
git config --list --show-origin
git cms-addpkg GeneratorInterface/SherpaInterface
mkdir -p workdir/${PROCESS}/test
mkdir -p workdir/${PROCESS}/python
export SUBDIR=${TOPDIR}/workdir/${PROCESS}

chmod +x ${TOPDIR}/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh
chmod +x ${TOPDIR}/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh

mv ${HOME}/inputs/* ${SUBDIR}/test
ls -trlha ${SUBDIR}/test
scram b
cd ${SUBDIR}/test

# define the process
echo " --> NANOGEN"

# Generate random seeds
RANDOMSEED=`od -vAn -N4 -tu4 < /dev/urandom`

#Sometimes the RANDOMSEED is too long
RANDOMSEED=`echo $RANDOMSEED | rev | cut -c 3- | rev`

echo " --> Input process   : $PROCESS"
echo " --> Input nevent    : $NEVENT"
echo " --> RANDOMSEED      : $RANDOMSEED"
echo " --> Weight cfi      : $CFI"

# take care of weight list cfi
if [ -e "${CFI}" ]; then
    cp ${CFI} ${TOPDIR}
    ${TOPDIR}/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh -i ./ -p ${PROCESS} -e ${CFI}
    cp ${CFF} ${CFI} ${SUBDIR}/python
    echo "${TOPDIR}/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh -i ./ -p ${PROCESS} -e ${CFI}"
else
    ${TOPDIR}/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh -i ./ -p ${PROCESS}
    cp ${CFF} ${SUBDIR}/python
    echo "${TOPDIR}/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh -i ./ -p ${PROCESS}"
fi

cd ${TOPDIR}; scram b
cd ${SUBDIR}; scram b
cd ${SUBDIR}/test

cmsDriver.py workdir/${PROCESS}/python/${CFF} \
    --step GEN,NANOGEN \
    --mc \
    --datatier NANOAOD \
    --eventcontent NANOAODGEN \
    --conditions 106X_upgrade2018_realistic_v15_L1v1 \
    --beamspot Realistic25ns13TeVEarly2018Collision \
    --geometry DB:Extended \
    --era Run2_2018 \
    --python_filename ${CFG} \
    --fileout sherpa_${PROCESS}_${RANDOMSEED}.root \
    -n ${NEVENT} \
    --customise_commands process.RandomNumberGeneratorService.generator.initialSeed=${RANDOMSEED} \
    --customise Configuration/DataProcessing/Utils.addMonitoring \
    --no_exec

cmsRun ${CFG}

ls -trlh

xrdcp sherpa_${PROCESS}_${RANDOMSEED}.root  root://eosuser.cern.ch//eos/user/s/shoh/NANOAD_private/Sherpa_${PROCESS}_events/sherpa_${PROCESS}_${RANDOMSEED}.root

echo " --> DONE"

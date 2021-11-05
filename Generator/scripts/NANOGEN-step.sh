#!/bin/bash

set -e

BASE=$PWD

NAME=$1
NEVENT=$2
CFI=$3

if [[ -z "$1" ]]; then
    echo "Please specify run card"
    echo "Example: generate_sherpack.sh NAME 10 sherpa_NAME_weight_cfi.py (if any)"
    exit 0
fi

if [[ -z "$2" ]]; then
    NEVENT="100"
fi

if [[ -z "$3" ]]; then
    CFI=""
else
    CFI="-e $3"
    cp sherpa_${NAME}_weights_cfi.py ${CMSSW_BASE}/src
    cp sherpa_${NAME}_weights_cfi.py ${CMSSW_BASE}/src/Sherpa-cmssw/Generator/python
fi

# Generate random seeds
RANDOMSEED=`od -vAn -N4 -tu4 < /dev/urandom`
#Sometimes the RANDOMSEED is too long
RANDOMSEED=`echo $RANDOMSEED | rev | cut -c 3- | rev`

echo " --> Input process    : $NAME"
echo " --> Input nevent     : $NEVENT"
echo " --> RANDOMSEED       : $RANDOMSEED"
echo " --> RUNNING"
echo "${CMSSW_BASE}/src/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh -i ${BASE} -p ${NAME} ${CFI}"

${CMSSW_BASE}/src/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh -i ${BASE} -p ${NAME} ${CFI}
cp sherpa_${NAME}_MASTER_cff.py ${CMSSW_BASE}/src/Sherpa-cmssw/Generator/python
cd ${CMSSW_BASE}/src/

scram b 
cmsDriver.py Sherpa-cmssw/Generator/python/sherpa_${NAME}_MASTER_cff.py \
    --step GEN,NANOGEN \
    --mc \
    --datatier NANOAOD \
    --eventcontent NANOAODGEN \
    --conditions 106X_upgrade2018_realistic_v15_L1v1 \
    --beamspot Realistic25ns13TeVEarly2018Collision \
    --geometry DB:Extended \
    --era Run2_2018 \
    --python_filename cmsrun_${NAME}_MASTER_cfg.py \
    --fileout sherpa_${NAME}_${RANDOMSEED}.root \
    -n ${NEVENT} \
    --customise_commands process.RandomNumberGeneratorService.generator.initialSeed=$RANDOMSEED \
    --customise Configuration/DataProcessing/Utils.addMonitoring \
    --no_exec

cmsrun_${NAME}_MASTER_cfg.py

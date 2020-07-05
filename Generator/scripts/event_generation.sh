#!/bin/bash

set -e

if [[ `echo $1 | awk -F "_" '{print $1}'` != "Run.dat" ]] || [[ -z "$1" ]]; then
    echo "Please specify run card"
    exit 0
fi

LOCAL=$PWD

NAME=`echo $1 | awk -F "Run.dat_" '{print $2}'`
echo "Input process : $NAME"

GEN-SIM-STEP(){
    # conditions : https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideFrontierConditions#Global_Tags_for_Monte_Carlo_Prod
    cmsDriver.py Sherpa-cmssw/Generator/python/sherpa_${1}_MASTER_cff.py \
    --mc \
    --step GEN,SIM \
    --datatier GEN-SIM \
    --eventcontent RAWSIM \
    --conditions 102X_upgrade2018_realistic_v11 \
    --beamspot Realistic25ns13TeVEarly2018Collision \
    --geometry DB:Extended \
    --era Run2_2018 \
    --python_filename cmsrun_${1}_MASTER_cfg.py \
    --fileout sherpa_${1}.root \
    -n 100 \
    --customise_commands process.RandomNumberGeneratorService.generator.initialSeed=1111111 \
    --no_exec
}

if [ ! -e "sherpa_${NAME}_MASTER.tgz" ]; then

    #### STEP1 ####
    # hardcoded to use mpirun with 9 core; mpirun only use in creating libraries
    echo " --> STEP1 : MakeSherpaLibs.sh -p $NAME -o LBCR -v -m mpirun -M '-n 10'"
    chmod +x $CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh
    $CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh -p $NAME -o LBCR -v -m mpirun -M '-n 20'

    #### STEP2 ####
    echo " --> STEP2 : PrepareSherpaLibs.sh -p $NAME"
    $CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh \
	-p ${NAME}
        #-e $CMSSW_BASE/src/Sherpa-cmssw/Generator/SherpaGeneration/Generator/python/${SHERPA_CFI}

    #### STEP3 ####
    echo " --> STEP3 : Generating GEN-SIM"
    cp sherpa_${NAME}_MASTER_cff.py $LOCAL/../python
    cd $LOCAL/..
    scram b
    cd $LOCAL

    GEN-SIM-STEP ${NAME}

    cmsRun cmsrun_${NAME}_MASTER_cfg.py

else
    cp sherpa_${NAME}_MASTER_cff.py $LOCAL/../python
    cd $LOCAL/..
    scram b
    cd $LOCAL

    GEN-SIM-STEP ${NAME}
    cmsRun cmsrun_${NAME}_MASTER_cfg.py
fi

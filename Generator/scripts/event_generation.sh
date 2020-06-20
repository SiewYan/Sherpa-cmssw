#!/bin/bash

set -e

if [[ `echo $1 | awk -F "_" '{print $1}'` != "Run.dat" ]] || [[ -z "$1" ]]; then
    echo "Please specify run card"
    exit 0
fi

LOCAL=$PWD

NAME=`echo $1 | awk -F "Run.dat_" '{print $2}'`
echo "Input process : $NAME"

#### STEP1 ####
# hardcoded to use mpirun with 9 core; mpirun only use in creating libraries
#echo " --> STEP1 : MakeSherpaLibs.sh -p $NAME -o LBCR -v -m mpirun -M '-n 15'"
chmod +x $CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh
$CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh -p $NAME -o LBCR -v -m mpirun -M '-n 15'

#### STEP2 ####
for EXT in crss.tgz crdE.tgz logL.tgz libs.tgz migr.tgz
do
    if [ ! -e "sherpa_${NAME}_$EXT" ];then
	echo "missing libraries file sherpa_${NAME}_$EXT"
	exit 0
    fi
done

echo " --> STEP2 : PrepareSherpaLibs.sh -p $NAME"
$CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh \
    -p ${NAME}
    #-e $CMSSW_BASE/src/Sherpa-cmssw/Generator/SherpaGeneration/Generator/python/${SHERPA_CFI}

#### STEP3 ####
cp sherpa_${NAME}_MASTER_cff.py $LOCAL/../python
cd $LOCAL/..
scram b
cd $LOCAL

# conditions : https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideFrontierConditions#Global_Tags_for_Monte_Carlo_Prod
cmsDriver.py Sherpa-cmssw/Generator/python/sherpa_${NAME}_MASTER_cff.py \
    --mc \
    --step GEN,SIM \
    --datatier GEN-SIM \
    --eventcontent RAWSIM \
    --conditions auto:mc \
    --beamspot Realistic25ns13TeVEarly2018Collision \
    --geometry DB:Extended \
    --era Run2_2017 \
    --python_filename cmsrun_${NAME}_MASTER_cfg.py \
    --fileout sherpa_${NAME}.root \
    -n 10 \
    --customise_commands process.RandomNumberGeneratorService.generator.initialSeed=1111111 \
    --no_exec

cmsRun cmsrun_${NAME}_MASTER_cfg.py

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
#echo " --> STEP1 : MakeSherpaLibs.sh -p $NAME -o LBCR -v -m mpirun -M '-n 9'"
chmod +x $CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh
$CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh -p $NAME -o LBCR -v -m mpirun -M '-n 9'

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

#generated sherpack:
#sherpa_${NAME}_MASTER.tgz
#generated python fragment:
#sherpa_${NAME}_MASTER_cff.py
#MD5 checksum file:
#sherpa_${NAME}_MASTER.md5

#### STEP2 ####
for EXT in crss.tgz crdE.tgz logL.tgz libs.tgz migr.tgz
do
    rm sherpa_${NAME}_$EXT
done


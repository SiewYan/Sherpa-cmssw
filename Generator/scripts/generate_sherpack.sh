#!/bin/bash

set -e

NAME=`echo $1 | awk -F "Run.dat_" '{print $2}'`
NCPU=$2

if [[ `echo $1 | awk -F "_" '{print $1}'` != "Run.dat" ]] || [[ -z "$1" ]]; then
    echo "Please specify run card"
    echo "Example: generate_sherpack.sh Run.dat_NAME NCPU (if any)"
    exit 0
fi

if [[ -z "$1" ]]; then
    NCPU="4"
fi

echo " --> Input process : $NAME"
echo " --> Input Ncpu    : $NCPU"
echo " --> RUNNING"
echo "${CMSSW_BASE}/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M \"-n ${NCPU}\""

chmod +x $CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh
${CMSSW_BASE}/src/GeneratorInterface/SherpaInterface/data/MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M "-n ${NCPU}"


#### STEP2 ####
#for EXT in crss.tgz crdE.tgz logL.tgz libs.tgz migr.tgz
#do
#    if [ ! -e "sherpa_${NAME}_$EXT" ];then
#	echo "missing libraries file sherpa_${NAME}_$EXT"
#	exit 0
#    fi
#done

#echo " --> STEP2 : PrepareSherpaLibs.sh -p $NAME"
#$CMSSW_BASE/src/GeneratorInterface/SherpaInterface/data/PrepareSherpaLibs.sh \
#    -p ${NAME}
    #-e $CMSSW_BASE/src/Sherpa-cmssw/Generator/SherpaGeneration/Generator/python/${SHERPA_CFI}

#generated sherpack:
#sherpa_${NAME}_MASTER.tgz
#generated python fragment:
#sherpa_${NAME}_MASTER_cff.py
#MD5 checksum file:
#sherpa_${NAME}_MASTER.md5

#### STEP2 ####
#for EXT in crss.tgz crdE.tgz logL.tgz libs.tgz migr.tgz
#do
#    rm sherpa_${NAME}_$EXT
#done


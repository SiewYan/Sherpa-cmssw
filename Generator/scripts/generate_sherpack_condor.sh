#!/bin/bash

set -e

export SHERPACKDIR=${PWD}
#+++++++++++++++++++++++++++++++++++++++++++++++
#Run on one sherpack for testing, please comment this if run in bunches
#export EOSSPACE="/eos/uscms${eos_input}"
export EOSSPACE="./inputs"
#+++++++++++++++++++++++++++++++++++++++++++++++
export BASEDIR=${PWD}
if [ -e "work_${1}" ];then
    rm -r work_${1}
fi
mkdir work_${1}
export SUBMIT_WORKDIR=${PWD}/work_${1}

#copying necessary inputs
echo "GITCONFIG=${HOME}/.gitconfig" > ./submit/inputs.sh
echo "DAT=Run.dat_${1}"             >> ./submit/inputs.sh
for EXT in libs crdE crss logL migr; do echo "${EXT}=sherpa_${1}_${EXT}.tgz" >> ./submit/inputs.sh; done
echo "SHERPACK=sherpa_${1}_MASTER.tgz" >> ./submit/inputs.sh
echo "CFF=sherpa_${1}_MASTER_cff.py" >> ./submit/inputs.sh
echo "CFI=sherpa_${1}_MASTER_cfi.py" >> ./submit/inputs.sh
echo "CFG=cmsrun_${1}_MASTER_cfg.py" >> ./submit/inputs.sh
echo "MD5=sherpa_${1}_MASTER.md5" >> ./submit/inputs.sh
echo "PROCESS=${1}" >> ./submit/inputs.sh
echo "USERNAME=${USER}" >> ./submit/inputs.sh

if [ -z "$2" ]
then
    echo "EVENTGENERATION=1" >> ./submit/inputs.sh
    echo "You want to produce events for $1. Good luck!"
else
    echo "EVENTGENERATION=0" >> ./submit/inputs.sh
    echo "You want to produce sherpack for $1. Good luck!"
fi

# copy input files
mkdir -p ./submit/inputs/
for EXT in libs crdE crss logL migr; do cp ${SHERPACKDIR}/sherpa_${1}_${EXT}.tgz ./submit/inputs ; done
if [ -z ${BASEDIR}/${CFI} ]; then cp ${BASEDIR}/${CFI} ./submit/inputs ; fi

#x509
voms-proxy-init -voms cms -valid 172:00
cp ${HOME}/x509up_u${UID} ${SUBMIT_WORKDIR}/x509up

#git
cp ${HOME}/.gitconfig ${SUBMIT_WORKDIR}

#creating tarball
echo "Tarring up submit..."
tar -chzf submit.tgz submit 
rm -r ${BASEDIR}/submit/inputs/*

mv ${BASEDIR}/submit.tgz ${SUBMIT_WORKDIR}

cp ${BASEDIR}/exec.sh ${SUBMIT_WORKDIR}

#does everything look okay?
ls -l ${SUBMIT_WORKDIR}

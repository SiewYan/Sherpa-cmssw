#!/bin/bash

set -e

CARD=$1

if [[ `echo $CARD | awk -F "_" '{print $1}'` != "Run.dat" ]] || [[ -z "$1" ]]; then
    echo "Please specify run card"
    exit 0
fi

if [ ! -d "$PWD/log" ]; then
    mkdir log
else
    rm log/*
fi

NAME=`echo $CARD | awk -F "Run.dat_" '{print $2}'`
NCPU="10"

cat > submit_${NAME}.jdl <<EOF
universe                = vanilla
should_transfer_files   = YES
when_to_transfer_output = ON_EXIT
transfer_input_files    = {0}/submit.tgz, ${HOME}/.gitconfig
transfer_output_files   = sherpa_${NAME}_libs.tgz, sherpa_${NAME}_crdE.tgz, sherpa_${NAME}_crss.tgz, sherpa_${NAME}_logL.tgz, sherpa_${NAME}_migr.tgz
executable              = ${CMSSW_BASE}/src/Sherpa-cmssw/Generator/condor/sherpa.sh
arguments               = ${NAME} ${CMSSW_VERSION} ${NCPU}
request_cpus            = ${NCPU}
+JobFlavour             = "nextweek"
output                  = log/job_\$(Cluster)-\$(Process).out
error                   = log/job_\$(Cluster)-\$(Process).err
log                     = log/job_\$(Cluster)-\$(Process).log
queue 1
EOF

CLUSTER_ID=$(condor_submit "submit_${NAME}.jdl" | tail -n1 | rev | cut -d' ' -f1 | rev)
LOG_FILE=$(condor_q -format '%s\n' UserLog $CLUSTER_ID | tail -n1)

#echo "condor_submit submit_${NAME}.jdl"
#condor_submit submit_${NAME}.jdl

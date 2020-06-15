#!/bin/bash

set -e

if [[ `echo $1 | awk -F "_" '{print $1}'` != "Run.dat" ]] || [[ -z "$1" ]]; then
    echo "Please specify run card"
    exit 0
fi

LOCAL=$PWD
NAME=`echo $1 | awk -F "Run.dat_" '{print $2}'`
echo $1 > input.txt

cat > condor_sherpack_${NAME}.sub <<EOF
universe                = vanilla
should_transfer_files   = YES
when_to_transfer_output = ON_EXIT
transfer_input_files    = $PWD/$1
transfer_output_files   = sherpa_${NAME}_MASTER.tgz, sherpa_${NAME}_MASTER_cff.py, sherpa_${NAME}_MASTER.md5
executable              = $CMSSW_BASE/src/Sherpa-cmssw/Generator/scripts/sherpack_generation.sh
arguments               = $PWD/input.txt
RequestCpus             = 9
+JobFlavour             = "espresso"
output                  = output/${NAME}.out
error                   = error/${NAME}.err
log                     = log/${NAME}.log
queue
EOF

echo "condor_submit condor_sherpack_${NAME}.sub"
condor_submit condor_sherpack_${NAME}.sub

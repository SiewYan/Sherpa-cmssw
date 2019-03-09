#!/bin/bash

NAME=$1

./MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M '-n 9'

#./MakeSherpaLibs.sh -p ${NAME} -d ${CMSSW_BASE}/src/SherpaGeneration/Generator/sherpant -f drellyanZp -o LBCR -v -m mpirun -M '-n 9'

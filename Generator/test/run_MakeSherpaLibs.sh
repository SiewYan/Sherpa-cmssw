#!/bin/bash

NAME="ZtoEE_0j_OpenLoops_13TeV"

#./MakeSherpaLibs.sh -p ${NAME} -o LBCR -v

./MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M '-n 9'

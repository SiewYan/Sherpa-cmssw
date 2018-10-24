#!/bin/bash

NAME=$1

./MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M '-n 10'

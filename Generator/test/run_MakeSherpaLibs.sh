#!/bin/bash

ls Run.dat_*
echo "Please enter the tag of available Run.dat: Format Run.dat_[TAG]"
read NAME

echo "./MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M '-n 9'"
sleep 3

./MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M '-n 9'

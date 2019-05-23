#!/bin/bash

NAME=$1

begin=$(date +"%s")

./MakeSherpaLibs.sh -p ${NAME} -o LBCR -v -m mpirun -M '-n 9'

termin=$(date +"%s")
difftimelps=$(($termin-$begin))
echo "$(($difftimelps / 60)) minutes and $(($difftimelps % 60)) seconds elapsed for Script Execution."
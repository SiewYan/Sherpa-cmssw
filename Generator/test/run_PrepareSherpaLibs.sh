#!/bin/bash

#NAME="ZtoEE_0j_OpenLoops_13TeV"
#SHERPA_CFI="ExtendedSherpaWeights_cfi.py"
NAME=$1
SHERPA_CFI=$2

#./PrepareSherpaLibs.sh -p ${NAME} -e SherpaGeneration/Generator/python/ExtendedSherpaWeights_Moriond18_cfi.py

./PrepareSherpaLibs.sh -p ${NAME} -e SherpaGeneration/Generator/python/${SHERPA_CFI}

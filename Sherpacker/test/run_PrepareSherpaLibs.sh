#!/bin/bash

NAME=$1
SHERPA_CFI=$2

if [[ -z "$SHERPA_CFI" ]]; then
    ./PrepareSherpaLibs.sh -p ${NAME}
else
    ./PrepareSherpaLibs.sh -p ${NAME} -e SherpaGeneration/Generator/python/${SHERPA_CFI}
fi

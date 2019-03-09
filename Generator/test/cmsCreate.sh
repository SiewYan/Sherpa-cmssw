#!/bin/bash

echo "
cmsDriver.py SherpaGeneration/Generator/python/sherpa_HAHM_variableMW_UFO_Zpmumu_LO_13TeV_MASTER_cff.py \
    -s GEN -n 1000 --no_exec --conditions auto:mc --eventcontent RAWSIM
"
cmsDriver.py SherpaGeneration/Generator/python/sherpa_HAHM_variableMW_UFO_Zpmumu_LO_13TeV_MASTER_cff.py \
    -s GEN -n 1000 --no_exec --conditions auto:mc --eventcontent RAWSIM
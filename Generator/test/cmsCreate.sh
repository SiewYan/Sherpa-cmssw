#!/bin/bash

frag=$1

Nevent="1000"

echo "
cmsDriver.py SherpaGeneration/Generator/python/${frag} \
--mc -s GEN --datatier GEN-SIM -n ${Nevent} --no_exec --conditions auto:run2_mc_FULL \
--eventcontent RAWSIM --beamspot Realistic25ns13TeVEarly2017Collision
"

cmsDriver.py SherpaGeneration/Generator/python/${frag} \
    --mc -s GEN --datatier GEN-SIM -n ${Nevent} --no_exec --conditions auto:run2_mc_FULL \
    --eventcontent RAWSIM --beamspot Realistic25ns13TeVEarly2017Collision
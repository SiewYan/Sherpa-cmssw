#!/bin/bash

cmsDriver.py Sherpa-cmssw/Generator/python/sherpa_$1_MASTER_cff.py \
    --mc \
    --step GEN,SIM \
    --datatier GEN-SIM \
    --eventcontent RAWSIM \
    --conditions auto:mc \
    --beamspot Realistic25ns13TeVEarly2018Collision \
    --geometry DB:Extended \
    --era Run2_2017 \
    --python_filename cmsrun_$1_MASTER_cfg.py \
    --fileout sherpa_$1.root \
    -n 10 \
    --customise_commands process.RandomNumberGeneratorService.generator.initialSeed=1111111 \
    --no_exec

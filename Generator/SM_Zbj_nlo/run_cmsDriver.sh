#!/bin/bash

frag=$1
Nevent="100"
dir=`pwd`

if [ -e $frag ];then
    scp $frag ../python/
    eval cd ../
    scram b
    eval cd $dir

    cmsDriver.py SherpaGeneration/Generator/python/${frag} \
	--mc \
	--step GEN,SIM \
	--datatier GEN-SIM \
	--eventcontent RAWSIM \
	--conditions 93X_mc2017_realistic_v3 \
	--beamspot Realistic25ns13TeVEarly2017Collision \
	--geometry DB:Extended \
	--era Run2_2017 \
	--python_filename ${dir}/cmsRun_cfg.py \
	-n ${Nevent} \
	--customise Configuration/GenProduction/randomizeSeeds.randomizeSeeds \
	--customise_commands process.RandomNumberGeneratorService.generator.initialSeed=1111111 \
	--no_exec
else
    echo "$frag is missing"
    exit 0
fi

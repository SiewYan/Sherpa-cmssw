#!/bin/bash

#msDriver.py A/B/python/sherpa_WtoLNu_2j_NLO_BlackHat_CKKW_13TeV_MASTER_cff.py \
#        -s GEN -n 100 --no_exec --conditions auto:mc --eventcontent RAWSIM

#BlackHat
GENFRAGMENT=sherpa_WtoLNu_2j_NLO_OpenLoops_CKKW_13TeV_MASTER_cff.py
NEVTS=1000
RIVET=rivet_customize_13TeV_Wjet_NLO.py
withVALIDATION=0

if [ "${withVALIDATION}" == "1" ];then
    echo "GEN,VALIDATION STEP"
    cmsDriver.py SherpaGeneration/Generator/python/${GENFRAGMENT} \
	--mc \
	-n ${NEVTS} \
	--python_filename cmsrun_rivet_GENVAL_${GENFRAGMENT} \
	-s GEN,VALIDATION:genvalid_all \
	--datatier GEN-SIM,DQMIO \
	--eventcontent RAWSIM,DQM \
	--conditions auto:run2_mc_FULL \
	--beamspot Realistic25ns13TeVEarly2017Collision \
	--customise SherpaGeneration/Generator/${RIVET} \
	--no_exec

    echo "---> cmsrun_rivet_sherpa_WtoLNu_2j_NLO_OpenLoops_CKKW_13TeV_MASTER_cff.py produced"
else
    echo "ONLY GEN STEP"
    cmsDriver.py SherpaGeneration/Generator/python/${GENFRAGMENT} \
        --mc \
        -n ${NEVTS} \
        --python_filename cmsrun_rivet_GEN_${GENFRAGMENT} \
        -s GEN \
        --datatier GEN-SIM \
        --eventcontent RAWSIM \
        --conditions auto:run2_mc_FULL \
        --beamspot Realistic25ns13TeVEarly2017Collision \
        --customise SherpaGeneration/Generator/${RIVET} \
        --no_exec

    echo "---> cmsrun_rivet_sherpa_WtoLNu_2j_NLO_OpenLoops_CKKW_13TeV_MASTER_cff.py produced"
fi
#Realistic8TeVCollision

#!/bin/bash

#Nevent is preconfiged to 100 events for generating only Sherpack (The idea is to perform \
#a whole generation chain to sort of validate the sherpack is working). Unless you wanna \
#generate events, change 100 to desire sizable number.
#./makeJob.sh ZtoEE_0j_OpenLoops_13TeV ExtendedSherpaWeights_cfi.py 100 1nd
#./makeJob.sh WtoLNu_2j_NLO_BlackHat_CKKW_13TeV ExtendedSherpaWeights_cfi.py 1000 1nd
#./makeJob.sh WtoLNu_2j_NLO_OpenLoops_CKKW_13TeV ExtendedSherpaWeights_cfi.py 1000 1nd

./makeJob.sh WtoMNu_2j_LO_BlackHat_13TeV no 1000 1nw
./makeJob.sh WtoMNu_2j_LO_OpenLoops_13TeV no 1000 1nw
./makeJob.sh WtoMNu_2j_NLO_BlackHat_CKKW_13TeV no 1000 1nw
./makeJob.sh WtoMNu_2j_NLO_OpenLoops_CKKW_13TeV no 1000 1nw

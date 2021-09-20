#!/bin/bash

#Nevent is preconfiged to 100 events for generating only Sherpack (The idea is to perform \
#a whole generation chain to sort of validate the sherpack is working). Unless you wanna \
#generate events, change 100 to desire sizable number.
./makeJob.sh ZtoEE_0j_OpenLoops_13TeV ExtendedSherpaWeights_cfi.py 100 1nd

#!/bin/bash

export PATH=${PATH}:${CMSSW_BASE}/src/SherpaGeneration/Generator/sherpant/bin
export SHERPA_SHARE_PATH=${SHERPA_SHARE_PATH}:${CMSSW_BASE}/src/SherpaGeneration/Generator/sherpant/share/SHERPA-MC
export SHERPA_INCLUDE_PATH=${SHERPA_INCLUDE_PATH}:${CMSSW_BASE}/src/SherpaGeneration/Generator/sherpant/include/SHERPA-MC
export SHERPA_LIBRARY_PATH=${SHERPA_LIBRARY_PATH}:${CMSSW_BASE}/src/SherpaGeneration/Generator/sherpant/lib/SHERPA-MC
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${CMSSW_BASE}/src/SherpaGeneration/Generator/sherpant/lib/SHERPA-MC

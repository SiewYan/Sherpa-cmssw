# Sherpa-Generation

## Setup

   Setup CMSSW environment, using Sherpa v2.2.4; OpenLoops v1.3.1; BlackHat v0.9.9

   ```
   scram project CMSSW_9_4_8
   cd CMSSW_9_4_8/src
   cmsenv	 
   export TOPDIR=$PWD
   ```

   checkout the SherpaInterface: 

   ```
   git cms-addpkg -q GeneratorInterface/SherpaInterface
   ```

   checkout the clone

   ```
   git clone https://github.com/SiewYan/SherpaGeneration.git
   scram b -j8
   ```
   
   The version of Sherpa Interfaced with the cmssw can be revealed

   ```
   scram tool info Sherpa
   ```

## Generate Sherpack on Z+jets

   ```
   cd SherpaGeneration/Generator/test
   sh run_MakeSherpaLibs.sh ZtoEE_0j_OpenLoops_13TeV
   sh run_PrepareSherpaLibs.sh ZtoEE_0j_OpenLoops_13TeV ExtendedSherpaWeights_cfi.py
   sh run_GenerateEvent.sh sherpa_ZtoEE_0j_OpenLoops_13TeV
   ```

## Reference

   - https://twiki.cern.ch/twiki/bin/view/CMS/SherpaInterfaceStepByStep

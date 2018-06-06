# Sherpa-Generation

## Setup

   Setup CMSSW environment, using Sherpa v2.2.4; OpenLoops v1.3.1; BlackHat v0.9.9

   ```
   scram project CMSSW_9_3_1
   cd CMSSW_9_3_1/src
   cmsenv	 
   export TOPDIR=$PWD
   ```

   checkout the SherpaInterface: 

   ```
   git cms-addpkg GeneratorInterface/SherpaInterface
   ```

   checkout the clone

   ```
   git clone https://github.com/SiewYan/Sherpa-Generation.git
   scram b -j8
   ```

## Generate Sherpack

   ```
   cd Sherpa-Generation/Generator/test
   sh run_MakeSherpaLibs.sh
   sh run_PrepareSherpaLibs.sh
   sh generateValidation.sh sherpa_ZtoEE_0j_OpenLoops_13TeV
   ```

## Reference

   - https://twiki.cern.ch/twiki/bin/view/CMS/SherpaInterfaceStepByStep

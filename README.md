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
   git cms-addpkg GeneratorInterface/SherpaInterface
   ```

   checkout the clone

   ```
   git clone https://github.com/SiewYan/SherpaGeneration.git
   scram b -j8
   ```

## Generate Sherpack

   ### On head

   ```
   cd SherpaGeneration/Generator/test
   sh run_MakeSherpaLibs.sh
   sh run_PrepareSherpaLibs.sh
   sh generateValidation.sh sherpa_ZtoEE_0j_OpenLoops_13TeV
   ```

   ### Using LSF Batch

   ```
   cd SherpaGeneration/Generator/batch
   sh run.sh #running on ZtoEE_0j_OpenLoops_13TeV with weight ExtendedSherpaWeights_cfi.py
   ```

   By default, your job is submitted to 1 day queue, checking your LSF job status:

   ```
   bqueue
   ```

## Reference

   - https://twiki.cern.ch/twiki/bin/view/CMS/SherpaInterfaceStepByStep

# Sherpa-Generation

## Setup

   Setup CMSSW environment
   ``` 
   CMSSW_10_3_0_pre5: sherpa 2.2.5; openloops 2.0.b; blackhat 0.9.9-omkpbe4
   ```

   ```
   scram project CMSSW_10_3_0_pre5
   cd CMSSW_10_3_0_pre5/src
   cmsenv	 
   export TOPDIR=$PWD
   ```

   checkout the SherpaInterface: 

   ```
   git cms-addpkg -q GeneratorInterface/SherpaInterface
   ```

   checkout the RivetInterface:

   ```
   git-cms-addpkg GeneratorInterface/RivetInterface
   ```

   Copy the interface scripts to working directory ```test```

   ```
   cp $TOPDIR/GeneratorInterface/SherpaInterface/data/*SherpaLibs.sh $TOPDIR/SherpaGeneration/Generator/test/
   ```

   Clone the repository SherpaGeneration:

   ```
   git clone https://github.com/SiewYan/SherpaGeneration.git
   scram b -j8
   ```
   
   The version of Sherpa Interfaced with the cmssw can be revealed

   ```
   scram tool info Sherpa
   ```

## Generate Sherpack on Z+jets

   ### On head

   ```
   cd SherpaGeneration/Generator/test
   sh run_MakeSherpaLibs.sh ZtoEE_0j_OpenLoops_13TeV
   sh run_PrepareSherpaLibs.sh ZtoEE_0j_OpenLoops_13TeV ExtendedSherpaWeights_cfi.py
   sh run_GenerateEvent.sh sherpa_ZtoEE_0j_OpenLoops_13TeV
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
   
   You will find a bunch of log file to check the health of the sherpack,sherpacks, and fragment file in EOS

   ```
   #ls /eos/user/U/USERNAME/SHERPA_ZtoEE_0j_OpenLoops_13TeV/
   Log_step1                                               sherpa_ZtoEE_0j_OpenLoops_13TeV_crdE.tgz
   Log_step2                                               sherpa_ZtoEE_0j_OpenLoops_13TeV_crss.tgz
   MPI_Cross_Sections.dat                                  sherpa_ZtoEE_0j_OpenLoops_13TeV_libs.tgz
   sherpa_ZtoEE_0j_OpenLoops_13TeV_MASTER.tgz              sherpa_ZtoEE_0j_OpenLoops_13TeV_logL.tgz
   sherpa_ZtoEE_0j_OpenLoops_13TeV_MASTER_cff.py           sherpa_ZtoEE_0j_OpenLoops_13TeV_migr.tgz
   sherpa_ZtoEE_0j_OpenLoops_13TeV_MASTER_cff_py_GEN.root   
   ```

## Reference

   - https://twiki.cern.ch/twiki/bin/view/CMS/SherpaInterfaceStepByStep

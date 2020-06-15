# Sherpa-cmssw
helping kits for sherpa event generation

## Setup

   Setup CMSSW environment, decide your release
   
   | release | master release  | Sherpa version | Openloop version |
   | ------------- | ------------- | ------------- | ------------- |
   | 71X  | [CMSSW_7_1_15](https://github.com/cms-sw/cmssw/releases/CMSSW_7_1_45)  | 2.2.8 | 2.0.0 |
   | 93X  | [CMSSW_9_3_17](https://github.com/cms-sw/cmssw/releases/CMSSW_9_3_17)  | 2.2.8 | 2.1.0 |
   | 102X | [CMSSW_10_2_20](https://github.com/cms-sw/cmssw/releases/CMSSW_10_2_20) | 2.2.8 | 2.1.0 |
   | 106X | [CMSSW_10_6_7](https://github.com/cms-sw/cmssw/releases/CMSSW_10_6_8)  | 2.2.8 | 2.1.0 |
   | 110X | [CMSSW_11_0_0](https://github.com/cms-sw/cmssw/releases/CMSSW_11_0_0) | 2.2.8 | 2.1.0 |
   
  See more info see Gurpreet's [slide](https://indico.cern.ch/event/873792/contributions/3718710/attachments/1981426/3299820/Sherpa_status_CMS.pdf)
  

   ```
   scram project CMSSW_X_Y_Z
   cd CMSSW_X_Y_Z/src
   cmsenv	 
   export TOPDIR=$PWD
   ```

   checkout the SherpaInterface: 

   ```
   git cms-addpkg -q GeneratorInterface/SherpaInterface
   ```

   checkout the RivetInterface (optional):

   ```
   git-cms-addpkg GeneratorInterface/RivetInterface
   ```

   Clone the repository SherpaGeneration:

   ```
   git clone https://github.com/SiewYan/Sherpa-cmssw.git
   scram b -j8
   ```
   
   The version of Sherpa (Openloops) Interfaced with the cmssw can be identified by:

   ```
   scram tool info Sherpa
   scram tool info OpenLoops
   ```

## Example of generating Events

   ### On head

   ```
   cd Sherpa-cmssw/Generator/test
   ../scripts/generate.sh Run.dat_ZtoEE_0j_LO_OpenLoops_13TeV
   ```
    -- TO BE UPDATE --
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

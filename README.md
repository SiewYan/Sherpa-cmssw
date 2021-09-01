# Sherpa-cmssw
helper script for sherpa event generation

## Sherpa, Openloops version
   
   | release cycle | master/pre release  | Sherpa version | Openloop version | Remark |
   | ------------- | ------------- | ------------- | ------------- | ------------- |
   | 7_1_X  | [CMSSW_7_1_45](https://github.com/cms-sw/cmssw/releases/CMSSW_7_1_45) | 2.2.8 | 2.0.0 | OpenLoop version 2.0.0 due to old git version |
   | 9_3_X  | [CMSSW_9_3_17](https://github.com/cms-sw/cmssw/releases/CMSSW_9_3_17) | 2.2.8 | 2.1.0 | Release for developments for physics ready 2017 MC and data taking release |
   | 10_2_X | [CMSSW_10_2_20](https://github.com/cms-sw/cmssw/releases/CMSSW_10_2_20) | 2.2.8 | 2.1.0 |  2018 pp data taking release  |
   |        | [CMSSW_10_2_24](https://cmssdt.cern.ch/SDT/ReleaseNotes/CMSSW_10/CMSSW_10_2_24.html) | 2.2.10 | 2.1.0 | |
   | 10_6_X | [CMSSW_10_6_7](https://github.com/cms-sw/cmssw/releases/CMSSW_10_6_8) | 2.2.8 | 2.1.0 | ultra-legacy reprocessing of Run2 and L1T TDR  |
   |        | [CMSSW_10_6_15](https://cmssdt.cern.ch/SDT/ReleaseNotes/CMSSW_10/CMSSW_10_6_15.html) | 2.2.10 | 2.1.0 | |
   |        | [CMSSW_10_6_28](https://github.com/cms-sw/cmssw/releases?after=CMSSW_11_3_X_2021-08-31-2300) | 2.2.11 | 2.1.2 | |
   | 11_0_X | [CMSSW_11_0_0](https://github.com/cms-sw/cmssw/releases/CMSSW_11_0_0) | 2.2.8 | 2.1.0 | |
   | 11_2_X | [CMSSW_11_2_0_pre3](https://cmssdt.cern.ch/SDT/ReleaseNotes/CMSSW_11/CMSSW_11_2_0_pre3.html) | 2.2.10 | 2.1.1 | Release for the migration to DD4HEP and DPG developments for Run-3 |
   
   
  See more info see Gurpreet's [slide](https://indico.cern.ch/event/873792/contributions/3718710/attachments/1981426/3299820/Sherpa_status_CMS.pdf)
  

## Setup

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
   ../scripts/event_generation.sh Run.dat_ZtoEE_0j_LO_OpenLoops_13TeV
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

# Process Runcards

## Overview:

   In order to perform a sensible comparison between Sherpa and Madgraph MC generator, a benchmark runcard is needed between two MC generators.

## Standard Candle processes under study:
   
   - Generator choice:
     - NLO_QCD_Mode: ```MC@NLO```
     - Matrix Element Generator: ```Amegic```
     - Real Subtracted NLO Generator: ```Comix```
     - Loop Generator: ```OpenLoop```
     - MI Generator  : ```Amisic```

   - Run condition:
     - Number of events: ```EVENTS 1M```
     - 13 TeV
     - 5 Flavor: ```MASSIVE_PS 4 5```
     - Default scale: ```FSF:=1., RSF:=1., QSF:=1.```
     - Scale setters (CKKW): ```SCALES METS{FSF*MU_F2}{RSF*MU_R2}{QSF*MU_Q2};```
     - Event Generation mode: ```Unweighted```
     - Multijets: ```NJET:=2```
     - Exclude tau from lepton container: ```MASSIVE[15] 1```
     - PDFID: ```PDF_SET = NNPDF31_nnlo_hessian_pdfas```
     - No scale variation choice.
     - Matrix element level Cuts at respective Boson mass window: ```(selector)```     

   - Processes:
   
   | Processes | Accuracy | Runcard | Madgraph Validation | Data Validation |  
   | --- | --- | --- | --- | --- |
   | Z+jets      | NLO | [Z_2j_NLO_OpenLoops_CKKW_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Inclusives/Run.dat_Z_2j_NLO_OpenLoops_CKKW_13TeV) | | [ATLAS_2017_I1514251](https://rivet.hepforge.org/analyses/ATLAS_2017_I1514251.html)|
   | Z(ee)       | LO | [ZtoEE_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_0j_LO_OpenLoops_13TeV) | | |
   | Z(ee)+jets  | LO/NLO | [ZtoEE_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_2j_LO_OpenLoops_13TeV) [ZtoEE_2j_NLO_OpenLoops_CKKW_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_2j_NLO_OpenLoops_CKKW_13TeV) | | [ATLAS_2017_I1514251_EL](https://rivet.hepforge.org/analyses/ATLAS_2017_I1514251_EL.html) |
   | Z(mm)+jets  | NLO |  [ZtoMM_2j_NLO_OpenLoops_CKKW_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoMM_2j_NLO_OpenLoops_CKKW_13TeV) | | [ATLAS_2017_I1514251_MU](https://rivet.hepforge.org/analyses/ATLAS_2017_I1514251_MU.html) |
   | W           | LO | [W_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Inclusives/Run.dat_W_0j_LO_OpenLoops_13TeV)  | | |
   | W+jets      | LO | [W_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Inclusives/Run.dat_W_2j_LO_OpenLoops_13TeV)  | | [CMS_2017_I1610623](https://rivet.hepforge.org/analyses/CMS_2017_I1610623.html) |  
   | W(enu)+jets | NLO | [WtoENu_2j_NLO_OpenLoops_CKKW_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_WtoENu_2j_NLO_OpenLoops_CKKW_13TeV) | | |
   | W(mnu)      | LO | [WtoMNu_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_WtoMNu_0j_LO_OpenLoops_13TeV) | | |
   | W(mnu)+jets | LO/NLO | [WtoMNu_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_WtoMNu_2j_LO_OpenLoops_13TeV) [WtoMNu_2j_NLO_OpenLoops_CKKW_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_WtoMNu_2j_NLO_OpenLoops_CKKW_13TeV)  | | |
   | QCD        | LO | | | |
   | Gamma+jets | LO | | | |
   | DY+jets    | LO | | | |
   | VBS, VBF   | LO | | | |
   | ttbar      | LO | | | |	
   | ttbar+jets | LO | | | |
   | Higgs+jets | LO | | | |

## Reference:

   - Sherpa 2.2.5 Reference: https://sherpa.hepforge.org/doc/SHERPA-MC-2.2.5.html#Introduction-to-Sherpa
   - Sherpa 2.2.5 Overview : https://www.physik.uzh.ch/~marek/talks/20180621_CERN_b.pdf
   - Sherpa proceses: https://indico.cern.ch/event/746827/contributions/3112180/attachments/1705240/2747419/Sherpa_27_8_18_Gurpreet.pdf

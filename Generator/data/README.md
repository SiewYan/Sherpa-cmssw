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

   - Processes:
   
   | Processes | Accuracy | Runcard | Madgraph Validation | Data Validation |  
   | --- | --- | --- | --- | --- |
   | Z(ee)       | LO | [ZtoEE_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_0j_LO_OpenLoops_13TeV) | | |
   | Z(ee)+jets  | LO/NLO | [ZtoEE_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_2j_LO_OpenLoops_13TeV) [ZtoEE_2j_NLO_OpenLoops_CKKW_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_2j_NLO_OpenLoops_CKKW_13TeV) | | |
   | Z(mm)+jets  | NLO |  [ZtoMM_2j_NLO_OpenLoops_CKKW_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoMM_2j_NLO_OpenLoops_CKKW_13TeV) | | |
   | W           | LO | [W_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Inclusives/Run.dat_W_0j_LO_OpenLoops_13TeV)  | | |
   | W+jets      | LO | [W_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Inclusives/Run.dat_W_2j_LO_OpenLoops_13TeV)  | | |  
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
   - Sherpa proceses: https://indico.cern.ch/event/746827/contributions/3112180/attachments/1705240/2747419/Sherpa_27_8_18_Gurpreet.pdf

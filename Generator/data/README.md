# Process Runcards

## Overview:

   In order to perform a sensible comparison between Sherpa and Madgraph MC generator, a benchmark runcard is needed between two MC generators.

## Standard Candle processes under study:
   
   - Generator choice:
     - NLO_QCD_Mode: MC@NLO
     - Matrix Element Generator: Amegic
     - Real Subtracted NLO Generator: Comix
     - Loop Generator: OpenLoop

   - Processes:
   
   | Processes | Accuracy | Runcard | Madgraph Validation | Data (Rivet) Validation |  
   | --- | --- | --- | --- | --- |
   | Z(ee)      | LO: NJET:=0, LJET:=0; NLO: NJET:=0, LJET:=2 | [ZtoEE_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_0j_LO_OpenLoops_13TeV); [ZtoEE_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_0j_LO_OpenLoops_13TeV) | | |
   | Z(ee)+jets | LO: NJET:=2, LJET:=0. | [ZtoEE_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_ZtoEE_2j_LO_OpenLoops_13TeV) | | |
   | W          | LO: NJET:=0, LJET:=0. | [W_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Inclusives/Run.dat_W_0j_LO_OpenLoops_13TeV)  | | |
   | W+jets     | LO: NJET:=2, LJET:=0. | [W_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Inclusives/Run.dat_W_2j_LO_OpenLoops_13TeV)  | | |  
   | W(mn)      | LO: NJET:=0, LJET:=0. | [WtoMN_0j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_WtoMN_0j_LO_OpenLoops_13TeV)  | | |
   | W(mn)+jets | LO: NJET:=2, LJET:=0. | [WtoMN_2j_LO_OpenLoops_13TeV](https://github.com/SiewYan/SherpaGeneration/blob/master/Generator/data/Exclusives/Run.dat_WtoMN_2j_LO_OpenLoops_13TeV)  | | |
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

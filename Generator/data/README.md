# Process Runcards

## Overview:

   In order to perform a sensible comparison between Sherpa and Madgraph MC generator, a benchmark runcard is needed between two MC generators.

## Standard Candle processes under study:

   | Processes | Accuracy | Runcard | Madgraph Validation | Data (Rivet) Validation |  
   | --- | --- | --- | --- | --- |
   | Z(ee)      | LO: NJET:=0; LJET:=0; | Run.dat_ZtoEE_0j_OpenLoops_13TeV | | |
   | Z(ee)+jets | LO: NJET:=2; LJET:=0; | Run.dat_ZtoEE_2j_OpenLoops_13TeV | | |
   | W          | LO | | | |
   | W+jets     | LO | | | |  
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
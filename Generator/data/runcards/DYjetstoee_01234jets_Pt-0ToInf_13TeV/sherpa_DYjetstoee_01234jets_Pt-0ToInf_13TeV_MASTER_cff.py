import FWCore.ParameterSet.Config as cms
import os
from Sherpa-cmssw.Generator.ExtendedSherpaWeights_Moriond18_cfi import *

source = cms.Source("EmptySource")

generator = cms.EDFilter("SherpaGeneratorFilter",
  maxEventsToPrint = cms.int32(0),
  filterEfficiency = cms.untracked.double(1.0),
  crossSection = cms.untracked.double(-1),
  SherpaProcess = cms.string('DYjetstoee_01234jets_Pt-0ToInf_13TeV'),
  SherpackLocation = cms.string('./'),
  SherpackChecksum = cms.string('93f335e2f5c24e509b4041fa92621b65'),
  FetchSherpack = cms.bool(False),
  SherpaPath = cms.string('./'),
  SherpaPathPiece = cms.string('./'),
  SherpaResultDir = cms.string('Result'),
  SherpaDefaultWeight = cms.double(1.0),
  SherpaWeightsBlock = SherpaWeightsBlock,
  SherpaParameters = cms.PSet(parameterSets = cms.vstring(
                             "MPI_Cross_Sections",
                             "Run"),
                              MPI_Cross_Sections = cms.vstring(
				" MPIs in Sherpa, Model = Amisic:",
				" semihard xsec = 39.7388 mb,",
				" non-diffractive xsec = 17.0318 mb with nd factor = 0.3142."
                                                  ),
                              Run = cms.vstring(
				" (run){",
				" EVENTS 100K; ERROR 0.99;",
				" HEPMC_USE_NAMED_WEIGHTS=1;",
				" FSF:=1.; RSF:=1.; QSF:=1.;",
				" SCALES STRICT_METS{FSF*MU_F2}{RSF*MU_R2}{QSF*MU_Q2};",
				" SCALE_VARIATIONS 0.25,0.25 0.25,1. 1.,0.25 1.,1. 1.,4. 4.,1. 4.,4.;",
				" ASSOCIATED_CONTRIBUTIONS_VARIATIONS EW EW|LO1;",
				" ME_SIGNAL_GENERATOR Comix Amegic LOOPGEN;",
				" OL_PREFIX=/cvmfs/cms.cern.ch/slc6_amd64_gcc481/external/openloops/2.0.0;",
				" EVENT_GENERATION_MODE PartiallyUnweighted;",
				" OL_PARAMETERS ew_renorm_scheme 1;",
				" LOOPGEN:=OpenLoops;",
				" PP_RS_SCALE VAR{0.25*H_Tp2};",
				" MASSIVE[15] 1;",
				" BEAM_1 2212; BEAM_ENERGY_1 = 6500.;",
				" BEAM_2 2212; BEAM_ENERGY_2 = 6500.;",
				" PDF_LIBRARY LHAPDFSherpa;",
				" PDF_SET NNPDF30_nnlo_as_0118;",
				" PDF_VARIATIONS NNPDF30_nnlo_as_0118[all];",
				"}(run)",
				" (processes){",
				" Process 93 93 -> 11 -11;",
				" Order (*,2); CKKW sqr(QCUT/E_CMS);",
				" NLO_QCD_Mode MC@NLO {LJET};",
				" ME_Generator Amegic {LJET};",
				" RS_ME_Generator Comix {LJET};",
				" Loop_Generator LOOPGEN {LJET};",
				" Associated_Contributions EW|LO1 {LJET};",
				" Enhance_Observable VAR{log10(PPerp(p[2]+p[3]))}|1.|3. {3,4,5,6};",
				" Integration_Error 0.02 {2};",
				" Integration_Error 0.02 {3};",
				" Integration_Error 0.02 {4};",
				" Integration_Error 0.05 {5};",
				" Integration_Error 0.05 {6};",
				" End process;",
				"}(processes)",
				" (selector){",
				" Mass 11 -11 50. E_CMS;",
				"}(selector)"
                                                  ),
                             )
)

ProductionFilterSequence = cms.Sequence(generator)


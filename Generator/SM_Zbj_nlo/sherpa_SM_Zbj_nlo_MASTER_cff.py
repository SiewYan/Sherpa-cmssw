import FWCore.ParameterSet.Config as cms
import os

source = cms.Source("EmptySource")

generator = cms.EDFilter("SherpaGeneratorFilter",
  maxEventsToPrint = cms.int32(0),
  filterEfficiency = cms.untracked.double(1.0),
  crossSection = cms.untracked.double(-1),
  SherpaProcess = cms.string('SM_Zbj_nlo'),
  SherpackLocation = cms.string('./'),
  SherpackChecksum = cms.string('318730406a38a1a2f12d5ad8788304ad'),
  FetchSherpack = cms.bool(False),
  SherpaPath = cms.string('./'),
  SherpaPathPiece = cms.string('./'),
  SherpaResultDir = cms.string('Result'),
  SherpaDefaultWeight = cms.double(1.0),
  SherpaParameters = cms.PSet(parameterSets = cms.vstring(
                             "MPI_Cross_Sections",
                             "Run"),
                              MPI_Cross_Sections = cms.vstring(
				" MPIs in Sherpa, Model = Amisic:",
				" semihard xsec = 80.6402 mb,",
				" non-diffractive xsec = 17.0318 mb with nd factor = 0.3142."
                                                  ),
                              Run = cms.vstring(
				" (run){",
				" # general settings",
				" EVENTS 100;",
				" # me generator setup",
				" # Amegic",
				" ME_SIGNAL_GENERATOR Comix Amegic LOOPGEN;",
				" OL_PREFIX=/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/openloops/2.0.0",
				" ME_SIGNAL_GENERATOR  Comix LOOPGEN;",
				" OL_PREFIX=/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/openloops/2.0.0",
				" EVENT_GENERATION_MODE PartiallyUnweighted;",
				" LOOPGEN:=OpenLoops;",
				" SCALES VAR{Abs2(p[0]+p[1])};",
				" # model setup",
				" MODEL SM;",
				" # tags for process setup",
				" # NJET = the maximal number of extra jets",
				" # LJET = the multiplicity of the MC@NLO subprocesses, exp: LJET = 2,3 means X+jj and X+jjj will be produced NLO",
				" # QCUT = the merging cut",
				" NJET:=1; LJET:=0,1; QCUT:=30;",
				" # uncomment to disable underlying event simulation:",
				" # MI_HANDLER None; #Or Amisic",
				" # uncomment to disable hadronization:",
				" #FRAGMENTATION Ahadic; #Or Ahadic",
				" # uncomment to disable shower:",
				" # SHOWER_GENERATOR None; #Or Dire, CSS",
				" # LHC beam setup:",
				" BEAM_1 2212; BEAM_ENERGY_1 6500;",
				" BEAM_2 2212; BEAM_ENERGY_2 6500;",
				" # LHAPDF",
				" PDF_LIBRARY = LHAPDFSherpa;",
				" PDF_SET = NNPDF30_lo_as_0130; #263000",
				" # the bottom quark is treated masslessly by default, a five flavour calculation is performed",
				" PARTICLE_CONTAINER 900 bottom 5 -5;",
				" PARTICLE_CONTAINER 901 lightflavs 1 -1 2 -2 3 -3 4 -4 21 5 -5;",
				" #NLO_CSS_DISALLOW_FLAVOUR 5;",
				" # 15000.0       =  bwcutoff",
				" # https://cp3.irmp.ucl.ac.be/projects/madgraph/wiki/FAQ-Cards-2",
				" # With the default HARD_MASS_SMEARING= the kinematic mass of the unstable propagator is distributed according to a Breit-Wigner shape a posteriori.",
				" # All matrix elements are still calculated in the narrow-width approximation with onshell particles. Only the kinematics are affected.",
				" # To keep all intermediate particles onshell HARD_MASS_SMEARING=0",
				" # Hard decay",
				" # particle properties (ME widths need to be zero if external)",
				" #HARD_DECAYS : This decay module can also be used on top of NLO matrix elements, but it does not include any NLO corrections in the decay matrix elements themselves.",
				" #HARD_DECAYS 1; #HARD_MASS_SMEARING 0;",
				" #WIDTH[23] 0;",
				" ## disable higgs -> neu neu",
				"}(run)",
				" (processes){",
				" Process 901 901 -> 23[a] 900 901{NJET}",
				" DecayOS 23[a] -> 91 91",
				" #Order (*,0); #This ensures that all final state jets are produced via the strong interaction.",
				" CKKW sqr(QCUT/E_CMS);",
				" NLO_QCD_Mode MC@NLO {LJET};",
				" ME_Generator Amegic {LJET};",
				" RS_ME_Generator Comix {LJET};",
				" Loop_Generator LOOPGEN {LJET};",
				" Integration_Error 0.02 {4};",
				" Integration_Error 0.02 {5};",
				" Integration_Error 0.05 {6};",
				" Integration_Error 0.08 {7};",
				" Integration_Error 0.10 {8};",
				" End process;",
				"}(processes)",
				" (selector){",
				" # phase space cuts for matrix elements",
				" FastjetFinder antikt 1 5 0 0.4 0.75 5 100 1; #FastjetFinder <algorithm> <n> <ptmin> <etmin> <dr> [<f(siscone)>=0.75] [<eta-max>] [<y-max>] [<nb>] [<nb2>]",
				" #The transverse momentum of v in GeV.",
				" PT2 12 -12 200. E_CMS",
				"}(selector)"
                                                  ),
                             )
)

ProductionFilterSequence = cms.Sequence(generator)

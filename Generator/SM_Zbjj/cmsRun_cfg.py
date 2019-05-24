# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: SherpaGeneration/Generator/python/sherpa_SM_Zbjj_MASTER_cff.py --mc --step GEN,SIM --datatier GEN-SIM --eventcontent RAWSIM --conditions 93X_mc2017_realistic_v3 --beamspot Realistic25ns13TeVEarly2017Collision --geometry DB:Extended --era Run2_2017 --python_filename /lustre/cmswork/hoh/GenStudy/bfilter/CMSSW_9_3_15/src/SherpaGeneration/Generator/SM_Zbjj/cmsRun_cfg.py -n 100 --customise Configuration/GenProduction/randomizeSeeds.randomizeSeeds --no_exec
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('SIM',eras.Run2_2017)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.GeometrySimDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic25ns13TeVEarly2017Collision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

# Input source
process.source = cms.Source("EmptySource",
			    firstRun = cms.untracked.uint32(1),
                            firstLuminosityBlock = cms.untracked.uint32(1111111),
			    )

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('SherpaGeneration/Generator/python/sherpa_SM_Zbjj_MASTER_cff.py nevts:100'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    ),
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(9),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(20971520),
    fileName = cms.untracked.string('sherpa_SM_Zbjj_MASTER_cff_py_GEN_SIM.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.XMLFromDBSource.label = cms.string("Extended")
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '93X_mc2017_realistic_v3', '')

process.generator = cms.EDFilter("SherpaGeneratorFilter",
    FetchSherpack = cms.bool(False),
    SherpaDefaultWeight = cms.double(1.0),
    SherpaParameters = cms.PSet(
        MPI_Cross_Sections = cms.vstring(' MPIs in Sherpa, Model = Amisic:', 
            ' semihard xsec = 81.5347 mb,', 
            ' non-diffractive xsec = 17.0318 mb with nd factor = 0.3142.'),
        Run = cms.vstring(' (run){', 
            ' # general settings', 
            ' EVENTS 100;', 
            ' # me generator setup', 
            ' # Amegic', 
            ' ME_SIGNAL_GENERATOR Comix Amegic LOOPGEN;', 
            ' OL_PREFIX=/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/openloops/2.0.0', 
            ' EVENT_GENERATION_MODE PartiallyUnweighted;', 
            ' LOOPGEN:=OpenLoops;', 
            ' SCALES VAR{Abs2(p[0]+p[1])};', 
            ' # model setup', 
            ' MODEL SM;', 
            ' # tags for process setup', 
            ' # NJET = the maximal number of extra jets', 
            ' # LJET = the multiplicity of the MC@NLO subprocesses, exp: LJET = 2,3 means X+jj and X+jjj will be produced NLO', 
            ' # QCUT = the merging cut', 
            ' NJET:=2; LJET:=0; QCUT:=30;', 
            ' # uncomment to disable underlying event simulation:', 
            ' # MI_HANDLER None; #Or Amisic', 
            ' # uncomment to disable hadronization:', 
            ' #FRAGMENTATION Ahadic; #Or Ahadic', 
            ' # uncomment to disable shower:', 
            ' # SHOWER_GENERATOR None; #Or Dire, CSS', 
            ' # LHC beam setup:', 
            ' BEAM_1 2212; BEAM_ENERGY_1 6500;', 
            ' BEAM_2 2212; BEAM_ENERGY_2 6500;', 
            ' # LHAPDF', 
            ' PDF_LIBRARY = LHAPDFSherpa;', 
            ' PDF_SET = NNPDF30_lo_as_0130; #263000', 
            ' # the bottom quark is treated masslessly by default, a five flavour calculation is performed', 
            ' PARTICLE_CONTAINER 900 bottom 5 -5;', 
            ' PARTICLE_CONTAINER 901 lightflavs 1 -1 2 -2 3 -3 4 -4 21 5 -5;', 
            ' #NLO_CSS_DISALLOW_FLAVOUR 5;', 
            ' # 15000.0       =  bwcutoff', 
            ' # https://cp3.irmp.ucl.ac.be/projects/madgraph/wiki/FAQ-Cards-2', 
            ' # With the default HARD_MASS_SMEARING= the kinematic mass of the unstable propagator is distributed according to a Breit-Wigner shape a posteriori.', 
            ' # All matrix elements are still calculated in the narrow-width approximation with onshell particles. Only the kinematics are affected.', 
            ' # To keep all intermediate particles onshell HARD_MASS_SMEARING=0', 
            ' # Hard decay', 
            ' # particle properties (ME widths need to be zero if external)', 
            ' #HARD_DECAYS : This decay module can also be used on top of NLO matrix elements, but it does not include any NLO corrections in the decay matrix elements themselves.', 
            ' #HARD_DECAYS 1; #HARD_MASS_SMEARING 0;', 
            ' #WIDTH[23] 0;', 
            ' ## disable higgs -> neu neu', 
            '}(run)', 
            ' (processes){', 
            ' Process 901 901 -> 23[a] 900 901{NJET}', 
            ' DecayOS 23[a] -> 91 91', 
            ' #Order (*,0); #This ensures that all final state jets are produced via the strong interaction.', 
            ' CKKW sqr(QCUT/E_CMS);', 
            ' NLO_QCD_Mode MC@NLO {LJET};', 
            ' ME_Generator Amegic {LJET};', 
            ' RS_ME_Generator Comix {LJET};', 
            ' #Loop_Generator LOOPGEN {LJET};', 
            ' Integration_Error 0.02 {4};', 
            ' Integration_Error 0.02 {5};', 
            ' Integration_Error 0.05 {6};', 
            ' Integration_Error 0.08 {7};', 
            ' Integration_Error 0.10 {8};', 
            ' End process;', 
            '}(processes)', 
            ' (selector){', 
            ' # phase space cuts for matrix elements', 
            ' FastjetFinder antikt 1 5 0 0.4 0.75 5 100 1; #FastjetFinder <algorithm> <n> <ptmin> <etmin> <dr> [<f(siscone)>=0.75] [<eta-max>] [<y-max>] [<nb>] [<nb2>]', 
            ' #The transverse momentum of v in GeV.', 
            ' PT2 12 -12 200. E_CMS', 
            ' PT2 14 -14 200. E_CMS', 
            ' PT2 16 -16 200. E_CMS', 
            '}(selector)'),
        parameterSets = cms.vstring('MPI_Cross_Sections', 
            'Run')
    ),
    SherpaPath = cms.string('./'),
    SherpaPathPiece = cms.string('./'),
    SherpaProcess = cms.string('SM_Zbjj'),
    SherpaResultDir = cms.string('Result'),
    SherpackChecksum = cms.string('70ff388c8357f8b3b1477402fe94f6ec'),
    SherpackLocation = cms.string('./'),
    crossSection = cms.untracked.double(-1),
    filterEfficiency = cms.untracked.double(1.0),
    maxEventsToPrint = cms.int32(0)
)


process.ProductionFilterSequence = cms.Sequence(process.generator)

# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.simulation_step = cms.Path(process.psim)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.simulation_step,process.endjob_step,process.RAWSIMoutput_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.ProductionFilterSequence * getattr(process,path)._seq 

# customisation of the process.

# Automatic addition of the customisation function from Configuration.GenProduction.randomizeSeeds
from Configuration.GenProduction.randomizeSeeds import randomizeSeeds 

#call to customisation function randomizeSeeds imported from Configuration.GenProduction.randomizeSeeds
process = randomizeSeeds(process)

# End of customisation functions

# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion

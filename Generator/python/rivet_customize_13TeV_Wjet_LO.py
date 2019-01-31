import FWCore.ParameterSet.Config as cms

def customise(process):
        process.load('GeneratorInterface.RivetInterface.rivetAnalyzer_cfi')
	#http://rivet.hepforge.org/analyses/CMS_2017_I1610623.html
        #process.rivetAnalyzer.AnalysisNames = cms.vstring('CMS_2017_CMS_2017_I1610623')
	process.rivetAnalyzer.OutputFile = cms.string('mcfile_13TeV_Wjet_LO.yoda')
	#process.rivetAnalyzer.CrossSection = cms.double(1996)
        process.generation_step+=process.rivetAnalyzer
        return(process)


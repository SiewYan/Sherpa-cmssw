import FWCore.ParameterSet.Config as cms

SherpaWeightsBlock = cms.PSet(
    SherpaWeights = cms.vstring(
                  'Weight',
                  'MEWeight',
                  'WeightNormalisation',
                  'NTrials'
    ),
    SherpaVariationWeights = cms.vstring(
        'MUR1_MUF1_PDF306038'
        )
)

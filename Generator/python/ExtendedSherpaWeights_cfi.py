import FWCore.ParameterSet.Config as cms

SherpaWeightsBlock = cms.PSet(
    SherpaWeights = cms.vstring(
                  'Weight',
                  'MEWeight',
                  'WeightNormalisation',
                  'NTrials'
    ),
    SherpaVariationWeights = cms.vstring(
        'MUR0.5_MUF0.5_PDF292000'
        )
)

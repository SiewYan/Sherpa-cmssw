import FWCore.ParameterSet.Config as cms

SherpaWeightsBlock = cms.PSet(
    SherpaWeights = cms.vstring(
                  'Weight',
                  'MEWeight',
                  'WeightNormalisation',
                  'NTrials'
    ),
    SherpaVariationWeights = cms.vstring(
        'MUR0.25_MUF0.25_PDF292000',
        'MUR0.5_MUF0.5_PDF292000',
        'MUR1_MUF1_PDF292000',
        'MUR2_MUF2_PDF292000',
        'MUR4_MUF4_PDF292000',
        'MUR0.25_MUF0.5_PDF292000',
        'MUR0.25_MUF0.5_PDF261000',
        )
)

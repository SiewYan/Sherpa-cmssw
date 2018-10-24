import FWCore.ParameterSet.Config as cms

SherpaWeightsBlock = cms.PSet(
    SherpaWeights = cms.vstring(
        'Weight',
        'MEWeight',
        'WeightNormalisation',
        'NTrials'
        ),
    SherpaVariationWeights = cms.vstring(
        'MUR0.5_MUF0.5_PDF292200',
        'MUR0.5_MUF1_PDF292200',
        'MUR1_MUF0.5_PDF292200',
        'MUR0.5_MUF0.5_PDF306000',
        'MUR0.5_MUF1_PDF306000',
        'MUR1_MUF0.5_PDF306000',
        )
    )

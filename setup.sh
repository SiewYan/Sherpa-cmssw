#!/bin/bash

CMSSW=$1

if [[ -z $CMSSW ]];then
CMSSW="CMSSW_10_6_30_patch1"

scram project $CMSSW
mkdir -p $CMSSW/src/sherpa
mv Generator $CMSSW/src/sherpa
cd $CMSSW/src
cmsenv 
export TOPDIR=$PWD

git cms-addpkg -q GeneratorInterface/SherpaInterface
git-cms-addpkg GeneratorInterface/RivetInterface

scram b -j8

scram tool info Sherpa
scram tool info OpenLoops

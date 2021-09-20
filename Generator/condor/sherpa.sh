#!/usr/bin/env bash

card_name=$1
cmssw_version=$2
ncpu=$3

export HOME=$PWD
echo "SOURCE CMSSW"
#source cmssw_setup.sh
source /cvmfs/cms.cern.ch/cmsset_default.sh
pwd
ls
echo "CARD_NAME=${card_name}"
echo "CMSSW_VERSION=${cmssw_version}"
echo "NCPU=${ncpu}"
echo "SCRAM_ARCH=${SCRAM_ARCH}"
echo "CMSSW_VERSION=${cmssw_version}"
export $SCRAM_ARCH
export $cmssw_version

echo "CMSREL"
scram -a $SCRAM_ARCH project ${cmssw_version}
scram project ${cmssw_version}
cd ${cmssw_version}/src

echo "CMSENV"
eval `scramv1 runtime -sh`
export TOPDIR=$PWD

shr=`scramv1 tool info sherpa | grep "SHERPA_BASE" | cut -f2 -d"="`
draw=`find $shr -type f -name plot_graphs.sh`

echo "CMS-ADDPKG"
git config --list --show-origin
git cms-addpkg GeneratorInterface/SherpaInterface
mkdir -p workdir/${card_name}/test
mkdir -p workdir/${card_name}/python
cd workdir/${card_name}/test
echo "IN WORKDIR"
cp $TOPDIR/GeneratorInterface/SherpaInterface/data/*SherpaLibs.sh .
chmod +x *sh
#cp /home/mlizzo/Sherpa/Cards/Run.dat_${card_name} .
cp ${HOME}/Run.dat_${card_name} .
ls -trlh

echo "RUNNING"
# Possible issue when running with verbose option (-v), not understood
./MakeSherpaLibs.sh -p ${card_name} -o LBCR -v -m mpirun -M "-n ${ncpu}"

echo "FINISHED RUNNING"
ls -trlh
mv sherpa_*.tgz $HOME

echo "TOP LEVEL DIRECTORY"
cd $HOME
ls -trlh
echo "DONE"

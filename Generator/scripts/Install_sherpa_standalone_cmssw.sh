#!/bin/bash

set -e

GIT=0

LOCAL=$PWD

if [ -z "${CMSSW_BASE}" ];then
    echo "Please cmsenv"
    exit 0
fi

if [[ `echo $LOCAL | awk -F "/" '{print $NF}'` != "Generator" ]];then
    echo "Please run the script on directory : $CMSSW_BASE/src/Sherpa-cmssw/Generator"
    exit 0
fi


####
if [[ "$1" == "build" ]];then
    
    # Install OpenLoops
    if [ ! -e "$LOCAL/OpenLoops-2.1.0"  ];then
	git clone -b OpenLoops-2.1.0 https://gitlab.com/openloops/OpenLoops.git OpenLoops-2.1.0
	cd OpenLoops-2.1.0
	git checkout -b OpenLoops-2.1.0
	./scons -j 10
	./openloops libinstall pphhjj2
	cd $LOCAL
    fi
    
    # Sherpa 
    if [ ! -e "$LOCAL/sherpa-2.2.8"  ];then
	if [ $GIT == 1 ];then
	    git clone -b rel-2-2-8 https://gitlab.com/sherpa-team/sherpa.git $LOCAL/sherpa-2.2.8
	else
	    wget https://sherpa.hepforge.org/downloads/SHERPA-MC-2.2.8.tar.gz
	    tar zxf SHERPA-MC-2.2.8.tar.gz && mv SHERPA-MC-2.2.8 sherpa-2.2.8 
	    rm SHERPA-MC-2.2.8.tar.gz
	fi
    fi
    
    cd sherpa-2.2.8

    if [ ! -e "$LOCAL/sherpa"  ];then
	./configure \
	    --prefix=${CMSSW_BASE}/src/Sherpa-cmssw/Generator/sherpa \
	    --enable-analysis --disable-silent-rules \
	    --enable-root=`root-config --prefix` \
	    --enable-fastjet=`scram tool info fastjet | grep 'BASE' | awk -F "=" '{print $2}'` \
	    --enable-hepmc2=`scram tool info hepmc | grep 'BASE' | awk -F "=" '{print $2}'` \
	    --enable-rivet=`scram tool info Rivet | grep 'BASE' | awk -F "=" '{print $2}'` \
	    --enable-lhapdf=`scram tool info lhapdf | grep 'BASE' | awk -F "=" '{print $2}'` \
	    --enable-blackhat=`scram tool info blackhat | grep 'BASE' | awk -F "=" '{print $2}'` \
	    --enable-openloops=${CMSSW_BASE}/src/Sherpa-cmssw/Generator/OpenLoops-2.1.0 \
	    --enable-ufo \
	    --enable-mpi \
	    --enable-shared \
	    --enable-lhole \
	    --enable-pythia \
	    --with-sqlite3=`scram tool info sqlite | grep 'BASE' | awk -F "=" '{print $2}'`
	
	make -j 15
	make install
    fi

elif [[ "$1" == "source" ]];then

    #set environment
    export SHERPA_BASE=${CMSSW_BASE}/src/Sherpa-cmssw/Generator/sherpa
    export PATH=${PATH}:${SHERPA_BASE}/bin
    export SHERPA_SHARE_PATH=${SHERPA_BASE}/share/SHERPA-MC
    export SHERPA_LIBRARY_PATH=${SHERPA_BASE}/lib/SHERPA-MC
    export SHERPA_INCLUDE_PATH=${SHERPA_BASE}/include/SHERPA-MC
    export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${SHERPA_BASE}/lib/SHERPA-MC

    export OPENLOOPS_BASE=${CMSSW_BASE}/src/Sherpa-cmssw/Generator/OpenLoops-2.1.0
    export LIBDIR=${OPENLOOPS_BASE}/OpenLoops-2.1.0/lib
    export CMS_OPENLOOPS_PREFIX=${OPENLOOPS_BASE}/OpenLoops-2.1.0
    echo "sherpa and openloops env set"
else
    echo "please do build or source."
    echo "examples: source Sherpa_standalone_cmssw.sh build/source"
fi

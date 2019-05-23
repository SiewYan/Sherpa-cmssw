#!/bin/bash

wget https://sherpa.hepforge.org/downloads/?f=SHERPA-MC-2.2.6.tar.gz

mv index.html?f=SHERPA-MC-2.2.6.tar.gz  SHERPA-MC-2.2.6.tar.gz

tar zxvf SHERPA-MC-2.2.6.tar.gz

rm SHERPA-MC-2.2.6.tar.gz

echo "Remember to remove manual folder and manual in Makefile"


#echo "
#Libraries have been installed in:
#   /lustre/cmswork/hoh/GenStudy/CMSSW_9_3_13/src/SherpaGeneration/Generator/sherpant/lib

#If you ever happen to want to link against installed libraries
#in a given directory, LIBDIR, you must either use libtool, and
#specify the full pathname of the library, or use the `-LLIBDIR'
#flag during linking and do at least one of the following:
#   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
#     during execution
#   - add LIBDIR to the `LD_RUN_PATH' environment variable
#     during linking
#   - use the `-Wl,-rpath -Wl,LIBDIR' linker flag
#   - have your system administrator add LIBDIR to `/etc/ld.so.conf'
#See any operating system documentation about shared libraries for
#more information, such as the ld(1) and ld.so(8) manual pages.
#"
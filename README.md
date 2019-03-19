# Sherpa-Generation

## Setup on lxplus

   Setup CMSSW environment
   ``` 
   CMSSW_9_3_13: sherpa 2.2.5; openloops 2.0.b; blackhat 0.9.9-mlhled2
   ```

   ```
   scram project CMSSW_9_3_13
   cd CMSSW_9_3_13/src
   cmsenv	 
   export TOPDIR=$PWD
   ```

   checkout the SherpaInterface: 

   ```
   git cms-addpkg -q GeneratorInterface/SherpaInterface
   ```
   
   Clone the repository SherpaGeneration:

   ```
   git clone https://github.com/SiewYan/SherpaGeneration.git -b EXO-2.2.5
   cp $TOPDIR/GeneratorInterface/SherpaInterface/data/*SherpaLibs.sh $TOPDIR/SherpaGeneration/Generator/test/
   scram b -j8
   ```
   
   The version of Sherpa Interfaced with the cmssw can be revealed

   ```
   scram tool info Sherpa
   ```
   
## Build standalone Sherpa

   To enable Sherpa-generate-model functionality, you need to build external sherpa with packages as close as possible to cmssw's Sherpa.
   
   ```
   cd $TOPDIR/SherpaGeneration/Generator/
   mkdir sherpant
   ./fetchSherpa.sh
   mv buildSherpant.sh SHERPA-MC-2.2.5
   cd $TOPDIR/SherpaGeneration/Generator/SHERPA-MC-2.2.5
   ./buildSherpant.sh
   ```
   
   Once the Makefile is produced, please edit Makefile (search for Manual) and remove it to avoid being built (buggy)
   Later, do
   
   ```
   make install -j4
   ```

   to install (take some time). Once its done, source the path of Sherpa's bin
   
   ```
   cd $TOPDIR/SherpaGeneration/Generator/
   source sherpant.sh
   cd $TOPDIR
   scram b -j4
   ```
   
## Generate UFO Model's library

   There is a copy of the model in ```data/models```:
   
   ```
   cd $TOPDIR/SherpaGeneration/Generator/data/models
   Sherpa-generate-model HAHM_variableMW_UFO
   ```
   
   At the end it will output a model runcard example, there is a modified runcard at ```test``` folder,
   
## Generate Sherpack
   Run the following command to generate sherpack:
   
   ```
   cd $TOPDIR/SherpaGeneration/Generator/test/
   ./run_MakeSherpaLibs.sh HAHM_variableMW_UFO_Zpmumu_m40_LO_13TeV
   ```
   
## Generate EDM event

   After the sherpack made successfully, produce the python fragment by runnin command

   ```
   ./run_PrepareSherpaLibs.sh HAHM_variableMW_UFO_Zpmumu_m40_LO_13TeV
   scp sherpa_HAHM_variableMW_UFO_Zpmumu_m40_LO_13TeV_MASTER_cff.py ../python
   cd $TOPDIR/SherpaGeneration/Generator/
   scram b 
   cd $TOPDIR/SherpaGeneration/Generator/test
   ./cmsCreate.sh sherpa_HAHM_variableMW_UFO_Zpmumu_m40_LO_13TeV_MASTER_cff.py
   cmsRun sherpa_HAHM_variableMW_UFO_Zpmumu_m40_LO_13TeV_MASTER_cff_py_GEN.py
   ```
   
   Note: running this step at lxplus will return error of fastjet packages is not permitted to be accessed (AFS phaseout).
   Workaround will be running it in institutional server.

#!/bin/bash

set -e

# path to submit jobs                                                                                                                                                                  
WORKDIR=`pwd -P`

OTAG=$1

BATCH=LSF
NJOBS=100
WORKDIR=`pwd -P`
ODIR=${WORKDIR}/samples
NEVTS=5000

if [ $# -eq 0 ];then
    echo "generateValidation: No arguments supplied, please parse the process name [PROCNAME]: [PROCNAME]_MASTER_cff.py"
    exit 0
fi

ODIR=${WORKDIR}/samples/${OTAG}/

mkdir -p ${ODIR}

sed -e "s,XXX,${WORKDIR}/," ${OTAG}_MASTER_cff.py > ${OTAG}_MASTER_cff.py_ ; mv ${OTAG}_MASTER_cff.py_ ${OTAG}_MASTER_cff.py

scp ${OTAG}_MASTER_cff.py ../python
eval cd ../python; scram b
eval cd ../test

cmsDriver.py SherpaGeneration/Generator/python/${OTAG}_MASTER_cff.py \
    -n ${NEVTS} --mc --no_exec --python_filename cmsrun_${OTAG}_MASTER_cff.py \
    -s GEN,VALIDATION:genvalid_all --datatier GEN-SIM,DQMIO --eventcontent RAWSIM,DQM \
    --conditions auto:run2_mc_FULL --beamspot Realistic8TeVCollision

echo "cmsrun_${OTAG}_MASTER_cff.py is generated."

#generate submission script
cat > subscript_${OTAG}.sh <<EOF
#!/bin/bash                                                                                                                                                                  
pushd ${CMSSW_BASE}/src/                                                                                                                                                     
eval \`scram runtime -sh\`                                                                                                                                                   
popd                                                                                                                                                                         
if [ ! -z ${TMPDIR} ] ; then                                                                                                                                                 
cd ${TMPDIR}                                                                                                                                                                 
fi                                                                                                                                                                           
mkdir -p tmp_\${OTAG}_\${OFFSET}                                                                                                                                             
cd tmp_\${OTAG}_\${OFFSET}                                                                                                                                                   
echo "execute job in path $PWD"                                                                             
cp ${WORKDIR}/cmsrun_\${OTAG}_MASTER_cff.py .
### adjust random numbers                                                                                                                                                    
LINE=\`egrep -n Configuration.StandardSequences.Services_cff cmsrun_\${OTAG}_MASTER_cff.py | cut -d: -f1 \`                                
SEED=\`echo "5267+\${OFFSET}" | bc\`                                                                                                                                         
sed -i "\${LINE}"aprocess.RandomNumberGeneratorService.generator.initialSeed=\${SEED} cmsrun_\${OTAG}_MASTER_cff.py      
### run config                                                                                                                                                               
cmsRun cmsrun_\${OTAG}_MASTER_cff.py || exit $? ;                                                          
### copy output                                                                                                                                                              
if [ $? -eq 0 ]; then                                                                                                                                                        
cp *_inDQM.root \${ODIR}/\${OTAG}_\${OFFSET}.root                                                                                                                            
else                                                                                                                                                                         
echo "Generation problems please check log file carefully!"                                                                                                                  
fi 
cd ../                                                                                                                                                                       
rm -rf tmp_\${OTAG}_\${OFFSET}                                                             
EOF

# adjust rights                                                                                                                                                   
chmod 755 subscript_${OTAG}.sh

### submit jobs                                                                                                                                                          
IJOBS=1
while [ "${IJOBS}" -le "${NJOBS}" ]; do
    if [ ! -s ${ODIR}/${OTAG}_${IJOBS}.root ] ; then
    # submit to sge system                                                                                                                                               
        if [ "${BATCH}" == "SGE" ] ; then
            qsub -N ${OTAG}_${IJOBS} -V -v OFFSET=${IJOBS} -v OTAG=${OTAG} -v ODIR=${ODIR} -j y -m as -o ${ODIR}/${OTAG}_${IJOBS}.out -S /bin/bash -l h_rt=12:00:00,h_vmem=6G,distro=sld6 subscript_${OTAG}.sh
    # submit to lsf system
        elif [ "${BATCH}" == "LSF" ] ; then
        #suppress lsf emails                                                                                                                                             
            export LSB_JOB_REPORT_MAIL="N"
            bsub -o ${ODIR}/${OTAG}_${IJOBS}.out  -q 1nd -C 0  -R "rusage[mem=6000:pool=10000]" -env "all , OFFSET=${IJOBS} , OTAG=${OTAG} , ODIR=${ODIR}" subscript_${OTAG}.sh
    # unknown batch mode                                                                                                                                                 
        else
            echo "Unknown batch system!"
            exit 0
        fi
    fi
    IJOBS=$(($IJOBS+1))
done # end of job loop

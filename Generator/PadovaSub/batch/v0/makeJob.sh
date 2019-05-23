#!/bin/sh

if [ "$2" == "no" ];then
    weightsFrag="no"
else
    weightsFrag=`echo $2 | awk -F "_" '{print $1}'`
fi

cp -rf SHERPAtmpl.job sherpa_$1_${weightsFrag}.job
rm -rf temp

#chaging some environmental variable
DIR=`pwd -P`
sed  s#INPUT01#${CMSSW_BASE}#g sherpa_$1_${weightsFrag}.job > temp
mv temp sherpa_$1_${weightsFrag}.job

sed  s#INPUT02#${DIR}#g sherpa_$1_${weightsFrag}.job > temp
mv temp sherpa_$1_${weightsFrag}.job
 
#$1
sed s/INPUT1/$1/g sherpa_$1_${weightsFrag}.job > temp
mv temp sherpa_$1_${weightsFrag}.job
#$2
if [ "$2" == "no" ];then
    sed s/INPUT2/""/g sherpa_$1_${weightsFrag}.job > temp
    mv temp sherpa_$1_${weightsFrag}.job
else
    sed s/INPUT2/$2/g sherpa_$1_${weightsFrag}.job > temp
    mv temp sherpa_$1_${weightsFrag}.job
fi

#$3
sed s/XX_NEVENT_XX/$3/g sherpa_$1_${weightsFrag}.job > temp
mv temp sherpa_$1_${weightsFrag}.job

##
chmod a+x sherpa_$1_${weightsFrag}.job

## Send job
bsub -R "rusage[mem=4000]" -q $4 -o Log_$1_${weightsFrag} sherpa_$1_${weightsFrag}.job

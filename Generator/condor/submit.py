from sys import argv
from os import system,getenv,getuid,getcwd,environ,path,system

logpath=getcwd()+'/logs/'
if not path.exists( path.join( getcwd() , logpath ) ): system( 'mkdir %s' %logpath )
workpath=getcwd()+'/'+str(argv[1])
home=environ['HOME']

njobs = argv[2]

#espresso     = 20 minutes
#microcentury = 1 hour
#longlunch    = 2 hours
#workday      = 8 hours
#tomorrow     = 1 day
#testmatch    = 3 days
#nextweek     = 1 week

#queue="nextweek"
queue="longlunch"

classad='''
universe                = vanilla
should_transfer_files   = YES
when_to_transfer_output = ON_EXIT
executable              = {0}/exec.sh 
arguments               = $(Process)      
transfer_input_files    = {0}/submit.tgz
transfer_output_files   = ""
input                   = /dev/null
rank                    = Mips
RequestMemory           = 3000
request_cpus            = 3
+JobFlavour             = {3}
use_x509userproxy       = True
x509userproxy           = {0}/x509up
on_exit_hold            = (ExitBySignal == True) || (ExitCode != 0)
output                  = {1}/job_$(Cluster)-$(Process).out
error                   = {1}/job_$(Cluster)-$(Process).err
log                     = {1}/job_$(Cluster)-$(Process).log
queue {2}
'''.format( workpath , logpath , njobs , queue )

with open(logpath+'/condor.jdl','w') as jdlfile:
  jdlfile.write(classad)

system('condor_submit %s/condor.jdl'%logpath)

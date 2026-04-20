#!/bin/bash -l
  
# setting name of job
#SBATCH -J gdstem-run-S1-region-1

# setting standard error output
#SBATCH -e slurm/slurm_out_%j

# setting standard output
#SBATCH -o slurm/slurm_out_%j

# setting medium priority
#SBATCH -p med2

# Request ! CPUs and 128 GB of RAM from 1 node:
##SBATCH --nodes=1
#SBATCH --mem=2G
##SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

# setting the max time
#SBATCH -t 72:00:00

# mail alerts at beginning and end of job
##SBATCH --mail-type=FAIL
#SBATCH --mail-type=FAIL

# send mail here
#SBATCH --mail-user=emonier@ucdavis.edu

RUNNER="/home/emonier/gdstem/gdstem-source-code/xtem_gds_gofile_g++"
chunk=1

srun bash -c $RUNNER < xml-inputs/xml-file$chunk.txt

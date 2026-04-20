#!/bin/bash -l
  
# setting name of job
#SBATCH -J  gdstem-run-debug

# setting up the account
#SBATCH --account=moniergrp

# setting standard error output
#SBATCH -e slurm/sterror_%j.txt

# setting standard output
#SBATCH -o slurm/stdoutput_%j.txt

# setting medium priority
#SBATCH -p high

# Request ! CPUs and 128 GB of RAM from 1 node:
##SBATCH --nodes=1
#SBATCH --mem=6G
##SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

# setting the max time
#SBATCH -t 12:00:00

# mail alerts at beginning and end of job
##SBATCH --mail-type=FAIL
##SBATCH --mail-type=FAIL

# send mail here
#SBATCH --mail-user=emonier@ucdavis.edu

RUNNER="/group/moniergrp/emonier/gdstem/gdstem-source-code-TRENDY/xtem_gds_gofile_g++"
ARG=xml-file.txt
srun bash -c "\"$RUNNER\" < $ARG"

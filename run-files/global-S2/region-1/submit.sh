#!/bin/bash
#SBATCH --partition=DO_NOT_SUBMIT_WITH_SBATCH_USE_BASH_INSTEAD

RUNNER="/group/moniergrp/emonier/gdstem/gdstem-source-code/xtem_gds_gofile_g++"
ARGFILE="arguments.txt"

# enforce no blank lines
nlines_nonblank=$(grep -c . "$ARGFILE")
nlines=$(wc -l < "$ARGFILE")
if (( nlines_nonblank != nlines )); then
  echo "error: you have blank lines in $ARGFILE"
  echo "hint: fix this via: \"sed -i '\''/^$/d'\'' $ARGFILE\""
  exit 1
fi
[[ -f $ARGFILE ]] || { echo "error: missing arguments file: $ARGFILE"; exit 1; }

export _JOB_ARRAY_INDEX="$ARGFILE"
export _JOB_ARRAY_COMMAND="$RUNNER"
export _JOB_ARRAY_NLINES="$nlines"

# two namelists per array element
nelems=$(( (nlines + 1) / 2 ))

# Optional partition wiring:
PARTITION=${PARTITION:-high}
sbatch --partition="$PARTITION" --array=1-"$nelems" sol-ex.sh


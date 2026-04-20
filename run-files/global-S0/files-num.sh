#!/bin/bash

total_files=0

for i in {1..48}; do
  count=$(find "region-$i/var-out/" -type f | wc -l)
  total_files=$((total_files + count))

  if [ $count -ne 500 ]; then
    echo "Region $i has $count files."
  fi
done

echo "Total number of files in all var_out_new directories: $total_files"

#!/bin/bash

i=48
mkdir -p region-$i/{slurm,restart,clm-out,var-out,xml-files,xml-inputs}
cp region-1/*.sh region-$i/
cp region-1/sol-ex.sh.nomultithread region-$i/sol-ex.sh
cp region-1/parallel-template.xml region-$i/

sed -i "s/region-1/region-$i/g" region-$i/parallel-template.xml
sed -i "s/region-1/region-$i/g" region-$i/*.sh

for i in {2..47}; do

    mkdir -p region-$i/{slurm,restart,clm-out,var-out,xml-files,xml-inputs}

    cp region-1/*.sh region-$i/
    cp region-1/sol-ex.sh.multithread region-$i/sol-ex.sh
    cp region-1/parallel-template.xml region-$i/
    
    
    sed -i "s/region-1/region-$i/g" region-$i/parallel-template.xml
    sed -i "s/region-1/region-$i/g" region-$i/*.sh

done

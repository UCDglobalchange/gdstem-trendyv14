#!/bin/bash

i=48
echo region-$i
cd region-$i
bash split-xml.sh
bash submit.sh
cd ..
sleep 5

for i in {2..47}; do
echo region-$i
cd region-$i
bash split-xml.sh 
bash submit.sh 
cd ..
sleep 5
done

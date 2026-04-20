cd region_1
edit the parallel_template.xml as needed
bash split_xml.sh
if you want to run without multithread (you should for region 1 and 48)
cp sol-ex.sh.nomultithread sol-ex.sh
if you want to run with multithread (if you need to run multiple simulation, multithread can allow you to use less cpus for simulation, which is advantageous)
cp sol-ex.sh.multithread sol-ex.sh
bash submit.sh
check for some output to make sure it is working properly
cd ../
bash copy_run_files.sh
bash run_regions.sh (currently regions other 48 use multithread, and 48 does not use multithread)
to check that everything is set up and properly submitted run:
bash files_num.sh

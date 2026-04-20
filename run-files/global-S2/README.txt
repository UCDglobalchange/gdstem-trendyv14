cd region_1
edit the parallel_template.xml as needed
bash split_xml.sh
bash submit.sh
check for some output to make sure it is working properly
cd ../
bash copy_run_files.sh
bash run_regions.sh
to check that everything is set up and properly submitted run:
bash files_num.sh

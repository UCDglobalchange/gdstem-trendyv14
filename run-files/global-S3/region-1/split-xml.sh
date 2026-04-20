#!/bin/bash

###this program makes the input xml files from the parallel version of TEM
###based on a parallel template xml file
###that will be submitted as a slurm array job
# Assign the number of lines in the file to the variable 'total_rows
total_rows=$(wc -l /group/moniergrp/TRENDY/input-files/region-input/S3/region-1/cruigbpstxtlf.glb | awk '{print $1}')
echo $total_rows
numjobs=$(wc -l /group/moniergrp/TRENDY/input-files/region-input/S3/region-1/INITGRID-GRIDSIZE.txt | awk '{print $1}')
echo $numjobs

template="parallel-template.xml" #name and location of the template parallel file
array_arguments="arguments.txt" #name of the text file with all the array job arguments
xml_file_path="xml-files/" #location of the xml input files for tem
xml_tem_input_path="xml-inputs/" #location of the text files that have the xml file path
file_prefix="xml-file" #prefix of the text file that has the xml file name
rm -f $array_arguments
touch $array_arguments

for ((i=1;i<=$numjobs;i++))
do
	initgrid=$(awk -F',' 'NR == '$i' {print $1}' /group/moniergrp/TRENDY/input-files/region-input/S3/region-1/INITGRID-GRIDSIZE.txt) 
	echo $initgrid
	gridsize=$(awk -F',' 'NR == '$i' {print $2}' /group/moniergrp/TRENDY/input-files/region-input/S3/region-1/INITGRID-GRIDSIZE.txt)
	echo $gridsize
        infile="$xml_file_path$(echo $template | sed 's/template/'$initgrid'/g')"
        sed -e 's/GRIDSIZE/'$gridsize'/g' -e 's/INITGRID/'$initgrid'/g' ${template} > "${infile}"
        new_filename="$xml_tem_input_path$file_prefix${i}.txt"
        touch $new_filename
        echo $new_filename
	echo "$infile" > $new_filename
	echo "$new_filename" >> "$array_arguments"
    
    initgrid=$[$initgrid + $gridsize]

done


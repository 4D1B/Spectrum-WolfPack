#!/bin/bash
export LC_ALL='C'

#Cut and sort the unique entities using ',' delimiter and select the first field.

cut -d ',' -f1 data28.csv | sort -u > data28CS.txt


#Remove ' " ' character from extracted values

tr -d '"' < data28CS.txt > data28CSresult.txt


#Removing leading 0's

sed 's/^0*//' data28CSresult.txt > FinOutput.txt


#Removing unnessecery files

rm data28CS.txt data28CSresult.txt


echo "Success!!!!"


#Auto start final output file

start FinOutput.txt


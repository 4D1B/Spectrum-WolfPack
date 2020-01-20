# `` Finding Unique Entities in given Dataset. ``

## `` Introduction ``

- Our purpose is to extract unique policy numbers from the given dataset and show them in a new output file.

## `` Given Dataset ``

- data__2019-11-28.csv
- data__2019-11-29.csv

## `` Tools Used ``

- Git Bash

## `` Processes Followed ``

-  Cut the text into fields using ',' as the delimiter and selects only the first field: 

        cut -d ',' -f1 

- Sorts the results, selects the uniques and writes to out.file: 

        sort -u > out.file

- We used both commands as combined is the SCRIPT:

        cut -d ',' -f1 data28.csv | sort -u > data28CS.txt

- This is the quicker process used, which can remove given characters:

        tr -d '"' < data28CS.txt > data28CSresult.txt 

    We used this to **Remove** `` ` " ` `` from the starting and ending of the extracted policy numbers.

- Using sed command, to remove leading **0's**:

        sed 's/^0*//' data28CSresult.txt > FinOutput.txt

    The expression `` '^0*' `` will search for a sequence of 0's in the beginning and delete them.

- Removed unnesserry files:

        rm data28CS.txt data28CSresult.txt 

- To auto start the **.sh** file:

        start FinOutput.txt

---

### ``git cmd : GIT BASH ``
Create .sh file using **nano**
            
        nano assign1Bash.sh  

To execute the **.sh** file    

        ./assign1Bash.sh
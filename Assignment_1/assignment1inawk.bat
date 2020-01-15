echo on
 
 awk -F , "NR>1 {a[$1\" \"$7]++} END{for(b in a){arr[i+1]=b; i++} count=i;maleCount=0;femaleCount=0; for(j=0;j<count;j++){if(index(arr[j],\"MALE\")){maleCount++; } if(index(arr[j],\"FEMALE\")){femaleCount++; }}print femaleCount \" is the total female count and total male count is \" maleCount-femaleCount;}" h:/ad.csv
 
 cmd /k
 

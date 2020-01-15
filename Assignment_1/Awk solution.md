# Finding unique value from a given dataset using awk on command prompt


Here, We are using awk in windows command prompt to write the command which will give the output. The process is shared below, 
- At first, We are using awk command and along with that, we are using command for comma separating value.
	
	`` awk -F ,``

- After that, we are taking first column and seventh column value which are unique Policy Number and gender consecutively in an array.
	
	``	NR>1 {a[$1\" \"$7]++}; ``

- Finally, we are reading the unique data that are coming into that array using for loop.
	
	 ``	END{for(b in a){arr[i+1]=b; i++} ``

- After that we are going through that array and finding MALE string through index checking. Having matched, a variable value increases. 
	
	``	count=i;maleCount=0;femaleCount=0; for(j=0;j<count;j++){if(index(arr[j],\"MALE\")){maleCount++; } ``

- After that, we are checking female index and putting sum in a variable.
	
	`` if(index(arr[j],\"FEMALE\")){femaleCount++; } ``

- Finally, we are eliminating total female count from male because both male counted variable contained female string too. Thus, we are getting only male count and printing it.
	
	`` print femaleCount \" \" maleCount-femaleCount; ``
	
Here is the command we executed in command line where h:/ad.csv is the file location.
	
	`` awk -F , "NR>1 {a[$1\" \"$7]++} END{for(b in a){arr[i+1]=b; i++} count=i;maleCount=0;femaleCount=0; for(j=0;j<count;j++){if(index(arr[j],\"MALE\")){maleCount++; } if(index(arr[j],\"FEMALE\")){femaleCount++; }}print femaleCount \" \" maleCount-femaleCount;}" h:/ad.csv ``
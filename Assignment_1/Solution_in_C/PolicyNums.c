#include <stdio.h>
#include <time.h>
#include <stdbool.h>

FILE *fptr1, *fptr2, *fptr3;

// you  need to pass a char array with end character
int stringLength (char line[])
{
    int length = 0;
    while (line[length] != '\0')
        length++;
    return length;
}

char* trimQuote(char val[], char oVal[])
{
    int len = stringLength(val);
    int vIndx = 0, oIndx = 0;
    for(;vIndx<len; vIndx++)
    {
        if(val[vIndx] != '"')
        {
            oVal[oIndx] = val[vIndx];
            oIndx++;
        }
    }
    oVal[oIndx] = '\0';
    return oVal;
}

char* splitCsv (char line[], int length, char c, int index, char subString[])
{
    int cArr[29], cArrIndex = 0;
    for(int i = 0; i < 30; i++)
        cArr[i] = -1;

    // find the index of char c and store it in cArr.
    // we can use the cArrIndex to find the total split number.
    
    for(int i=0; i<length; i++)
    {
        if(line[i] == c)
        {
            cArr[cArrIndex] = i;
            cArrIndex++;
        }
    }

    if(index > cArrIndex  || index < 0)
        return '\0';
    else if(index == 0)
    {
        // zero index
        int i = 0;
        for(; i < cArr[0]; i++)
            subString[i] = line[i];
        subString[i] = '\0';
        return subString;
    }else if(index == cArrIndex)
    {
        // last index
        int subStringLength = stringLength(line) - cArr[cArrIndex - 1];
        int lIndex = cArr[cArrIndex - 1] + 1;
        int i = 0;
        for(; i < subStringLength; i++, lIndex++)
            subString[i] = line[lIndex];
        subString[i] = '\0';
        return subString;
    }else
    {
        // middle indexes
        int subStringLength =  cArr[index] - cArr[index - 1] - 1;
        int lIndex = cArr[index - 1] + 1;
        int i = 0;
        for(; i < subStringLength; i++, lIndex++)
            subString[i] = line[lIndex];
        subString[i] = '\0';
        return subString;
    }
}

long long getVal(long long indx)
{
    long long val = 0, line = 0;
    FILE *ptr;
    ptr = fopen("data_28_sorted.txt", "r");
    while (fscanf(ptr, "%llu", &val) != EOF)
    {
        if(line == indx)
            return val;
        else
            line++;
    }
    return val;
}

bool stringEqual(char first[], char second[])
{
    int lenf = stringLength(first), lenS = stringLength(second);
    if(lenf != lenS)
        return false;
    else
    {
        for(int i = 0; i<lenf; i++)
        {
            if(first[i] != second[i])
                return false;
        }
        return true;
    }
}


int main ()
{
    //char line[1000];
    
    // Getting row numbers
    //start - file1
    // int rowNum = 0;
    // FILE *fptr;
    // fptr = fopen("data__2019-11-28.csv", "r");
    // if(fptr == NULL)
    //     return 1;

    // // count rows
    // clock_t before = clock();
    // fscanf(fptr, "\n%[^\n]", line);
    // while (fscanf(fptr, "\n%[^\n]", line) != EOF)
    // {
    //     rowNum++;
    // }
    // clock_t totalTime = clock() - before;
    // fclose(fptr);
    // printf("Row number: %d\n", rowNum);
    // printf("Total time taken: %d ms\n", ((totalTime * 1000)/CLOCKS_PER_SEC));
    //end - file1

    // fptr1 = fopen("data__2019-11-28.csv", "r");
    // fptr2 = fopen("data__2019-11-28_policy_nums.txt", "w");
    // fscanf(fptr1, "\n%[^\n]", line);
    // //fscanf(fptr1, "\n%[^\n]", line);
    // char policyNums[15];
    // //splitCsv(line, stringLength(line), ',', 0, policyNums);

    // //printf("%s\n", policyNums);

    // char policyNumsWQ[15];
    // //trimQuote(policyNums, policyNumsWQ);
    // //printf("Without quote: %s\n", policyNumsWQ);
    // while (fscanf(fptr1, "\n%[^\n]", line) != EOF)
    // {
    //     splitCsv(line, stringLength(line), ',', 0, policyNums);
    //     trimQuote(policyNums, policyNumsWQ);
    //     fprintf(fptr2, "%s\n", policyNumsWQ);
    // } 

    // making array of policy nums
    // long long policyArr[423400];
    long long val, indx = 0;
    fptr1 = fopen("data_28_sorted.txt", "r");
    long long rightIndx = 423396, midIndx, leftIndx = 0;
    //printf("Getting val %llu", getVal(0));
    while (fscanf(fptr1, "%llu\n", &val) != EOF)
    {
        clock_t before = clock();
        midIndx = ((leftIndx + rightIndx) / 2);
        //printf("%llu", midIndx);
        
        
        while(1)
        {
            long long comVal = getVal(midIndx);
            if(comVal == val)
            {
                // comVal = getVal(midIndx - 1);
                // if( comVal != val)
                // {
                //     comVal = getVal(midIndx + 1);
                //     if(comVal != val)
                //         indx++;
                // }
                indx++;
                break;
            }else if(comVal < midIndx)
            {
                rightIndx = midIndx;
            }else
            {
                leftIndx = midIndx + 1;
            }
        }
        
        
        
        clock_t time = clock() - before;
        printf("Unique num: %llu\n", indx);
        printf("time taken: %d ms\n", ((time * 1000)/ CLOCKS_PER_SEC));
    }

    
    printf("Unique number: %llu\n", indx);
    fclose(fptr1);
    

    return 0;
}
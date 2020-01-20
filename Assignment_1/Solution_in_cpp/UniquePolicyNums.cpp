#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

string split(string line, char delimiter, int index)
{
    size_t pos = 0;
    string token = "";
    int i = 0;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        if(index == i)
            break;
        line.erase(0, pos + 1);
        i++;
    }
    token = token.substr(token.find('"') + 1, token.find_last_of('"') - 1);
    return token;
}

int main()
{
    ifstream fptr("data__2019-11-28.csv");
    string policyNum, line;
    getline(fptr, line);
    vector<string> policyNums;
    
    while (getline(fptr, line))
    {
        policyNum = split(line, ',', 0);
        policyNums.push_back(policyNum);        
    }
    vector<string>::iterator endIndex;    
    endIndex = unique(policyNums.begin(), policyNums.end());
    policyNums.resize(distance(policyNums.begin(), endIndex));
    cout<< "Unique policy numbers: "<< policyNums.size()<<endl;

    return 0;    
}

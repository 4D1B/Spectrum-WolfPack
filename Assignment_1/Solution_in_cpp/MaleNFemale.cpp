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
    string gender, line;
    getline(fptr, line);
    int male = 0, female = 0, others = 0;
    
    while (getline(fptr, line))
    {
        gender = split(line, ',', 6);
        if(gender == "MALE")
            male++;
        else if(gender == "FEMALE")
            female++;
        else
            others++;
    }

    cout << "Total male: "<< male << endl;
    cout << "Total female: "<< female << endl;
    cout << "Others: "<< others << endl;
    //cout << male + female << endl;
    return 0;    
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
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
    string dob, line;
    getline(fptr, line);
    int dyear, count = 0;

    // getting current year
    time_t now = time(0);
    tm *current = localtime(&now);
    int year = 1900 + current->tm_year;

    //cout << "age: " << year - dyear << endl;
    while (getline(fptr, line))
    {
        dob = split(line, ',', 9); 
        // we are doing try catch bacause there are some invalid data in dob column.
        try
        {
            dyear = stoi(split(dob, '-', 0));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " Invalid input " << dob <<'\n';
            continue;
        }
        
        if((year - dyear) > 50)
            count++;
    }

    cout << "Age more than 50: " << count << endl;
    
    return 0;    
}

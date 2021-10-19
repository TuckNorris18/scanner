#include<iostream>
#include<fstream>
#include <string>
#include <vector>

using namespace std;
bool isString(char c);
bool isSpace(char c);
bool isPeriod(char c);

void getTokens(vector<string> &arr) 
{
    ifstream in("Text.txt");
    char c;
    string str = "";
    
    //error reading file
    if (!in.eof() && in.fail())
    {
        cout << "error reading " << endl;
    }

    

    if(in.is_open()) {
        while (in.get(c)) 
        {
            cout << c << '\n';
            if (isString(c))
            {
                string s(1, c);
                str.append(s);

                //cout << s << '\n';
            }
            if(isSpace(c) || isPeriod(c))
            {
                //cout << str << '\n';
                arr.push_back(str);
                str = "";
            }
            //cout << str << '\n';
        }
        
    }
  
    //cout << str;

    in.close();
}
bool isString(char c)
{
    int temp = (int)c;
    if (temp >= 41 && temp <= 132)
    {
        return true;
    }
    if (temp >= 141 && temp <= 172)
    {
        return true;
    }
    
    return false;
}
bool isSpace(char c)
{
    if ((int)c == 32)
    {
        return true;
    }
    return false;
}
bool isPeriod(char c)
{
    if ((int)c == 46)
    {
        return true;
    }
    return false;
}
int main() {
    vector<string> arr;
    
    getTokens(arr);

    
    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << " ";
    }
        
    
    cout << '\n' << arr.size();

    return 0;
}

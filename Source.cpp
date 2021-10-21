#include<iostream>
#include<fstream>
#include <string>
#include <vector>

using namespace std;
bool isString(char c);
bool isSpace(char c);
bool isPeriod(char c);
bool isComment(string str);
bool isRead(string str);
bool isWrite(string str);
string isToken(string str);

void scan(vector<string> &arr) 
{
    ifstream in("Text.txt");
    char c;
    string str = "";
    string temp = "";
    
    //error reading file
    if (!in.eof() && in.fail())
    {
        cout << "error reading " << endl;
    }

    

    if(in.is_open()) {
        while (in.get(c)) 
        {
            
            if (isString(c))
            {
                string s(1, c);
                str.append(s);

                //cout << isComment(str) << endl;

                if (isComment(str) == true)
                {
                    cout << "Comment detected" << endl;
                    while (c != '/')
                    {
                        cout << c << endl;

                        in.get(c);
                    }
                }

                
            }
            if(isSpace(c) || isPeriod(c))
            {
                cout << "Adding: " << str << endl;
                arr.push_back(str);
                str = "";
            }
            if (c == '\n')
            {
                //cout << "End of line" << endl;
            }
            
        }
        
    }

    in.close();
}
bool isString(char c)
{
    int temp = (int)c;
    if (temp >= 65 && temp <= 90)
    {
        return true;
    }
    if (temp >= 97 && temp <= 122)
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
bool isComment(string str)
{
    if (str == "/*")
    {
        return true;
    }
    return false;
}
bool isRead(string str)
{
    if (str == "read")
    {
        return true;
    }
    return false;
}
bool isWrite(string str)
{
    if (str == "write")
    {
        return true;
    }
    return false;
}
bool isID(string str)
{
    bool flag = true;
    for (int i = 0; i < str.length(); i++)
    {
        
        if (!isString(str[i]))
        {
            
            flag = false;
        }
    }
    return flag;
}
bool isNum(string str)
{
    bool flag = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (!((int)str[i] >= 48 && (int)str[i] <= 57))
        {
            flag = false;
        }
    }

    return flag;
}
bool isAssign(string str)
{
    bool flag = false;
    for (int i = 0; i < str.length(); i++)
    {
        if ((int)str[i] == 58)
        {
            if ((int)str[i + 1] == 61)
            {
                return true;
            }
        }
    }
    return flag;
}
string isToken(string str)
{
    if (isWrite(str))
    {
        return "write";
    }
    if (isRead(str))
    {
        return "read";
    }
    if (isID(str))
    {
        return "ID";
    }
    if (isNum(str))
    {
        return "num";
    }
}
int main() {
    vector<string> arr;
    
    scan(arr);

    /*
    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << " ";
    }
    */

    
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    

    //cout << isToken("5") << endl;

    return 0;
}

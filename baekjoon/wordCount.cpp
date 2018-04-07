#include<iostream>
#include<string>
using namespace std;

int main()
{
    int count = 0;
    string s;
    getline(cin, s);
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (i != 0 && i != s.size()-1)
                count++;
        }
    }
    return count + 1;
}
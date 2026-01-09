#include <iostream>
#include <string>

using namespace std;

void printSubstrings(string& s, string curr="",int i=0)
{
    if(i==s.length())
    {
        cout<<curr<<endl;
        return;
    }

    printSubstrings(s, curr, i+1);
    printSubstrings(s, curr+s[i], i+1);
}
int main()
{
    string s= "ABC";
    printSubstrings(s);
}
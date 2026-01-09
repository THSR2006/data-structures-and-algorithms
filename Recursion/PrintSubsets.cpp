#include <iostream>
#include <string>

using namespace std;

void printSubSets(string& s, string curr="",int i=0)
{
    if(i==s.length())
    {
        cout<<curr<<endl;
        return;
    }

    printSubSets(s, curr, i+1);
    printSubSets(s, curr+s[i], i+1);
}
int main()
{
    string s= "ABC";
    printSubSets(s);
}
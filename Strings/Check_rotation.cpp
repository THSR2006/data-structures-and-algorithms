#include <iostream>
#include <string>

using namespace std;

bool areRotations(const string& s1, const string& s2)
{
    if(s1.length()!=s2.length())
        return false;
    
    return ((s1+s1).find(s2) != string::npos);
}

int main()
{
    string s1 = "abcabc";
    string s2 = "bcabca";


    (areRotations(s1, s2))? cout<<"True\n"<<endl : cout<<"False"<<endl;

    return 0;
}
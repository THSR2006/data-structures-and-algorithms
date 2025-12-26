#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ComputeLPS(const string& pattern, int* lps)
{   
    const int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    
    int i=1;
    while(i<m)
    {
        if(pattern[i]==pattern[len])    
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMP(const string& text, const string&pattern)
{
    const int m = pattern.length();
    const int n = text.length();
    
    int lps[m];
    ComputeLPS(pattern, lps);

    int i=0;
    int j=0;
    vector<int> v;

    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }

        if(j==m)
        {
            v.push_back(i-j);
            j = lps[j-1];
        }
        else if(i<n && pattern[j]!=text[i])
        {
            if(j==0)
                i++;
            else
                j = lps[j-1];
        }  
    }
    return v;
}

int main()
{
    string text = "BANANA";
    string pattern = "ANA";

    vector<int> v = KMP(text, pattern);

    for(int x: v)
        cout<<x<<',';

    return 0;
}
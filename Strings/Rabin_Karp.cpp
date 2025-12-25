#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> RabinKarp(string text, string pattern)
{
    int m = text.length();
    int n = pattern.length();

    const int B = 53;
    const int M = 1000000007;

    long long patternHash = 0;
    long long textHash = 0;
    long long power = 1;

    vector<int> v;

    if(m<n) return v;

    for(int i=0; i<n; i++)
    {
        patternHash = (patternHash * B + pattern[i]) % M;
        textHash = (textHash * B + text[i]) % M;

        if(i < n-1)
            power = (power * B) % M;
    }

    for(int i=0; i<=m-n; i++)
    {
        if(patternHash == textHash)
            if(text.substr(i, n)==pattern)
                v.push_back(i);

        if(i < m-n)
        {
            textHash = (textHash - text[i]*power) % M;
            if(textHash < 0)
                textHash += M;

            textHash = (textHash*B + text[i+n]) % M;
        }
    }
    return v;
}

int main()
{
    string text = "aaaaaaaa";
    string pattern = "aaaaaa";

    vector<int> v = RabinKarp(text, pattern);

    for(int i: v)
    {
        cout<< i << ',';
    }
}
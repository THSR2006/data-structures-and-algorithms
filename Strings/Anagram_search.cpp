#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPresent(const string& text, const string& pattern)
{
    int m = pattern.length();
    int n = text.length();

    if(m>n)
        return false;

    int matchings = 0;
    vector<int> countPattern(256,0);
    vector<int> countText(256,0);

    for(int i=0; i<m; i++)
    {
        countPattern[pattern[i]]++;
        countText[text[i]]++;
    }

    for(int i=0; i<256; i++)
    {
        if(countPattern[i]==countText[i])
            matchings++;
    }

    int l,r;

    for(int i=m; i<n; i++)
    {
        if(matchings==256)
            return true;

        l = text[i-m];
        r = text[i];
        
        if(countText[r]==countPattern[r])
            matchings--;

        countText[r]++;

        if(countText[r]==countPattern[r])
            matchings++;

        if(countText[l]==countPattern[l])
            matchings--;
        
        countText[l]--;

        if(countText[l]==countPattern[l])
            matchings++;
    }

    return (matchings==256);
}

int main()
{
    string text = "snake";
    string pattern = "ekans";

    cout<<isPresent(text, pattern)<<endl;

    return 0;
}
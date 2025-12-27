#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool processInput(string& str)
{
    int len = str.length();
    
    if(len>20 || len==0)
        return false;

    for(char ch : str)
    {
        if(!isalpha(ch))
            return false;
    }

    for(char&ch : str)
    {
        ch = toupper(ch);
    }

    return true;
}

int computeLexographicRank(string str)
{
    int len = str.length();

    if(processInput(str))
    {
        int alphabetFrequency[26] = {0};
        int countArray[26] = {0};

        for(char ch: str)
        {
            alphabetFrequency[ch-'A']++;
        }

        int count = 0;

        for(int i=0; i<26; i++)
        {
            if(alphabetFrequency[i]==0)
                continue;

            countArray[i]++;
            count += alphabetFrequency[i];
        }

        
    }
    
    return -1;
}
int main()
{
    string str = "hemanth2006";
    return 0;
}
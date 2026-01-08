#include <iostream>
using namespace std;

int ropeCutting(int n, int a, int b, int c)
{
    if(n<0)
        return -1;
    if(n==0)
        return 0;

    int count = max( max(ropeCutting(n-a,a,b,c), ropeCutting(n-b,a,b,c)), ropeCutting(n-c,a,b,c));

    if(count==-1)
        return -1;
    else
        return count + 1;
}

int main()
{
    cout<<ropeCutting(23, 10,13, 23);
    return 0;
}

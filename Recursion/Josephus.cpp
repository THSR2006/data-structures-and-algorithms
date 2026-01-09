#include <iostream>
#include <vector>

using namespace std;

int playJosephus(int n, int k)
{
    if(n<=1)
        return 0;

    return (playJosephus(n-1, k)+k)%n;
}
int main()
{
    cout<<playJosephus(4,3)<<endl;
}
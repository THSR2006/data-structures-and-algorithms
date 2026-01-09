#include <iostream>
using namespace std;

void TOH(int n, char source, char aux, char destination)
{
    if(n==1)
    {
        cout<<"Moving 1 from "<<source<<" to "<<destination<<endl;
        return;
    }

    TOH(n-1, source, destination, aux);
    cout<<"Moving "<<n<<" from "<<source<<" to "<<destination<<endl;
    TOH(n-1, aux, source, destination);

    return;
}

int main()
{
    TOH(3, 'A', 'B', 'C');
    return 0;
}
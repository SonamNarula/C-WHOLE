#include <iostream>
using namespace std;

int minOfTwo(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    cout << "min of 2 numbers = " << minOfTwo(10, 21) << endl;
    return 0; 
}
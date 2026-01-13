#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "x = ";
    cin >> x;

    cout << endl;

    if (x % 2 == 0)
    {
        cout << x << " is an even number";
    }

    else
    {
        cout << x << " is an odd number";
    }

    return 0;
}
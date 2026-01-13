#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "x = ";
    cin >> x;

    cout << endl;

    if (x >= 0)
    {
        cout << "absolute value of x = " << x;
    }

    else
    {
        cout << "absolute value of x = " << (-x);
    }

    return 0;
}
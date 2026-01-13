#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "x = ";
    cin >> x;

    if (x > 99 && x < 1000)
    {
        cout << x << " is a 3 digit number";
    }
    else
    {
        cout << x << " is not a 3 digit number";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "side 1 of triangle = ";
    cin >> a;

    int b;
    cout << "side 2 of triangle = ";
    cin >> b;

    int c;
    cout << "side 3 of triangle = ";
    cin >> c;

    if (a + b == c || b + c == a || a + c == b)
    {
        cout << "its a triangle";
    }
    else
    {
        cout << "not a triangle";
    }
    return 0;
}
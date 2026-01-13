#include <iostream>
using namespace std;

int main()
{
    int n;
    int product = 1;
    cout << "n = ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    cout << "product = " << product;

    return 0;
}
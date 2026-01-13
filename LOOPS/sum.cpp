#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cout << "n = ";
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    cout << "sum = " << sum;

    return 0;
}
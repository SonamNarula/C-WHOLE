#include <iostream>
using namespace std;

int main()
{
    int costPrice;
    cout << "cp = ";
    cin >> costPrice;

    int sellingPrice;
    cout << "sp = ";
    cin >> sellingPrice;

    if (costPrice > sellingPrice)
    {
        cout << "loss";
    }

    else if (costPrice == sellingPrice)
    {
        cout << "no profit no loss";
    }

    else
    {
        cout << "profit";
    }
    return 0;
}
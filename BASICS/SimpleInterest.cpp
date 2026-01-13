#include <iostream>
using namespace std;

int main()
{
    int p;
    cout << "enter principle : " << " ";
    cin >> p;

    cout << endl;

    int r;
    cout << "enter rate of interest : " << " ";
    cin >> r;

    cout << endl;

    int t;
    cout << "enter time : " << " ";
    cin >> t;

    cout << "simple interest = " << (p * r * t) / 100;
}
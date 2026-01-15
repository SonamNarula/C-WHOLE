#include <iostream>
using namespace std;

void printHello()
{
    cout << "Hello, ";
}
int sonammBete()
{
    cout << "sona ";
    return 3;
}
int main()
{
    printHello();
    sonammBete();
    cout << endl;
    cout << sonammBete();
}
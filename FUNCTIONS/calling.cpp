#include <iostream>
using namespace std;

void greet()
{
    cout << "hey! lets learn c++";
}
int multiply(int a, int b)
{
    return a * b;
}
int main()
{
    greet();
    cout << endl;
    int result = multiply(8, 10);
    cout << result;
}
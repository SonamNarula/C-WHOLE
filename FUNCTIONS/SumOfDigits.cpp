#include<iostream>
using namespace std;

int SumOfDigits(int n){
    int digitSum = 0;
    while(n>0){
        int lastDigit = n%10;
        n = n/10;
        digitSum += lastDigit;
    }
    return digitSum;
}
int main(){
    cout<<SumOfDigits(1245)<<endl;
    cout<<SumOfDigits(101020)<<endl;
}
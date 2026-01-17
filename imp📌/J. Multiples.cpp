// Given two numbers A and B. Print "Multiples" if A is multiple of B or vice versa. Otherwise print "No Multiples".
#include<bits/stdc++.h>
using namespace std;

int main(){
    int A;
    int B;
    cin>>A;
    cin>>B;

    if(A%B==0 || B%A==0){
        cout<<"Multiples";
    }else{
        cout<<"No Multiples";
    }

    return 0;
}
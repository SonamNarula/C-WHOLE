#include<iostream>
using namespace std;

int main()
{
    int length;
    cout<<"length of rectangle : ";
    cin>>length;

      int breadth;
    cout<<"breadth of rectangle : ";
    cin>>breadth;

    int area = length*breadth;
    int perimeter = 2*(length+breadth);

    if(area > perimeter){
        cout<<"area is greater than perimeter";
    }

    else if(area == perimeter){
        cout<<"area and perimeter are equal";
    }
    else{
        cout<<"area is less than perimeter";
    }

    return 0;

}
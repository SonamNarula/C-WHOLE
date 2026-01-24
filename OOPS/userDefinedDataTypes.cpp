#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
    // properties / attributes
    string name;
    string dept;
    string subject;
    double salary;

    void changeDept(string newDept)
    {
        dept = newDept;
    }
};

int main()
{
    Teacher t1;
    t1.name = "sonam";
    t1.subject = "C++";
    t1.dept = "Computer";
    t1.salary = 1000000;

    cout << t1.name << endl;
    return 0;
}
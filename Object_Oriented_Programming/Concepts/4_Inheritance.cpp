#include <iostream>
#include <string>
using namespace std;

// 4. Inheritance: "The Man" (and The Child)
// Passing down attributes and methods to child classes.

// Base Class
class Musician {
public:
    string genre;
    
    void practice() {
        cout << "Practicing scales and chords..." << endl;
    }
};

// Derived Class (Inherits from Musician)
class PopStar : public Musician {
public:
    int grammys;

    void performAndDance() {
        cout << "Singing + Dancing choreography!" << endl;
    }
};

int main() {
    PopStar taylor;
    
    // Accessing inherited member
    taylor.genre = "Pop";
    taylor.practice(); 

    // Accessing own member
    taylor.grammys = 14; 
    taylor.performAndDance();

    cout << "Genre: " << taylor.genre << ", Grammys: " << taylor.grammys << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// Concept: Advanced Inheritance & Diamond Problem
// "Folklore" -> Passing down stories through generations.
// Covers: Multilevel, Multiple, and Virtual Inheritance.

// ---------------------------------------------------------
// 1. Multilevel Inheritance (Grandparent -> Parent -> Child)
// ---------------------------------------------------------
class Grammys {
public:
    void host() {
        cout << "[Grammys]: Hosting the awards night..." << endl;
    }
};

class Artist : public Grammys {
public:
    string name;
    Artist(string n) : name(n) {}
    void compose() { cout << name << " is composing..." << endl; }
};

class Superstar : public Artist {
public:
    Superstar(string n) : Artist(n) {}
    void winAward() { 
        cout << name << " wins Album of the Year!" << endl; 
    }
};

// ---------------------------------------------------------
// 2. Multiple Inheritance (Mom + Dad -> Child)
// ---------------------------------------------------------
class Singer {
public:
    void sing() { cout << "Singing scales..." << endl; }
};

class Songwriter {
public:
    void write() { cout << "Writing lyrics..." << endl; }
};

class PopIcon : public Singer, public Songwriter {
public:
    void perform() {
        cout << "Performing live!" << endl;
    }
};

// ---------------------------------------------------------
// 3. Virtual Inheritance (Solving the Diamond Problem)
// ---------------------------------------------------------
// Without 'virtual', 'ErasTour' would have TWO copies of 'Person'
// (one via Producer, one via Performer).

class Person {
public:
    Person() { cout << "Person Constructor Called" << endl; }
};

// Both inherit 'virtually' from Person
class Producer : virtual public Person {
public:
    Producer() { cout << "Producer Constructor Called" << endl; }
};

class Performer : virtual public Person {
public:
    Performer() { cout << "Performer Constructor Called" << endl; }
};

// ErasTour inherits from both, but 'Person' is constructed only ONCE.
class ErasTour : public Producer, public Performer {
public:
    ErasTour() { cout << "ErasTour Object Created Successfully!" << endl; }
};

int main() {
    cout << "=== Multilevel Inheritance ===" << endl;
    Superstar s("Taylor");
    s.host();      // Inherited from Grammys (Grandparent)
    s.compose();   // Inherited from Artist (Parent)
    s.winAward();  // Own method

    cout << "\n=== Multiple Inheritance ===" << endl;
    PopIcon icon;
    icon.sing();   // From Singer
    icon.write();  // From Songwriter
    icon.perform();

    cout << "\n=== Virtual Inheritance (Diamond Problem) ===" << endl;
    ErasTour et; 
    // Notice: 'Person Constructor Called' appears only ONCE.

    return 0;
}

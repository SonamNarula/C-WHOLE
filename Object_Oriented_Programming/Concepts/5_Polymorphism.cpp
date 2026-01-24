#include <iostream>
using namespace std;

// 5. Polymorphism: "Look What You Made Me Do"
// "Many Forms". Same function name, different behavior.

// Run-time Polymorphism (Overriding)
class Instrument {
public:
    virtual void makeSound() { // 'virtual' allows overriding
        cout << "Some generic instrument sound..." << endl;
    }
};

class Guitar : public Instrument {
public:
    void makeSound() override {
        cout << "Strumming acoustic strings..." << endl;
    }
};

class Piano : public Instrument {
public:
    void makeSound() override {
        cout << "Playing a melodic tune..." << endl;
    }
};

// Compile-time Polymorphism (Overloading)
class VolumeControl {
public:
    void setLevel(int level) {
        cout << "Setting volume to " << level << endl;
    }
    void setLevel(string level) { // Overloaded function
        cout << "Setting volume to mode: " << level << endl;
    }
};

int main() {
    // Run-time
    Instrument* i1 = new Guitar();
    Instrument* i2 = new Piano();
    
    i1->makeSound(); // Calls Guitar's version
    i2->makeSound(); // Calls Piano's version

    // Compile-time
    VolumeControl remote;
    remote.setLevel(13);
    remote.setLevel("MAXIMUM");

    delete i1;
    delete i2;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// Concept: The 'this' Pointer
// "Cornelia Street" -> Identifying the address of the current object.
// Used for:
// 1. Resolving name conflicts (param name == member name)
// 2. method chaining (returning *this)

class Scholar {
private:
    string name;
    string currentFocus;

public:
    // 1. Resolving Name Conflict
    Scholar(string name) {
        this->name = name; // 'this->name' refers to member, 'name' refers to param
        this->currentFocus = "General Studies";
        cout << "[System]: Scholar '" << this->name << "' registered at address: " << this << endl;
    }

    // 2. Method Chaining (returning reference to current object)
    Scholar& setFocus(string newFocus) {
        this->currentFocus = newFocus;
        cout << "[Log]: Focus shifted to " << this->currentFocus << endl;
        return *this; // Returns the object itself
    }

    Scholar& study() {
        cout << "[Action]: " << this->name << " is studying " << this->currentFocus << " deeply." << endl;
        return *this;
    }
    
    void printStatus() {
        cout << "Status: " << this->name << " | " << this->currentFocus << endl;
    }
};

int main() {
    Scholar s1("Sonam");

    // Chaining methods: setFocus() -> study() -> printStatus()
    // This works because each method returns the object reference (*this)
    s1.setFocus("Advanced C++ Pointers").study().setFocus("System Design").study();

    return 0;
}

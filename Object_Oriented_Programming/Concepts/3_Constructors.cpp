#include <iostream>
#include <string>
using namespace std;

// 3. Constructors & Destructors: "Begin Again" & "Closure"
// Constructor: Called when object is created (Setup).
// Destructor: Called when object is destroyed (Cleanup).

class Concert {
public:
    string city;

    // Default Constructor
    Concert() {
        city = "Unknown City";
        cout << "Planning a concert..." << endl;
    }

    // Parameterized Constructor
    Concert(string c) {
        city = c;
        cout << "Welcome to the Eras Tour in " << city << "!" << endl;
    }

    // Destructor
    ~Concert() {
        cout << "The show in " << city << " is over. Goodnight!" << endl;
    }
};

int main() {
    cout << "--- Creating concert 1 ---" << endl;
    Concert c1("London");

    cout << "\n--- Creating concert 2 ---" << endl;
    {
        Concert c2("Paris"); 
        // c2 will be destroyed here when scope ends
    }
    
    cout << "\n--- Back to main ---" << endl;
    return 0;
}

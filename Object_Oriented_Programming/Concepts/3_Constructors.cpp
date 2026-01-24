#include <iostream>
#include <string>
using namespace std;

// Concept: Object Lifecycle (Initialization & Destruction)
// "Begin Again" -> Constructor
// "Closure" -> Destructor

class Thesis {
private:
    string topic;
    int pageCount;

public:
    // Default Constructor
    Thesis() {
        topic = "Untitled Research";
        pageCount = 0;
        cout << "[System]: Initializing empty thesis buffer..." << endl;
    }

    // Parameterized Constructor
    Thesis(string t, int p) {
        topic = t;
        pageCount = p;
        cout << "[System]: Thesis '" << topic << "' started with " << pageCount << " pages." << endl;
    }

    // Copy Constructor
    Thesis(const Thesis &t) {
        topic = t.topic + " (Review Copy)";
        pageCount = t.pageCount;
        cout << "[System]: Copying thesis for peer review..." << endl;
    }

    // Destructor
    ~Thesis() {
        cout << "[System]: Deallocating resources for '" << topic << "'. Data saved." << endl;
    }
};

int main() {
    cout << "--- Academic Session Start ---" << endl;
    
    Thesis masters("Machine Learning Optimization", 45);
    
    {
        Thesis draft = masters; // Calls Copy Constructor
    } // draft dies here (Destructor called)

    cout << "--- Academic Session End ---" << endl;
    return 0;
}

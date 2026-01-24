#include <iostream>
#include <string>
using namespace std;

// 2. Encapsulation: "Reputation"
// Keeping data private and safe from outside interference.
// Only accessible via public methods (getters/setters).

class Diary {
private:
    string secretEntry; // Private: No one can see this directly!

public:
    void setEntry(string entry) {
        if (entry.length() > 0) {
            secretEntry = entry;
            cout << "Diary entry saved completely safe." << endl;
        } else {
            cout << "Cannot save empty entry!" << endl;
        }
    }

    string getEntry() {
        return "Confidential: " + secretEntry;
    }
};

int main() {
    Diary myDiary;
    
    // myDiary.secretEntry = "I ate the last cookie"; // Error! Private member.

    myDiary.setEntry("Today was a fairytale.");
    cout << myDiary.getEntry() << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Concept: Shallow Copy vs Deep Copy
// "I Knew You Were Trouble" -> Shallow Copy (Two pointers, one memory block. Danger.)
// "Clean" -> Deep Copy (Two pointers, two independent memory blocks. Safe.)

// ---------------------------------------------------------
// 1. Shallow Copy (The Dangerous Way)
// ---------------------------------------------------------
class ShallowProject {
public:
    int* data;
    
    ShallowProject(int val) {
        data = new int(val);
    }
    
    // Default Copy Constructor does a SHALLOW COPY
    // Both objects will point to the SAME memory address.
    ShallowProject(const ShallowProject& source) = default; 

    ~ShallowProject() {
        // Danger! If two objects point to 'data', 
        // the first destructor frees it, the second causes a crash (Double Free).
        // Commenting out delete to prevent crash in this demo, 
        // but normally this is a major bug.
        // delete data; 
    }
};

// ---------------------------------------------------------
// 2. Deep Copy (The Safe Way)
// ---------------------------------------------------------
class DeepProject {
public:
    int* data;

    DeepProject(int val) {
        data = new int(val);
    }

    // Custom Copy Constructor does a DEEP COPY
    DeepProject(const DeepProject& source) {
        // 1. Allocate NEW memory
        data = new int(*source.data); 
        // 2. Copy the VALUE, not the address
    }

    ~DeepProject() {
        delete data; // Safe because each object owns its own memory.
    }
};

int main() {
    cout << "--- SHALLOW COPY DEMO ---" << endl;
    ShallowProject p1(100);
    ShallowProject p2 = p1; // Shallow copy
    
    cout << "p1 Address: " << p1.data << " Value: " << *p1.data << endl;
    cout << "p2 Address: " << p2.data << " Value: " << *p2.data << endl;
    
    *p1.data = 500; // Modifying p1
    cout << "[Modified p1] p2 Value check: " << *p2.data << " (Changed! p2 is affected)" << endl;


    cout << "\n--- DEEP COPY DEMO ---" << endl;
    DeepProject d1(100);
    DeepProject d2 = d1; // Deep copy
    
    cout << "d1 Address: " << d1.data << " Value: " << *d1.data << endl;
    cout << "d2 Address: " << d2.data << " Value: " << *d2.data << endl;
    
    *d1.data = 500; // Modifying d1
    cout << "[Modified d1] d2 Value check: " << *d2.data << " (Safe! d2 is independent)" << endl;

    return 0;
}

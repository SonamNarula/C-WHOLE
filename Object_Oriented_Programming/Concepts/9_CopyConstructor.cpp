#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Concept: Deep Copy vs Shallow Copy
// "Wonderland" -> Finding a place where things are not easily lost.
// When a class has pointers, the default copy constructor performs a Shallow Copy
// (copying the address only). We need a Deep Copy to duplicate the actual data.

class LabExperiment {
private:
    int* dataPoints; // Dynamic memory
    int pointCount;

public:
    // Constructor
    LabExperiment(int count, int startValue) {
        pointCount = count;
        dataPoints = new int[count];
        for (int i = 0; i < count; i++) {
            dataPoints[i] = startValue + i;
        }
        cout << "[Allocated]: Experiment memory created at " << dataPoints << endl;
    }

    // Deep Copy Constructor
    LabExperiment(const LabExperiment& other) {
        pointCount = other.pointCount;
        // Deep Copy: Allocate NEW memory
        dataPoints = new int[pointCount];
        
        // Copy actual values
        for (int i = 0; i < pointCount; i++) {
            dataPoints[i] = other.dataPoints[i];
        }
        cout << "[Cloned]: Deep copy created at " << dataPoints << " (Separate from " << other.dataPoints << ")" << endl;
    }

    // Destructor
    ~LabExperiment() {
        delete[] dataPoints;
        cout << "[Deallocated]: Memory freed." << endl;
    }

    void showData() {
        cout << "Data: ";
        for (int i = 0; i < pointCount; i++) {
            cout << dataPoints[i] << " ";
        }
        cout << endl;
    }
    
    // Function to modify data to prove independence
    void modifyData(int index, int val) {
        if(index < pointCount) dataPoints[index] = val;
    }
};

int main() {
    LabExperiment exp1(5, 10);
    exp1.showData();

    cout << "\n--- Creating Copy (Deep Copy) ---" << endl;
    LabExperiment exp2 = exp1; // Calls Deep Copy Constructor
    
    cout << "\n--- Modifying Copy ---" << endl;
    exp2.modifyData(0, 999); // Should NOT affect exp1
    
    cout << "Original (exp1): ";
    exp1.showData();
    cout << "Copy     (exp2): ";
    exp2.showData();

    cout << "\n--- End of Experiment ---" << endl;
    return 0;
}

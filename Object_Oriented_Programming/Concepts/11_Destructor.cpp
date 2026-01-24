#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Concept: Destructor (~Class)
// "The Last Time" -> Ensuring proper cleanup when an object expires.
// Crucial for Memory Management (preventing leaks) and Resource Management (closing files/connections).
// This relies on RAII (Resource Acquisition Is Initialization).

class FileHandler {
private:
    string filename;
    ofstream* fileStream; // Pointer to file stream

public:
    // Constructor: Opens the file (Acquires Resource)
    FileHandler(string fname) {
        filename = fname;
        fileStream = new ofstream(filename);
        
        if (fileStream->is_open()) {
            cout << "[Opened]: File '" << filename << "' is ready for writing." << endl;
        } else {
            cout << "[Error]: Failed to open '" << filename << "'." << endl;
        }
    }

    void writeLog(string message) {
        if (fileStream->is_open()) {
            *fileStream << message << endl;
            cout << "[Writing]: " << message << endl;
        }
    }

    // Destructor: Closes the file and frees memory (Releases Resource)
    // Automatically called when object goes out of scope.
    ~FileHandler() {
        if (fileStream->is_open()) {
            fileStream->close();
            cout << "[Closed]: '" << filename << "' saved properly." << endl;
        }
        delete fileStream; // Prevent memory leak
        cout << "[Cleanup]: Memory for '" << filename << "' handler released." << endl;
    }
};

void createTempLog() {
    cout << "\n--- Inside Function Scope ---" << endl;
    FileHandler log("session_log.txt"); // Created here
    log.writeLog("System initialized.");
    log.writeLog("User logged in.");
    
    // Log object is destroyed automatically here when function ends
    cout << "--- Function Scope Ending ---" << endl;
}

int main() {
    cout << "Starting Application..." << endl;
    
    createTempLog();
    
    cout << "\nBack in Main. Log file closed automatically." << endl;
    
    return 0;
}

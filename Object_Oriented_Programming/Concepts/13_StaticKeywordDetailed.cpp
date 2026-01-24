#include <iostream>
#include <string>
using namespace std;

// Concept: The 'static' Keyword (The Timeless Concept)
// "Timeless" -> Things that persist beyond a single moment (or object).
// 1. Static Data Members: Shared by all objects (Class Property).
// 2. Static Member Functions: Can be called without an object (Class Method).
// 3. Static Local Variables: Retain value between function calls.

class StreamingService {
private:
    string userName;

public:
    // 1. Static Data Member
    static int activeUsers; // Shared across all instances

    StreamingService(string name) {
        userName = name;
        activeUsers++; // Increment shared counter
        cout << "[Login]: " << userName << " joined." << endl;
    }

    ~StreamingService() {
        activeUsers--; // Decrement shared counter
        cout << "[Logout]: " << userName << " left." << endl;
    }

    // 2. Static Member Function
    // Can ONLY access static data members.
    static void showTotalUsers() {
        cout << "[System]: Total Active Users: " << activeUsers << endl;
        // cout << userName; // ERROR: Cannot access non-static member
    }
};

// Initialize Static Member (Must be outside class)
int StreamingService::activeUsers = 0;

void playSong() {
    // 3. Static Local Variable
    // Initialized only ONCE, value persists between calls.
    static int songsPlayed = 0; 
    songsPlayed++;
    cout << "Playing song... (Session total: " << songsPlayed << ")" << endl;
}

int main() {
    cout << "--- Static Members & Methods ---" << endl;
    StreamingService::showTotalUsers(); // Calling without object

    StreamingService user1("Sonam");
    StreamingService user2("User_13");
    
    StreamingService::showTotalUsers(); // Shared count = 2

    {
        StreamingService user3("Guest");
        StreamingService::showTotalUsers(); // Shared count = 3
    } // user3 destroyed here

    StreamingService::showTotalUsers(); // Shared count = 2

    cout << "\n--- Static Local Variables ---" << endl;
    playSong(); // songsPlayed = 1
    playSong(); // songsPlayed = 2
    playSong(); // songsPlayed = 3 (remembers previous value)

    return 0;
}

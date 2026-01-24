#include <iostream>
using namespace std;

// 6. Abstraction: "State of Grace" (Pure)
// Hiding implementation details, showing only the interface.

// Abstract Class (cannot be instantiated)
class SongWriter {
public:
    virtual void writeLyrics() = 0; // Pure Virtual Function
    
    void sleep() {
        cout << "Sleeping to get fresh ideas..." << endl;
    }
};

class PopArtist : public SongWriter {
public:
    void writeLyrics() override {
        cout << "Writing catchy hooks and storytelling verses." << endl;
    }
};

int main() {
    // SongWriter sw; // Error: Cannot instantiate abstract class

    PopArtist p;
    p.sleep();
    p.writeLyrics();

    return 0;
}

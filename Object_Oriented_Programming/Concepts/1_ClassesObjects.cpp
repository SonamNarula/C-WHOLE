#include <iostream>
#include <string>
using namespace std;

// 1. Classes & Objects: "You Belong With Me"
// A Class is a blueprint (like a Song sheet music)
// An Object is an instance (like a live performance of that song)

class Song {
public:
    string title;
    string album;
    int durationSeconds;

    void play() {
        cout << "Now Playing: " << title << " from the album " << album << endl;
    }
};

int main() {
    // Creating an object of class Song
    Song track1;
    track1.title = "Love Story";
    track1.album = "Fearless";
    track1.durationSeconds = 235;

    // Accessing member function
    track1.play();

    Song track2;
    track2.title = "Blank Space";
    track2.album = "1989";
    track2.play();

    return 0;
}

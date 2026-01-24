#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Developer {
private:
    string name;
    vector<string> skills;
    int bugsFixed;
    int songsListenedTo;

public:
    Developer(string n) : name(n), bugsFixed(0), songsListenedTo(0) {}

    void learnSkill(string skill) {
        skills.push_back(skill);
        cout << "Learned " << skill << "! Added to the blank space in my brain." << endl;
    }

    void fixBug() {
        bugsFixed++;
        cout << "Fixed a bug! karma is a relaxing thought." << endl;
    }

    void listenToTaylorSwift() {
        songsListenedTo++;
        cout << "Listening to T-Swift... Can't stop, won't stop moving." << endl;
    }

    void showStats() {
        cout << "\n=== " << name << "'s Developer Stats ===" << endl;
        cout << "Skills collected: " << skills.size() << endl;
        for (const string& skill : skills) {
             cout << "- " << skill << endl;
        }
        cout << "Bugs obliterated: " << bugsFixed << endl;
        cout << "Songs jammed to: " << songsListenedTo << endl;
        cout << "======================================" << endl;
    }
};

int main() {
    Developer dev("Sonam");

    dev.learnSkill("C++");
    dev.learnSkill("Object Oriented Programming");
    dev.learnSkill("Style"); // We never go out of style

    dev.fixBug();
    dev.listenToTaylorSwift();
    dev.fixBug();

    dev.showStats();

    return 0;
}

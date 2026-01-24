#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Me {
private:
    string name;
    string currentEra; // Taylor Swift reference intended ;)
    string mood;
    bool isCaffeinated;

public:
    // Constructor (The Debut)
    Me(string n, string era) : name(n), currentEra(era) {
        mood = "Ready for it";
        isCaffeinated = false;
    }

    void drinkCoffee() {
        isCaffeinated = true;
        mood = "Feeling 22 (and energetic)";
        cout << "*Sips coffee* ... All too well." << endl;
    }

    void setMood(string newMood) {
        mood = newMood;
    }

    void introduce() {
        cout << "Hi, I'm " << name << "!" << endl;
        cout << "Currently in my " << currentEra << "." << endl;
        cout << "Current Mood: " << mood << endl;
        if (isCaffeinated) {
            cout << "Status: Caffeinated and coding like a mastermind." << endl;
        } else {
            cout << "Status: Need coffee to shake it off." << endl;
        }
    }
};

int main() {
    Me sonam("Sonam", "C++ Master Era");
    
    sonam.introduce();
    
    cout << "\n...Fetching coffee...\n" << endl;
    sonam.drinkCoffee();
    
    cout << "\n...After coffee...\n" << endl;
    sonam.introduce();

    return 0;
}

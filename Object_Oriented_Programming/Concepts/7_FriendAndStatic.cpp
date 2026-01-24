#include <iostream>
using namespace std;

// 7. Friend & Static: "You Need To Calm Down" (and work together)

class FanClub {
private:
    int memberKey;

public:
    static int totalFans; // Static member: Shared by all objects

    FanClub() {
        memberKey = 1989;
        totalFans++;
    }

    // Friend Function Declaration
    friend void revealKey(FanClub& fc);
};

// Initialize static member
int FanClub::totalFans = 0;

// Friend Function Definition
// Can access private members of FanClub
void revealKey(FanClub& fc) {
    cout << "Exclusive Access! The secret key is: " << fc.memberKey << endl;
}

int main() {
    FanClub fan1;
    FanClub fan2;
    FanClub fan3;

    cout << "Total Fans (Static): " << FanClub::totalFans << endl; // Shared count

    revealKey(fan1); // Friend function accessing private data

    return 0;
}

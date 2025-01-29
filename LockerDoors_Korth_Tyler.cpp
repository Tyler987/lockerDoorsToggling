#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

//Checks input
int ValidInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt; //outputs prompt
        cin >> value; //reads input
        if (cin.fail() || value <= 0) { //checks input
            cin.clear(); //clears cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes invalid input
            cout << "Invalid input, whole number please\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes input
            return value;
        }
    }
}

int main() {
    int n, r;
    //gets user input and calls the function ValidInput
    n = ValidInput("Enter the number of lockers: ");
    r = ValidInput("Enter the number of passes: ");

    //0 is closed
    //1 is open
    //sets all lockers to 0 at start
    vector<int> lockers(n + 1, 0);  

    //goes through the passes and toggles every ith locker
    //Gets what lockers are going to be toggled each pass
    //if locker is closed then it is open, if it is open then it is closed
    for (int i = 1; i <= r; i++) {  //passes
        for (int j = i; j <= n; j += i) {  //iteration with locker doors
            lockers[j] = 1 - lockers[j];  //open and close
        }
    }

    //outputs if the locker is closed or open
    cout << "Locker status: \n";
    for (int i = 1; i <= n; i++) {
        cout << "Locker " << i << ": " << (lockers[i] == 1 ? "open" : "closed") << endl;
    }

    //output open lockers
    int openCount = 0;
    for (int i = 1; i <= n; i++) {
        if (lockers[i] == 1) {
            openCount++;
        }
    }
    cout << "Number of open lockers: " << openCount << endl;

    return 0;
}

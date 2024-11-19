#include <iostream>
#include <stdlib.h>




using namespace std;

int RandomNumber(int min, int max){
    return rand()%(max-min + 1) + min;
}

int main(int argc, char const *argv[])
{
    while (true) {
        int correctGuessed = 0;
        cout << "Type in a number, to guess another number between 1 and x! : ";
        int play;
        cin >> play;

        // terminate on error
        if (cin.fail()){
            terminate();
            return -1;
        }

        // terminate if its a negative number
        if (play < 0) {
            cout << "You can't have negative numbers!";
            terminate();
            return -1;
        }

        while (true){
            cout << "Type in a number from 1-" << play << " and try to guess it! (Enter any character to quit or enter your amount + 1 to go back to the range setting)" << endl;
            int value;
            cin >> value;

            int randNum = RandomNumber(1,play);
            if (cin.fail()){
                cout << "Invalid input!" << endl;
                terminate();
                return -1;
            }
            if (value == randNum){
                // correctly guessed
                correctGuessed++;
                cout << "Successfully guessed number! Answered " << correctGuessed << " correctly so far!" << endl;
            }else if (value == play + 1){
                // go back to the setting
                break;
            }else if (value > play){
                // number too big
                cout << "Your number is too big!!" << endl;
                cout << "The answer was " << randNum << endl;
            }else{
                // guessed incorrectly
                cout << "Whoops! Looks like you failed.." << endl;
                correctGuessed = 0;
                cout << "The answer was " << randNum << endl;
            }
        }
    }
    return 0;
}

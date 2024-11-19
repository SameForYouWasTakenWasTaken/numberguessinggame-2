#include <iostream>




using namespace std;

int RandomNumber(int min, int max){
    return rand()%(max-min + 1) + min;
}

int main(int argc, char const *argv[])
{
    int correctGuessed = 0;
    cout << "Type in a number, to guess another number between it! :";
    int play;
    cin >> play;

    // terminate on error
    if (cin.fail()){
        terminate();
        return -1;
    }

    if (play < 0) {
        cout << "You can't have negative numbers!";
        terminate();
        return -1;
    }

    while (true){
        cout << "Type in a number from 1-" << play << " and try to guess it! (Enter any character to quit)" << endl;
        int value;
        cin >> value;

        int randNum = RandomNumber(1,play);
        if (cin.fail()){
            cout << "Invalid input!" << endl;
            terminate();
            return -1;
        }
        if (value == randNum){
            correctGuessed++;
            cout << "Successfully guessed number! Answered " << correctGuessed << " correctly so far!" << endl;
        }else if (value > play){
            cout << "Your number is too big!!" << endl;
        }else{
            cout << "Whoops! Looks like you failed.." << endl;
            correctGuessed = 0;
        }
        
        
    }
    return 0;
}

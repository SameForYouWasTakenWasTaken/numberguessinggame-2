#include <iostream>

using namespace std;

int RandomNumber(int min, int max){
    return rand()%(max-min + 1) + min;
}

int main(int argc, char const *argv[])
{
    int correctGuessed = 0;
    while (true){
        cout << "Type in a number from 1-3 and try to guess it! (Click any character to quit)" << endl;
        int value;
        cin >> value;

        int randNum = RandomNumber(1,3);
        if (cin.fail()){
            cout << "Invalid input!" << endl;
            terminate();
            return -1;
        }
        if (value == randNum){
            correctGuessed++;
            cout << "Successfully guessed number! Answered " << correctGuessed << " correctly so far!" << endl;
        }else if (value == 4){
            terminate();
        }else if (value > 3)
        {
            cout << "Your number is too big!!" << endl;
        }else{
            cout << "Whoops! Looks like you failed.." << endl;
            correctGuessed = 0;
        }
        
        
    }
    return 0;
}

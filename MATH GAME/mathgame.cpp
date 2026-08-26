#include <iostream>
using namespace std;

int main() 
{
    cout << "==================================================" << endl;
    cout << "==              SIMPLE MATH QUIZ                ==" << endl;
    cout << "==================================================" << endl;
    cout << endl;

    int score = 0;
    int answer;

    for(int i = 1; i <= 5; i++)
    {
        cout << "QUESTION " << i << endl;

        if(i == 1) {
            cout << "WHAT IS 4+8? ";
            cin >> answer;

            if(answer == 12) {
                cout << "GOOD JOB!" << endl;
                score++;
            } else {
                cout << "WRONG!" << endl;
            }
        }

        if(i == 2){
            cout << "WHAT IS 3+3? ";
            cin >> answer;

            if(answer == 6) {
                cout << "GOOD JOB!" << endl;
                score++;
            } else {
                cout << "WRONG!" << endl;
            }
        }

        if(i == 3) {
            cout << "WHAT IS 1+1? ";
            cin >> answer;

            if(answer == 2) {
                cout << "GOOD JOB!" << endl;
                score++;
            } else {
                cout << "WRONG!" << endl;
            }
        }

        if(i == 4) {
            cout << "WHAT IS 3+7? ";
            cin >> answer;

            if(answer == 10) {
                cout << "GOOD JOB!" << endl;
                score++;
            } else {
                cout << "WRONG!" << endl;
            }
        }

        if(i == 5) {
            cout << "WHAT IS 10+10? ";
            cin >> answer;

            if(answer == 20) {
                cout << "GOOD JOB!" << endl;
                score++;
            } else {
                cout << "WRONG!" << endl;
            }
        }
    }

    cout << endl;

    if(score == 5) {
        cout << "WOW! " << "YOUR SCORE IS " << score << "." << endl;
    } else if (score >= 3) {
        cout << "NICE! " <<  "YOUR SCORE IS " << score << "." << endl;
    } else {
        cout << "KEEP PRACTICING! " << "YOUR SCORE IS " << score << "." << endl;
    }
}
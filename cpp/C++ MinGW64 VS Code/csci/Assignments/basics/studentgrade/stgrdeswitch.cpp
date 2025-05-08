#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    //variables
    string name;
    float test1, test2, quiz, lab, final, total;
    char letterGrade;
    int scr;

    //inputs
    cout << "enter full name of student: (no more than 20 characters)" << endl;
    getline(cin, name);
    cout  << endl << "enter numerical grade for test 1, test 2, quiz, lab, and final in that order, \nseparated by a space or new line each time : " << endl;
    cin >> test1 >> test2 >> quiz >> lab >> final;


    //weights
      /*test1 and test2    	each 20%
      lab & quiz		each 15%
      final				30% */

    total = (test1 * 0.20) + (test2 * 0.20) + (quiz * 0.15) + (lab * 0.15) + (final*0.30);

    /* Compute letter grade of total score based of the following;
        Total	 >=90			A
        80 <=Total<90			B
        70<=Total<80			C
        60<=Total<70			D
        Total <60 				F */


    if (total > 100){ 
        cout << " The grade(s) inputted are incorrect or invalid";
        return 0;
    }

    scr = static_cast<int>(total)/10;

    switch (scr){
        case 10:
        case 9:
            letterGrade = 'A';
            break;
        case 8:
            letterGrade = 'B';
            break;
        case 7:
            letterGrade = 'C';
            break;
        case 6:
            letterGrade = 'D';
            break;
        default:
            letterGrade = 'F';
    }

    cout << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << "Student Name"
         << setw(8) << left << "Test 1"
         << setw(8) << left << "Test 2"
         << setw(8) << left << "Quiz"
         << setw(8) << left <<  "Lab"
         << setw(8) << left << "Final"
         << setw(8) << left << "Total"
         << setw(8) << left << "Grade" << endl;

         cout << setw(20) << left << "============="
         << setw(8) << left << "======="
         << setw(8) << left << "======="
         << setw(8) << left << "====="
         << setw(8) << left <<  "==="
         << setw(8) << left << "====="
         << setw(8) << left << "====="
         << setw(8) << left << "=====" << endl;

    cout << setw(20) << left << name 
         << setw(8) << left << test1
         << setw(8) << left << test2
         << setw(8) << left << quiz
         << setw(8) << left << lab 
         << setw(8) << left << final
         << setw(8) << left << total
         << setw(8) << left << letterGrade;


    return 0;
}
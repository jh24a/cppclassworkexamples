#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    //file setup
        ifstream infile ("main.txt");
        ofstream outfile ("main.out");

    //varaibles
        string fname, lname, name;
        float distance, speed, time;

    
   

    for (int i = 0; i<3; i++) {
        //for file
        infile >> fname >> lname >> distance >> speed;
        name = fname + " " + lname;
        time = distance / speed;
        outfile << fixed << showpoint << setprecision(1);
        outfile <<setw(15) << left << name 
                <<setw(6) << right << distance 
                <<setw(6) << right << speed 
                <<setw(6) << right << time << endl;

        //for monitor
        cout << fixed << showpoint << setprecision(1);
        cout <<setw(15) << left << name 
                <<setw(6) << right << distance 
                <<setw(6) << right << speed 
                <<setw(6) << right << time << endl;

    }

    infile.close();    
    return 0;
}
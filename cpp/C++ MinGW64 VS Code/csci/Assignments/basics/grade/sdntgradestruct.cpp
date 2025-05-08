#include <iostream>
#include <fstream> 
#include <iomanip>
using namespace std;

struct studentinfo {
    string name;
    int test1;
    int test2;
    int quiz; 
    int lab; 
    int final;
};

ifstream gradein("grades.txt");
ofstream gradeout("grades.out");

int main(){

    const int size = 5;
    studentinfo students[size];



    return 0;
}
/***************************************/

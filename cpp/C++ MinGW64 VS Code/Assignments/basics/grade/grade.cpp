#include <iostream>
#include  <fstream>
#include <iomanip>
#include <string> 
using namespace std;

void getData(string names[10], double testscores[10][5]);
void average(double testscores[][5], double avg[10]);
void grade(double testscores[][5], char grade[10]);
void print(string names[], double testscores[][5], double avg[10], char grade[]);

ifstream input("grade.txt");
ofstream output("grade.out");



int main(){
  string names[10];
  double testscores[10][5];

  getData(names, testscores);



  return 0;
}
void getData(string names[10], double testscores[10][5]){
  for (int i = 0; i<10; i++){
    input >> names[i];
    for( int j = 0; j <5; j++){
      input >> testscores[i][j];
    }
  }
}
/*****************************************************************/
void average(double testscores[][6], double avg[10]){
    double sum = 0;
    for(int i = 0; i < 10; i++){
      for(int j = 0; j< 5; j++){
        sum = sum + testscores[i][j];
      }
      avg[i] = sum/5.0;
    }

}
/*******************************************************************/
void grade(double avg[10], char grade[10]){
  for (int i = 0; i<10; i++){
    if (avg[i] >= 90)
      grade[i] = 'A';
    else if (  avg[i] >= 80)
      grade[i] = 'B';
    else if (  avg[i] >= 70)
      grade[i] = 'C';
    else if (  avg[i] >= 60)
      grade[i] = 'D';
    else
      grade[i] = 'F';

  }

}
/*****************************************************************/
void print(string names[], double testscores[][6], double avg[10], char grade[]){
  
  output << setw(15) << "Name"
         << setw(7) << "Test 1"
         << setw(7) << "Test 2"
         << setw(7) << "Test 3"
         << setw(7) << "Test 4"
         << setw(7) << "Test 5"
         << setw(8) << "Average"
         << setw(8) << "Grade";

  for (int i = 0; i < 10; i++){
    output << setw(15) <<  names[i];
    for (int j = 0; j< 5 ; j++){
      output << setw(7) << testscores[i][j];
    }
    output << setw(8) << avg[i] << grade[i] << endl;
  }


    cout << setw(15) << "Name"
         << setw(7) << "Test 1"
         << setw(7) << "Test 2"
         << setw(7) << "Test 3"
         << setw(7) << "Test 4"
         << setw(7) << "Test 5"
         << setw(8) << "Average"
         << setw(8) << "Grade";

  for (int i = 0; i < 10; i++){
    cout << setw(15) <<  names[i];
    for (int j = 0; j< 5 ; j++){
      cout << setw(7) << testscores[i][j];
    }
    cout << setw(8) << avg[i] << grade[i] << endl;
  }

}
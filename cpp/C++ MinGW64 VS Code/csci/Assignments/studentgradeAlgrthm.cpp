#include <iostream>
#include <fstream> 
#include <iomanip>
using namespace std;

struct studentinfo {
    string name;
    float test1;
    float test2;
    float quiz; 
    float lab; 
    float final;
    float total;
    char grade;
};

const int size = 5; 

//function prototypes
  void input(studentinfo& mystudent);
  void output(studentinfo mystudent);
  void header();
  void display(studentinfo students[]);
  void total(studentinfo students[]);
  void grade(studentinfo students[]);
  void sortscore(studentinfo students[]);// low to high
  void sortscorehl(studentinfo students[]);//high to low
  void sortname(studentinfo students[]);//alphabetical order
  void sortnamer(studentinfo students[]);//reverse
  void searchscore(studentinfo students[]);
  void searchname(studentinfo students[]);
  void menu(studentinfo students[]);

int main(){
  
  studentinfo students[size];

  for (int i =0; i<size; i++){
    input(students[i]);
    cout<< endl;
  }
  total(students);
  grade(students);
  cout << endl << endl;
  display(students);
  //***//
  cout << endl << endl;
  menu(students);

  return 0;
}
/***************************************/
void input(studentinfo& mystudent){
  string Name;
  float Test1, Test2, Quiz, Lab, Final;

  cout << "Name of Student: ";
  getline(cin,Name);
  cout << "Score of Test 1: ";
  cin >> Test1;
  cout << "Score of Test 2: ";
  cin >> Test2;
  cout << "Score of Lab: ";
  cin >> Lab;
  cout << "Score of Quiz: ";
  cin >> Quiz;
  cout << "Score of Final: ";
  cin >> Final;
  cin.ignore(1);

  mystudent.name = Name;
  mystudent.test1 = Test1;
  mystudent.test2 = Test2;
  mystudent.quiz = Quiz;
  mystudent.lab = Lab;
  mystudent.final = Final;
}
/***************************************/
void output(studentinfo mystudent){

    cout << fixed <<showpoint << setprecision(2);
    cout << left << setw(20) << mystudent.name
    << left << setw(9) << mystudent.test1
    << left << setw(9) << mystudent.test2
    << left << setw(7) << mystudent.lab
    << left << setw(7) << mystudent.quiz
    << left << setw(7) << mystudent.final
    << left << setw(7) << mystudent.total
    << left << setw(7) << mystudent.grade <<endl;

}
/****************************************/
void header(){
      cout << left << setw(20) <<"Student Name"
      << left << setw(9) <<"Test 1"
      << left << setw(9) <<"Test 2"
      << left << setw(7) <<"Lab"
      << left << setw(7) <<"Quiz"
      << left << setw(7) <<"Final"
      << left << setw(7) <<"Total"
      << left << setw(7) <<"Grade"<<endl;
      cout << left << setw(20) <<"============"
      << left << setw(9) <<"======"
      << left << setw(9) <<"======"
      << left << setw(7) <<"==="
      << left << setw(7) <<"===="
      << left << setw(7) <<"====="
      << left << setw(7) <<"====="
      << left << setw(7) <<"====="<<endl;
}
/****************************************/
void display(studentinfo students[]){

  // header
    header();

  //students 
    for (int i = 0; i<size; i++){
      output(students[i]);
    }

}
/****************************************/
void total(studentinfo students[]){
  float tot;

  for (int i = 0; i<size; i++){

    tot = (students[i].test1 *.20) + 
          (students[i].test2 *.20) + 
          (students[i].lab *.15) + 
          (students[i].quiz *.15) + 
          (students[i].final *.30);

    students[i].total = tot;
        
  }
}
/****************************************/
void grade(studentinfo students[]){

  for (int i = 0; i<size; i++){

    if(students[i].total >= 90)
      students[i].grade = 'A';
    else if(students[i].total >= 80)
      students[i].grade = 'B';
    else if( students[i].total >= 70)
      students[i].grade = 'C';
    else if( students[i].total >= 60)
      students[i].grade = 'D';
    else 
      students[i].grade = 'F';
        
  }
}
/***********************************ALGORITHMS*******************************/
void sortscore(studentinfo students[]){
  studentinfo temp;
  for (int i = 0; i< size -1; i++){
    for(int j = 0; j< size -i-1; j++){
      if (students[j].total > students[j+1].total){
        temp = students[j+1];
        students[j+1] = students[j];
        students[j] = temp;
      }
    }
  }

}
/***************************************/
void sortscorehl(studentinfo students[]){
  studentinfo temp;
  for (int i = 0; i< size -1; i++){
    for(int j = 0; j< size -i-1; j++){
      if (students[j].total < students[j+1].total){
        temp = students[j+1];
        students[j+1] = students[j];
        students[j] = temp;
      }
    }
  }

}
/****************************************/
void sortname(studentinfo students[]){ // sorting by first name not last
  studentinfo temp;
  for (int i = 0; i < size -1; i++){
    for (int j = 0 ; j < size - i -1; j++){
      if (students[j].name > students[j+1].name){
        temp = students[j+1];
        students[j+1] = students[j];
        students[j] = temp;
      }
    }
  }
}
/***************************************/
void sortnamer(studentinfo students[]){ //reverse
  studentinfo temp;
  for (int i = 0; i < size -1; i++){
    for (int j = 0 ; j < size - i -1; j++){
      if (students[j].name < students[j+1].name){
        temp = students[j+1];
        students[j+1] = students[j];
        students[j] = temp;
      }
    }
  }
}
/***************************************/
void searchscore(studentinfo students[]){
  float target;
  cout << "What total score are you looing for?(enter exact decimal): ";
  cin >> target;
  cout << endl;

  sortscore(students); //sorts to use binary search from low to high

  int low = 0;
  int high = size-1;
  int mid = 0;
  bool found = false;

  while (low <=high && !found){
    mid = (high + low) / 2;
    if (students[mid].total > target){
      high = mid -1;
    }
    else if(students[mid].total < target){
      low = mid + 1;
    }
    else {
      header();
      output(students[mid]);
      found  = true;
    }
  }
  
}
/****************************************/
void searchname(studentinfo students[]){
  string target;
  cout << "Who are you searching for?(enter exact name): ";
  getline(cin, target);
  cout << endl;

  int low = 0;
  int high = size-1;
  int mid = 0;
  bool found = false;

  while (low <= high && !found){
    mid = (high + low ) / 2;
    if(students[mid].name > target){
      low = mid+1;
    }
    else if (students[mid].name < target){
      high = mid -1;
    }
    else {
      header();
      output(students[mid]);
      found = true;
    }
  }
}
/***************************************/
void menu(studentinfo students[]){
  char retry = 'y';
  while(retry == 'y' || retry == 'Y'){
    int action;
    cout << "Would you like to sort or search? (enter 1 for sort, 2 for search respectively): ";
    cin >> action;
    if (action == 1){ // sort
      cout << "Sort by name or by score? (1/2):";
      cin >> action;
      if(action == 1){ //name  
        sortname(students);
        display(students);
        cout << endl;
      }
        
      else if (action == 2){ //score 
        sortscore(students);
        display(students);
        cout << endl;
      }
    }
    else if (action == 2){ //search
      cout << "Search name or score?(1/2):";
      cin >> action;
      cin.ignore(1);
      if(action == 1){ //name
        searchname(students);
      }

      else if(action == 2){ // score
        searchscore(students);
      }
    }
    cout << "Try again? (y/n): ";
    cin >> retry;
  }
}


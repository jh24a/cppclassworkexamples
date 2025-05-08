#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>
using namespace std;

ifstream input("test.txt");
ofstream output("test.out");



void data(string name[], double balance[], int size);
void getTotal(double balance[], double total[], int size );
void Payment(double tot[], double payment[] , int size);
void Display(string Name[], double Balance[], double Tot[], double payment[], int size );
void header();



int main (){
 /******************/ 
  int accounts;
  cout << "how many accounts are presesnt?: (must be 5 if testing the file ex.)";
  cin >> accounts;
  
  const int size = accounts; // 
//this section is optional, just replace all this with const int size = 5;
 /**********************/

  string name[size];
  double balance[size], total[size], payment[size];

  header();

  data(name, balance,size);
  getTotal(balance,total, size);
  Payment(total, payment, size);
  Display(name, balance, total, payment, size);
  
  input.close();
  output.close();
  return 0;
}

/*************************************************************************/
 void data(string name[], double balance[], int size){
  string name1, name2;
  for ( int i = 0; i < size; i++){
    input >> name1 >> name2 >> balance[i];
    name[i] = name1 + " " + name2;
  }
}

/**************************************/
void getTotal(double balance[], double total[], int size ){

  for ( int i = 0 ; i < size; i++){
    if (balance[i] > 4000.0 ) {
      total[i] = balance[i] + ((balance[i] - 3000)* 0.015) + ((balance[i] - 1000.0)*0.02) + ((balance[i] - 4000.0)*0.03);
    }
    else if (1000.0 <= balance[i] && balance[i] < 4000.0) {
      total[i] = balance[i] + ((balance[i] - 3000)* 0.015) + ((balance[i] - 1000.0)*0.02);
    }
    else if (balance[i] < 1000.0) {
      total[i] = balance[i] + (balance[i]* 0.015);
    }
  }
}

/**************************************/
 void Payment(double tot[], double payment[] , int size){
  

   for ( int i = 0; i< size; i++){
    payment[i] = tot[i]*0.10;

    if (payment[i] < 10.0){
      payment[i] = 10.0;
    }
    if ( tot[i] < 10.0){
      payment[i] = tot[i];
    }
   }
  
}

/***************************************/
 void Display(string Name[], double Balance[], double Tot[], double payment[], int size ){
  for ( int i = 0; i< size; i++){
    output << fixed << left << showpoint << setprecision(2);
    output<< setw(14) << Name[i] 
          << setw(14) << Balance[i] 
          << setw(14) << Tot[i] 
          << setw(10) << payment[i] << endl;
        
    cout << fixed << left << showpoint << setprecision(2);
    cout<< setw(14) << Name[i]
        << setw(14) << Balance[i]
        << setw(14) << Tot[i]
        << setw(10) << payment[i] <<endl;
  }
}



/****************************************/
void header(){

  cout  << left;
  cout  << setw(14) << "Name" 
      << setw(14) << "Balance" 
      << setw(14) << "Total" 
      << setw(10) << "Payment" <<endl;
  cout  << setw(14) << "====" 
      << setw(14) << "=======" 
      << setw(14) << "=====" 
      << setw(10) << "=======" <<endl;

  output  << left;
  output  << setw(14) << "Name" 
      << setw(14) << "Balance" 
      << setw(14) << "Total" 
      << setw(10) << "Payment" <<endl;
  output  << setw(14) << "====" 
      << setw(14) << "=======" 
      << setw(14) << "=====" 
      << setw(10) << "=======" <<endl;


}
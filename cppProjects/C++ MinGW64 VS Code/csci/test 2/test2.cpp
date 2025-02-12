#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream input("test.txt");
ofstream output("test.out");

void data(string& name, double& balance);
double getTotal(double balance );
double Payment(double tot );
void Display(string Name, double Balance, double Tot, double payment );
void header();

int main() {

  string name;
  double balance, totalAmount, minimumPay;
  
  header();

  do{
  
    //getdata
    data(name, balance);

    // get total
    totalAmount = getTotal(balance);

    // get pay
    minimumPay = Payment(totalAmount);

    // display data 
    Display(name, balance ,totalAmount, minimumPay);

  }while(!input.eof());


  input.close();
  output.close();

  return 0;
}

/*******************************************************************************/
void data(string& name, double& balance) {
  string name1, name2;
  input >> name1 >> name2 >> balance;
  name = name1 + " " + name2;
}
/**************************************/
double getTotal(double balance ){
  double total;

  if (balance > 4000.0 ) {
    total = balance + ((balance - 3000)* 0.015) + ((balance - 1000.0)*0.02) + ((balance - 4000.0)*0.03);
  }
  else if (1000.0 <= balance && balance < 4000.0) {
    total = balance + ((balance - 3000)* 0.015) + ((balance - 1000.0)*0.02);
  }
  else if (balance < 1000.0) {
    total = balance + (balance* 0.015);
  }

  return total;
}
/**************************************/
double Payment(double tot ) {
  double minPay;

  minPay = tot*0.10;

  if (minPay < 10.0){
    minPay = 10.0;
  }
  if ( tot < 10.0){
    minPay = tot;
  }

  return minPay;
}
/***************************************/
void Display(string Name, double Balance, double Tot, double payment ) {

  output << fixed << left << showpoint << setprecision(2);
  output<< setw(14) << Name 
        << setw(14) << Balance 
        << setw(14) << Tot 
        << setw(10) << payment<< endl;
      
  cout << fixed << left << showpoint << setprecision(2);
  cout<< setw(14) << Name 
      << setw(14) << Balance 
      << setw(14) << Tot 
      << setw(10) << payment<<endl;

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
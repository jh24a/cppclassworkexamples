#include <iostream>
#include <cmath>
using namespace std;

int main(){

//variables
  float num; //the prime number
  float x, sum = 0;
//input
  cout << " enter an integer: ";
  cin >> num;
//checks its a valid number
  if (num < 0 ){
    cout << "you did not enter a positive number";
    return 0;
  }
//finds factors 
  cout <<"Factors of " << num << " other than 1:" << endl;

  for (int i = num; --i;){
    x = num/i;
    if (floor(x) == ceil(x)){
      cout << x << " ";
      sum = sum + x; // adds all factors together
    }
  }
  
  if ( sum == num){ //sum of all factors other than 1 equals to num,then its prime
    cout  << endl << "The number " << num << " is a prime.";
  }
  else { cout << endl << "The number " << num << " is not a prime.";}
    return 0;
}
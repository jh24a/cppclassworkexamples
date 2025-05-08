#include <iostream>
#include "fruit.h"
using namespace std;

const int size = 5;

void sort(fruitType myfruit[]);
int compare(fruitType myfruit[], string fruit1, string fruit2);
int search(fruitType myfruit[], string key);

int main() {

  fruitType myfruit[size];
  string fruit1, fruit2;
  int index;
  
  myfruit[size].header();
  for (int i = 0; i <size; i++){
    myfruit[i].fillin();
    myfruit[i].display();
  }
  /*
  sort( myfruit);
    myfruit[size].header();
  for (int i = 0; i <size; i++){
    myfruit[i].display();
  }

  string key = "Mango";
  cout << search(myfruit,key);
  */

  cout << "What Fruit would you like to compare? Enter exact fruit names separeated by space: ";
  cin >> fruit1 >> fruit2;

  index = compare(myfruit, fruit1, fruit2);
  myfruit[size].header();
  myfruit[index].display();

  return 0;
}
/***************************************/
void sort(fruitType myfruit[]){
  fruitType temp;

  for (int i = 0; i < size-1; i++){
    for (int j = 0; j< size-i-1; j++){
      if (myfruit[j].getname() > myfruit[j+1].getname()){
        temp = myfruit[j+1];
        myfruit[j+1] = myfruit[j];
        myfruit[j] = temp;
      }
    }
  }

}
/****************************************/
int search(fruitType myfruit[], string key){

  int low = 0;
  int high = size-1;
  int mid = 0;
  bool found = false;

  while (high>=low && found == false){
    mid = (high + low)/2;
    if (myfruit[mid].getname() < key){
      low = mid+1;
    }
    else if (myfruit[mid].getname() > key){
      high = mid-1;
    }
    else{
      //myfruit[mid].display();
      found = true;
    }
  }

  return mid;
}
/*****************************************/
int compare(fruitType myfruit[], string fruit1, string fruit2){

  int index1, index2;
  int sum1, sum2;

  sort(myfruit);
  myfruit[size].header();
  for (int i = 0; i < size; i++){
    myfruit[i].display();
  }

  index1 = search(myfruit, fruit1);
  index2 = search(myfruit, fruit2);

  sum1 = myfruit[index1].getfat() + myfruit[index1].getsugar() + myfruit[index1].getcarbs();

  sum2 = myfruit[index2].getfat() + myfruit[index2].getsugar() + myfruit[index2].getcarbs();

  if (sum1 > sum2){
    return index2;
  }
  else if (sum1 < sum2){
    return index1;
  }

  return -1;
}


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


ifstream input("fruitlist.txt");
ofstream output("fruitfile.out");

class fruitType{

  private:
    string fruitname;
    string color;
    int fat;
    int sugar;
    int carbs;

  public:
    void fillin(){ //mutator
      input >> fruitname >> color >> fat >> sugar >> carbs;
    }

    void header(){ //method
      //monitor
        cout << endl;
        cout << left << setw(15) <<"Fruit Name"
        << left << setw(9) <<"Color"
        << left << setw(9) <<"Fat"
        << left << setw(9) <<"Sugar"
        << left << setw(9) <<"Carbs"<<endl;
        cout << left << setw(15) <<"============"
        << left << setw(9) <<"====="
        << left << setw(9) <<"==="
        << left << setw(9) <<"======"
        << left << setw(9) <<"======"<<endl;
      //file
        output << endl;
        output << left << setw(15) <<"Fruit Name"
        << left << setw(9) <<"Color"
        << left << setw(9) <<"Fat"
        << left << setw(9) <<"Sugar"
        << left << setw(9) <<"Carbs"<<endl;
        output << left << setw(15) <<"============"
        << left << setw(9) <<"====="
        << left << setw(9) <<"==="
        << left << setw(9) <<"======"
        << left << setw(9) <<"======"<<endl;
    }

    void display(){ //method
      //monitor
        cout << fixed <<showpoint << setprecision(2);
        cout << left << setw(15) << fruitname
        << left << setw(9) << color
        << left << setw(9) << fat
        << left << setw(9) << sugar
        << left << setw(9) << carbs <<endl;
      //file
        output << fixed <<showpoint << setprecision(2);
        output << left << setw(15) << fruitname
        << left << setw(9) << color
        << left << setw(9) << fat
        << left << setw(9) << sugar
        << left << setw(9) << carbs <<endl;

    }

    string getname(){ //accesor
      return fruitname;
    }

    int getfat(){ //
      return fat;
    }

    int getsugar(){
      return sugar;
    }

    int getcarbs(){
      return carbs;
    }

    
    

};

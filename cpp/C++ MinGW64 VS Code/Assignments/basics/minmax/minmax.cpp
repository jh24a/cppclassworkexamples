#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
string name, name1, name2 , x , t;
int score , max , min;
ifstream input("Text.txt");
ofstream output("text.out");


input >> name1 >> name2 >> score;
max =-1;
min = 150;
name = name1 + " " + name2;

do {
 input >> name1 >> name2 >> score;
 name = name1 + " " + name2;
 cout << name << " you have a score of: " << score << endl;
 output << name << " you have a score of: " << score << endl;

  //max
 if (max < score) {
  max = score;
  x = name + " " + to_string(max);
 }
  //min
 if (min > score) {
  min = score;
  t = name + " " + to_string(min);
 }

 
} while (!input.eof());// or !input.eof()    -not end of file


cout << "Person with max score is " << x << endl;
cout << "Perosn with min score is " << t << endl;

output << "Person with max score is " << x << endl;
output << "Perosn with min score is " << t << endl;


input.close();
output.close();
return 0;
}

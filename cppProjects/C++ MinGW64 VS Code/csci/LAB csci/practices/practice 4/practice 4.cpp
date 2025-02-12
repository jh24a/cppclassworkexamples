#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;


//math 
/*
int main() {

	//variables
	 long float x;
	 long float y;
	 long float z;

	//inputs
		cout << "enter x:" << endl;
		cin >> x;
		cout  << endl << "enter y:" << endl;
		cin >> y;
		cout << endl << "enter z" << endl;
		cin >> z;

	// processes
		cout << pow(x, y)<<endl;

		cout << pow(x, pow(y, z))<<endl;
		cout << abs(x)<<endl;
		cout << sqrt(pow((x*y), z))<<endl;
	


	return 0;
}
*/

//string
/*
int main() {

	//varaibles
		string s;
		int strLength;
		int middle;
		string s2;

	//inputs
		cout << "what is your string?" << endl;
		cin >> s;

	//calculate leght of string
		strLength = s.length();
		cout << "lenght: " << strLength << endl;

	//create new string
		if (strLength % 2 == 0) {
			middle = strLength / 2; // finds middle of string and then inserts +++
			s2 = s.insert(middle, "+++");
			cout << "your new string is: " << s2 << endl;
		}
		else {
			cout << "string does not have an exact middle";
		}

	return 0;
}
*/


//greatest number 
/*
int main() {

	//variables
		int x;
		int y;
		int z;

	//inputs
		cout << "enter x:" << endl;
		cin >> x;
		cout << endl << "enter y:" << endl;
		cin >> y;
		cout << endl << "enter z:" << endl;
		cin >> z;

	//program
		if (x > y) {
			if (x > z) { cout << x; }
			
		}
		else if (y > z) {
			if (y > z) { cout << y; }
			
		}
		else { cout << z; }
	
	
	

	return 0;
}
*/


//greatest number 2
int main() {

	int array[20] = {};
	int j;
	int n;
	int temp;
	srand(time(0));

	for (int i=0; i <20 ; i++ ) {
		j = rand() % 101;
		array [i]=j;

		cout << setw(5) << right <<array[i];
	}
	
	temp = 0;
	for (int t=0; t<20 ; t++) {
		n = array[t];
		if (temp < n) {
			temp = n;
		}
	}

	cout << endl;
	cout << "the greatest number is: " << temp;

	return 0;
}
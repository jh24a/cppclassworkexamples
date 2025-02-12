#include <iostream>
#include <string>
using namespace std;

//interstate highway numbers
/*
int main() {

	//variables
	int n;
	int p;
	
	
	
	//intput
	cout << "enter highway number: ";
	cin >> n;

	//makes sure that the number is a valid highway number
	if ( n == 0 || n == 100 || (n / 100  != 0 && n/1000 != 0) ) {
		cout << n << " is not a valid highway number";
		return 0;
	}

	//checks for primary
	if (n < 100) {
		if (n % 2 == 0) {
			cout << "the " << n << " is primary, going east/west" << endl;
			
		}
		else {

			cout << "the " << n << " is primary, going north/south " << endl;
		}
	}
	//checks for auxuliary
	else {
		p = n % 100; //finds the highway its serving
			if (p % 2 == 0) {
				cout << " the " << n << " is auxiliary, serving the " << p << ", goingt east/west";
			}
			else {
				cout << " the " << n << " is auxiliary, serving the " << p << ", going north/south";
			}
	}

	return 0;
}
*/

//leap year
/*
int main(){
	//varaibles
	int year;

	//input
	cout << "enter year: ";
	cin >> year;

	// makes sure its a four digit year
	if (year / 10000 != 0) {
		cout << year << " is too early or too late. Enter four digit year";
		return 0;
	}


	//for centry year
	if ( year % 400 == 0 ){
		cout << year << " is a leap year.";
	}

	//for normal leap year
	else if ( year % 4 == 0 ){
		cout << year << " is a leap year.";
	}

	else {
		cout << year << " is not a leap year";
	}

	return 0;
}
*/

int main(){

    //text message "keys"
    const string BFF = "best friend forever";
          string bff = "BFF";

	const string IDK = "I don't know";
          string idk = "IDK";

	const string JK = "just kidding";
          string jk = "JK";

	const string TMI = "too much information";
          string tmi = "TMI";

	const string TTYL = "talk to you later";
          string ttyl = "TTYL";

    //variables
    string tempInput;
	int s; //start of the string  expanded
	int e; // length of string expanded

    cout << "input string: ";
	getline (cin, tempInput);

	for ( int i = 0 ; i <= tempInput.length(); i++){  //makes sure to keep checking for abbreviations

		if ( tempInput.find (bff) != string::npos){    //checks for bff

			s = tempInput.find(bff);
			e = bff.length();

			tempInput.erase(s,e);
			tempInput.insert(s, BFF);

			cout << tempInput << endl;
		}







	}	












    return 0;
}

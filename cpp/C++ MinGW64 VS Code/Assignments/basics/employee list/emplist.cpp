#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Add an employee
void AddEmployee(vector<string> &name, vector<string> &department, 
                 vector<string> &title) {
   string theName;
   string theDept;
   string theTitle;

   cout << endl << "Enter the name to add: " << endl;
   getline(cin, theName);
   cout << "Enter " << theName << "'s department: " << endl;
   getline(cin, theDept);
   cout << "Enter " << theName << "'s title: " << endl;
   getline(cin, theTitle);

   name.push_back(theName);
   department.push_back(theDept);
   title.push_back(theTitle);

   cout << theName << "'s information has been added." << endl;
}

// Delete an employee
void DeleteEmployee(vector<string> &name, vector<string> &department, 
                    vector<string> &title) {
	// FIXME: Ask the user for the employee # to delete, then delete that employee
	int answer, index, nelements = name.size();					
	cout << "Bonjorno, what employee do you wnat to delete?(enter employee's #)(enter  -1 to quit and check list): "<< endl;
	cin >> answer;
	index = answer - 1;
	if (answer == -1){
		cout << "Exiting delete process..." << endl;
	}
	else if (nelements < index){
		cout << "There is no employee to delete,  exiting delete process..." << endl;
	}
	else{
		name.erase(name.begin() + index);
		department.erase(department.begin() + index);
		title.erase(title.begin() + index);
		cout << "Employee #" << answer << "has been deleted" << endl;
	}
}

// List all employees
void ListEmployees(vector<string> &name, vector<string> &department, 
                   vector<string> &title) {
   int nElements;
   int i;

   nElements = name.size();
   if (nElements > 0) {
      cout << endl;
      for (i = 0; i < nElements; ++i) {
         cout << i+1 << ") Name: " << name.at(i) <<
                      ",\tDepartment: " << department.at(i) <<
                      ",\tTitle: " << title.at(i) << endl;
      }
   }
   else {
      cout << endl << "There are no employees to list." << endl;
   }
}

// Get the action the user wants to perform
char GetAction(string prompt) {
   string answer;
   char firstChar;

   firstChar = '?';

   cout << endl << prompt << endl;
   getline(cin, answer);
   while(answer.size() == 0) {
      getline(cin, answer);
   }
   firstChar = toupper(answer[0]);

   return firstChar;
}

int main() {
   const char EXIT_CODE = 'X';
   const string PROMPT_ACTION = "Add, Delete, List or eXit (a,d,l,x): ";

   vector<string> name(0);
   vector<string> department(0);
   vector<string> title(0);

   char userAction;

   userAction = '?';

   // Loop until the user enters the exit code.
   userAction = GetAction(PROMPT_ACTION);

   while (userAction != EXIT_CODE) {
      switch(userAction) {
         case 'A': AddEmployee(name, department, title);
                   break;
         case 'D': DeleteEmployee(name, department, title);
                   break;
         case 'L': ListEmployees(name, department, title);
                   break;
         default : // Do nothing
                   break;
      }

      userAction = GetAction(PROMPT_ACTION);
   }

   return 0;
}
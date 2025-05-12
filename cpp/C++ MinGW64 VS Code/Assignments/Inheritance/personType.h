#ifndef H_personType
#define H_personType


#include <string>
#include <iostream>
using namespace std;


class personType{
public:
    void print() const{
        cout << "First Name: " << firstName << endl
             << "Last Name: " << lastName;
    }

    void setName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

   personType(string first = "", string last = "") {
        firstName = first;
        lastName = last;
    }
 

protected:
    string firstName; 
    string lastName;  
};
#endif
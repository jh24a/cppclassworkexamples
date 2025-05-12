#ifndef doctorType_H
#define doctorType_H

#include "personType.h"
#include <iomanip>

class doctorType : public personType {

public:
    doctorType(string fn = "", string ln = "", string  s = "") : personType(fn, ln) {
        specialty = s;
    }
    void setspecialty(string s) {
        specialty = s;
    }

    string getspecialty() const {
        return specialty;
    }

    void print() const {
        cout << left;
        cout << setw(19)<< "Doctor: " << firstName << " " << lastName
             << endl <<setw(19)<<"Specialty: " << specialty;
    }

protected:
    string specialty;

};
#endif


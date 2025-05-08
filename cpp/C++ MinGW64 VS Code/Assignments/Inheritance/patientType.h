#ifndef H_patientType
#define H_patientType


#include <string>
#include "doctorType.h"
#include "personType.h"
#include "dateType.h"
#include <iomanip>

using namespace std;



class patientType : public personType {
public:
	patientType(int id = 0, string fn = "", string ln = "",
				int bday = 1, int bmnth = 1, int byear = 2000,
				string docfn = "", string docln = "", string docsp = "",
				int admtday = 1, int admtmnth = 1, int admtyear = 2000,
				int dischday = 1, int dischmnth = 1, int dischyear = 2000) : personType(fn,ln){

		ID = id;
		DOF.setdate(bmnth, bday, byear);
		admitDate.setdate(admtmnth, admtday, admtyear);
		dischargeDate.setdate(dischmnth, dischday, dischyear);
		Doctor.setName(docfn, docln); Doctor.setspecialty(docsp);
	}
		
	void setinfo(int id , string fn , string ln ,
				 int bday , int bmnth , int byear ,
				 string docfn , string docln , string docsp ,
				 int admtday , int admtmnth , int admtyear ,
				 int dischday , int dischmnth , int dischyear ) {
		ID = id;
		firstName = fn;
		lastName = ln;
		DOF.setdate(bmnth, bday, byear);
		admitDate.setdate(admtmnth, admtday, admtyear);
		dischargeDate.setdate(dischmnth, dischday, dischyear);
		Doctor.setName(docfn, docln); Doctor.setspecialty(docsp);


	}

	void setID(int id) {
		ID = id;
	}
	int getID() const{
		return ID;
	}

	void setBirthDate(int bDay = 1, int bMth = 1, int bYear = 2000) {
		DOF.setday(bDay);
		DOF.setmonth(bMth);
		DOF.setyear(bYear);
	}
	int getBirthDay() const {
		return DOF.getday();
	}
	int getBirthMonth() const {
		return DOF.getmonth();
	}
	int getBirthYear() const{
		return DOF.getyear();
	}

	void setDoctorName(string fName = "", string lName = "") {
		Doctor.setName(fName, lName);
	}
	void setDoctorSpl(string spl = "") {
		Doctor.setspecialty(spl);
	}
	string getDoctorFName() const {
		return Doctor.getFirstName();
	}
	string getDoctorLName() const{
		return Doctor.getLastName();
	}
	string getDoctorSpl()const {
		return Doctor.getspecialty();
	}

	void setAdmDate(int admDay = 1, int admMth = 1, int admYear = 2000) {
		admitDate.setdate(admMth, admDay, admYear);
	}
	int getAdmDay() const{
		return admitDate.getday();
	}
	int getAdmMonth()const{
		return admitDate.getmonth();
	}
	int getAdmYear() const{
		return admitDate.getyear();
	}

	void setDisDate(int disDay = 1, int disMth = 1, int disYear = 2000) {
		dischargeDate.setdate(disMth, disDay, disYear);
	}
	int getDisDay()const{
		return dischargeDate.getday();
	}
	int getDisMonth() const{
		return dischargeDate.getmonth();
	}
	int getDisYear() const{
		return dischargeDate.getyear();
	}

	void print() const {
		cout << left;
		cout <<setw(19)<< "PATIENT:" << this->getFirstName() <<" "<< this ->getLastName();
		cout << endl << setw(19) << "ID: " << ID << endl;
		cout << setw(19) << "Date of Birth: ";
		DOF.print();
		cout << endl << setw(19) << "Admit Date: ";
		admitDate.print();
		cout << endl << setw(19) << "Discharge Date: ";
		dischargeDate.print();
		cout << endl<<endl;
		Doctor.print();

	}


protected:
	int ID;
	dateType DOF;
	dateType admitDate;
	dateType dischargeDate;
	doctorType Doctor;
};
#endif
#ifndef H_BillType
#define H_BillType

#include <string>
#include <iomanip>
//#include "doctorType.h"
//#include "personType.h"
//#include "dateType.h"

using namespace std;


class billType {

public:
	billType(int id = 0, double pcharges = 0, double dfee = 0, double rfee = 0 ) {
		ID = id;
		pharmcharges = pcharges;
		doctorsfee = dfee;
		roomfee = rfee;
	}

	void setid(int id) {
		ID = id;
	}
	void setpharmcharges(double pcharges) {
		pharmcharges = pcharges;
	}
	void setdoctorsfee(double dfee) {
		doctorsfee = dfee;
	}
	void setroomfee(int rfee) {
		roomfee = rfee;
	}

	int getid() const{
		return ID;
	}
	double getpharmcharges() const{
		return pharmcharges;
	}
	double getdoctorsfee() const{
		return doctorsfee;
	}
	double getroomfee() const {
		return roomfee;
	}

	void print() const {
		cout << fixed << showpoint << setprecision(2) << left;
		cout << "--------------BILL--------------" << endl
			<<setw(19)<< "ID: " << ID << endl
			<< setw(19) << "Pharmacy charges: " << pharmcharges <<"$"<< endl
			<< setw(19) << "Doctor's fee: " << doctorsfee << "$" << endl
			<< setw(19) << "Room fee: " << roomfee <<"$"<< endl
			<< setw(19) << "TOTAL: " << pharmcharges + doctorsfee + roomfee << "$" << endl;
	}


protected:
	int ID;
	double pharmcharges;
	double doctorsfee;
	double roomfee;
};
#endif
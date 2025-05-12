#include "patientType.h"
#include "billType.h"

void printall(patientType, billType);

int main() {
	int id, bd, bm, by, admtd, admtm, admty, dd, dm, dy;
	string pfname, plname;
	string dfname, dlname, dspecial;
	double pharmfee, rmfee, dctrfee;

	cout << "Enter ID#: ";
	cin >> id;
	cout << "Enter first name and last name: ";
	cin >> pfname >> plname;
	cout << "Enter birth month, day and year, separated my space: ";
	cin >> bm >> bd >> by;
	cout << "Enter doctors first name, last name, and specialty: ";
	cin >> dfname >> dlname >> dspecial;
	cout << "Enter  month, day and year of time admitted, separated my space: ";
	cin >> admtm >> admtd >> admty;
	cout << "Enter  month, day and year of time discharged, separated my space: ";
	cin >> dm >> dd >> dy;
	cout << "Enter cost of pharmaceuticals: ";
	cin >> pharmfee;
	cout << "Enter room fee: ";
	cin >> rmfee;
	cout << "Enter doctor's fee: ";
	cin >> dctrfee;

	patientType patient1(id, pfname, plname, bd, bm, by,
						 dfname, dlname, dspecial, admtd,
						 admtm, admty, dd, dm, dy);

	billType bill1(id, pharmfee, rmfee, dctrfee);

	

	printall(patient1,bill1);

	return 0;
}

void printall(patientType patient, billType bill) {
	cout << endl <<"================================"<< endl;
	patient.print();
	cout << endl;
	bill.print();
}

 /*
 *id, pfname, plname, bd, bm, by,
 *dfname, dlname, dspecial, admtd,
 *admtm, admty, dd, dm, dy, 
 *id, pharmfee, rmfee, dctrfee
 *
 */
 


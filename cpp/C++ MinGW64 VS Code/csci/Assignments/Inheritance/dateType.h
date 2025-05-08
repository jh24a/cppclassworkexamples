#ifndef dateType_H
#define dateType_H


class dateType{
public:
	dateType(int month = 1, int day = 1, int year = 2000) {
		Month = month;
		Day = day;
		Year = year;
	}

	void setdate(int month, int day, int year) {
		Month = month;
		Day = day;
		Year = year;
	}

	void setmonth(int month) {
		Month = month;
	}
	int getmonth() const {
		return Month;
	}

	void setday(int day) {
		Day = day;
	}
	int getday() const {
		return Day;
	}

	void setyear(int year){
		Year = year;
	}
	int getyear() const{
		return Year;
	}

	void print() const {
		cout << Month << "/" << Day << "/" << Year;
	}

protected:
	int Month;
	int Day;
	int Year;
};
#endif
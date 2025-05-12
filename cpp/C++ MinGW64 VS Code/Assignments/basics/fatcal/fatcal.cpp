#include <iostream>
using namespace std;

//function prototype/list
int getFat();
int getCalories(int cfat);
void showPercent(int sfat, int scal);

int main() {

    int fat, cal;
    cout << "enter negative number for fat to end program " << endl;
    fat = getFat();
    while (fat > 0) {
        if (fat < 0) { break; }
        cal = getCalories(fat);
        showPercent(fat, cal);
        cout << endl;
        fat = getFat();
    }

    return 0;
}
/******************************************************************************/
int getFat() {

    int ffat;

    cout << "enter fat in grams:";
    cin >> ffat;
    while (ffat == 0) {
        cout << "quantity must be greater than 0, ";
        cout << "enter fat in grams:";
        cin >> ffat;
    }
    return ffat;
}
/******************************************************************************/
int getCalories(int cfat) {
    int maxCal, inputAmount;

    maxCal = cfat * 9;

    cout << "enter number of calories: ";
    cin >> inputAmount;

    while (inputAmount <= 0 || inputAmount > maxCal) {
        cout << "Quantity must be between 0 and " << maxCal << "! ";
        cout << "enter a valid quantity: ";
        cin >> inputAmount;
    }

    return inputAmount;
}
/*****************************************************************************/
void showPercent(int sfat, int scal) {
    float percentCal;
    percentCal = ((sfat*9.0) / scal) * 100;
    cout << " Percentage of calories from fat is " << percentCal << "%.";
}

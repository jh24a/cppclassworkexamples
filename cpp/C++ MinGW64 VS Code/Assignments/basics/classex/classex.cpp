#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    cout << fixed << showpoint << setprecision(2);

    //variables
    float x1,y1,x2,y2, m , b;

    //inputs
    cout << " Enter coordinates for x1, y1, x2, y2, \n each separated by a space or new line:";
    cin >> x1 >> y1 >> x2 >> y2; 
    cout << endl << "your points: " <<"("<<x1<<","<<y1<<")"<<" and " << "("<<x2<<","<<y2<<")"<<endl;

    //slope
    m = (y2 - y1)/(x2 - x1);

    // y intercept
    b = -(m * x1) + y1; // there is a problem here compare first output with this program


    if (x2 - x1 == 0){
         cout << "The equation for this line is x = " << x1 << "\n";
         cout << "This is a vertical line.";
     }
    else if (m == 0){
         cout << "The equation for this line is y = " << y1 << "\n";
         cout << "This is a horizontal line";
     }
    else if (m > 0){
        cout << "The equation for this line is y = " << m << "x + " << b <<"\n";
        cout << "This line is increasing";
    }
    else if (m < 0){
        cout << "The equation for this line is y = " << m << "x + " << b <<"\n";
        cout << "This line is decreasing";
    }

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int sumArray( vector<int> array, int len);
void randomGen( vector<int>& array, int len);

int main(){

    int len;

    cout << "Enter size of the array: ";    
    cin >> len;

    vector<int> array(len);
    
    randomGen(array, len);

    int sum = sumArray(array, len);

    cout << "Sum of randomly generated array: ";
    cout << sum << endl;

    //display array
    cout << "Your array is: ";
    for ( int i = 0; i< len; i++)
        cout << array.at(i) << " ";

    return 0; 
}
/*******************************************/
int sumArray( vector<int> array, int len){
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum = sum + array.at(i);
    }
    return sum;
}
/********************************************/
void randomGen( vector<int>& array, int len){
    srand(time(NULL));
    for (int i = 0; i < len; i++){
        array.at(i) = rand() % 20;
    }
}
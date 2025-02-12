#include <iostream>
using namespace std;

int main(){


    int size, n; // sizee of array and number placed in array
    int  tempN , N = 0 ; // largest number

    cout << " ONLY INTEGERS ALLOWED IN PROGRAM" << endl;

    cout << " enter size of array: ";
    cin >> size;

    int array[size]; // array the size that the user asked for

    for (int i = 0; i< size; i++){//loop that fills array with user input
        cout << "enter number for position " << i << ": ";
        cin >> n;
        array[i] = n;
        
    }

    cout << endl << "Your array: ";
    for (int j = 0; j< size; j++){ // displays numbers in array
        cout << array[j] << " ";
    }

    for (int k = 0; k< size; k++){ // finds the largest number
        tempN = array[k];
        if (tempN > N){
            N = array[k];
        }
    }

    cout << array[0];

    cout << endl <<  "Largest number in array is " << N << "." << endl;
    
    

    return 0;
}
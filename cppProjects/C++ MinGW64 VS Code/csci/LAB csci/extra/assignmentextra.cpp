#include <iostream>
#include <vector>
using namespace std;

int main(){

    string n,  n2;
    cout << "enter number: ";
    cin >> n;

    int size = n.length();

    vector<char> arr(size);

    for(int i = 0; i< size; i++){  //creates string into array
        arr.at(i) = n.at(i);
    }

     for(int i = 0; i< size; i++){ //prints array
        cout << arr.at(i)<< " ";
    }
    cout << endl;


    char temp;
    for( int i = 0; i < size/2; i++){ //reverses array
        temp = arr.at(i);
        arr.at(i) = arr[size - (1+i)];
        arr[(size-1)-i] = temp;
    }


    for(int i = 0; i< size; i++){ //prints reverse array
         cout << arr.at(i)<< " ";
    }
    cout << endl;


    
     for(int i = 0; i< size; i++){ // stores to string
         n.at(i) = arr.at(i);
    }
    cout << n << endl;

/**********************************/

   int numzeros = 0; 
    while (n.at(numzeros) == '0')  // counts up tp the last leading zero
       numzeros++; 
  
    n.erase(0, numzeros);  //erases up to the last leading zero
  
  cout << n <<endl;




    return 0;
}
#include <iostream>

//POINTERS STORE ADRESSES, THEY ARE MADE FOR ADRESSES. 
// the type int* is a type is for int adresses. 
// if we have 'int a' and 'int b', then int* can store &a, &b.

int main() {

    int a = 42;
    int* p = &a; // here, the ampersand is reference operator.
                 // returns the adress of the 
                 // variable it is with

// printing pointer p will give you the adress, but 
// printing pointer p with the dereference operator * will give you
// the value, such as :

    int b = *p;
    std::cout << b << "\n"; // prints 42

    std::cout << p << "\n"; // prints memory location
    std::cout << *p << "\n"; // prints 42

    *p = 23;
    std::cout << *p << "\n"; //prints 23
    std::cout << a << "\n"; // prints 23
    std::cout << b << "\n"; // prints 42

    int* q = p;
    std::cout << "p = " << p << ", *p = " << *p << "\n"; //p = 0x28dd5ffe54, *p = 23
    std::cout << "q = " << q << ", *q = " << *q << "\n"; // q = 0x28dd5ffe54, *q = 23

    int c = 23;
    p = &c;
    std::cout << "p = " << p << ", *p = " << *p << "\n"; //p = 0x28dd5ffe50, *p = 23
    std::cout << "q = " << q << ", *q = " << *q << "\n"; //q = 0x28dd5ffe54, *q = 23


    int x = 21;
    int* w = &x; 

// https://stackoverflow.com/questions/8857857/how-does-the-ampersand-sign-work-in-c


//DEREFERENCING A nullptr CAN LEAD TO UNDEFINED BEHAVIOR.


/*
what is happening inside this function:

bool pointToSameValue(int* a, int* b){
    if (a && b) {                         // here, remember nullptr can be interpreted as an bool, 0 if nullptr or 1 if there is an adress using AND logical expression to check if both have an adress.
        return *a == *b;                  // now it checks if the values of the pointers are the same by dereferencing them
    }
    return !a && !b;                      // in this case (either one is nullptr or both are nullptr), since they can be interpreted as bool, !a is 'not an adress', so if both not adress, 
                                          // it return true, but if only 1 is not an adress, it return false.
}

*/

    return 0;
}
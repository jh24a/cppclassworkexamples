#include <iostream>

int main() {

// to create a dynamic array, create a pointer
// and allocate the size you want (in bytes) and type casting it

char* p = (char*) malloc(8); // this allocates 8 bytes, with char being 1 byte, i
                            // it is now an array of 8 bytes each holding a char (1 byte for each memory cell?)

//this allocated memory is uninitialized. you have to manually initialize
// it before trying to read from it.

for (int i = 0; i < 8; ++i){
    p[i] = 0;                   //what exactly is a byte? a single digit/letter/symbol?
}
std::cout << (void*) p <<"\n"; //why '(void*)'? this line of code prints the adress;
                                // if i remove '(void*)', it does not print anything.
                                // what is happening? shouldn't it print the adress just by stating the variable name?

//to allocate memory for other types, you multiply how many of the type you want by the size of the type with malloc
int* q = (int*) malloc(8 * sizeof(int));
std::cout<<q<<"\n"; //here we just use 'q' without '(void*)'. why?


int* r = (int*) malloc(0); //this result is unsepcified. 
                        // "dereferencing or deallocating this pointer is prohibited"
                        // I am guessing because it leads to undefined behavior. if i do it nothing bad happens


//to deallocate a previously allocated memory chunk, use the 'free' function.
//it takes a single argument - the pointer to the memory chunk to be deallocated

free(p);
free(q); 

//it is very important to deallocate (allocated) memory once it is no longer 
//needed. Otherwise, it becomes wasted, and if you waste a alrge amout of memory,
// your program is at risk of running out of memory.



    return 0;
}
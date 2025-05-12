#include <iostream>
#include <cstdlib>

/*
int sum_size(int* p, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(p + i);

    }

    return sum;
}

int sum_ptrs(int* begin, int* end) {
    int sum = 0;
    for ( int i = 0; *(begin + i) < *end; ++i) {
        sum += *(begin + i);

    }

    return sum;
}
*/

int sum_size(int* p, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += *(p + i);
    }
    return sum;
}

int sum_ptrs(int* begin, int* end) {
    int sum = 0;
    for (int* p = begin; p < end; ++p) {
         sum += *p;
    }
    return sum;
}



int main(){

    const size_t SIZE = 10;
    int a[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int* p = a;

    int size = sum_size(a,SIZE);
    int ptrs = sum_ptrs(a,a+SIZE);

    std::cout <<"tot sum_size: "<< size << "\n";
    std::cout <<"tot sum_ptrs: "<< ptrs << "\n";

    std::cout << (size == ptrs); 


    return 0;
}
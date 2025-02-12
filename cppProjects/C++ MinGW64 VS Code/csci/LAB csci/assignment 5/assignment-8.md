# The summary of a random array

## Description

Your program accepts an array of integers as input, and outputs the sum of all values in the array.

For example, if the array is 

    [11, 23, 15, 9, 12]

Your program should output

    60

If the array is

    [23, 15, 9, 12]

Your program should output

    49


## Requirements

Your submission should include two sub functions.

A function that can randomly generate an array of integers less than 20. This function has the following format

    int* randomGen(int len)

A function that accepts an array and its length as inputs, and outputs the sum. This function has the following format

    int sumArray(int *a, int len)

Please call these two functions in the main function as follows:

    int main()
    {
        int len;
        cin >> len; // ask the user to input the length of the array

        int * array = randomGen(len);

        int sum = sumArray(array);

        cout << sum << endl;
    }
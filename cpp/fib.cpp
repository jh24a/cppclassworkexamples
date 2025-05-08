#include <iostream>
using namespace std;


uintmax_t fib(unsigned int n);


int main(){


	
	int num = 0;

	cout << "please enter a number for fib:";
	cin >> num;

	/*
	//prints each number in sequence until nth iteration
	//only if using recursive solution
	int i = 0;
	while (i < num) {
		cout << fib(i) << "\n";
		i++;
	}
	cout << endl;
	*/
	
	
	//just gives you the final nth iteration number
	//only using recurive solution
	cout << fib(num) << endl;
	

	return 0;

}

uintmax_t fib(unsigned int n){

	/*
	//recursive
	if (n == 0){
		return 0;
	}
	
	if (n == 1){
		return 1;
	}

	return fib(n-1) + fib(n-2);
	*/
	

	//interative 
	//unsigned int prev1 = 1,prev2 = 1,curr = 1; // runs fine at 47 iterations. after around 48? iterations it does what i think is bit overflow because it starts returning wrong or negative inteegers.



	uintmax_t prev1 = 1,prev2 = 1,curr = 1;  // just needed to increase variables size to many of then to fix issue

	for (unsigned int i = 0; i < n; i ++){
		cout << curr << "\n";
		curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}





	return curr;
	
}


// this helped reach iteration 93 of fibonacci numbeers. It is now being limited by INT_MAX that is defined in cpp. 
//what is the next possible solution to reach higher iterations? Some libraries use arrays to be able to store large naumbers
// TODO: attemp to do my own library.






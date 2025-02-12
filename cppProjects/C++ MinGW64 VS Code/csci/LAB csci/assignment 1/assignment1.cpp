#include <iostream>
#include <string>
using namespace std;

int main(){
    //variables
        string s;
        int n;
        int p;

    //inputs
        cout <<"What is your string?:  ";
        cin >> s;
    
    //if there is a negative sign in the front
        if (s.at(0) == '-'){
            for (int i=1; i<s.length(); i++)
            {
                p = static_cast<char>(s.at(i));
                
                if (isdigit(p) == false)
                {
                    return 0;
                }
            
            }
        }
    //if there is no negative sign in the front
        else{
            for (int i=0; i<s.length(); i++)
            {
                p = static_cast<char>(s.at(i));
                
                if (isdigit(p) == false)
                {
                    return 0;
                }
            
            }
        }
    //turning string into number
        n = stoi(s);
        cout << "your string is now the number: " << n;

    return 0;
}
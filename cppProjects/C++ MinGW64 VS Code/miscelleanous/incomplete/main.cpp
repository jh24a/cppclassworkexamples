#include <iostream>
using namespace std;

struct creature {
    int health;
    int x;
    int y;
};


struct enemy : creature {
    int damage;
};

struct player : creature {
    bool weapon;
    int damage;
};


int main(){

    


    return 0;
}

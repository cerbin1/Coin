#include <iostream>
#include <cstdlib>
#include <time.h>

class Coin {
    double x, y;

    void throwACoin() {
        srand((unsigned int) time(NULL));
        x = rand() % 150;
        y = rand() % 150;
    }
    bool check(int otherCoin) {
        if()
    }
};


int main() {
    return 0;
}
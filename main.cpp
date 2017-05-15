#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

class Coin;

Coin *coins;

class Coin {
public:
    double x, y;

    void throwACoin() {
        x = rand() % 150;
        y = rand() % 150;
    }

    bool check(int otherCoin) {
        Coin other = coins[otherCoin];
        double x2 = other.x;
        double y2 = other.y;
        double AB = fabs(sqrt(pow((x - x2), 2.0)) + pow((y - y2), 2.0));
        return 0 <= AB && AB < 22;
    }

};


bool isWon(int i) {
    for (int j = i - 1; j >= 0; --j) {
        if (coins[i].check(j)) {
            cout << "Moneta o wspolrzednych: " << coins[i].x << ", " << coins[i].y << endl;
            cout << "Przeslonila monete o wspolrzednych: " << coins[j].x << ", " << coins[j].y << endl;
            return true;
        }
    }
    return false;
}

int main() {
    srand((unsigned int) time(NULL));
    cout << "Podaj liczbe monet: ";
    int coinsAmount;
    cin >> coinsAmount;

    coins = new Coin[coinsAmount];

    bool result = false;
    int i = 0;
    for (i = 0; i < coinsAmount; ++i) {
        Coin newCoin = Coin();
        newCoin.throwACoin();
        coins[i] = newCoin;
        cout << coins[i].x << ", " << coins[i].y << endl;
        if (isWon(i)) {
            result = true;
            break;
        }
    }
    if (result) {
        cout << "Wygrales w rundzie: " << i + 1 << endl;
    } else {
        cout << "Niestety przegrales" << endl;
    }
    delete[]coins;
    return 0;
}


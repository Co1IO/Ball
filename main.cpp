#include <iostream>
#include "ball.h"
#include <math.h>
using namespace std;

int main() {
    Ball b = Ball(0, 0, 10, 0.785);
    for (int i = 0; i < 15; i++) {
        b.fly(0.2);
        cout << b.GetX() << " " << b.GetY() << endl;
    }
    return 0;
}
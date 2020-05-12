#include <iostream>
#include "ball.h"
#include <math.h>
using namespace std;

int main() {
    Ball b = Ball(0, 0, 10, 0.785);
    b.fly(0.5);
    cout << b.GetX() << " " << b.GetY() << endl;
    b.fly(1);
    cout << b.GetX() << " " << b.GetY() << endl;
    b.fly(1.5);
    cout << b.GetX() << " " << b.GetY() << endl;
    b.fly(2);
    cout << b.GetX() << " " << b.GetY() << endl;
    b.fly(2.5);
    cout << b.GetX() << " " << b.GetY() << endl;
    b.fly(3);
    cout << b.GetX() << " " << b.GetY() << endl;
    b.fly(3.5);
    cout << b.GetX() << " " << b.GetY() << endl;
    b.fly(4);
    cout << b.GetX() << " " << b.GetY() << endl;
    return 0;
}
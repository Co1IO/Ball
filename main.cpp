#include <iostream>
#include "ball.h"
#include <math.h>
using namespace std;

int main() {
    Ball b = Ball(3, 4, 0, 0);
    for (int i = 0; i < 20; i++) {
        b.fly(0.2);
        cout << b.GetX() << " " << b.GetY() << endl;
        
        // getchar();
    }
    return 0;
}
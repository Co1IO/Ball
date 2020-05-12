#ifndef BALL_H
#define BALL_H
#include <math.h>

#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a > b? b : a
const double g = 10;
const double eps = 0.01;

class Ball
{
private:
    double speed_x = 0, speed_y = 0;
    double angle = 0;
    double x0 = 0, y0 = 0;
    double loss = 0;
    double l_border = 0, r_border = 0;
    double x_f = 0, y_f = 0;
    double time = 0;
    bool borders = false;
public:
    Ball() = default;
    Ball(double velocity, double alpha) {
        speed_x = velocity * cos(alpha);
        speed_y = velocity * sin(alpha);
    }
    Ball(double x1, double y1, double velocity, double alpha) {
        x0 = x1;
        y0 = y1;
        speed_x = velocity * cos(alpha);
        speed_y = velocity * sin(alpha);
    }
    Ball(double x1, double y1, double velocity, double alpha, double loss1) {
        Ball(x1, y1, velocity, alpha);
        loss = loss1;
    }
    Ball(double x1, double y1, double velocity, double alpha, double loss1, double l_bord, double r_bord) {
        Ball(x1, y1, velocity, alpha, loss);
        l_border = l_bord;
        r_border = r_bord;
        borders = true;
    }

    double GetSpeed() {
        return sqrt(speed_y * speed_y + speed_x * speed_x);
    }

    void SetCoords(double x1, double y1) {
        x0 = x1;
        y0 = y1;
    }

    double GetAngle() {
        return angle;
    }

    double GetX0(){
        return x0;
    }

    double GetY0(){
        return y0;
    }

    void SetSpeed(double velocity, double alpha) {
        speed_x = velocity * cos(alpha);
        speed_y = velocity * sin(alpha);
    }

    void fly(double t);

    double GetX() {
        return x_f;
    }    

    double GetY() {
        return y_f;
    }

    ~Ball() = default;
};

double square_equaation(double, double, double);

#endif
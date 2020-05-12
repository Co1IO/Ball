#include "ball.h"
#include <math.h>
#include <iostream>


double square_equaation(double a, double b, double c) {    //ax^2 + bx + c = 0
    double D = (b * b - 4 * a * c) / 4;

    if (a == 0 && b == 0) return -1;
    if (a == 0) return -c / b;
    if (D < 0) return -1;
    return MAX((-b/2 - sqrt(D)) / a, (-b/2 + sqrt(D)) / a);
}

void Ball::fly(double t) {

    if (abs(t) <= eps) return;

    double x, y;
    x = x_f;
    y = y_f;

    double t_flyy = 0;
    double t_flyx = 0;
    
    t_flyy = square_equaation( - g / 2, speed_y, y);
    
    if (borders) {
        if (speed_x > 0) {
            t_flyx = (r_border - x) / speed_x;
        }
        if (speed_x < 0) {
            t_flyy = (x - l_border) / (- speed_y);
        }
    }
    else t_flyx = -1;
    
    double t_fly = MIN(t_flyy == -1 ? t_flyx : t_flyy, t_flyx == -1 ? t_flyy : t_flyx);
    if (t_fly == -1) {
        std::cout << "t_fly = -1 ?\n";
        return;
    }

    if (t_fly > t) {
        x_f += speed_x * t;
        y_f += speed_y * t - g * t * t / 2;
        if (borders) {
            if ((l_border - eps <= x_f <= l_border + eps) || (r_border - eps <=  x_f <= r_border + eps)) {
                speed_x = - speed_x * (1 - loss);
                speed_y = speed_y * (1 - loss);
            }
        } 
        if (abs(y_f) <= eps) {
            speed_x = speed_x * (1 - loss);
            speed_y = - speed_y * (1 - loss);
        }
    }

    else {
        x_f += speed_x * t_fly;
        y_f += speed_y * t_fly - g * t_fly * t_fly / 2;
        if (borders) {
            if ((l_border - eps <= x_f <= l_border + eps) || (r_border - eps <=  x_f <= r_border + eps)) {
                speed_x = - speed_x * (1 - loss);
                speed_y = speed_y * (1 - loss);
            }
        } 
        if (abs(y_f) <= eps) {
            speed_x = speed_x * (1 - loss);
            speed_y = - speed_y * (1 - loss);
        }
        this -> fly(t - t_fly);
    }





}
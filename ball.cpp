#include "ball.h"
#include <math.h>
#include <assert.h>
#include <iostream>

double square_equaation(double a, double b, double c) {    //ax^2 + bx + c = 0
    double D = (b * b - 4 * a * c) / 4;
    if (a == 0 && b == 0) return -1;
    if (a == 0) return -c / b;
    if (D < 0) return -1;
    double sol = MAX((-b/2 - sqrt(D)) / a, (-b/2 + sqrt(D)) / a);
    return sol;
}

void Ball::fly(double t) {
    
    if (abs(t) <= eps) return;
    
    double x, y;
    x = this -> x_f;
    y = this -> y_f;

    double t_flyy = 0;
    double t_flyx = 0;
    
    t_flyy = square_equaation( - g / 2, this -> speed_y, y);
    // std::cout << t_flyy << std::endl;
    if (this -> borders) {
        if (this -> speed_x > 0) {
            t_flyx = (this -> r_border - x) / this -> speed_x;
        }
        if (this -> speed_x < 0) {
            t_flyy = (x - this -> l_border) / (- this -> speed_y);
        }
    }
    else t_flyx = -1;
    
    double t_fly = MIN(t_flyy == -1 ? t_flyx : t_flyy, t_flyx == -1 ? t_flyy : t_flyx);
    if (t_fly == -1) {
        return;
    }

    if (t_fly > t) {
        this -> x_f += this -> speed_x * t;
        this -> y_f += this -> speed_y * t - g * t * t / 2;
        if (this -> borders) {
            if ((this -> l_border - eps <= this -> x_f <= this -> l_border + eps) || (this -> r_border - eps <=  this -> x_f <= this -> r_border + eps)) {
                this -> speed_x = - this -> speed_x * (1 - this -> loss);
                this -> speed_y = this -> speed_y - g * t;
                this -> speed_y = this -> speed_y * (1 - this -> loss);
                return;
            }
        } 
        if (abs(this -> y_f) <= eps) {
            this -> speed_x = this -> speed_x * (1 - this -> loss);
            this -> speed_y = this -> speed_y - g * t;
            this -> speed_y = - this -> speed_y * (1 - this -> loss);
            return;
        }
        this -> speed_y = this -> speed_y - g * t;
        return;
    }

    else {
        this -> x_f += this -> speed_x * t_fly;
        this -> y_f += this -> speed_y * t_fly - g * t_fly * t_fly / 2;
        if (this -> borders) {
            if ((this -> l_border - eps <= this -> x_f <= this -> l_border + eps) || (this -> r_border - eps <=  this -> x_f <= this -> r_border + eps)) {
                this -> speed_x = - this -> speed_x * (1 - this -> loss);
                this -> speed_y = this -> speed_y - g * t_fly;
                this -> speed_y = this -> speed_y * (1 - this -> loss);
            }
        } 
        if (abs(this -> y_f) <= eps) {
            this -> speed_y = this -> speed_y - g * t_fly;
            this -> speed_x = this -> speed_x * (1 - this -> loss);
            this -> speed_y = - this -> speed_y * (1 - this -> loss);
        }
        this -> fly(t - t_fly);
    }


}
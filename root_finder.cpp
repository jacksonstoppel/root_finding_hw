#include <cmath>
#include <iostream>
#include <functional>
#include <vector>
#include "root_finder.hpp"


double root_finder::find_error(double x_old, double x_new) {
    return (std::abs(x_new - x_old))/x_old;
}

std::pair<double, std::vector<double>> root_finder::bisection_method(double initial_x1, double initial_x2, double proj_err, double (*func)(double x_val)) {
    double x_1 = initial_x1;
    double x_2 = initial_x2;
    double x_temp;
    int num_iters = 0;
    std::vector<double> x_vals;
    while (find_error(x_1, x_2) > proj_err) {
        num_iters += 1;
        x_temp = (x_1 + x_2)/2;
        x_vals.push_back(x_temp);
        if (std::signbit(func(x_temp)) == std::signbit(func(x_1))) {
            x_1 = x_temp;
        }
        else {
            x_2 = x_temp;
        }
    }
    std::cout << "Number of Iterations for Cubic Spline: " << num_iters << std::endl;

    return {x_temp, x_vals};
}

std::pair<double, std::vector<double>> root_finder::newton_raphson(double x_1, double (*func)(double x_val), double (*func_derivative)(double x_val), double proj_err) {

    double x_2 = x_1 - (func(x_1)/func_derivative(x_1));
    int num_iters = 0;
    std::vector<double> x_vals;
    x_vals.push_back(x_1);
    x_vals.push_back(x_2);
    
    while (std::abs(x_2 - x_1)/x_1 > proj_err) {
        
        x_1 = x_2;
        x_2 = x_1 - (func(x_1)/func_derivative(x_1));
        x_vals.push_back(x_2);
        num_iters += 1;

    }
    std::cout << "Number of Iterations for Newton Raphson: " << num_iters << std::endl;
    
    return {x_2, x_vals};
}
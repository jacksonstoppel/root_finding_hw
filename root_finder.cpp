#include <cmath>
#include <iostream>
#include <functional>
#include <vector>
#include <iomanip>
#include "root_finder.hpp"

// Function to find error
double root_finder::find_error(double x_old, double x_new) {
    return (std::abs((x_new - x_old)/x_old));
};

// Define the bisection function
std::pair<double, std::vector<double> > root_finder::bisection_method(double initial_x1, double initial_x2, double proj_err) {
    // Define initial x_1 and x_2, as well as a temporary x value and the iteration counter
    double x_1 = initial_x1;
    double x_2 = initial_x2;
    double x_temp;
    int num_iters = 0;
    std::vector<double> x_vals;
    // Iterate until error requirement is met
    while (find_error(x_1, x_2) > proj_err) {
        num_iters += 1;
        x_temp = (x_1 + x_2)/2;
        x_vals.push_back(x_temp);
        // Determine which point to "throw out"
        if (std::signbit(func(x_temp)) == std::signbit(func(x_1))) {
            x_1 = x_temp;
        }
        else {
            x_2 = x_temp;
        }
    }
    std::cout << "Number of Iterations for Bisection Method: " << num_iters << std::endl;

    return std::make_pair(x_temp, x_vals);
};

// Define the newton-raphson function
std::pair<double, std::vector<double> > root_finder::newton_raphson(double x_1, double proj_err) {

    // define the initial iteration point, and the matrix that stores x values
    double x_2 = x_1 - (func(x_1)/func_derivative(x_1));
    int num_iters = 1;
    std::vector<double> x_vals;
    x_vals.push_back(x_1);
    x_vals.push_back(x_2);

    // Iterate until the error meets the requirement
    while (std::abs((x_2 - x_1)/x_1) > proj_err) {
        
        x_1 = x_2;
        x_2 = x_1 - (func(x_1)/func_derivative(x_1));
        x_vals.push_back(x_2);
        num_iters += 1;

    }
    std::cout << std::setprecision(17) << "Number of Iterations for Newton Raphson: " << num_iters << std::endl;
    
    return std::make_pair(x_2, x_vals);
};
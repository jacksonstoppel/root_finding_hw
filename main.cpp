#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <gsl/gsl_sf_hyperg.h>
#include "root_finder.hpp"


// Whittaker W for question 3. I hard coded the mu and kappa values in, but in principle these could be variable
double whittaker_W(double z) {
    double a = 0.5 - 1.3 + 0.5;
    double b = 2.0 * 0.5 + 1.0;
    return std::exp(-z / 2.0)*std::pow(z, 0.5 + 0.5)*gsl_sf_hyperg_U(a, b, z);
}

// function for question 1 & 2
double function_q1(double x_val) {
    return pow(x_val, 3) - 7*x_val*x_val + 14*x_val - 5;
};

// derivative fir quesiton 1 & 2
double function_q1_deriv(double x_val) {
    return 3*x_val*x_val - 14*x_val + 14;
};

int main() {

    // Define the root finder for q1 and perform the evaluations
    root_finder rootFinder; 
    rootFinder.func = function_q1;
    rootFinder.func_derivative = function_q1_deriv;
    std::pair<double, std::vector<double> > bisec_meth = rootFinder.bisection_method(-1, 1, 1e-8);
    std::pair<double, std::vector<double> > new_raph = rootFinder.newton_raphson(1.45142, 1e-8);
    
    std::cout << std::setprecision(17) << "Value of intercept for Bisction Method: " << bisec_meth.first << std::endl;
    std::cout << std::setprecision(17) << "Value of intercept for Newton_Raphson Method: " << new_raph.first << std::endl;

    // Define the root finder for q2 and perform the evaluations 
    root_finder rootFinder_2;
    rootFinder_2.func = whittaker_W;
    rootFinder_2.func_derivative = function_q1_deriv;
    std::pair<double, std::vector<double> > bisec_meth_2 = rootFinder_2.bisection_method(0.3, 0.6, 1e-8);
    std::cout << std::setprecision(17) << "Value of intercept for Bisction Method: " << bisec_meth_2.first << std::endl;
};
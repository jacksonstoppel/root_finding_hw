#ifndef ROOT_FINDER_H
#define ROOT_FINDER_H
#include <iostream>
#include <functional>


class root_finder {
    
    public:

        std::function<double()> func;

        std::function<double()> func_derivative;

        std::pair<double, std::vector<double>> root_finder::bisection_method(double initial_x1, double initial_x2, double proj_err, double (*func)(double x_val));

        std::pair<double, std::vector<double>> root_finder::newton_raphson(double x_1, double (*func)(double x_val), double (*func_derivative)(double x_val), double proj_err);

        double root_finder::find_error(double x_old, double x_new);

};

#endif
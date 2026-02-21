#pragma once

#include <functional>
#include <utility>  // std::pair
#include <vector>   // std::vector

class root_finder {
public:
    std::function<double(double)> func;
    std::function<double(double)> func_derivative;

    double find_error(double x_old, double x_new);

    std::pair<double, std::vector<double> >
    bisection_method(double initial_x1, double initial_x2, double proj_err);

    std::pair<double, std::vector<doubl
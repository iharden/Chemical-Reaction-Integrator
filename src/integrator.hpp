#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include <tuple>
#include "class_system.hpp"

#include <boost/numeric/odeint.hpp>
#include <json.hpp>
namespace integrator {

std::tuple<std::vector<std::vector<double>>, std::vector<double>>
    do_integration(nlohmann::json j, state_type init, double t_start, double t_end, double step_init=0.0001, double abs_err=1.0e-06, double rel_err=1.0e-06);
}

#endif // INTEGRATOR_HPP



#include "integrator.hpp"
namespace odeint = boost::numeric::odeint;
using state_type = boost::numeric::ublas::vector<double>;
using matrix_type = boost::numeric::ublas::matrix<double>;

namespace integrator {

std::tuple<std::vector<std::vector<double>>, std::vector<double>> do_integration(const nlohmann::json& j, const state_type& init, double t_start, double t_end, double step_init, double abs_err, double rel_err) {

    //------------------------------------------------------------------------//
    //                                                                        //
    // Generate the System                                                    //
    // ON OUTPUT: The system and Jacobian Matrix and initial concentrations   //
    //------------------------------------------------------------------------//
    class_system sys(j); // sys() calculates dy/dx
    class_system_jacobi sys_mat(sys); // sys_mat() calculates J

    state_type x = init;
    state_type dxdt(sys.numspecies);
    state_type dfdt(sys.numspecies);
    matrix_type J(sys.numspecies, sys.numspecies);

    //-------------------------------------------------------------------------//
    //                                                                         //
    // Define output vectors, observer and call the integration function       //
    // ON OUTPUT: Concentrations and time points                               //
    //-------------------------------------------------------------------------//

    std::vector<std::vector<double>> x_vec(sys.numspecies);
    std::vector<double> times;

    auto obs = [&x_vec, &times](const state_type& x, double t) {
        for(int i=0;i<x.size();++i)
            x_vec[i].push_back(x[i]);
        times.push_back(t);
    };

    auto stepper = odeint::make_controlled<odeint::rosenbrock4<double>>(abs_err, rel_err);
    [[maybe_unused]] size_t steps = odeint::integrate_adaptive(stepper, std::make_pair(sys, sys_mat), x, t_start, t_end, step_init, obs);
    return std::make_tuple(x_vec,times);
}
}

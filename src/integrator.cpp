

#include "integrator.hpp"
using namespace std;
using namespace boost::numeric::odeint;

namespace integrator {

tuple<vector<vector<double>>, vector<double>> do_integration(nlohmann::json j, state_type init, double t_start, double t_end, double step_init, double abs_err, double rel_err) {

    //------------------------------------------------------------------------//
    //                                                                        //
    // Generate the System                                                    //
    // ON OUTPUT: The system and Jacobian Matrix and initial concentrations   //
    //------------------------------------------------------------------------//
    class_system sys(j); // sys() calculates dy/dx
    class_system_matrix sys_mat(sys); // sys_mat calculates J

    state_type x(sys.numspecies, 0.0);
    state_type dxdt(sys.numspecies);
    state_type dfdt(sys.numspecies);
    matrix_type J(sys.numspecies, sys.numspecies);

    for(int i=0;i<x.size();++i)
        x[i] = init[i];

    //-------------------------------------------------------------------------//
    //                                                                         //
    // Define output vectors, observer and call the integration function       //
    // ON OUTPUT: Concentrations and time points                               //
    //-------------------------------------------------------------------------//

    vector<vector<double>> x_vec(sys.numspecies);
    vector<double> times;
    auto obs = [&](state_type x, double t) {
        for(int i=0;i<x.size();++i)
            x_vec[i].push_back(x[i]);
        times.push_back(t);
    };

    auto stepper = make_controlled<rosenbrock4<double>>(abs_err, rel_err);
    size_t steps = integrate_adaptive(stepper, make_pair(sys, sys_mat), x, t_start, t_end, step_init, obs);
    return make_tuple(x_vec,times);
}
}

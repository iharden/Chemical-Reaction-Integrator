#ifndef CLASS_SYSTEM_HPP
#define CLASS_SYSTEM_HPP

#include <cmath>
#include <vector>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <json.hpp>

typedef boost::numeric::ublas::vector< double > state_type;
typedef boost::numeric::ublas::matrix< double > matrix_type;

class class_system
{
public:

    int numspecies{};
    int numreact{};

    std::vector<std::string> labels;  // size == numspecies
    std::vector<double> rates;        // size == numreact
 
    boost::numeric::ublas::matrix<double> coeffs; //size == numspecies, numreact) ; Contains all reaction coefficients of species j to reaction i

    class_system();
    class_system(nlohmann::json j);

    void operator()(const state_type& x, state_type& dxdt, double t);
};

class class_system_matrix {
public:

    int numspecies{};
    int numreact{};
    std::vector<double> rates;
    boost::numeric::ublas::matrix<double> coeffs;
    class_system_matrix();
    class_system_matrix(const class_system&);

    void operator()(const state_type& x, matrix_type& J, const double& t, state_type& dfdt);
};

#endif // CLASS_SYSTEM_HPP

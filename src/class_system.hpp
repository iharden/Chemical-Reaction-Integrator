#ifndef CLASS_SYSTEM_HPP
#define CLASS_SYSTEM_HPP

#include <cmath>
#include <vector>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <json.hpp>

class class_system
{
public:

    size_t numspecies{};
    size_t numreact{};

    std::vector<std::string> labels;  // size == numspecies
    std::vector<double> rates;        // size == numreact
 
    boost::numeric::ublas::matrix<double> coeffs; //size == numspecies, numreact) ; Contains all reaction coefficients of species j to reaction i

    class_system() = default;
    class_system(const nlohmann::json& j);

    void operator()(const boost::numeric::ublas::vector<double>& x, boost::numeric::ublas::vector<double>& dxdt, double /*t*/);
};

class class_system_jacobi {
public:

    size_t numspecies{};
    size_t numreact{};
    std::vector<double> rates;
    boost::numeric::ublas::matrix<double> coeffs;

    class_system_jacobi() = default;
    class_system_jacobi(const class_system&);

    void operator()(const boost::numeric::ublas::vector<double>& x, boost::numeric::ublas::matrix<double>& J, const double& /*t*/, boost::numeric::ublas::vector<double>& dfdt);
};

#endif // CLASS_SYSTEM_HPP

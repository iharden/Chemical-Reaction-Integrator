#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <QString>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>

#include <boost/algorithm/string.hpp>
#include <json.hpp>

namespace functions{
std::vector<std::string> get_stdstring(const std::vector<QString>& lines);
std::vector<QString> get_qstring(const std::vector<std::string>& lines);
nlohmann::json setup_json(std::vector<std::string> lines, const std::vector<double>& forward_rates, const std::vector<double>& backward_rates);
std::vector<double> convert_rates(const std::vector<double>& rates, double T, bool energyinput, const QString& energyunit="");


}
#endif // FUNCTIONS_HPP

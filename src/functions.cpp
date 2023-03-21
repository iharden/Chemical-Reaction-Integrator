#include <exception>
#include <algorithm>
#include <cctype>
#include <iostream>
#include "functions.hpp"

using std::vector;
using std::string;

namespace functions {
vector<string> get_stdstring(const vector<QString>& lines) {

    vector<string> strings(lines.size());
    transform(lines.begin(), lines.end(), strings.begin(), [](const QString& s) {return s.toStdString(); });
    return strings;
}

vector<QString> get_qstring(const vector<string>& lines) {

    vector<QString> strings(lines.size());
    transform(lines.begin(), lines.end(), strings.begin(), [](const string& s) {return QString::fromStdString(s); });
    return strings;
}

nlohmann::json setup_json(vector<string> lines, const vector<double>& forward_rates, const vector<double>& backward_rates) {

    if (lines.empty())
        throw std::runtime_error("You have to specify at least one reaction equation!");

    if(lines.size()!=forward_rates.size())
        throw std::runtime_error("Not for all reactions a rate constant or energy barrier was specified (or vice versa :) )!");

    for (const string& s : lines) {
        if (s.find("->") == string::npos)
            throw std::runtime_error("At least one reaction equation does not contain ->");
    }

    nlohmann::json j;
    vector<string> res{};
    vector<string> all_reactands, all_products;

    int idx = 0;
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string abc = "abcdefghijklmnopqrstuvwxyz";
    string onetwothree = "1234567890";
    string tmp;

    for (int lc=0;lc<lines.size();++lc) {
        //remove whitespaces
        lines[lc].erase(remove_if(lines[lc].begin(), lines[lc].end(), [](unsigned char x) {return isspace(x); }), lines[lc].end());

        // make reactands and products
        boost::split(res, lines[lc], boost::is_any_of("->"), boost::token_compress_on);

        // split reactands and products
        all_reactands.clear();
        all_products.clear();

        if(res[0].find("+") != string::npos)
            boost::split(all_reactands, res[0], boost::is_any_of("+"), boost::token_compress_on);
        else
            all_reactands.push_back(res[0]);

        if(res[1].find("+") != string::npos)
            boost::split(all_products, res[1], boost::is_any_of("+"), boost::token_compress_on);
        else
            all_products.push_back(res[1]);

        string coeff;
        string chem;
        vector<int> react_coeff;
        vector<string> react_chem;

        // get from each reactand/product coefficient and label - stored in react_coeff, react_chem, prod_coeff_prod_chem: vectors which contain all informations of 1 overall equation
        for(int i = 0;i < all_reactands.size();++i) {
            coeff.clear();
            chem.clear();
            tmp = all_reactands[i];

            // check if there is a number in reactant
            // maybe better approach: Check only if first char is number, if true check if second char is a number etc. Needs a while Loop
            for(int j = 0;j < tmp.size();++j) {
                if(onetwothree.find(tmp[j]) != string::npos)
                    coeff.push_back(tmp[j]);
            }

            if(coeff != "")
                react_coeff.push_back(stoi(coeff));
            else
                react_coeff.push_back(1);

            // get each letter and transform it into capital letters
            for(int j = 0;j < tmp.size();++j) {
                if(abc.find(tmp[j]) != string::npos)
                    tmp[j] = toupper(tmp[j]);

                if(ABC.find(tmp[j]) != string::npos)
                    chem.push_back(tmp[j]);
            }
            react_chem.push_back(chem);
        }

        vector<int> prod_coeff;
        vector<string> prod_chem;

        for(int i = 0;i < all_products.size();++i) {
            coeff.clear();
            chem.clear();
            tmp = all_products[i];
            for(int j = 0;j < tmp.size();++j) {
                if(onetwothree.find(tmp[j]) != string::npos)
                    coeff.push_back(tmp[j]);
            }
            if(coeff != "")
                prod_coeff.push_back(stoi(coeff));
            else
                prod_coeff.push_back(1);

            for(int j = 0;j < tmp.size();++j) {
                if(abc.find(tmp[j]) != string::npos)
                    tmp[j] = toupper(tmp[j]);

                if(ABC.find(tmp[j]) != string::npos)
                    chem.push_back(tmp[j]);
            }
            prod_chem.push_back(chem);
        }

        // setup JSON object
        j["reactions"][idx]["reactands"]["Coeffs"] = react_coeff;
        j["reactions"][idx]["reactands"]["Labels"] = react_chem;

        j["reactions"][idx]["products"]["Coeffs"] = prod_coeff;
        j["reactions"][idx]["products"]["Labels"] = prod_chem;

        j["reactions"][idx]["rates"] = forward_rates[lc];

        ++idx;

        // Check if a backward reaction was required
        if(backward_rates[lc]!=-1.0) {

            j["reactions"][idx]["reactands"]["Coeffs"] = prod_coeff;
            j["reactions"][idx]["reactands"]["Labels"] = prod_chem;

            j["reactions"][idx]["products"]["Coeffs"] = react_coeff;
            j["reactions"][idx]["products"]["Labels"] = react_chem;

            j["reactions"][idx]["rates"] = backward_rates[lc];
            idx++;
        }

    }

    return j;
}

vector<double> convert_rates(const vector<double>& r, double T, bool energyinput, const QString& energyunit) {

    constexpr double R  = 8.31446261815324;
    constexpr double kB = 1.3380649e-23;
    constexpr double h  = 6.62607015e-34;

    const double kbT = kB*T;
    const double RT  = R*T;
    double CF  = 0.0;

    vector<double> rates = r;

    if(energyinput==false)
        return rates;

    if(energyunit=="kcal")
        CF=4.184*1000;
    if(energyunit=="ev")
        CF=96485.30749925791;
    if(energyunit=="hartree")
        CF=2625.5002*1000;

    for(auto& x:rates)
        if(x>0)                     //necessary to catch negative energies from optional backward reactions
            x=kbT/h*exp(-x*CF/RT);

    return rates;
}
}

#include <exception>
#include <algorithm>
#include <cctype>
#include <iostream>
#include "functions.hpp"
using namespace std;
using namespace nlohmann;
using namespace boost;

namespace functions {
vector<string> get_stdstring(vector<QString> lines) {

    vector<string> strings;
    for_each(lines.begin(), lines.end(), [&strings](const QString& s) {strings.push_back(s.toStdString());});
    return strings;
}

vector<QString> get_qstring(vector<string> lines) {

    vector<QString> strings;
    for_each(lines.begin(), lines.end(), [&strings](const string& s) {strings.push_back(QString::fromStdString(s));});
    return strings;
}

json setup_json(vector<string> lines, vector<double> forward_rates, vector<double> backward_rates) {

    json j;
    vector<string> res{};
    vector<string> all_reactands, all_products;

    if(lines.size()!=forward_rates.size())
        throw runtime_error("Not for all reactions a rate constant oder energy barrier was specified (or vice versa :) )!");

    for (string s : lines) {
        if (s.find("->") == string::npos)
            throw runtime_error("At least one reaction equation does not contain ->");
    }

    int idx = 0;
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string abc = "abcdefghijklmnopqrstuvwxyz";
    string onetwothree = "1234567890";
    string tmp;

    for (int i=0;i<lines.size();++i) {
        //remove whitespaces
        lines[i].erase(remove_if(lines[i].begin(), lines[i].end(), [](unsigned char x) {return isspace(x); }), lines[i].end());
        // make reactands and products
        split(res, lines[i], is_any_of("->"), token_compress_on);

        // split reactands and products
        all_reactands.clear();
        all_products.clear();

        if(res[0].find("+") != string::npos)
            split(all_reactands, res[0], is_any_of("+"), token_compress_on);
        else
            all_reactands.push_back(res[0]);
        if(res[1].find("+") != string::npos)
            split(all_products, res[1], is_any_of("+"), token_compress_on);
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

        j["reactions"][idx]["rates"] = forward_rates[i];

        ++idx;

        // Check if a backward reaction was required
        if(backward_rates[i]!=-1.0) {

            j["reactions"][idx]["reactands"]["Coeffs"] = prod_coeff;
            j["reactions"][idx]["reactands"]["Labels"] = prod_chem;

            j["reactions"][idx]["products"]["Coeffs"] = react_coeff;
            j["reactions"][idx]["products"]["Labels"] = react_chem;

            j["reactions"][idx]["rates"] = backward_rates[i];
            idx++;
        }

    }

    return j;
}

vector<double> convert_rates(const vector<double>& r, double T, bool energyinput, QString energyunit) {

    const double R=8.31446261815324;
    const double kB=1.3380649e-23;
    const double h=6.62607015e-34;

    double kbT = kB*T;
    double RT  = R*T;
    double CF=0.0;

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

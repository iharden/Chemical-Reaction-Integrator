#include "class_system.hpp"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace nlohmann;

class_system::class_system()
{

}

class_system::class_system(json J) {

    //GET NUMBER OF LABELS AND SORT THEM - this determines the size of vector<state_type>

    numreact=J["reactions"].size();

    for(int i=0;i<numreact;++i) {
        for(int j=0;j<J["reactions"][i]["reactands"]["Labels"].size();++j)
            labels.push_back(J["reactions"][i]["reactands"]["Labels"][j]);
        for(int j=0;j<J["reactions"][i]["products"]["Labels"].size();++j)
            labels.push_back(J["reactions"][i]["products"]["Labels"][j]);

        rates.push_back(J["reactions"][i]["rates"]);
    }
    sort(labels.begin(),labels.end());
    labels.erase(unique(labels.begin(),labels.end()),labels.end());

    numspecies=labels.size();

    string label;
    vector<string> tmp_labels;
    int idx;

    coeffs.resize(numspecies, numreact);
    for (int i = 0; i < numspecies;++i) {
        for (int j = 0;j < numreact;++j) {
            coeffs(i, j) = 0;
        }
    }

    for (int i = 0; i < labels.size();++i) {
        label = labels[i];
        for (int j = 0;j < numreact;++j) {
            tmp_labels.clear();
            for(int z=0;z< J["reactions"][j]["reactands"]["Labels"].size();++z)
                tmp_labels.push_back(J["reactions"][j]["reactands"]["Labels"][z]);

            auto it = find(tmp_labels.begin(), tmp_labels.end(), label);

            if (it != tmp_labels.end()) {
                idx = distance(tmp_labels.begin(), it);
                coeffs(i,j) = J["reactions"][j]["reactands"]["Coeffs"][idx];
                coeffs(i,j) *= -1.0;
            }

            tmp_labels.clear();
            for (int z=0;z < J["reactions"][j]["products"]["Labels"].size();++z)
                tmp_labels.push_back(J["reactions"][j]["products"]["Labels"][z]);

            it = find(tmp_labels.begin(), tmp_labels.end(), label);
            if (it != tmp_labels.end()) {
                idx = distance(tmp_labels.begin(), it);
                coeffs(i,j) = J["reactions"][j]["products"]["Coeffs"][idx];
                coeffs(i,j) *= 1.0;
            }
        }
    }
}

void class_system::operator()(const state_type& x, state_type& dxdt, double t) {

    for(int i=0;i<numspecies;++i) {
        dxdt[i] = 0;
        for(int j=0;j<numreact;++j) {
            double tmp = 1;
            if(coeffs(i,j) != 0) {                     // is species i in reaction j?
                for(int k=0;k<numspecies;++k) {        // go to specific reaction j
                    if(coeffs(k,j) < 0) {              // is species k educt in reaction j? Only educts contribute to ODE!
                        tmp *= pow(x[k],-coeffs(k,j)); // minus sign because edcuts have negative coefficients, but we need of course the absolute value
                    }
                }            
                dxdt[i] += (coeffs(i,j) * rates[j]*tmp);        // We don't have to check for whether it is product or educt, because this is implicit in coeffs(i,j)
            }
        }
    }
}

class_system_matrix::class_system_matrix(const class_system& sys) {

    numspecies = sys.numspecies;
    numreact = sys.numreact;
    coeffs = sys.coeffs;
    rates = sys.rates;

}

void class_system_matrix::operator()(const state_type& x, matrix_type& J, const double& t, state_type& dfdt) {

    for (int i = 0; i < numspecies;++i) {
        for (int j = 0;j < numspecies;++j) {
            J(i, j) = 0.0;
            for (int k = 0;k < numreact;++k) {
                double tmp = 1;
                if (coeffs(i, k) != 0 && coeffs(j,k) < 0) {                                 // species i in reaction k and species j is educt?
                    for (int l = 0;l < numspecies;++l) {                                    // go to specific reaction k
                        if (coeffs(l, k) < 0) {                                             // species l educt in reaction k?
                            if (l == j) {                                                   // species l the species for that you need derivate?
                                tmp *= -coeffs(l, k) * pow(x[l], -coeffs(l, k) - 1.0);        // d/dt (x^t) = t*x^(t-1)
                            }
                            if (l != j) {                                               
                                tmp *= pow(x[l], -coeffs(l, k));
                            }
                        }
                    } // l
                    J(i, j) += (coeffs(i, k) * rates[k] * tmp);
                }
            } // k
        } // j
        dfdt[i] = 0.0;
    } //i
}

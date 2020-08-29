#ifndef TURBULANCECALCULATOR_H
#define TURBULANCECALCULATOR_H

#include <cmath>
#include <tuple>

namespace TurbulanceCalculator
{

void menu();

double omega_from_k_epsilon(double k, double epsilon);
double epsilon_from_k_omega(double k, double omega);
std::tuple<double, double, double> turbulence_variables_from_intensity_length_scale(double u, double tu, double tul);
std::tuple<double, double, double> turbulence_variables_from_intensity_eddy_viscosity_ratio(double u, double tu, double ni, double mi);
double intensity_from_k(double u, double k);
double TuL_from_k_epsilon(double k, double epsilon);
double TuL_from_k_omega(double k, double omega);
double eddy_viscosity_ratio_from_k_epsion(double k, double epsilon, double ni);
double eddy_viscosity_ratio_from_k_omega(double k, double omega, double ni);

}

#endif // TURBULANCECALCULATOR_H

#ifndef TURBULANCECALCULATOR_H
#define TURBULANCECALCULATOR_H

#include "menu.h"

#include <iostream>
#include <cmath>
#include <string>

namespace TurbulanceCalculator
{
struct CalcResult
{
    double U{0.0};
    double k{0.0};
    double epsilon{0.0};
    double omega{0.0};
    double tu{0.0};
    double tul{0.0};
    double ni{0.0};
    double mitMi{0.0};

};
struct CalcResultNames
{
    std::string U{"Freestream velocity U"};
    std::string k{"Turbulence kinetic energy k"};
    std::string epsilon{"Turbulence dissipation \u03B5"};
    std::string omega{"Specific turbulence dissipation \u03C9"};
    std::string tu{"Turbulence intensity/level Tu"};
    std::string tul{"Turbulence length scale TuL"};
    std::string ni{"Kinematic viscosity \u03BD"};
    std::string mitMi{"Eddy viscosity ratio \u03BCt/\u03BC"};
};



void menu();

CalcResult omega_from_k_epsilon(double k, double epsilon);
void omega_from_k_epsilonCalc();
CalcResult epsilon_from_k_omega(double k, double omega);
void epsilon_from_k_omegaCalc();
CalcResult turbulence_variables_from_intensity_length_scale(double u, double tu, double tul);
void turbulence_variables_from_intensity_length_scaleCalc();
CalcResult turbulence_variables_from_intensity_eddy_viscosity_ratio(double u, double tu, double ni, double mi);
void turbulence_variables_from_intensity_eddy_viscosity_ratioCalc();
CalcResult intensity_from_k(double u, double k);
void intensity_from_kCalc();
CalcResult TuL_from_k_epsilon(double k, double epsilon);
void TuL_from_k_epsilonCalc();
CalcResult TuL_from_k_omega(double k, double omega);
void TuL_from_k_omegaCalc();
CalcResult eddy_viscosity_ratio_from_k_epsion(double k, double epsilon, double ni);
void eddy_viscosity_ratio_from_k_epsionCalc();
CalcResult eddy_viscosity_ratio_from_k_omega(double k, double omega, double ni);
void eddy_viscosity_ratio_from_k_omegaCalc();
}

#endif // TURBULANCECALCULATOR_H

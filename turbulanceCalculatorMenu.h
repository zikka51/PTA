#ifndef TURBULANCECALCULATORMENU_H
#define TURBULANCECALCULATORMENU_H

#include "menu.h"
#include "turbulanceCalculator.h"

#include <iostream>
#include <string>
#include <tuple>


namespace TurbulanceCalculatorMenu
{
struct CalcResultNames
{
    std::string U{"Freestream velocity U [m/s]"};
    std::string k{"Turbulence kinetic energy k [m^2 / s^2]"};
    std::string epsilon{"Turbulence dissipation ɛ [m^2 / s^3]"};
    std::string omega{"Specific turbulence dissipation ω [1/s]"};
    std::string tu{"Turbulence intensity/level Tu [%]"};
    std::string tul{"Turbulence length scale TuL [m]"};
    std::string ni{"Kinematic viscosity ν [m^2/s]"};
    std::string mitMi{"Eddy viscosity ratio μt/μ []"};
};

void menu();

void omega_from_k_epsilonCalc();
void epsilon_from_k_omegaCalc();
void turbulence_variables_from_intensity_length_scaleCalc();
void turbulence_variables_from_intensity_eddy_viscosity_ratioCalc();
void intensity_from_kCalc();
void TuL_from_k_epsilonCalc();
void TuL_from_k_omegaCalc();
void eddy_viscosity_ratio_from_k_epsionCalc();
void eddy_viscosity_ratio_from_k_omegaCalc();

}

#endif // TURBULANCECALCULATORMENU_H

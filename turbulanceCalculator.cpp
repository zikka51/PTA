#include "turbulanceCalculator.h"


namespace TurbulanceCalculator
{

double omega_from_k_epsilon(double k, double epsilon)
{
    double omega = epsilon / (k * 0.09);

    return omega;
}



double epsilon_from_k_omega(double k, double omega)
{
    double epsilon = omega * k * 0.09;

    return epsilon;
}


std::tuple<double, double, double> turbulence_variables_from_intensity_length_scale(double u, double tul, double tu)
{
    double k = 1.5 * std::pow(tu/100.0, 2) * std::pow(u, 2);
    double epsilon = 0.09 * std::pow(k, 1.5) / tul;
    double omega = epsilon / (0.09 * k);

    return std::make_tuple(k, epsilon, omega);
}



std::tuple<double, double, double> turbulence_variables_from_intensity_eddy_viscosity_ratio(double u, double tu, double ni, double mi)
{
    double k = 1.5 * std::pow(tu/100.0, 2) * std::pow(u, 2);
    double epsilon = 0.09 * std::pow(k, 2) / (ni * mi);
    double omega = epsilon / (0.09 * k);

    return std::make_tuple(k, epsilon, omega);
}


double intensity_from_k(double u, double k)
{
    double tu = 100 * std::pow((2 * k / 3), 0.5) / u;

    return tu;
}


double TuL_from_k_epsilon(double k, double epsilon)
{
    double tul = 0.09 * std::pow(k, 1.5) / epsilon;

    return tul;
}


double TuL_from_k_omega(double k, double omega)
{
    double tul = std::pow(k, 0.5) / omega;

    return tul;
}


double eddy_viscosity_ratio_from_k_epsion(double k, double epsilon, double ni)
{
    double mi = (0.09 * std::pow(k, 2)) / (ni * epsilon);

    return mi;
}


double eddy_viscosity_ratio_from_k_omega(double k, double omega, double ni)
{
    double mi = k / (ni * omega);

    return mi;
}


}

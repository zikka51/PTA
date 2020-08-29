#include "ypCalculator.h"


namespace YpCalculator
{

std::tuple<double, double> calculateYP(double u, double rho, double mu, double l, double yp)
{

    double re = (rho * u * l) / mu;

    double c_f= std::pow((2*std::log(re)/std::log(10)-0.65),-2.3);
    double tau_w = c_f * 0.5 * rho * u * u;
    double u_f = std::sqrt(tau_w/rho);

    double d = (yp * mu)/(u_f * rho);

    return std::make_tuple(re,d);
}

}

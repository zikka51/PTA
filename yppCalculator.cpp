#include "yppCalculator.h"


namespace YppCalculator
{

YPdata calculateYPP(double u, double rho, double mu, double l, double yp)
{
    YPdata res;
    res.u = u;
    res.rho = rho;
    res.mu = mu;
    res.l = l;
    res.yp = yp;

    res.re = (res.rho * res.u * res.l) / res.mu;
    double c_f= std::pow((2*std::log(res.re)/std::log(10)-0.65),-2.3);
    std::cout << c_f << '\n';
    double tau_w = c_f * 0.5 * res.rho * res.u * res.u;
    double u_f = std::sqrt(tau_w/res.rho);

    res.d = (res.yp * res.mu)/(u_f * res.rho);
    std::cout << "Reynolds: " << res.re << ", distance: " << res.d << '\n';
    return res;
}

}

#include "turbulanceCalculator.h"


namespace TurbulanceCalculator
{

CalcResultNames varNames;

void menu()
{
    std::string opt[]{"9",
        "Calculate omega from k and epsilon",
        "Calculate epsilon from k and omega",
        "k, epsilon, omega from freestream velocity, turbulance intensity, length-scale",
        "k, epsilon, omega from turbulance intensity, eddy viscosity, freestream velocity, kinematic viscosity",
        "Turbulence intensity from turbulence kinetic energy and freestream velocity",
        "Turbulence length scale from turbulence kinetic energy and dissipation",
        "Turbulence length scale from turbulence kinetic energy and specific dissipation",
        "Turbulence eddy viscosity ratio from turbulence kinetic energy and dissipation",
        "Turbulence eddy viscosity ratio from turbulence kinetic energy and specific dissipation"
       };
    std::cout << "Turbulance Calculator\n";
    int m{Menu::menu(opt)};
    switch (m)
    {
    case 1:
        omega_from_k_epsilonCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 2:
        epsilon_from_k_omegaCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 3:
        turbulence_variables_from_intensity_length_scaleCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 4:
        turbulence_variables_from_intensity_eddy_viscosity_ratioCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 5:
        intensity_from_kCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 6:
        TuL_from_k_epsilonCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 7:
        TuL_from_k_omegaCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 8:
        eddy_viscosity_ratio_from_k_epsionCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 9:
        eddy_viscosity_ratio_from_k_omegaCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case 0:
        break;
    default:
        system("clear");
        std::cout << "Option " << m << " does not exist, Please try again.\n";
        menu();
        break;
    }
}


CalcResult omega_from_k_epsilon(double k, double epsilon)
{
    CalcResult res;
    res.k = k;
    res.epsilon = epsilon;

    res.omega = res.epsilon / (res.k * 0.09);

    return res;
}

void omega_from_k_epsilonCalc()
{
    std::cout << "\u03C9 from k and \u03B5 using \u03B2* = C\u03BC = 0.09\n";

    CalcResult res{epsilon_from_k_omega(Menu::readValueInput(varNames.k),
                            Menu::readValueInput(varNames.epsilon))};

    std::cout <<  "\u03C9: " << res.omega << '\n';

}

CalcResult epsilon_from_k_omega(double k, double omega)
{
    CalcResult res;
    res.k = k;
    res.omega = omega;

    res.epsilon = res.omega * res.k * 0.09;

    return res;
}

void epsilon_from_k_omegaCalc()
{
    std::cout << "\u03C9 from k and \u03B5 using \u03B2* = C\u03BC = 0.09\n";

    CalcResult res{epsilon_from_k_omega(Menu::readValueInput(varNames.k),
                                        Menu::readValueInput(varNames.omega))};

    std::cout << "\u03B5: " << res.epsilon << '\n';
}

CalcResult turbulence_variables_from_intensity_length_scale(double u, double tul, double tu)
{
    CalcResult res;
    res.U = u;
    res.tul = tul;
    res.tu = tu;

    res.k = 1.5 * std::pow(res.tu/100.0, 2) * std::pow(res.U, 2);
    res.epsilon = 0.09 * std::pow(res.k, 1.5) / res.tul;
    res.omega = res.epsilon / (0.09 * res.k);

    return res;
}

void turbulence_variables_from_intensity_length_scaleCalc()
{
    std::cout << "Turbulence variables (k, epsilon, omega) from turbulence intensity (Tu), "
                 "length-scale (TuL) and freestream velocity (U)\n";

    CalcResult res{turbulence_variables_from_intensity_length_scale(
                            Menu::readValueInput(varNames.U),
                            Menu::readValueInput(varNames.tul),
                            Menu::readValueInput(varNames.tu))};

    std::cout << "k: " << res.k << ", \u03B5: " << res.epsilon << ", \u03C9: " << res.omega << '\n';

}

CalcResult turbulence_variables_from_intensity_eddy_viscosity_ratio(double u, double tu, double ni, double mi)
{
    CalcResult res;
    res.U = u;
    res.tu = tu;
    res.ni = ni;
    res.mitMi = mi;

    res.k = 1.5 * std::pow(res.tu/100.0, 2) * std::pow(res.U, 2);
    res.epsilon = 0.09 * std::pow(res.k, 2) / (res.ni * res.mitMi);
    res.omega = res.epsilon / (0.09 * res.k);

    return res;
}

void turbulence_variables_from_intensity_eddy_viscosity_ratioCalc()
{
    std::cout << "Turbulence variables (k, epsilon, omega) from turbulence intensity , eddy viscosity ratio, freestream velocity and kinematic viscosity\n";

    CalcResult res{turbulence_variables_from_intensity_eddy_viscosity_ratio(
                    Menu::readValueInput(varNames.U),
                    Menu::readValueInput(varNames.tu),
                    Menu::readValueInput(varNames.ni),
                    Menu::readValueInput(varNames.mitMi))};
    std::cout << "k: " << res.k << ", \u03B5: " << res.epsilon << ", \u03C9: " << res.omega << '\n';

}

CalcResult intensity_from_k(double u, double k)
{
    CalcResult res;
    res.U = u;
    res.k = k;

    res.tu = 100 * std::pow((2 * res.k / 3), 0.5) / res.U;

    return res;
}

void intensity_from_kCalc()
{
    std::cout << "Turbulence intensity from turbulence kinetic energy and freestream velocity\n";

    CalcResult res{intensity_from_k(
                    Menu::readValueInput(varNames.U),
                    Menu::readValueInput(varNames.k))};
    std::cout << "Tu: " << res.tu;
}

CalcResult TuL_from_k_epsilon(double k, double epsilon)
{
    CalcResult res;
    res.k = k;
    res.epsilon = epsilon;

    res.tul = 0.09 * std::pow(res.k, 1.5) / res.epsilon;

    return res;
}

void TuL_from_k_epsilonCalc()
{
    std::cout << "Turbulence length scale from turbulence kinetic energy and dissipation\n";
    CalcResult res{TuL_from_k_epsilon(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.epsilon))};

    std::cout << "TuL: " << res.tul << '\n';
}

CalcResult TuL_from_k_omega(double k, double omega)
{
    CalcResult res;
    res.k = k;
    res.omega = omega;

    res.tul = std::pow(res.k, 0.5) / res.omega;

    return res;
}

void TuL_from_k_omegaCalc()
{
    std::cout << "Turbulence length scale from turbulence kinetic energy and specific dissipation\n";
    CalcResult res{TuL_from_k_omega(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.omega))};
    std::cout << "TuL: " << res.tul << '\n';
}

CalcResult eddy_viscosity_ratio_from_k_epsion(double k, double epsilon, double ni)
{
    CalcResult res;
    res.k = k;
    res.epsilon = epsilon;
    res.ni = ni;

    res.mitMi = (0.09 * std::pow(res.k, 2)) / (res.ni * res.epsilon);

    return res;
}

void eddy_viscosity_ratio_from_k_epsionCalc()
{
    std::cout << "Turbulence eddy viscosity ratio from turbulence kinetic energy and dissipation\n";
    CalcResult res{eddy_viscosity_ratio_from_k_epsion(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.epsilon),
                    Menu::readValueInput(varNames.ni))};
    std::cout << "\u03BCt/\u03BC: " << res.mitMi << '\n';
}

CalcResult eddy_viscosity_ratio_from_k_omega(double k, double omega, double ni)
{
    CalcResult res;
    res.k = k;
    res.omega = omega;
    res.ni = ni;

    res.mitMi = res.k / (res.ni * res.omega);

    return res;
}

void eddy_viscosity_ratio_from_k_omegaCalc()
{
    std::cout << "Turbulence eddy viscosity ratio from turbulence kinetic energy and specific dissipation\n";
    CalcResult res{eddy_viscosity_ratio_from_k_omega(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.omega),
                    Menu::readValueInput(varNames.ni))};
    std::cout << "\u03BCt/\u03BC: " << res.mitMi << '\n';
}



}

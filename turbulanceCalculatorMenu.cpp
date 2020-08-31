#include "turbulanceCalculatorMenu.h"

namespace TurbulanceCalculatorMenu
{
CalcResultNames varNames;

void menu()
{
    enum MENU_OPTIONS
    {
        OMEGA_FROM_K_EPSILON,
        EPSILON_FROM_K_OMEGA,
        TURBULENCE_VARIABLES_FROM_INTENSITY_LENGTH_SCALE,
        TURBULENCE_VARIABLES_FROM_INTENSITY_EDDY_VISCOSITY_RATIO,
        INTENSITY_FROM_K,
        TUL_FROM_K_EPSILON,
        TUL_FROM_K_OMEGA,
        EDDY_VISCOSITY_RATIO_FROM_K_EPSION,
        EDDY_VISCOSITY_RATIO_FROM_K_OMEGA,
        EXIT_MENU,
    };

    std::vector<std::string> opt{
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
    std::cout << std::scientific;
    int m{Menu::menu(opt)};
    switch (m)
    {
    case OMEGA_FROM_K_EPSILON:
        omega_from_k_epsilonCalc();
        Menu::backToMenu();
        break;
    case EPSILON_FROM_K_OMEGA:
        epsilon_from_k_omegaCalc();
        std::cout << "Press Enter to return to main screen.";
        std::cin.ignore();
        break;
    case TURBULENCE_VARIABLES_FROM_INTENSITY_LENGTH_SCALE:
        turbulence_variables_from_intensity_length_scaleCalc();
        Menu::backToMenu();
        break;
    case TURBULENCE_VARIABLES_FROM_INTENSITY_EDDY_VISCOSITY_RATIO:
        turbulence_variables_from_intensity_eddy_viscosity_ratioCalc();
        Menu::backToMenu();
        break;
    case INTENSITY_FROM_K:
        intensity_from_kCalc();
        Menu::backToMenu();
        break;
    case TUL_FROM_K_EPSILON:
        TuL_from_k_epsilonCalc();
        Menu::backToMenu();
        break;
    case TUL_FROM_K_OMEGA:
        TuL_from_k_omegaCalc();
        Menu::backToMenu();
        break;
    case EDDY_VISCOSITY_RATIO_FROM_K_EPSION:
        eddy_viscosity_ratio_from_k_epsionCalc();
        Menu::backToMenu();
        break;
    case EDDY_VISCOSITY_RATIO_FROM_K_OMEGA:
        eddy_viscosity_ratio_from_k_omegaCalc();
        Menu::backToMenu();
        break;
    case EXIT_MENU:
        break;
    default:
        system("clear");
        std::cout << "Option " << m << " does not exist, Please try again.\n";
        menu();
        break;
    }
}


void omega_from_k_epsilonCalc()
{
    std::cout << "ω from k and ɛ using β* = Cμ = 0.09\n";

    double omega{TurbulanceCalculator::epsilon_from_k_omega(Menu::readValueInput(varNames.k),
                            Menu::readValueInput(varNames.epsilon))};

    std::cout <<  "ω: " << omega << '\n';

}

void epsilon_from_k_omegaCalc()
{
    std::cout << "ɛ from k and ω using β* = Cμ = 0.09\n";

    double epsilon{TurbulanceCalculator::epsilon_from_k_omega(Menu::readValueInput(varNames.k),
                                        Menu::readValueInput(varNames.omega))};

    std::cout << "ɛ: " << epsilon << '\n';
}

void turbulence_variables_from_intensity_length_scaleCalc()
{
    std::cout << "Turbulence variables (k, epsilon, omega) from turbulence intensity (Tu), "
                 "length-scale (TuL) and freestream velocity (U)\n";
    double k;
    double epsilon;
    double omega;
    std::tie(k, epsilon, omega) = TurbulanceCalculator::turbulence_variables_from_intensity_length_scale(
                            Menu::readValueInput(varNames.U),
                            Menu::readValueInput(varNames.tul),
                            Menu::readValueInput(varNames.tu));

    std::cout << "k: " << k << ", ɛ: " << epsilon << ", ω: " << omega << '\n';

}

void turbulence_variables_from_intensity_eddy_viscosity_ratioCalc()
{
    std::cout << "Turbulence variables (k, epsilon, omega) from turbulence intensity , eddy viscosity ratio, freestream velocity and kinematic viscosity\n";

    double k;
    double epsilon;
    double omega;
    std::tie(k, epsilon, omega) = TurbulanceCalculator::turbulence_variables_from_intensity_eddy_viscosity_ratio(
                    Menu::readValueInput(varNames.U),
                    Menu::readValueInput(varNames.tu),
                    Menu::readValueInput(varNames.ni),
                    Menu::readValueInput(varNames.mitMi));
    std::cout << "k: " << k << ", ɛ: " << epsilon << ", ω: " << omega << '\n';

}

void intensity_from_kCalc()
{
    std::cout << "Turbulence intensity from turbulence kinetic energy and freestream velocity\n";

    double tu{TurbulanceCalculator::intensity_from_k(
                    Menu::readValueInput(varNames.U),
                    Menu::readValueInput(varNames.k))};
    std::cout << "Tu: " << tu << '\n';;
}

void TuL_from_k_epsilonCalc()
{
    std::cout << "Turbulence length scale from turbulence kinetic energy and dissipation\n";
    double tul{TurbulanceCalculator::TuL_from_k_epsilon(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.epsilon))};

    std::cout << "TuL: " << tul << '\n';
}

void TuL_from_k_omegaCalc()
{
    std::cout << "Turbulence length scale from turbulence kinetic energy and specific dissipation\n";
    double tul{TurbulanceCalculator::TuL_from_k_omega(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.omega))};
    std::cout << "TuL: " << tul << '\n';
}

void eddy_viscosity_ratio_from_k_epsionCalc()
{
    std::cout << "Turbulence eddy viscosity ratio from turbulence kinetic energy and dissipation\n";
    double mi{TurbulanceCalculator::eddy_viscosity_ratio_from_k_epsion(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.epsilon),
                    Menu::readValueInput(varNames.ni))};
    std::cout << "μt/μ: " << mi << '\n';
}

void eddy_viscosity_ratio_from_k_omegaCalc()
{
    std::cout << "Turbulence eddy viscosity ratio from turbulence kinetic energy and specific dissipation\n";
    double mi{TurbulanceCalculator::eddy_viscosity_ratio_from_k_omega(
                    Menu::readValueInput(varNames.k),
                    Menu::readValueInput(varNames.omega),
                    Menu::readValueInput(varNames.ni))};
    std::cout << "μt/μ: " << mi << '\n';
}



}

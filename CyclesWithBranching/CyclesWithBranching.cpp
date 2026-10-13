/*****************************
* Автор:   Горбунова Анастасия
* Задание: Циклы с ветвлениями
* Вариант: 5
* ****************************/

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double TemperatureG, TemperatureB;
    double viscosityG;
    int n;

    std::cout << "Enter TemperatureG (C): ";
    std::cin >> TemperatureG;

    std::cout << "Enter TemperatureB (C): ";
    std::cin >> TemperatureB;

    std::cout << "Enter viscosityG (cm^2/s): ";
    std::cin >> viscosityG;

    std::cout << "Enter number of diameters n: ";
    std::cin >> n;

    // Domain check: denominators must not be zero
    if (viscosityG == 0.0) {
        std::cout << "Error: viscosity cannot be zero.\n";
        return 1;
    }
    if (TemperatureB + 273.0 == 0.0) {
        std::cout << "Error: temperature denominator is zero.\n";
        return 1;
    }
    if (n <= 0) {
        std::cout << "Error: n must be positive.\n";
        return 1;
    }
    const double g = 9.81;
    const double theta = viscosityG * 1e-4;

    // Print all real numbers with one digit after the decimal point
    std::cout << std::fixed
              << "\n  d, m     Gr          Nu\n"
              << "------------------------------\n";

    for (int i = 0; i < n; ++i) {
        double d;
        std::cout << "Enter d[" << i + 1 << "] (m): ";
        std::cin >> d;

        if (d <= 0.0) {
            std::cout << "  invalid diameter\n";
            continue;
        }

        double Gr = g * d * d * d / (theta * theta)
            * (TemperatureG - TemperatureB) / (TemperatureB + 273.0);

        double Nu;
        if (Gr < 1e9) {
            Nu = 0.76 * std::pow(Gr, 0.22);
        }
        else {
            Nu = 0.15 * std::pow(Gr, 0.35);
        }

        std::cout << std::setprecision(3) << std::setw(6) << d  << "  "
                  << std::setprecision(1) << std::setw(12)<< Gr << "  "
                  << std::setprecision(1) << std::setw(8) << Nu << "\n";
    }
    return 0;
}

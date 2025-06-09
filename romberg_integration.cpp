// Aliya Rizqiningrum Salamun - 2306161813
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <iomanip>

// Fungsi untuk mendekati integral menggunakan aturan trapesium komposit
double trapezoidalRule(std::function<double(double)> func, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; ++i) {
        sum += 2 * func(a + i * h);
    }
    return sum * h / 2;
}

// Fungsi Romberg Integration
double rombergIntegration(std::function<double(double)> func, double a, double b, double es, int maxit) {
    std::vector<std::vector<double>> I(maxit, std::vector<double>(maxit));
    double ea = 100.0;

    int n = 1;
    I[0][0] = trapezoidalRule(func, a, b, n);

    for (int iter = 1; iter < maxit; ++iter) {
        n = std::pow(2, iter);
        I[iter][0] = trapezoidalRule(func, a, b, n);

        for (int k = 1; k <= iter; ++k) {
            I[iter][k] = (std::pow(4, k) * I[iter][k-1] - I[iter-1][k-1]) / (std::pow(4, k) - 1);
        }

        ea = std::abs((I[iter][iter] - I[iter-1][iter-1]) / I[iter][iter]) * 100.0;

        if (ea <= es) {
            return I[iter][iter];
        }
    }
    return I[maxit-1][maxit-1];
}

// Mendefinisikan fungsi sinyal arus i(t)
double current_signal(double t) {
    // Contoh: i(t) = 5 * sin(2 * PI * t)
    return 5.0 * std::sin(2.0 * M_PI * t);
}

// Mendefinisikan fungsi yang akan diintegrasikan untuk perhitungan RMS: f(t) = i(t)^2
double func_to_integrate(double t) {
    double i_t = current_signal(t);
    return i_t * i_t;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    double T = b - a;

    // Parameter untuk Romberg Integration
    double es_romberg = 0.0001;
    int maxit_romberg = 20;

    std::cout << "-------------------------------------------------\n";
    std::cout << "     Perhitungan RMS menggunakan Romberg Integration\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << std::fixed << std::setprecision(5);
    double integral_romberg = rombergIntegration(func_to_integrate, a, b, es_romberg, maxit_romberg);
    double rms_romberg = std::sqrt(integral_romberg / T);
    std::cout << "RMS (Romberg Integration): " << rms_romberg << " A\n";

    // Solusi analitis untuk perbandingan
    std::cout << "RMS Teoritis (Analitis): " << 5.0 / std::sqrt(2.0) << " A\n";

    std::cout << "-------------------------------------------------\n";

    return 0;
}

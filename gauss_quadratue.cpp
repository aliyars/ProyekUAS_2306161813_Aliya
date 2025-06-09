// Aliya Rizqiningrum Salamun - 2306161813
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <iomanip>

// Fungsi untuk melakukan Gauss-Legendre Quadrature
double gaussQuadrature(std::function<double(double)> func, double a, double b, int n_points) {
    // Titik dan bobot Gauss-Legendre
    std::vector<double> x, w;
    
    // Menentukan titik dan bobot berdasarkan jumlah titik (n_points)
    if (n_points == 2) {
        x = {-0.5773502692, 0.5773502692};
        w = {1.0, 1.0};
    } else if (n_points == 3) {
        x = {-0.7745966692, 0.0, 0.7745966692};
        w = {0.5555555556, 0.8888888889, 0.5555555556};
    } else if (n_points == 4) {
        x = {-0.8611363116, -0.3399810436, 0.3399810436, 0.8611363116};
        w = {0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451};
    } else if (n_points == 5) {
        x = {-0.9061798459, -0.5384693101, 0.0, 0.5384693101, 0.9061798459};
        w = {0.2369268851, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268851};
    } else {
        // Default ke 2 titik jika jumlah titik tidak valid
        x = {-0.5773502692, 0.5773502692};
        w = {1.0, 1.0};
    }
    
    // Transformasi dari interval [-1, 1] ke [a, b]
    double sum = 0.0;
    for (int i = 0; i < n_points; ++i) {
        double xi = 0.5 * (b - a) * x[i] + 0.5 * (b + a);
        sum += w[i] * func(xi);
    }
    
    return 0.5 * (b - a) * sum;
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

    // Menampilkan pesan awal
    std::cout << "-------------------------------------------------\n";
    std::cout << "     Perhitungan RMS menggunakan Gauss Quadrature\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << std::fixed << std::setprecision(5);
    
    // Menguji jumlah titik yang berbeda
    for (int n_points = 2; n_points <= 5; ++n_points) {
        double integral_gauss = gaussQuadrature(func_to_integrate, a, b, n_points);
        double rms_gauss = std::sqrt(integral_gauss / T);
        std::cout << "RMS (Gauss " << n_points << "-point): " << rms_gauss << " A\n";
    }

    // Solusi analitis untuk perbandingan
    std::cout << "RMS Teoritis (Analitis): " << 5.0 / std::sqrt(2.0) << " A\n";

    std::cout << "-------------------------------------------------\n";

    return 0;
}

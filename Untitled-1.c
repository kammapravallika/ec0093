#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define N 10 // Number of Fourier terms

// Define the function f(x)
double f(double x) {
    // Example: f(x) = x^2 on interval [-PI, PI]
    return x * x;
}

// Compute a0 (constant term)
double compute_a0(double T, int intervals) {
    double sum = 0.0, dx = T / intervals;
    for (int i = 0; i <= intervals; i++) {
        double x = -T / 2 + i * dx;
        sum += f(x);
    }
    return (sum * dx) / T;
}

// Compute an (cosine coefficients)
double compute_an(int n, double T, int intervals) {
    double sum = 0.0, dx = T / intervals;
    double omega = 2 * PI / T;
    for (int i = 0; i <= intervals; i++) {
        double x = -T / 2 + i * dx;
        sum += f(x) * cos(n * omega * x);
    }
    return (2 * sum * dx) / T;
}

// Compute bn (sine coefficients)
double compute_bn(int n, double T, int intervals) {
    double sum = 0.0, dx = T / intervals;
    double omega = 2 * PI / T;
    for (int i = 0; i <= intervals; i++) {
        double x = -T / 2 + i * dx;
        sum += f(x) * sin(n * omega * x);
    }
    return (2 * sum * dx) / T;
}

// Fourier Series Reconstruction
double fourier_series(double x, double T, int terms, int intervals) {
    double a0 = compute_a0(T, intervals);
    double sum = a0 / 2.0; // Start with the constant term
    double omega = 2 * PI / T;

    for (int n = 1; n <= terms; n++) {
        double an = compute_an(n, T, intervals);
        double bn = compute_bn(n, T, intervals);
        sum += an * cos(n * omega * x) + bn * sin(n * omega * x);
    }
    return sum;
}

int main() {
    double T = 2 * PI;      // Period of the function
    int intervals = 1000;   // Number of intervals for integration
    int terms = N;          // Number of Fourier terms to compute

    printf("Fourier Series Approximation:\n");
    printf("x\t\tf(x)\t\tFourier Approximation\n");
    for (double x = -PI; x <= PI; x += 0.1) {
        double original = f(x);
        double approximation = fourier_series(x, T, terms, intervals);
        printf("%.4f\t%.4f\t%.4f\n", x, original, approximation);
    }

    return 0;
}

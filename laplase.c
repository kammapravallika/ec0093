#include <stdio.h>
#include <math.h>

// Define the function f(t) to transform
double f(double t) {
    // Example: f(t) = t * exp(-t)
    return t * exp(-t);
}

// Laplace Transform function
double laplaceTransform(double s, double tMax, double stepSize) {
    double integral = 0.0;
    for (double t = 0.0; t <= tMax; t += stepSize) {
        integral += f(t) * exp(-s * t) * stepSize;
    }
    return integral;
}

int main() {
    double sValues[] = {0.5, 1.0, 2.0, 5.0}; // Values of s to evaluate
    int nValues = sizeof(sValues) / sizeof(sValues[0]);
    double tMax = 100.0;  // Upper limit for t in numerical integration
    double stepSize = 0.01; // Step size for integration

    printf("Laplace Transform of f(t) = t * exp(-t):\n");
    printf("s\t\tF(s)\n");
    printf("-----------------------\n");

    for (int i = 0; i < nValues; i++) {
        double s = sValues[i];
        double result = laplaceTransform(s, tMax, stepSize);
        printf("%.2f\t\t%.6f\n", s, result);
    }

    return 0;
}

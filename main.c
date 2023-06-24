#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100      // Number of time points
#define h_min 0.001   // Minimum step size
#define h_max 0.1     // Maximum step size
#define A 1.0     // Parameter A
#define B 3.5     // Parameter B
#define tol 1e-6  // Error tolerance

void brusselator(double x[], double *t, double h) {
    double k1x, k2x, k3x, k4x, k5x, k6x;
    double k1y, k2y, k3y, k4y, k5y, k6y;
    double temp_x, temp_y;

    k1x = h * (A + x[0] * x[0] * x[1] - (B + 1) * x[0]);
    k1y = h * (B * x[0] - x[0] * x[0] * x[1]);

    k2x = h * (A + (x[0] + 0.5 * k1x) * (x[0] + 0.5 * k1x) * (x[1] + 0.5 * k1y) - (B + 1) * (x[0] + 0.5 * k1x));
    k2y = h * (B * (x[0] + 0.5 * k1x) - (x[0] + 0.5 * k1x) * (x[0] + 0.5 * k1x) * (x[1] + 0.5 * k1y));

    k3x = h * (A + (x[0] + 0.5 * k2x) * (x[0] + 0.5 * k2x) * (x[1] + 0.5 * k2y) - (B + 1) * (x[0] + 0.5 * k2x));
    k3y = h * (B * (x[0] + 0.5 * k2x) - (x[0] + 0.5 * k2x) * (x[0] + 0.5 * k2x) * (x[1] + 0.5 * k2y));

    k4x = h * (A + (x[0] + k3x) * (x[0] + k3x) * (x[1] + k3y) - (B + 1) * (x[0] + k3x));
    k4y = h * (B * (x[0] + k3x) - (x[0] + k3x) * (x[0] + k3x) * (x[1] + k3y));

    k5x = h * (A + (x[0] + (2.0 / 3.0) * k4x) * (x[0] + (2.0 / 3.0) * k4x) * (x[1] + (2.0 / 3.0) * k4y) - (B + 1) * (x[0] + (2.0 / 3.0) * k4x));
    k5y = h * (B * (x[0] + (2.0 / 3.0) * k4x) - (x[0] + (2.0 / 3.0) * k4x) * (x[0] + (2.0 / 3.0) * k4x) * (x[1] + (2.0 / 3.0) * k4y));

    k6x = h * (A + (x[0] + 0.25 * k1x + 0.75 * k4x) * (x[0] + 0.25 * k1x + 0.75 * k4x) * (x[1] + 0.25 * k1y + 0.75 * k4y) - (B + 1) * (x[0] + 0.25 * k1x + 0.75 * k4x));
    k6y = h * (B * (x[0] + 0.25 * k1x + 0.75 * k4x) - (x[0] + 0.25 * k1x + 0.75 * k4x) * (x[0] + 0.25 * k1x + 0.75 * k4x) * (x[1] + 0.25 * k1y + 0.75 * k4y));

    temp_x = x[0] + (1.0 / 9.0) * (2 * k1x + 3 * k3x + 4 * k4x);
    temp_y = x[1] + (1.0 / 9.0) * (2 * k1y + 3 * k3y + 4 * k4y);

    x[0] = temp_x;
    x[1] = temp_y;

    *t += h;
}

double random_perturbation() {
    // Generates a random number between -0.5 and 0.5
    return (double)rand() / RAND_MAX - 0.5;
}

int main() {
    double x[2] = {1.2, 3.1};  // Initial conditions
    double t = 0.0;
    double h = h_max;          // Initial step size

    // Seed the random number generator
    srand(time(NULL));

    printf("t = %.2f: x = %.5f, y = %.5f\n", t, x[0], x[1]);

    while (t < 100.0) {
        // Add random perturbations to x
        x[0] += random_perturbation();
        x[1] += random_perturbation();

        brusselator(x, &t, h);

        printf("t = %.2f: x = %.5f, y = %.5f\n", t, x[0], x[1]);

        h = fmin(h_max, h);
        h = fmax(h_min, h);

        if (t + h > 100.0)
            h = 100.0 - t;

    }
    puts("\nPress any key to exit.");
getch();
    return 0;
}

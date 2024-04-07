// Michael Sexton
// Problem 4

#include <iostream>
#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

// Drag bucket equation function
double drag_bucket(double d0, double k, double l) {
    return d0 + k * l * l;
}

int main() {
    // Constants
    double d0 = 100; // Parasite drag (N)
    double k = 0.1; // Drag coefficient related to induced drag (1/(lift coefficient)^2)

    // Lift force range (N)
    std::vector<double> lift_force;
    for (double l = 0; l <= 5000; l += 100) {
        lift_force.push_back(l);
    }

    // Calculate drag force for each lift force
    std::vector<double> drag_force;
    for (double l : lift_force) {
        drag_force.push_back(drag_bucket(d0, k, l));
    }

    // Plot
    plt::plot(lift_force, drag_force);
    plt::xlabel("Lift Force (N)");
    plt::ylabel("Drag Force (N)");
    plt::title("Drag Bucket Equation");
    plt::grid(true);
    plt::show();

    return 0;
}

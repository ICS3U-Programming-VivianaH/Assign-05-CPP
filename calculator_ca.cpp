// Copyright 2025 Viviana Hurtado
// Created by: Viviana Hurtado
// Date: May, 2025
// This program calculates velocity and acceleration
#include <iomanip>
#include <iostream>

// Function calculates velocity for each measurement (v = d/t)
void calculateV(const float distance[], const float time[], float velocity[]) {
    for (int counter = 0; counter < 3; counter++) {
        velocity[counter] = distance[counter] / time[counter];
    }
}

// Function calculates acceleration for each measurement (a = v/t)
void calculateA(const float velocity[], const float time[], float acceler[]) {
    for (int counter = 0; counter < 3; counter++) {
        acceler[counter] = velocity[counter] / time[counter];
    }
}

int main() {
    // Arrays for input and results (3 measurements)
    float distance[3];
    float time[3];
    float velocity[3];
    float acceler[3];

    // Input distance with validation (must be >= 0)
    for (int counter = 0; counter < 3; counter++) {
        while (true) {
            std::cout << "Enter d" << counter << " value (km): ";
            if (std::cin >> distance[counter]) {
                if (distance[counter] < 0) {
                    std::cout << "Distance cannot be negative" << std::endl;
                    continue;
                }
                break;
            } else {
                std::cout << "Please enter a valid number" << std::endl;
            }
        }
    }

    // Input time with validation (must be > 0)
    for (int counter = 0; counter < 3; counter++) {
        while (true) {
            std::cout << "Enter t" << counter << " value (hours): ";
            if (std::cin >> time[counter]) {
                if (time[counter] <= 0) {
                    std::cout << "Time must be positive" << std::endl;
                    continue;
                }
                break;
            } else {
                std::cout << "Please enter a valid number" << std::endl;
            }
        }
    }

    // Calculate and display results
    calculateV(distance, time, velocity);
    calculateA(velocity, time, acceler);

    std::cout << "\nResults:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Measurement " << i << ":" << std::endl;
        std::cout << "  Distance: " << distance[i] << " km" << std::endl;
        std::cout << "  Time: " << time[i] << " hours" << std::endl;
        std::cout << std::fixed << std::setprecision(2);  // Format to 2 dec.
        std::cout << "  Velocity: " << velocity[i] << " km/h" << std::endl;
        std::cout << "  Acceleration: " << acceler[i] << " km/h²" << std::endl;
    }
}

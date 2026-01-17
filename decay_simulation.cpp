#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>


const int N0 = 1000;          // Initial particles
const double LAMBDA = 0.1;    // Decay constant
const int STEPS = 1000;        // Time steps

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Store results: Time _ Remaining Particles
    std::vector<int> time_points;
    std::vector<int> N_t;

    int current_N = N0;

    std::cout << "Starting Monte Carlo Simulation..." << std::endl;
    std::cout << "Initial Particles: " << N0 << std::endl;

    // Open file to save data (for plotting)
    std::ofstream dataFile("decay_results.csv");
    dataFile << "Time,Particles\n"; // Header

    // Time Loop
    for (int t = 0; t < STEPS; ++t) {
        // Save current state
        time_points.push_back(t);
        N_t.push_back(current_N);
        dataFile << t << "," << current_N << "\n";

        // Decay Loop (The Monte Carlo Step)
        // We check every single atom to see if it decays
        int decayed_count = 0;
        for (int i = 0; i < current_N; ++i) {
            // Generate random number between 0 and 1
            double r = (double)std::rand() / RAND_MAX;
            
            // If random number < lambda, the atom decays
            if (r < LAMBDA) {
                decayed_count++;
            }
        }

        // Update the number of remaining particles
        current_N -= decayed_count;
    }

    dataFile.close();
    std::cout << "Simulation Complete. Data saved to 'decay_results.csv'" << std::endl;

    return 0;
}
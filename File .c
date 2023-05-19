#include <stdio.h>
#include <math.h>

#define G 6.67430e-11       // Gravitational Constant
#define K 8.99e9            // Electrostatic Constant in a Vacuum

struct Particle {
    double x, y, z;         // Position in space (x, y, z coordinates)
    double mass;            // Particle Mass
    double charge;          // Electric charge of the particle
    int isStatic;           // Flag indicating whether the particle is static (0 - mobile, 1 - static)
};

typedef struct Particle Particle;

// Function to calculate the Gravitational Force
double calculateGravitationalForce(double mass1, double mass2, double distance) {
    return (G * mass1 * mass2) / (distance * distance);
}

// Function to calculate the Eletric Force
double calculateElectricForce(double charge1, double charge2, double distance) {
    return (K * charge1 * charge2) / (distance * distance);
}

// Function to calculate the Total Force
double calculateTotalForce(double gravitationalForce, double electricForce) {
    return gravitationalForce + electricForce;
}

int main() {
    int numParticles;

    printf("Enter the number of particles: ");      // Input the number of particles
    scanf("%d", &numParticles);

   Particle particles[numParticles];              // The dimension of the array is defined by the number of particles you inputted before

    // Reading input for each particle
    for (int i = 0; i < numParticles; i++) {
        printf("\nParticle %d:\n", i+1);
        printf("Enter the position (x, y, z): ");
        scanf("%lf %lf %lf", &particles[i].x, &particles[i].y, &particles[i].z);        // Store each position in the dimension for each particle (e.g 12 82 50)

        printf("Enter the mass: ");
        scanf("%lf", &particles[i].mass);       // Store the mass of each particle

        printf("Enter the charge: ");
        scanf("%lf", &particles[i].charge);     // Store the charge of each particle

        printf("Is the particle static? (0 - No, 1 - Yes): ");
        scanf("%d", &particles[i].isStatic);        // Store the info about the state of each particle
    }

    // Calculating forces
    for (int i = 0; i < numParticles; i++) {
        for (int j = i + 1; j < numParticles; j++) {
            double distance = sqrt(pow(particles[j].x - particles[i].x, 2) +
                                   pow(particles[j].y - particles[i].y, 2) +
                                   pow(particles[j].z - particles[i].z, 2));

            double gravitationalForce = calculateGravitationalForce(particles[i].mass, particles[j].mass, distance);        // Recall the functions and run it to store the results at the variables
            double electricForce = calculateElectricForce(particles[i].charge, particles[j].charge, distance);              
            double totalForce = calculateTotalForce(gravitationalForce, electricForce);                                     

            printf("\nForces between Particle %d and Particle %d:\n", i+1, j+1);        // Print to the terminal/screen the results of the specified particles 
            printf("Distance between the particles: %.2f m\n", distance);               // Print the results of each calculation stored in each variable
            printf("Gravitational Force: %6.3e N\n", gravitationalForce);               
            printf("Electric Force: %6.3e N\n", electricForce);                         
            printf("Total Force: %6.3e N\n", totalForce);
        }
    }

    return 0;
}

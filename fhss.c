#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FREQUENCIES 10 // Number of frequencies in the frequency band
#define HOP_INTERVAL 1     // Time interval between frequency hops in seconds

// Function to simulate hopping to a random frequency
void hopToRandomFrequency()
{
  // Generate a random frequency index
  int randomIndex = rand() % NUM_FREQUENCIES;

  // Simulate hopping to the selected frequency
  printf("Hopping to frequency %d\n", randomIndex);
}

int main()
{
  srand(time(NULL)); // Seed the random number generator

  printf("FHSS (Frequency Hopping Spread Spectrum) Simulation\n");

  // Continuous hopping loop
  while (1)
  {
    hopToRandomFrequency(); // Hop to a random frequency
    sleep(HOP_INTERVAL);    // Wait for the hop interval
  }

  return 0;
}

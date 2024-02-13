#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task 1: Initialize CLANT to Zero
// Requirement: Create a function that initializes a CLANT with a specified length, setting all elements to '0'.
// Code:
char* initializeCLANT() {
    // Allocate memory for the CLANT dynamically.
    char* clant = (char*)malloc(1001 * sizeof(char));
    
    // Check if memory allocation is successful.
    if (clant == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Set all elements of the CLANT to '0'.
    memset(clant, '0', 1001);

    // Return the initialized CLANT.
    return clant;
}

int main() {
    // Task 1: Initialize CLANT to Zero
    // Requirement: Call the initializeCLANT function to obtain an initialized CLANT.
    // Code:
    char* initializedCLANT = initializeCLANT();

    // Requirement: Display the initialized CLANT.
    // Code:
    printf("Initialized CLANT: %s\n", initializedCLANT);

    // Expected Output: Initialized CLANT: 000...000 (1001 zeros)

    // Free the dynamically allocated memory.
    free(initializedCLANT);

    return 0;
}

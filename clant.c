#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task 2: CLANT Comparator
int compareCLANTs(const char* clant1, const char* clant2) {
    return strcmp(clant1, clant2);
}

// Task 3: CLANT Adder
char* addCLANTs(const char* clant1, const char* clant2) {
    int size = strlen(clant1);
    char* result = (char*)malloc((size + 2) * sizeof(char));
    int carry = 0;

    for (int i = size - 1; i >= 0; --i) {
        int sum = (clant1[i] - '0') + (clant2[i] - '0') + carry;
        result[i + 1] = (sum % 10) + '0';
        carry = sum / 10;
    }

    result[0] = carry + '0';
    result[size + 1] = '\0';

    return result;
}

// Task 4: CLANT Subtractor
char* subtractCLANTs(const char* clant1, const char* clant2) {
    int size = strlen(clant1);
    char* result = (char*)malloc((size + 1) * sizeof(char));
    int borrow = 0;

    for (int i = size - 1; i >= 0; --i) {
        int diff = (clant1[i] - '0') - (clant2[i] - '0') - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[i] = diff + '0';
    }

    result[size] = '\0';

    return result;
}

// Task 5: CLANT Multiplier
char* multiplyCLANTs(const char* clant1, const char* clant2) {
    int size1 = strlen(clant1);
    int size2 = strlen(clant2);
    char* result = (char*)malloc((size1 + size2 + 1) * sizeof(char));

    for (int i = 0; i < size1 + size2; ++i) {
        result[i] = '0';
    }
    result[size1 + size2] = '\0';

    for (int i = size1 - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = size2 - 1; j >= 0; --j) {
            int product = (clant1[i] - '0') * (clant2[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = (product % 10) + '0';
            carry = product / 10;
        }
        result[i] += carry;
    }

    return result;
}

// Task 6: CLANT Fibonacci
char* fibonacciCLANT(unsigned int n) {
    char* a = (char*)malloc(2 * sizeof(char));
    char* b = (char*)malloc(2 * sizeof(char));

    a[0] = '0';
    a[1] = '\0';

    b[0] = '1';
    b[1] = '\0';

    if (n == 0) return a;
    if (n == 1) return b;

    for (unsigned int i = 2; i <= n; ++i) {
        char* temp = addCLANTs(a, b);
        free(a);
        a = b;
        b = temp;
    }

    free(a);
    return b;
}

// Function to free the allocated memory for CLANTs
void freeCLANT(char* clant) {
    free(clant);
}

int main() {
    // Task 2: CLANT Comparator
    const char* clant1 = "123456789";
    const char* clant2 = "987654321";
    int comparisonResult = compareCLANTs(clant1, clant2);
    printf("Comparison Result: %d\n", comparisonResult);

    // Task 3: CLANT Adder
    char* sumResult = addCLANTs(clant1, clant2);
    printf("Sum: %s\n", sumResult);
    freeCLANT(sumResult);

    // Task 4: CLANT Subtractor
    char* subtractionResult = subtractCLANTs(clant1, clant2);
    printf("Difference: %s\n", subtractionResult);
    freeCLANT(subtractionResult);

    // Task 5: CLANT Multiplier
    char* multiplicationResult = multiplyCLANTs(clant1, clant2);
    printf("Product: %s\n", multiplicationResult);
    freeCLANT(multiplicationResult);

    // Task 6: CLANT Fibonacci
    unsigned int fibonacciIndex = 10;
    char* fibonacciResult = fibonacciCLANT(fibonacciIndex);
    printf("Fibonacci at index %u: %s\n", fibonacciIndex, fibonacciResult);
    freeCLANT(fibonacciResult);

    return 0;
}

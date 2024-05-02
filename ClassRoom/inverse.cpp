#include <iostream>

int modInverse(int A, int M) {
    for (int X = 1; X < M; X++) {
        if (((A % M) * (X % M)) % M == 1) {
            return X;
        }
    }
    return -1; // If no modular inverse exists
}

int main() {
    int A = 215, M = 592;

    // Function call
    int result = modInverse(A, M);
    if (result != -1) {
        std::cout << "Modular multiplicative inverse of " << A << " under modulo " << M << " is: " << result;
    } else {
        std::cout << "Modular multiplicative inverse of " << A << " under modulo " << M << " does not exist.";
    }
    
    return 0;
}

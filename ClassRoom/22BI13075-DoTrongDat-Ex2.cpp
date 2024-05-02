#include <iostream>

long Square_and_Multiply(long x, long e, long m) {
    unsigned long long r = x;
    int bin[32];
    int i = 0;

    // Converts H to Binary
    while (e > 0) {
        bin[i] = e % 2;
        e = e / 2;
        i++;
    }

    i--;

    while (i > 0) {
        r = (r * r) % m;    // r = r^2 mod n if binary digit = 0
        if (bin[--i] == 1) {
            r = (r * x) % m;    // r = r * x mod n if binary digit = 1
        }
    }

    return r;
}

int main() {
    long x, e, m;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter e: ";
    std::cin >> e;

    std::cout << "Enter m: ";
    std::cin >> m;

    std::cout << "Computing " << x << " to the power " << e << " modulo " << m << "\n";
    long Y = Square_and_Multiply(x, e, m); // Square and Multiply modular Exponentiation

    std::cout << x << " to the power " << e << " ≡ " << Y << " (modulo " << m << ")\n";

    return 0;
}

// // Public key (N, e)
// // Private key d
// // Encryption: C ≡ M^e (mod N) 
// // Decryption: M ≡ C^d (mod N)

// #include <iostream>
// #include <cmath>

// int checkPrime(int n) {
//     if (n <= 1) return 0;
//     for(int i = 2; i <= sqrt(n); i++) {
//         if(n % i == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }

// int modInverse(int a, int m) {
//     a = a % m;  // Ensure that a is within the range from 0 to m - 1
//     for (int x = 1; x < m; x++)
//         if ((a * x) % m == 1)
//             return x;   // Return the inverse element if found
//     return 1;
// }

// // Lab_work 2
// long Square_and_Multiply(long x, long e, long m) {
//     unsigned long long r = x;
//     int bin[32];
//     int i = 0;

//     // Converts H to Binary
//     while (e > 0) {
//         bin[i] = e % 2;
//         e = e / 2;
//         i++;
//     }

//     i--;

//     while (i > 0) {
//         r = (r * r) % m;    // r = r^2 mod n if binary digit = 0
//         if (bin[--i] == 1) {
//             r = (r * x) % m;    // r = r * x mod n if binary digit = 1
//         }
//     }

//     return r;
// }

// int main() {
//     int p, q, e, d;
//     int n, phi;
//     char ch;
//     int num, cipher, decrypt;
//     printf("Mention if e or d is given: ");
//     scanf("%c",&ch);
//     while (1) {
//         printf("Enter value for p,q: ");
//         scanf("%d %d", &p, &q);

//         if (!(checkPrime(p) && checkPrime(q)))
//             printf("Both numbers are not prime. Please enter prime numbers only\n");
//         else if (!checkPrime(p))
//             printf("The first number you entered is not prime, please try again\n");
//         else if (!checkPrime(q))
//             printf("The second number you entered is not prime, please try again\n");
//         else
//             break;
//     }
    
//     n = p * q;

//     phi = (p - 1) * (q - 1);
    
//     if(ch=='d') {
//         printf("Provide value for d: ");
//         scanf("%d",&d);
//         e=modInverse(d,phi);    // e = d^-1 mod(p-1)(q-1)
//     }
//     else {
//         printf("Provide value for e: ");
//         scanf("%d",&e);
//         d = 0;
//         for (d = e + 1; d <= 100; d++) {
//             if ( ((d * e) % phi) == 1)
//                 break;
//         }
//     }
//     printf("Value of e: %d\nValue of d: %d\n", e, d);

//     printf("Enter number to encrypt: ");
//     scanf("%d", &num);

//     cipher = Square_and_Multiply(num, e, n);
//     printf("The cipher number is: %d\n", cipher);

//     decrypt = Square_and_Multiply(cipher, d, n);
//     printf("The decrypted number is: %d\n", decrypt);
//     return 0;
// }


// -------------------------------------------

// update code can use long long 

#include <iostream>
#include <cmath>

int checkPrime(int n) {
    if (n <= 1) return 0;
    for(unsigned long long i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

unsigned long long modInverse(unsigned long long a, unsigned long long m) {
    a = a % m;  // Ensure that a is within the range from 0 to m - 1
    for (unsigned long long x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;   // Return the inverse element if found
    return 1;
}

// Lab_work 2
unsigned long long Square_and_Multiply(unsigned long long x, unsigned long long e, unsigned long long m) {
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
    int p, q, e, d;
    unsigned long long n, phi;
    char ch;
    unsigned long long num, cipher, decrypt;
    printf("Mention if e or d is given: ");
    scanf("%c",&ch);
    while (1) {
        printf("Enter value for p,q: ");
        scanf("%d %d", &p, &q);

        if (!(checkPrime(p) && checkPrime(q)))
            printf("Both numbers are not prime. Please enter prime numbers only\n");
        else if (!checkPrime(p))
            printf("The first number you entered is not prime, please try again\n");
        else if (!checkPrime(q))
            printf("The second number you entered is not prime, please try again\n");
        else
            break;
    }
    
    n = p * q;

    phi = (p - 1) * (q - 1);
    
    if(ch=='d') {
        printf("Provide value for d: ");
        scanf("%d",&d);
        e=modInverse(d,phi);    // e = d^-1 mod(p-1)(q-1)
    }
    else {
        printf("Provide value for e: ");
        scanf("%d",&e);
        d = modInverse(e, phi); // Calculate d using the modInverse function
    }
    printf("Value of e: %d\nValue of d: %d\n", e, d);

    printf("Enter number to encrypt: ");
    scanf("%llu", &num);

    cipher = Square_and_Multiply(num, e, n);
    printf("The cipher number is: %llu\n", cipher);

    decrypt = Square_and_Multiply(cipher, d, n);
    printf("The decrypted number is: %llu\n", decrypt);
    return 0;
}


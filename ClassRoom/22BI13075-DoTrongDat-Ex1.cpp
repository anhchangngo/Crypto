/* 
List n the keystream bits, suppose that the values of registers are provided X0, Y0, Z0
Test the program with following values:
X = (x0, x1, ..., x18) = (1111101010101010101)
Y = (y0, y1, ..., y21) = (1100110011001100110011)
Z = (z0, z1, ..., z22) = (11100001111000011110000)
n = 10
*/

#include <iostream>
using namespace std;

#define SIZE_X 19
#define SIZE_Y 22
#define SIZE_Z 23 
#define BITS 3  // number of keystream

int maj(int x, int y, int z);  // majority

int main() {
    int m;
    // int x[SIZE_X] = {1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
    // int y[SIZE_Y] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
    // int z[SIZE_Z] = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};

    int x[SIZE_X] = {0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
    int y[SIZE_Y] = {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1};
    int z[SIZE_Z] = {1,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1};


    for(int i = 0; i < BITS; i ++) {
        m = maj(x[8], y[10], z[10]); // find majority 

        cout << " X : ";
        if(x[8] == m) { // if majority matches with index in x -> compute and shift
            int p = x[13] ^ x[16] ^ x[17] ^ x[18];  // compute the polynomial x
            for(int j = SIZE_X - 1; j >= 0; j --) {
                if(j == 0) {
                    x[j] = p;
                }
                else {
                    x[j] = x[j - 1];
                }
            }
        }
            for(int j = 0; j < SIZE_X; j ++) {
                cout << x[j];
            }

        cout << "\n Y : ";
        if(y[10] == m) {
            int p = y[20] ^ y[21];
            for(int j = SIZE_Y - 1; j >= 0; j --) {
                if(j == 0) {
                    y[j] = p;
                }
                else {
                    y[j] = y[j - 1];
                }
            }
        }
            for(int j = 0; j < SIZE_Y; j ++) {
            cout << y[j];
        }

        cout << "\n Z : ";
        if(z[10] == m) {
            int p = z[7] ^ z[20] ^ z[21] ^ z[22];
            for(int j = SIZE_Z - 1; j >= 0; j --) {
                if(j == 0) {
                    z[j] = p;
                }
                else {
                    z[j] = z[j - 1];
                }
            }
        }
            for(int j = 0; j < SIZE_Z; j ++) {
                cout << z[j];
            }

        if(i < BITS) {
            int key = x[SIZE_X - 1] ^ y[SIZE_Y - 1] ^ z[SIZE_Z - 1];
            cout << "\n KeyStream Bit " << BITS - i - 1 << " = " << x[SIZE_X - 1] << " ^ "  << y[SIZE_Y - 1] <<  " ^ " << z[SIZE_Z - 1] << " = " << key;
            cout << "\n";
        }
}
return 0;
}

int maj(int x, int y, int z) {
    if(x == 0) {
        if(y == 0 || z == 0) {
            return 0; // x is already 0, so if either y or z = 0 -> majority = 0
        }
        else {
            return 1; // both y and z = 1
        }
    }
    else {
        if(y == 1 || z == 1) {
            return 1; // x is already 1, so if either y or z = 1 -> majority = 1
        }
        else {
            return 0; // both y and z = 0
        }
    }
}
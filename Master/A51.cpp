#include <iostream>

# define x_size 19
# define y_size 22 
# define z_size 23 
# define bits 5

int majority_of_bit(int X, int Y, int Z);

int main() {
    
  int max_B;
  // int X_0[x_size] = {1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
  // int Y_0[y_size] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
  // int Z_0[z_size] = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};

  int X_0[x_size] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0};
  int Y_0[y_size] = {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1};
  int Z_0[z_size] = {1,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1,1};

  printf("\nInitial Values:");
  printf("\nX = ");
  for (int j = 0; j < x_size; j++) 
  {
    printf("%d", X_0[j]);
  }

  printf("\nY = ");
  for (int j = 0; j < y_size; j++) 
  {
    printf("%d", Y_0[j]);
  }

  printf("\nZ = ");
  for (int j = 0; j < z_size; j++) 
  {
    printf("%d", Z_0[j]);
  }

  for (int i = 0; i < bits; i++) {
    // Calculate keystore bit before shifting
    int keystream_bit = majority_of_bit(X_0[8], Y_0[10], Z_0[10]);

    max_B = majority_of_bit(X_0[8], Y_0[10], Z_0[10]); 

    printf("\nStep %d:", i + 1);
    
    // Keystream Bit Calculation
    printf("\n  Keystream Bit %d Calculation: X[18] = %d, Y[21] = %d, Z[22] = %d, Result = %d", 
           i, X_0[18], Y_0[21], Z_0[22], X_0[18] ^ Y_0[21] ^ Z_0[22]);

    // Majority Calculation for X[8], Y[10], Z[10]
    printf("\n  Majority Calculation: X[8] = %d, Y[10] = %d, Z[10] = %d, Majority = %d", X_0[8], Y_0[10], Z_0[10], max_B);

    // Majority Shifts
    if (X_0[8] == max_B) 
    { 
      int p = X_0[13] ^ X_0[16] ^ X_0[17] ^ X_0[18];
      for (int j = x_size - 1; j >= 0; j--) {
        if (j == 0) 
        {
          X_0[j] = p;
        } 
        else 
        {
          X_0[j] = X_0[j - 1];
        }
      }
      printf("\n  Shift X");
    }

    if (Y_0[10] == max_B) 
    { 
      int p = Y_0[20] ^ Y_0[21]; 
      for (int j = y_size - 1; j >= 0; j--) 
      {
        if (j == 0) 
        {
          Y_0[j] = p;
        } 
        else 
        {
          Y_0[j] = Y_0[j - 1];
        }
      }
      printf("\n  Shift Y");
    }

    if (Z_0[10] == max_B) 
    {
      int p = Z_0[7] ^ Z_0[20] ^ Z_0[21] ^ Z_0[22]; 
      for (int j = z_size - 1; j >= 0; j--) 
      {
        if (j == 0) 
        {
          Z_0[j] = p;
        } 
        else 
        {
          Z_0[j] = Z_0[j - 1];
        }
      }
      printf("\n  Shift Z");
    }

    printf("\n  After Shift:");
    printf("\n    X = ");
    for (int j = 0; j < x_size; j++) 
    {
      printf("%d", X_0[j]);
    }

    printf("\n    Y = ");
    for (int j = 0; j < y_size; j++) 
    {
      printf("%d", Y_0[j]);
    }

    printf("\n    Z = ");
    for (int j = 0; j < z_size; j++) 
    {
      printf("%d", Z_0[j]);
    }
    printf("\n");
  }

  printf("\nFinal Values:");
  printf("\nX = ");
  for (int j = 0; j < x_size; j++) 
  {
    printf("%d", X_0[j]);
  }
  
  printf("\nY =  ");
  for (int j = 0; j < y_size; j++) 
  {
    printf("%d", Y_0[j]);
  }
  
  printf("\nZ =  ");
  for (int j = 0; j < z_size; j++) 
  {
    printf("%d", Z_0[j]);
  }

  return 0;
}

int majority_of_bit(int X, int Y, int Z) 
{
  if (X == 0) 
  {
    if (Y == 0 || Z == 0) 
    {
      return 0; 
    } 
    else 
    {
      return 1; 
    }
  } 
  else 
  {
    if (Y == 1 || Z == 1) {
      return 1; 
    } 
    else 
    {
      return 0; 
    }
  }
}

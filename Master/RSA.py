from sympy import gcd, mod_inverse

# Step 1: Key Generation
def generate_keypair(p, q, e1=None, e2=None, d=None):
    # Initialize e
    e = None
    
    # Calculate modulus N
    N = p * q
    print(f"Compute modulus N: N = p * q = {p} * {q} = {N}")

    # Calculate Euler's totient function
    phi_N = (p - 1) * (q - 1)
    print(f"Compute Euler's totient function: phi(N) = (p-1)*(q-1) = ({p}-1)*({q}-1) = {phi_N}")

    # Calculate public exponent e if d is provided
    if d is not None:
        e = mod_inverse(d, phi_N)
        print(f"Compute the encryption exponent e: e = d^(-1) mod phi(N) = {d}^(-1) mod {phi_N} = {e}")
        if e1 is not None and e2 is not None and (e != e1 or e != e2):
            raise ValueError("Invalid decrytion exponent (d)")
        else:
            print(f"Valid encrytion exponent: {e}")
    else:
        # Check if e1 and e2 are valid
        if e1 is not None and 0 < e1 < phi_N and gcd(e1, phi_N) == 1:
            print(f"Valid encrytion exponent: e1 = {e1}")
        else:
            print(f"Invalid encrytion exponent: {e1} because GCD(e1,Phi_N) different 1")

        if e2 is not None and 0 < e2 < phi_N and gcd(e2, phi_N) == 1:
            print(f"Valid public exponent: e2 = {e2}")
        else:
            print(f"Invalid public exponent: {e2} because GCD(e1,Phi_N) different 1")

        # Choose the smaller valid exponent
        if e1 is not None and e2 is not None:
            e = min(e1, e2)
            print(f"Choosing the smaller valid public exponent: {e}")

    # Calculate private exponent d if e is provided
    if e is not None:
        d = mod_inverse(e, phi_N)
        print(f"Compute the decryption exponent d: d = e^(-1) mod phi(N) = {e}^(-1) mod {phi_N} = {d}")

    # Return public and private keys
    public_key = (N, e)
    private_key = (N, d)

    return public_key, private_key

def get_valid_input(prompt, is_valid, error_message):
    while True:
        try:
            user_input = int(input(prompt))
            if is_valid(user_input):
                return user_input
            else:
                print(error_message)
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

# Prompt user for prime numbers p and q
p = get_valid_input("Enter prime number p: ", lambda x: x > 1, "Please enter a prime number greater than 1.")
q = get_valid_input("Enter prime number q: ", lambda x: x > 1, "Please enter a prime number greater than 1.")

# Prompt user to choose e or d
choice_ed = input("Choose public exponent type (e/d): ")

if choice_ed.lower() == 'e':
    # Prompt user for the number of public exponents
    num_e = get_valid_input("Enter the number of public exponents (1 or 2): ", lambda x: x in [1, 2], "Please enter 1 or 2.")

    if num_e == 1:
        # Prompt user for public exponent e
        e = get_valid_input("Enter public exponent e: ", lambda x: x > 1, "Please enter a valid public exponent greater than 1.")
        e1 = e2 = e  # Set e1 and e2 to e since they are not needed
        phi_N = (p - 1) * (q - 1)  # Calculate Euler's totient function
        d = mod_inverse(e, phi_N)
        print(f"Compute the decryption exponent d: d = e^(-1) mod phi(N) = {e}^(-1) mod {phi_N} = {d}")

    elif num_e == 2:
        # Prompt user for public exponents e1 and e2
        e1 = get_valid_input("Enter public exponent e1: ", lambda x: x > 1, "Please enter a valid public exponent greater than 1.")
        e2 = get_valid_input("Enter public exponent e2: ", lambda x: x > 1, "Please enter a valid public exponent greater than 1.")
        e = None  # Set e to None since it's not needed
    else:
        print("Invalid number of public exponents. Exiting.")
        exit()

    d = None  # Set d to None since it's not needed
elif choice_ed.lower() == 'd':
    # Prompt user for private exponent d
    d = get_valid_input("Enter private exponent d: ", lambda x: x > 1, "Please enter a valid private exponent greater than 1.")
    e1 = e2 = None  # Set e1 and e2 to None since they are not needed
else:
    print("Invalid choice. Exiting.")
    exit()

# Generate key pair
try:
    public_key, private_key = generate_keypair(p, q, e1=e1, e2=e2, d=d)
    print("\nKey Generation Successful")
except ValueError as e:
    print(f"Error in key generation: {e}")
    exit()

# Prompt user to choose C or M
choice_cm = input("Choose input type (C/M): ")

if choice_cm.lower() == 'm':
    # Prompt user for the plaintext message M
    M = get_valid_input("Enter the plaintext message (M): ", lambda x: x >= 0, "Please enter a non-negative integer.")
    
    # Encryption
    C = pow(M, public_key[1], public_key[0])  # Encrypt to get the ciphertext
    
    # Print results
    print(f"\nChosen public exponent (e): {public_key[1]}")
    print(f"Public Key (N, e): {public_key}")
    print(f"Private Key (N, d): {private_key}")
    print(f"Original Message (M): {M}")
    print(f"Encryption: C = M^e mod N = {M}^{public_key[1]} mod {public_key[0]} = {C}")
    print(f"C(Ciphertext): = {C}")
    
elif choice_cm.lower() == 'c':
    # Prompt user for the ciphertext C
    C = get_valid_input("Enter the ciphertext (C): ", lambda x: x >= 0, "Please enter a non-negative integer.")
    
    # Decryption
    M_decrypted = pow(C, private_key[1], private_key[0])  # Decrypt to get the plaintext
    
    # Print results
    print(f"\nChosen private exponent (d): {private_key[1]}")
    print(f"Public Key (N, e): {public_key}")
    print(f"Private Key (N, d): {private_key}")
    print(f"Original Ciphertext (C): {C}")
    print(f"Decryption: M = C^d mod N = {C}^{private_key[1]} mod {private_key[0]} = {M_decrypted}")
    print(f"Decrypted Message, M(PlainText) = {M_decrypted}")

else:
    print("Invalid choice. Exiting.")
    exit()
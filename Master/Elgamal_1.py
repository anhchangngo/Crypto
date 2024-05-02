from sympy import mod_inverse

# Function to calculate ElGamal signature
def elgamal_sign(x, k, d, p, alpha):
    # Calculate r
    r = pow(alpha, k, p)
    # Calculate s
    k_inv = mod_inverse(k, p-1)
    s = (k_inv * (x - d*r)) % (p-1)
    return r, s

# Function to verify ElGamal signature
def elgamal_verify(x, r, s, p, alpha, beta):
    # Verify r and s
    left = (pow(beta, r, p) * pow(r, s, p)) % p
    right = pow(alpha, x, p)
    return left == right

# Taking user input for ElGamal parameters
print("Calculating ElGamal signature and verifying messages and certificates:")
p = int(input("Enter the prime number p: "))
alpha = int(input("Enter the generator alpha: "))
d = int(input("Enter the private key d: "))
x = int(input("Enter the message x: "))
kE = int(input("Enter the ephemeral key kE:"))

# Given parameters
beta = pow(alpha, d, p)
# Part A: Calculate ElGamal signature
print("\nPart A: Calculating ElGamal signature for message from Bob to Alice:")
r, s = elgamal_sign(x, kE, d, p, alpha)
print(f"beta = alpha^d mod p = {alpha}^{d} mod {p} = {beta} mod {p}")
# Print results and calculations for Part A
print(f"   Message: {x}, ephemeral key: {kE}")
print(f"   Intermediate calculations for Part A:")
print(f"      Compute r : alpha^kE mod p = {alpha}^{kE} mod {p} = {pow(alpha, kE, p)} mod {p} = {r} mod {p}")
print(f"      Compute kE^(-1) mod (p-1) : kE^(-1) mod (p-1) = {kE}^(-1) mod {p-1} = {mod_inverse(kE, p-1)} mod {p-1}")
print(f"      Compute s : kE^(-1) * (x - d*r) mod (p-1) = {mod_inverse(kE, p-1)} * ({x} - {d}*{r}) mod {p-1} = {s} mod {p-1}")
print(f"   Signature (r, s): ({r}, {s})")

# Verify the signature
t = (pow(beta, r, p) * pow(r, s, p)) % p
alpha_xi_mod_p = pow(alpha, x, p)
verify_signature = elgamal_verify(x, r, s, p, alpha, beta) and (alpha_xi_mod_p == t)
print(f"   Verification: {verify_signature}")
print(f"      r: {r}, s: {s}, alpha^x: {alpha_xi_mod_p}, t: {t}")

# Part B: Verify messages from Bob
print("\nPart B: Verifying messages from Bob:")
message_1 = int(input("Enter x1: "))
r_1 = int(input("Enter r_1: "))
s_1 = int(input("Enter s_1: "))

message_2 = int(input("Enter x2: "))
r_2 = int(input("Enter r_2: "))
s_2 = int(input("Enter s_2: "))

# Verify messages from Bob for Part B
t_1 = (pow(beta, r_1, p) * pow(r_1, s_1, p)) % p
alpha_xi_mod_p_1 = pow(alpha, message_1, p)
verify_message_1 = elgamal_verify(message_1, r_1, s_1, p, alpha, beta) and (alpha_xi_mod_p_1 == t_1)

t_2 = (pow(beta, r_2, p) * pow(r_2, s_2, p)) % p
alpha_xi_mod_p_2 = pow(alpha, message_2, p)
verify_message_2 = elgamal_verify(message_2, r_2, s_2, p, alpha, beta) and (alpha_xi_mod_p_2 == t_2)

# Print results for messages from Bob for Part B
print(f"   Message 1 Verification: {verify_message_1}")
print(f"      Compute alpha^x_1 mod p= {alpha}^{message_1} mod {p} = {alpha_xi_mod_p_1} mod {p}")
print(f"      Compute t_1 mod p = (beta^r_1 * r_1^s_1) mod p = ({beta}^{r_1} * {r_1}^{s_1}) mod {p} = {t_1} mod {p}")
print(f"   Message 2 Verification: {verify_message_2}")
print(f"      Compute alpha^x_2 mod p = {alpha}^{message_2} mod {p} = {alpha_xi_mod_p_2} mod {p}")
print(f"      Compute t_2 mod p = (beta^r_2 * r_2^s_2) mod p = ({beta}^{r_2} * {r_2}^{s_2}) mod {p} = {t_2} mod {p}")

# Part C: Verify CertA and CertB signatures
print("\nPart C: Verifying Certificates:")
IDA = int(input("Enter IDA: "))
bA = int(input("Enter bA: "))
kE_A = int(input("Enter KE_A: "))
IDB = int(input("Enter IDB: "))
bB = int(input("Enter bB: "))
kE_B = int(input("Enter KE_B:"))

# Compute xi for CertA and CertB for Part C
xi_A = (147 * bA + IDA)
xi_B = (147 * bB + IDB)
print(f"X_A = {xi_A}")
print(f"X_B = {xi_B}")

# Compute CertA and CertB signatures for Part C
print("1. Computing CertA signature:")
r_A, s_A = elgamal_sign(xi_A, kE_A, d, p, alpha)

print("2. Computing CertB signature:")
r_B, s_B = elgamal_sign(xi_B, kE_B, d, p, alpha)

# Verify CertA and CertB signatures for Part C
t_A = (pow(beta, r_A, p) * pow(r_A, s_A, p)) % p
alpha_xi_mod_p_A = pow(alpha, xi_A, p)
verify_certA = elgamal_verify(xi_A, r_A, s_A, p, alpha, beta) and (alpha_xi_mod_p_A == t_A)

t_B = (pow(beta, r_B, p) * pow(r_B, s_B, p)) % p
alpha_xi_mod_p_B = pow(alpha, xi_B, p)
verify_certB = elgamal_verify(xi_B, r_B, s_B, p, alpha, beta) and (alpha_xi_mod_p_B == t_B)

# Print results for CertA and CertB for Part C
print(f"3. Certificate A Verification: {verify_certA}")
print(f"   Intermediate calculations for CertA:")
print(f"      Compute r_A : alpha^kE_A mod {p} = {alpha}^{kE_A} mod {p} = {pow(alpha, kE_A, p)} mod {p} = {r_A} mod {p}")
print(f"      Compute kE_A^(-1) mod (p-1) : kE_A^(-1) mod (p-1) ={kE_A}^(-1) mod {p-1} ={mod_inverse(kE_A, p-1)} mod {p}")
print(f"      Compute s_A : kE_A^(-1)  * (xi_A - d*r_A) mod (p-1) ={mod_inverse(kE_A, p-1)} * ({xi_A} - {d}*{r_A}) mod {p-1} ={s_A} mod {p-1}")
print(f"      Compute alpha^xi_A : {alpha}^{xi_A} mod {p} = {alpha_xi_mod_p_A} mod {p}")
print(f"      Compute t_A : (beta^r_A * r_A^s_A) mod p = ({beta}^{r_A} * {r_A}^{s_A}) mod {p} = {t_A} mod {p}")
print("----------------------------")
print(f"   Certificate B Verification: {verify_certB}")
print(f"   Intermediate calculations for CertB:")
print(f"      Compute r_B : alpha^kE_B mod {p} = {alpha}^{kE_B} mod {p}  = {pow(alpha, kE_B, p)} mod {p} = {r_B} mod {p}")
print(f"      Compute kE_B^(-1) mod (p-1) : kE_B^(-1) mod (p-1) = {kE_B}^(-1) mod {p-1} = {mod_inverse(kE_B, p-1)} mod {p}")
print(f"      Compute s_B : kE_B^(-1) * (xi_B - d*r_B) mod (p-1) = {mod_inverse(kE_B, p-1)} * ({xi_B} - {d}*{r_B}) mod {p-1} = {s_B} mod {p-1}")
print(f"      Compute alpha^xi_B : {alpha}^{xi_B} mod {p} = {alpha_xi_mod_p_B} mod {p}")
print(f"      Compute t_B : (beta^r_B * r_B^s_B) mod p = ({beta}^{r_B} * {r_B}^{s_B}) mod {p} = {t_B} mod {p}")
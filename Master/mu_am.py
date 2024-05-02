def mod_inverse(a, m):
    # Tìm modulo nghịch đảo của a modulo m
    g, x, y = extended_gcd(a, m)
    if g != 1:
        raise ValueError(f"{a} không có modulo nghịch đảo modulo {m}")
    else:
        return x % m

def extended_gcd(a, b):
    # Thuật toán Euclid mở rộng để tìm GCD và coefficients x, y
    if a == 0:
        return b, 0, 1
    else:
        g, x, y = extended_gcd(b % a, a)
        return g, y - (b // a) * x, x

def calculate_mod_pow(base, exponent, modulus):
    # Tính a^b modulo m với exponent là số âm
    inverse_base = mod_inverse(base, modulus)
    return pow(inverse_base, -exponent, modulus)

# Ví dụ sử dụng
p = 592 # for p - 1
x = 215
e = -1


# Tính x^-e mod p
result = calculate_mod_pow(x, e, p)
print(f"Kết quả: {result}")
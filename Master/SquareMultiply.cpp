#include <iostream>
//algorithm
long long square_and_multiply(long long x, long long e, long long m) {
    long long result = 1; // dùng long long thay vì int vì nó có thể lưu chữ các giá trị nguyên lớn hơn so với int
    x = x % m;  // Đảm bảo x nằm trong khoảng [0, m) không bị lệch ra khỏi modul

    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * x) % m;
        }
        e = e / 2;
        x = (x * x) % m;
    }

    return result;


}

int main() {
    long long x, e, m;
    std::cout << "Input value of base (x): ";
    std::cin >> x;
    std::cout << "Input value of power (e): ";
    std::cin >> e;
    std::cout << "Input value of modulo (m): ";
    std::cin >> m;
    
    long long result = square_and_multiply(x, e, m);
    std::cout << x << "^" << e << " mod " << m << " = " << result << std::endl;
    return 0;
}

// ollama run codellama
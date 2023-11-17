#include "Drob.h"
#include <iostream>

int main() {
    Drob a;
    Drob b;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "a is: " << a << '\n';
    std::cout << "b is: " << b << '\n';
    std::cout << "unchange operations:\n";
    std::cout << '\t' << "a + b: " << a + b << '\n';
    std::cout << '\t' << "a - b: " << a - b << '\n';
    std::cout << '\t' << "a * b: " << a * b << '\n';
    std::cout << '\t' << "a / b: " << a / b << '\n';
    std::cout << '\t' << "!a: " << !a << '\n';
    std::cout << '\t' << "-a: " << -a << '\n';
    std::cout << "change operations:\n";
    std::cout << '\t' << "++a: " << ++a << '\n';
    std::cout << '\t' << "--a: " << --a << '\n';
    a *= b;
    std::cout << '\t' << "a *= b: " << a << '\n';
    a /= b;
    std::cout << '\t' << "a /= b: " << a << '\n';
    std::cout << "comparings:\n";
    std::cout << '\t' << "a > b" << (a > b) << '\n';
    std::cout << '\t' << "a < b" << (a < b) << '\n';
    std::cout << '\t' << "a == b" << (a == b) << '\n';
    std::cout << '\t' << "a != b" << (a != b) << '\n';
    std::cout << '\t' << "a <= b" << (a <= b) << '\n';
    std::cout << '\t' << "a >= b" << (a >= b) << '\n';
    return 0;
}

#include <iostream>

namespace test {
    int a = 1;
    int b = 1;
}

int main() {
    std::cout << test::a << " " << test::b << std::endl;
    return 0;
}
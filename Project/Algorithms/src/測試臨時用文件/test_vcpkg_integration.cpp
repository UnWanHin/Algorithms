#include <boost/math/special_functions/binomial.hpp>
#include <iostream>
#include <stdexcept>

int main() {
    try {
        // 计算组合数 C(n,k)
        int n = 10, k = 3;

        if (k < 0 || k > n) {
            throw std::invalid_argument("k must be between 0 and n");
        }

        double combinations = boost::math::binomial_coefficient<double>(n, k);

        std::cout << "组合数 C(" << n << "," << k << ") = " << combinations << std::endl;
        std::cout << "计算: " << n << "! / (" << k << "! * " << (n-k) << "!) = " << combinations << std::endl;

        // 更多示例
        std::cout << "\n其他组合数示例:" << std::endl;
        std::cout << "C(6,2) = " << boost::math::binomial_coefficient<double>(6, 2) << std::endl;  // 15
        std::cout << "C(8,4) = " << boost::math::binomial_coefficient<double>(8, 4) << std::endl;  // 70
        std::cout << "C(7,1) = " << boost::math::binomial_coefficient<double>(7, 1) << std::endl;  // 7

    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
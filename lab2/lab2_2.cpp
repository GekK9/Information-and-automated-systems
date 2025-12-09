#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    std::string numStr = std::to_string(abs(number));
    std::sort(numStr.begin(), numStr.end());

    int sortedNumber = std::stoi(numStr);

    std::cout << "Отсортированное число: " << sortedNumber << std::endl;

    return 0;
}
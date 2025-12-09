#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
    return y + sqrt(x) - x / y + exp(x * y);
}

double calculateS(double x, double y) {
    if (x < 1 && y < 1) {
        return f(pow(y, 2), pow(x, 2));
    } else {
        return f(sqrt(y), sqrt(x));
    }
}

int main() {
    double x, y;
    
    cout << "Введите значения x и y: ";
    cin >> x >> y;
    
    double result = calculateS(x, y);
    cout << "Значение s равно: " << result << endl;
    
    return 0;
}
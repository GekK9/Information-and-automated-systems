#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    const int n = 16;
    double a[n];
    
    cout << "Введите 16 действительных чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }
    
    double maxSum = a[0] + a[15];
    
    for (int i = 1; i < n / 2; i++) {
        double currentSum = a[i] + a[n - 1 - i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    
    cout << "Максимальная сумма пар: " << maxSum << endl;
    
    return 0;
}
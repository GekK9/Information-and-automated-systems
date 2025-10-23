#include <iostream>
using namespace std;

int main() {
    int n, m;
    
    cout << "Введите число n: ";
    cin >> n;
    cout << "Введите количество последних цифр m: ";
    cin >> m;

    int sum = 0;

    for (int i = 0; i < m; i++) {
        sum += n % 10; 
        n /= 10; 
    }
    cout << "Сумма последних " << m << " цифр равна: " << sum << endl;
    
    return 0;
}
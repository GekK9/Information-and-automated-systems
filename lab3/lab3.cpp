#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double calculateTotalCost(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Файл не найден.\n";
        return 0.0;
    }

    double total_cost = 0.0;
    string line;
    while(getline(file, line)) {
        size_t pos = 0;
        size_t delimPos;

        for(int i = 0; i < 4; ++i) {
            delimPos = line.find(';', pos);
            pos = delimPos + 1;
        }

        total_cost += stod(line.substr(pos));
    }
    file.close();
    return total_cost;
}

int main() {
    const char* filename = "inventory.txt";

    double totalCost = calculateTotalCost(filename);
    cout << "Суммарные затраты на оборудование: " << totalCost << " рублей.\n";

    return 0;
}
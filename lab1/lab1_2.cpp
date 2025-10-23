#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    
    cout << "Введите текст: ";
    getline(cin, text);
    
    string result = "";
    
    for (char c : text) {
        if (isalnum(c)) {
            result += tolower(c);
        }
    }
    
    cout << "Обработанный текст: " << result << endl;
    
    return 0;
}
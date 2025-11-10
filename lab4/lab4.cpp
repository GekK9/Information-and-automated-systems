#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct note {
    char fullName[50];
    char phoneNumber[13];
    int birthDate[3];
};

void createNotesFile() {
    ofstream file("notes.txt", ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    note notes[] = {
        {"Иванов Петр", "+79123456789", {15, 05, 1990}},
        {"Петрова Анна", "+79876543210", {10, 12, 1985}},
        {"Смирнов Алексей", "+79234567890", {25, 03, 1995}},
        {"Васильева Мария", "+79123456780", {05, 07, 1980}},
        {"Попов Евгений", "+79876543211", {30, 11, 1992}}
    };

    for (const auto &e : notes) {
        file.write(reinterpret_cast<const char*>(&e), sizeof(note));
    }

    file.close();
}

void searchByLastName(const char* lastName) {
    fstream file("notes.txt", ios::in | ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    note currentNote;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&currentNote), sizeof(note))) {
        char extractedLastName[50];
        sscanf(currentNote.fullName, "%[^ ]", extractedLastName);

        if (strcmp(lastName, extractedLastName) == 0) {
            cout << "ФИО: " << currentNote.fullName << endl;
            cout << "Телефон: " << currentNote.phoneNumber << endl;
            cout << "Дата рождения: " << currentNote.birthDate[0] << "." << currentNote.birthDate[1] << "." << currentNote.birthDate[2] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Человек с указанной фамилией не найден." << endl;
    }

    file.close();
}

int main() {
    createNotesFile();

    char inputLastName[50];
    cout << "Введите фамилию для поиска: ";
    cin.getline(inputLastName, 50);

    searchByLastName(inputLastName);

    return 0;
}
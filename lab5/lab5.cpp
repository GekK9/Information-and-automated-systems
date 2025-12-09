#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Comp {
private:
    int hard_disk_size; 
    int ram_size; 

public:

    Comp(int hdd = 0, int ram = 0) : hard_disk_size(hdd), ram_size(ram) {}; 

    ~Comp() {cout << "Компьютер удален." << endl; }

    void setHardDiskSize(int size) {hard_disk_size = size;}
    int getHardDiskSize() const {return hard_disk_size;}

    void setRamSize(int size) {ram_size = size;}
    int getRamSize() const {return ram_size;}
};

int randomFromArray(const int arr[], int size) {
    static default_random_engine generator((unsigned long) time(NULL));
    uniform_int_distribution<int> distribution(0, size - 1);
    return arr[distribution(generator)];
}
int main() {
    const int possible_hard_disks[] = {10, 20, 40, 80, 160};
    const int num_possible_values = sizeof(possible_hard_disks)/sizeof(possible_hard_disks[0]);

    Comp* computers[10];

    for (int i = 0; i < 10; ++i) {
        computers[i] = new Comp(randomFromArray(possible_hard_disks, num_possible_values));

        cout << "Объект №" << i + 1 << ": Жесткий диск - " << computers[i]->getHardDiskSize() << " Гб\n";
     }
     int *ram_sizes = new int[10];
    
     for (int i = 0; i < 10; ++i) {
        cout << "Объем RAM компьютера №" << i + 1 << ": ";
        cin >> ram_sizes[i];
     }

     for (int i = 0; i < 10; ++i) {
        delete computers[i];
     }
     delete [] ram_sizes;
     return 0;
}
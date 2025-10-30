#include <iostream>

class Comp {
private:
    double hardDiskSize; 
    double ramSize; 

public:
    Comp();
    Comp(double hdd, double ram); 

    ~Comp();

    void setHardDiskSize(double size);   
    double getHardDiskSize() const;  

    void setRamSize(double size);
    double getRamSize() const;  
};

Comp::Comp() : hardDiskSize(0.0), ramSize(0.0) {}

Comp::Comp(double hdd, double ram) : hardDiskSize(hdd), ramSize(ram) {}

Comp::~Comp() {}

void Comp::setHardDiskSize(double size) {
    hardDiskSize = size;
}

double Comp::getHardDiskSize() const {
    return hardDiskSize;
}

void Comp::setRamSize(double size) {
    ramSize = size;
}

double Comp::getRamSize() const {
    return ramSize;
}

int main() {
    Comp myComputer(500.0, 8.0);

    std::cout << "Объем жесткого диска: " << myComputer.getHardDiskSize() << " Гб\n";
    std::cout << "Объем оперативной памяти: " << myComputer.getRamSize() << " Гб\n";

    myComputer.setHardDiskSize(1000.0);
    myComputer.setRamSize(16.0);

    std::cout << "\nПосле изменения:\n";
    std::cout << "Новый объем жесткого диска: " << myComputer.getHardDiskSize() << " Гб\n";
    std::cout << "Новый объем оперативной памяти: " << myComputer.getRamSize() << " Гб\n";

    return 0;
}
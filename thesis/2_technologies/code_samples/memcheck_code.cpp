#include <iostream>

int main() {
    int no_value; // niezainicjalizowana zmienna
    int value{10};
    if(no_value == 0) { // użycie niezainicjalizowanej zmiennej
        std::cout << "No-value equal to zero. Setting value to 5." << std::endl;
        value = 5;
    }
    std::cout << "Value: " << value << std::endl;

    int* leak = new int[10]; // wyciek pamięci - brak delete[]
}
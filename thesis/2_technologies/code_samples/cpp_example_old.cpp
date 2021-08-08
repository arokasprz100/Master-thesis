#include <vector>
#include <iostream>

// klasa abstrakcyjna reprezentująca zasilacz, udostępnia interfejs pozwalający
// na ustawienie wartości napięcia
class PowerSupply {
public:
    virtual ~PowerSupply() {};
    virtual void set_voltage(double value) const = 0;
};

// klasa reprezentująca konkretny typ zasilacza
class CaenPowerSupply : public PowerSupply {
public: 
    void set_voltage(double value) const {
        std::cout << "Setting voltage to value: " << value << std::endl; 
    }
};

// klasa reprezentująca atrapę (mock) zasilacza
class MockPowerSupply : public PowerSupply {
public: 
    void set_voltage(double value) const {
        std::cout << "Setting mock voltage to value: " << value << std::endl;
    }
};


int main() {
    // utworzenie i wypełnienie kontenera przechowującego wskaźniki 
    // zawierające adresy obiektów reprezentujących zasilacze
    std::vector<PowerSupply*> power_supply_units;
    power_supply_units.push_back(new CaenPowerSupply());
    power_supply_units.push_back(new MockPowerSupply());

    // iteracja po kontenerze, polimorficzne wywołanie metody set_voltage
    for(std::vector<PowerSupply*>::const_iterator it = power_supply_units.begin(); it != power_supply_units.end(); ++it) {
        (*it)->set_voltage(2.5);
    }

    // zwalnianie pamięci
    delete power_supply_units[0];
    delete power_supply_units[1];
}
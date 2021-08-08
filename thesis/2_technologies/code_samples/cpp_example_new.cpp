#include <vector>
#include <iostream>
#include <memory>

// klasa abstrakcyjna reprezentująca zasilacz, udostępnia interfejs pozwalający
// na ustawienie wartości napięcia
class PowerSupply {
public:
    virtual ~PowerSupply() = default;
    virtual void set_voltage(double value) const = 0;
};

// klasa reprezentująca konkretny typ zasilacza
class CaenPowerSupply final : public PowerSupply {
public: 
    void set_voltage(double value) const override {
        std::cout << "Setting voltage to value: " << value << std::endl; 
    }
};

// klasa reprezentująca atrapę (mock) zasilacza
class MockPowerSupply final : public PowerSupply {
public: 
    void set_voltage(double value) const override {
        std::cout << "Setting mock voltage to value: " << value << std::endl;
    }
};


int main() {
    // utworzenie i wypełnienie kontenera przechowującego inteligentne 
    // wskaźniki zawierające adresy obiektów reprezentujących zasilacze
    std::vector<std::unique_ptr<PowerSupply>> power_supply_units{};
    power_supply_units.emplace_back(new CaenPowerSupply());
    power_supply_units.emplace_back(new MockPowerSupply());

    // iteracja po kontenerze, polimorficzne wywołanie metody set_voltage
    for(const auto& psu : power_supply_units) {
        psu->set_voltage(2.5);
    }
}
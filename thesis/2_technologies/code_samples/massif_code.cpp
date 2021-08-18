#include <iostream>
#include <vector>
#include <unistd.h>

constexpr unsigned int NUMBER_OF_SAMPLES{100000};

int main() {
    std::vector<int*> measurement_history{};

    // pętla symulująca następujący cyklicznie pomiar
    // o przerwaniu lub kontynuacji pomiaru decyduje użytkownik
    do {
        sleep(1);
        measurement_history.push_back(new int[NUMBER_OF_SAMPLES]);
        std::cout << "Measurement performed. Press q to stop or anything else to continue ..." << std::endl;
    } while(std::cin.get() != 'q');

    // zwolnienie zaalokowaneej pamięci
    for(int* iteration: measurement_history) {
        delete [] iteration;
    }
    sleep(1);
}
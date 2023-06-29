#include "input_seged.h"
#include <iostream>
#include <limits>
int felhasznaloInput(){
    std::string in;
    std::cin.sync();
    std::cout << ">> ";
    std::getline(std::cin, in);
    // ha csak entert nyomott
    if (in.empty()) {
        std::cout << "Nem adott meg bemeneti erteket." << std::endl;
        return -1;
    }
    int ertek;
    try {
        ertek = std::stoi(in);
    } catch (const std::exception& e) {
        std::cout << "Nincs ilyen menupont." << std::endl;
    }
    return ertek;
}

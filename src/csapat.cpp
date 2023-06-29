#include "string.h"
#include "csapat.h"
#include "memtrace.h"
// default konstruktor
Csapat::Csapat(String nv, int asz):nev(nv), alapletszam(asz){ };
// destruktor
Csapat::~Csapat() { };
// vissza adja a csapat nevét
String Csapat::getNev() const { return nev; };
// vissza adja a csapat alaplétszámát
int Csapat::getAlapletszam() const { return alapletszam; };
// kiírja a csapat nevét és alaplétszámát a konzolra
void Csapat::kiir() const {
    std::cout << "Név: " << nev.c_str() << "; Alaplétszám: "
    << alapletszam << ";" << std::endl;
};
// értékadó operátor
Csapat& Csapat::operator=(const Csapat& masik) {
    if (this != &masik) {
        this->nev = masik.getNev().c_str();
        this->alapletszam = masik.getAlapletszam();
    }
    return *this;
}

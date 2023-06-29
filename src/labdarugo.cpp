#include "labdarugo.h"
#include "string.h"
#include "csapat.h"
#include "edzo.h"
#include "tipusok.h"
#include "memtrace.h"
// default konstruktor
Labdarugo::Labdarugo(String lnev, int asz, String foedz, String masod)
:Csapat(lnev,asz),foedzo(foedz),masodedzo(masod) { };
// destruktor
Labdarugo::~Labdarugo() { };
// csapat tipusának lekérdezése
int Labdarugo::getTipus() const{ return labdarugo; };
// csapat fő edzőjének lekérdezése
Edzo Labdarugo::getFoedzo() const { return foedzo; };
// csapat másod edzőjének lekérdezése
Edzo Labdarugo::getMasodedzo() const { return masodedzo; };
// csapat adatainak kiírása a konzolra
void Labdarugo::kiir() const{
    std::cout << "Labdarugo csapat:" << std::endl;
    std::cout << "Nev: " << getNev().c_str() << std::endl;
    std::cout << "Alapletszam: " << getAlapletszam() << std::endl;
    std::cout << "Fo edzo: " << foedzo.getNev().c_str() << std::endl;
    std::cout << "Masod edzo: " << masodedzo.getNev().c_str() << std::endl;
}
// értékadó operátor
Labdarugo& Labdarugo::operator=(const Labdarugo& masik) {
    if (this != &masik) {
        Csapat::operator=(masik);
        this->foedzo.setNev(masik.foedzo.getNev());
        this->masodedzo.setNev(masik.masodedzo.getNev());
    }
    return *this;
}

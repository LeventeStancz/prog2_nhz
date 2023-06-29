#include "kosar.h"
#include "string.h"
#include "pompomlany.h"
#include "csapat.h"
#include "edzo.h"
#include "tipusok.h"
#include "memtrace.h"
// default konstruktor
Kosar::Kosar(const String& lnev, int asz, const String& foedz, PomPomLany* lany):Csapat(lnev, asz),edzo(foedz),hossz(0){
    // egy pompom lány mindenképp kell (feladat spec.)
    hozzaad(lany);
}
// destruktor
Kosar::~Kosar(){
    // tároló elemeinek felszabadítása
    for(size_t i = 0; i < hossz; ++i){
        delete lanyok[i];
    }
    delete[] lanyok;
}
// aktuális méret lekérdezése
size_t Kosar::meret() const { return hossz; };
// csapat tipusának lekérdezése
int Kosar::getTipus() const { return kosarlabda; };
// csapat edzőjének lekérdezése
Edzo Kosar::getEdzo() const { return edzo; };
// csapat adatainak kiírása a konzolra
void Kosar::kiir() const{
    std::cout << "Kosar csapat:" << std::endl;
    std::cout << "Nev: " << getNev().c_str() << std::endl;
    std::cout << "Alapletszam: " << getAlapletszam() << std::endl;
    std::cout << "Edzo: " << edzo.getNev().c_str() << std::endl;
    std::cout << "Pom-pom lanyok: " << std::endl;
    for (size_t i = 0; i < hossz; ++i) {
        std::cout << "id: " << (i+1) << " - " << lanyok[i]->getNev().c_str() << std::endl;
    }
}
// pompom lány hozzáadása a tárolóhoz
void Kosar::hozzaad(PomPomLany* add_lany){
    // új terület lefoglalása
    PomPomLany** tmp = new PomPomLany*[hossz+1];
    // jelenlegi pompom lányok átmásolása
    for(size_t i = 0; i < hossz; ++i){
        tmp[i] = lanyok[i];
    }
    // új pompom lány felvétele
    tmp[hossz] = add_lany;
    if(hossz != 0) delete[] lanyok;
    lanyok = tmp;
    // méret növelése
    ++hossz;
}
// pompom lány eltávolítása index alapján
void Kosar::eltavolit(size_t index){
    // legalább egy pompom lánynak kell lennie a tárolóban (feladat spec.)
    if((hossz-1) < 1){
        throw std::invalid_argument("Legalabb egy pompom lanya kell legyen a kosarlabda csapatnak.");
    }
    // kivétel kezelés nem megfelelő index esetére
    if(index > (hossz-1)){
        throw std::out_of_range("Nem megfelelo id.");
    }
    // pompom lány törlése
    delete lanyok[index];
    // adatok csúsztatása
    for(size_t i = index; i < hossz - 1; ++i){
        lanyok[i] = lanyok[i+1];
    }
    // új terület lefoglalása
    PomPomLany** tmp = new PomPomLany*[hossz-1];
    // adatok átmásolása
    for (size_t i = 0; i < hossz - 1; ++i) {
        tmp[i] = lanyok[i];
    }
    delete[] lanyok;
    lanyok = tmp;
    //méret csökkentése
    --hossz;
}
// index operátor
PomPomLany* Kosar::operator[](size_t index) const{
    // kivétel kezelése
    if(index >= hossz){
        throw std::out_of_range("Nem megfelelo index!");
    }
    return lanyok[index];
}
// értékadó operátor
Kosar& Kosar::operator=(const Kosar& masik){
    if (this != &masik) {
        Csapat::operator=(masik);
        this->edzo.setNev(masik.edzo.getNev());
        // másik csapat pompom lányainak hozzáadása a jelenlegi csapatéhoz
        for(size_t i = 0; i < masik.meret(); ++i){
            hozzaad(new PomPomLany(masik[i]->getNev()));
        }
    }
    return *this;
}

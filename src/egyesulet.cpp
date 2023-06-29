#include "egyesulet.h"
#include "string.h"
#include "csapat.h"
#include "memtrace.h"
// az összes tárolt csapat felszabadítása
void Egyesulet::deleteCsapatok(){
    if (csapatok != nullptr) {
        for (size_t i = 0; i < meret; ++i) {
            delete csapatok[i];
        }
        delete[] csapatok;
        csapatok = nullptr;
    }
    meret = 0;
}
// default konstruktor
Egyesulet::Egyesulet(String nv):meret(0),nev(nv){
    csapatok = nullptr;
};
// destruktor
Egyesulet::~Egyesulet(){
    deleteCsapatok();
}
// aktuális méret lekérdezése
size_t Egyesulet::getMeret() const{ return meret; };
// egyesület nevének lekérdezése
String Egyesulet::getNev() const{ return nev; };
// egyesület adatainak és a tárolt csapatok adatainak kiírása a konzolra
void Egyesulet::kiir() const{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Az egyesulet neve: " << nev << std::endl;
    std::cout << "Csapatok:" << std::endl;
    std::cout << "------------------------------" << std::endl;
    if(meret == 0){
        std::cout << "Az egyesuletnek jelenleg nincs csapata." << std::endl;
    }else{
        for(size_t i = 0; i < meret; ++i){
            std::cout << "id: " << (i+1) << "." << std::endl;
            csapatok[i]->kiir();
            std::cout << "------------------------------" << std::endl;
        }
    }
}
// csapat hozzáadása a tárolóhoz
void Egyesulet::hozzaad(Csapat* add){
    // terület lefoglalása
    Csapat** tmp = new Csapat*[meret+1];
    // jelenlegi adatok átmásolása
    for(size_t i = 0; i < meret; ++i){
        tmp[i] = csapatok[i];
    }
    // új csapat beillesztése
    tmp[meret] = add;
    // régiek törlése
    delete[] csapatok;
    // felülírása
    csapatok = tmp;
    // méret növelése
    ++meret;
}
// csapat eltávolítása a tárolóból
void Egyesulet::eltavolit(size_t index){
    // index kezelése
    if(index >= meret){
        throw std::out_of_range("Nem megfelelo id!");
    }
    // csapat törlése
    delete csapatok[index];
    // adatok csúsztatása
    for(size_t i = index; i < meret - 1; ++i){
        csapatok[i] = csapatok[i+1];
    }
    // új terület lefoglalása
    Csapat** tmp = new Csapat*[meret-1];
    // adatok átmásolása
    for (size_t i = 0; i < meret - 1; ++i) {
        tmp[i] = csapatok[i];
    }
    // régiek törlése
    delete[] csapatok;
    // felülírás
    csapatok = tmp;
    // méret csökkentése
    --meret;
}
// index operátor
Csapat* Egyesulet::operator[](size_t index) const{
    // index kezelése
    if(index >= meret){
        throw std::out_of_range("Nem megfelelo index!");
    }
    return csapatok[index];
}

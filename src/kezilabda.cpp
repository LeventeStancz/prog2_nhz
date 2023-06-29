#include "kezilabda.h"
#include "string.h"
#include "csapat.h"
#include "edzo.h"
#include "tipusok.h"
#include "memtrace.h"
// Default konstruktor
Kezilabda::Kezilabda(String lnev, int asz, String edz, int t_osszeg, String u_tamogatas)
:Csapat(lnev,asz),edzo(edz),tamogatas_osszeg(t_osszeg),utolso_tamogatas(u_tamogatas) { };
// Destruktor
Kezilabda::~Kezilabda(){ };
// támogatás összegének lekérdezése
int Kezilabda::getTamogatasOsszeg() const{ return tamogatas_osszeg; };
// Utolsó támogatás idejének lekérdezése
String Kezilabda::getUtolsoTamogatas() const{ return utolso_tamogatas; };
// Csapat típusának lekérdezése
int Kezilabda::getTipus() const{ return kezilabda; };
// Edző lekérdezése
Edzo Kezilabda::getEdzo() const{ return edzo; };
// Csapat adatainak kiírása a konzolra
void Kezilabda::kiir() const{
    std::cout << "Kezilabda csapat:" << std::endl;
    std::cout << "Nev: " << getNev().c_str() << std::endl;
    std::cout << "Alapletszam: " << getAlapletszam() << std::endl;
    std::cout << "Edzo: " << edzo.getNev().c_str() << std::endl;
    std::cout << "Tamogatas osszeg: " << tamogatas_osszeg << std::endl;
    std::cout << "Utolso tamogatas: " << utolso_tamogatas.c_str() << std::endl;
}
// Csapat támogatása
void Kezilabda::tamogatas(int osszeg, String datum){
    //dátum ellenőrzés --> dátum formátum yyyy.mm.dd kell legyen.
    //év ellenőrzes --> ha ugyanaz az év hiba -->
    // --> csak évente (következő évben) kaphat tamogatást a csapat
    if(utolso_tamogatas[3] == datum[3]){
        throw std::invalid_argument("Csak a kovetkezo evben kaphat tamogatast a kezilabda csapat!");
    }
    tamogatas_osszeg += osszeg;
    utolso_tamogatas = datum;
}
// értékadó operátor
Kezilabda& Kezilabda::operator=(const Kezilabda& masik){
    if (this != &masik) {
        Csapat::operator=(masik);
        this->edzo.setNev(masik.edzo.getNev());
        this->tamogatas_osszeg = masik.getTamogatasOsszeg();
        this->utolso_tamogatas = masik.getUtolsoTamogatas();
    }
    return *this;
}

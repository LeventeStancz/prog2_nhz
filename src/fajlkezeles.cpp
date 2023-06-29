#include "egyesulet.h"
#include "labdarugo.h"
#include "kosar.h"
#include "pompomlany.h"
#include "kezilabda.h"
#include "tipusok.h"
#include "memtrace.h"
#include <iostream>
#include <fstream>
#include <cstring>
/// Fájl beolvasása
/// @return Egyesulet pointer
Egyesulet* FajlBeolvas(){
    std::fstream fajl;
    // fájl megnyitása
    fajl.open("adatbazis.txt", std::ios::in);
    // nem lehet megnyitni
    if(!fajl){
        throw std::runtime_error("Nincs adatbazis fajl!");
    }
    // üres a fájl
    if (fajl.peek() == std::ifstream::traits_type::eof())
    {
        throw std::runtime_error("Nincs adatbazis fajl!");
    }
    //beolvasas soronkent
    if (fajl.is_open()) {
        std::string sor;
        std::string egyseg;
        //első sor -> egyesület neve
        std::getline(fajl, sor);
        Egyesulet* egyesulet = new Egyesulet(String(sor.c_str()));
        //csapatok beolvasás (ha vannak)
        std::vector <std::string> tomb;
        while (std::getline(fajl, sor)) {
            std::stringstream seged(sor);
            //kiszervezés tömbbe
            while(std::getline(seged, egyseg, ';')){
                tomb.push_back(egyseg);
            }
            //eldöntes milyen tipusu a csapat
            switch((tomb[0].at(0) - '0')){
                case labdarugo:
                    {
                       //;nev;alapletszam;foedzo;masodedzo
                        Labdarugo* l = new Labdarugo(String(tomb[1].c_str()),
                                                     atoi(tomb[2].c_str()),
                                                     String(tomb[3].c_str()),
                                                     String(tomb[4].c_str()));
                        egyesulet->hozzaad(l);
                    }
                break;
                case kosarlabda:
                    {
                        //;nev;alapletszam;foedzo;...pompomlanyok...
                        //első pompomlánnyal létrehozzuk a kosár tároloját (1-nek kötelező lennie)
                        Kosar* k = new Kosar(String(tomb[1].c_str()),
                                             atoi(tomb[2].c_str()),
                                             String(tomb[3].c_str()),
                                             new PomPomLany(String(tomb[4].c_str())));
                        //ha van még pompomlany akkor hozzáadjuk a tárolóhoz
                        if(tomb.size() > 5){
                            for(auto it = (tomb.begin()+5); it != tomb.end(); ++it){
                                k->hozzaad(new PomPomLany(String((*it).c_str())));
                            }
                        }
                        egyesulet->hozzaad(k);
                    }
                break;
                case kezilabda:
                    {
                        //;nev;alapletszam;foedzo;osszeg;utolso_tamogatas
                        Kezilabda* k = new Kezilabda(String(tomb[1].c_str()),
                                             atoi(tomb[2].c_str()),
                                             String(tomb[3].c_str()),
                                             std::stod(tomb[4].c_str()),
                                             String(tomb[5].c_str()));
                        egyesulet->hozzaad(k);
                    }
                break;
                default:
                    break;
            }
            //tömb kiűrités
            tomb.clear();
        }
        fajl.close();
        return egyesulet;
    }
    return nullptr;
}
/// Fájlba írás
/// @param Egyesület referencia
void FajlbaIr(Egyesulet& egyesulet){
    std::fstream fajl;
    // fájl megnyitása
    fajl.open("adatbazis.txt", std::ios::out);
    // nem lehet megnyitni a fájlt
    if(!fajl){
        throw std::runtime_error("Nem lehet fajlt letrehozni!");
    }
    if (fajl.is_open()){
        //első sor egyesület neve
        fajl << egyesulet.getNev().c_str() << '\n';
        //csapatok beírása
        for(size_t i = 0; i < egyesulet.getMeret(); ++i){
            switch(egyesulet[i]->getTipus()){
                case labdarugo:
                    {
                        Labdarugo* l = dynamic_cast<Labdarugo*>(egyesulet[i]);
                        //tipus;nev;alapletszam;foedzo;masodedzo
                        fajl << labdarugo << ';' << l->getNev().c_str() << ';' << l->getAlapletszam() << ';';
                        fajl << l->getFoedzo().getNev().c_str() << ';';
                        fajl << l->getMasodedzo().getNev().c_str() << '\n';
                    }
                break;
                case kosarlabda:
                    {
                        Kosar* k = dynamic_cast<Kosar*>(egyesulet[i]);
                        //tipus;nev;alapletszam;foedzo;...pompomlanyok...
                        fajl << kosarlabda << ';' << k->getNev().c_str() << ';' << k->getAlapletszam() << ';';
                        fajl << k->getEdzo().getNev().c_str();
                        for(size_t j = 0; j < k->meret(); ++j){
                            fajl << ';' << (k->operator[](j))->getNev().c_str();
                        }
                        fajl << '\n';
                    }
                break;
                case kezilabda:
                    {
                        Kezilabda* k = dynamic_cast<Kezilabda*>(egyesulet[i]);
                        //tipus;nev;alapletszam;foedzo;osszeg;utolso_tamogatas
                        fajl << kezilabda << ';' << k->getNev().c_str() << ';' << k->getAlapletszam() << ';';
                        fajl << k->getEdzo().getNev().c_str() << ';' << k->getTamogatasOsszeg() << ';';
                        fajl << k->getUtolsoTamogatas().c_str() << '\n';
                    }
                break;
                default:
                    break;
            }
        }
    }
    fajl.close();
}

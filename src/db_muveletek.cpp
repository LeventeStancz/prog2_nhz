#include "db_muveletek.h"
#include "egyesulet.h"
#include "string.h"
#include "labdarugo.h"
#include "pompomlany.h"
#include "kosar.h"
#include "kezilabda.h"
#include "fajlkezeles.h"
#include "input_seged.h"
#include "tipusok.h"
#include "memtrace.h"
using namespace std;
// labdarugo felvétele
int LabdarugoFelvetel(Egyesulet& egyesulet){
    cout << "------------------------------" << endl;
    cout << "Labdarugo csapat letrehozasa:" << endl;
    cout << "Adja meg a csapat nevet: ";
    String nev;
    cin.clear();
    cin >> nev;
    cout << "------------------------------" << endl;
    int alapletszam;
    cout << "Adja meg a csapat alap letszamat (min. 2): ";
    cin.clear();
    cin >> alapletszam;
    cout << "------------------------------" << endl;
    if(alapletszam < 2){
        throw out_of_range("Nem megfelelo alap letszam!");
        return 4;
    }
    cout << "Adja meg a csapat fo edzojenek nevet: ";
    String foedzo;
    cin.clear();
    cin >> foedzo;
    cout << "------------------------------" << endl;
    cout << "Adja meg a csapat masod edzojenek nevet: ";
    String masod;
    cin.clear();
    cin >> masod;
    cout << "------------------------------" << endl;
    Labdarugo* l = new Labdarugo(nev, alapletszam, foedzo, masod);
    cout << "Megfeleloek az adatok?" << endl;
    l->kiir();
    int menuid;
    do{
        cout << "1. igen, mentes." << endl;
        cout << "2. nem, vissza a fomenube." << endl;
        menuid = felhasznaloInput();
        if(menuid == 1){
           egyesulet.hozzaad(l);
            try{
                FajlbaIr(egyesulet);
                cout << "Sikeres mentes!" << endl;
            }catch(const exception & error){
                cout << error.what() << endl;
            }
            break;
        }
    }while(menuid != 2);
    if(menuid == 2) delete l;
    return 4;
}
// kosar felvétele
int KosarFelvetel(Egyesulet& egyesulet){
    cout << "------------------------------" << endl;
    cout << "Kosarlabda csapat letrehozasa:" << endl;
    cout << "Adja meg a csapat nevet: ";
    String nev;
    cin.clear();
    cin >> nev;
    cout << "------------------------------" << endl;
    int alapletszam;
    cout << "Adja meg a csapat alap letszamat (min. 2): ";
    cin.clear();
    cin >> alapletszam;
    cout << "------------------------------" << endl;
    if(alapletszam < 2){
        throw out_of_range("Nem megfelelo alap letszam!");
        return 4;
    }
    cout << "Adja meg a csapat fo edzojenek nevet: ";
    String foedzo;
    cin.clear();
    cin >> foedzo;
    cout << "------------------------------" << endl;
    cout << "Adjon meg egy pompom lanyt: ";
    String lany_nev;
    cin.clear();
    cin >> lany_nev;
    PomPomLany* lany = new PomPomLany(lany_nev);
    cout << "------------------------------" << endl;
    Kosar* k = new Kosar(nev, alapletszam, foedzo, lany);
    cout << "Megfeleloek az adatok?" << endl;
    k->kiir();
    int menuid;
    do{
        cout << "1. igen, mentes." << endl;
        cout << "2. nem, vissza a fomenube." << endl;
        menuid = felhasznaloInput();
        if(menuid == 1){
           egyesulet.hozzaad(k);
            try{
                FajlbaIr(egyesulet);
                cout << "Sikeres mentes!" << endl;
            }catch(const exception & error){
                cout << error.what() << endl;
            }
            break;
        }
    }while(menuid != 2);
    if(menuid == 2) delete k;
    return 4;
}
// kezilabda felévtele
int KezilabdaFelvetel(Egyesulet& egyesulet){
    cout << "------------------------------" << endl;
    cout << "Kezilabda csapat letrehozasa:" << endl;
    cout << "Adja meg a csapat nevet: ";
    String nev;
    cin.clear();
    cin >> nev;
    cout << "------------------------------" << endl;
    int alapletszam;
    cout << "Adja meg a csapat alap letszamat (min. 2): ";
    cin.clear();
    cin >> alapletszam;
    cout << "------------------------------" << endl;
    if(alapletszam < 2){
        throw out_of_range("Nem megfelelo alap letszam!");
        return 4;
    }
    cout << "Adja meg a csapat fo edzojenek nevet: ";
    String foedzo;
    cin.clear();
    cin >> foedzo;
    cout << "------------------------------" << endl;
    Kezilabda* k = new Kezilabda(nev, alapletszam,foedzo,0,String("0000.00.00 - meg nincs"));
    cout << "Megfeleloek az adatok?" << endl;
    k->kiir();
    int menuid;
    do{
        cout << "1. igen, mentes." << endl;
        cout << "2. nem, vissza a fomenube." << endl;
        menuid = felhasznaloInput();
        if(menuid == 1){
           egyesulet.hozzaad(k);
            try{
                FajlbaIr(egyesulet);
                cout << "Sikeres mentes!" << endl;
            }catch(const exception & error){
                cout << error.what() << endl;
            }
            break;
        }
    }while(menuid != 2);
    if(menuid == 2) delete k;
    return 4;
}
// csapat modosítása menü
int CsapatModositasMenu(Egyesulet& egyesulet, int index){
    try{
        int menuid;
        do{
            Csapat* cs = egyesulet[(size_t)index];
            cout << "Ezt a csapatot szeretne modositani?" << endl;
            cs->kiir();
            cout << "1. igen, modositom a csapatot" << endl;
            cout << "2. nem, vissza a fomenube" << endl;
            menuid = felhasznaloInput();
            if(menuid == 1){
                menuid = CsapatModositas(cs, egyesulet);
            }
        }while(menuid != 2);
    }catch(const exception& err){
        cout << err.what() << endl;
    }
    return 0;
}
// csapat módosítása
int CsapatModositas(Csapat* cs, Egyesulet& egyesulet){
    switch(cs->getTipus()){
        case labdarugo:
            {
                Labdarugo* l_old = dynamic_cast<Labdarugo*>(cs);
                try{
                    LabdarugoModositas(l_old, egyesulet);
                }catch(const exception & error){
                    cout << error.what() << endl;
                }
            }
        break;
        case kosarlabda:
            {
                Kosar* k_old = dynamic_cast<Kosar*>(cs);
                try{
                    KosarModositasMenu(k_old, egyesulet);
                }catch(const exception & error){
                    cout << error.what() << endl;
                }
            }
        break;
        case kezilabda:
            {
                Kezilabda* k_old = dynamic_cast<Kezilabda*>(cs);
                try{
                    KezilabdaModositasMenu(k_old, egyesulet);
                }catch(const exception & error){
                    cout << error.what() << endl;
                }
            }
        break;
        default:
            break;
    }
    return 2;
}
// labdarugo módosítása
void LabdarugoModositas(Labdarugo* l_old, Egyesulet& egyesulet){
    cout << "------------------------------" << endl;
    cout << "Labdarugo csapat modositasa:" << endl;
    cout << "Adja meg a csapat nevet (" << l_old->getNev().c_str() << "): ";
    String nev;
    cin.clear();
    cin >> nev;
    cout << "------------------------------" << endl;
    int alapletszam;
    cout << "Adja meg a csapat alap letszamat (min. 2) (" << l_old->getAlapletszam() << "): ";
    cin.clear();
    cin >> alapletszam;
    cout << "------------------------------" << endl;
    if(alapletszam < 2){
        throw out_of_range("Nem megfelelo alap letszam!");
    }
    cout << "Adja meg a csapat fo edzojenek nevet (" << l_old->getFoedzo().getNev().c_str() << "): ";
    String foedzo;
    cin.clear();
    cin >> foedzo;
    cout << "------------------------------" << endl;
    cout << "Adja meg a csapat masod edzojenek nevet (" << l_old->getMasodedzo().getNev().c_str() << "): ";
    String masod;
    cin.clear();
    cin >> masod;
    cout << "------------------------------" << endl;
    Labdarugo* l = new Labdarugo(nev, alapletszam, foedzo, masod);
    cout << "Megfeleloek az adatok?" << endl;
    l->kiir();
    int menuid;
    do{
        cout << "1. igen, mentes." << endl;
        cout << "2. nem, vissza a fomenube." << endl;
        menuid = felhasznaloInput();
        if(menuid == 1){
            *l_old = *l;
            try{
                FajlbaIr(egyesulet);
                cout << "Sikeres mentes!" << endl;
            }catch(const exception & error){
                cout << error.what() << endl;
            }
            menuid = 2;
        }
    }while(menuid != 2);
    delete l;
}
// kosar módosítása menü
void KosarModositasMenu(Kosar* k_old, Egyesulet& egyesulet){
    int menuid;
    do{
        cout << "------------------------------" << endl;
        cout << "Kosarlabda csapat modositasa:" << endl;
        cout << "1. Csapat modositasa"<< endl;
        cout << "2. PomPom lany felvetele"<< endl;
        cout << "3. PomPom lany torlese"<< endl;
        cout << "4. Vissza a fomenube"<< endl;
        menuid = felhasznaloInput();
        switch(menuid){
            case 1:
                KosarModositas(k_old, egyesulet);
                menuid = 4;
            break;
            case 2:
                {
                    cout << "------------------------------" << endl;
                    cout << "PomPom lany felvetel:" << endl;
                    cout << "PomPom lany neve: ";
                    String lany_nev;
                    cin >> lany_nev;
                    try{
                        PomPomLany* lany = new PomPomLany(lany_nev);
                        k_old->hozzaad(lany);
                        cout << "Sikeres pompom lany felvetel!" << endl;
                        FajlbaIr(egyesulet);
                        cout << "Sikeres mentes!" << endl;
                    }catch(const exception & error){
                        cout << error.what() << endl;
                    }
                    menuid = 4;
                }
            break;
            case 3:
                {
                    cout << "------------------------------" << endl;
                    cout << "PomPom lany torlese:" << endl;
                    k_old->kiir();
                    cout << "PomPom lany id: " << endl;
                    int index = felhasznaloInput();
                    try{
                        k_old->eltavolit((size_t)(index-1));
                        cout << "Sikeres pompom lany torles!" << endl;
                        FajlbaIr(egyesulet);
                        cout << "Sikeres mentes!" << endl;
                    }catch(const exception& error){
                        cout << error.what() << endl;
                    }
                    menuid = 4;
                }
            break;
            default:
                break;
        }
    }while(menuid != 4);
}
// kosar módosítása
void KosarModositas(Kosar* k_old, Egyesulet& egyesulet){
    cout << "------------------------------" << endl;
    cout << "Kosarlabda csapat modositasa:" << endl;
    cout << "Adja meg a csapat nevet (" << k_old->getNev().c_str() << "): ";
    String nev;
    cin.clear();
    cin >> nev;
    cout << "------------------------------" << endl;
    int alapletszam;
    cout << "Adja meg a csapat alap letszamat (min. 2) (" << k_old->getAlapletszam() << "): ";
    cin.clear();
    cin >> alapletszam;
    cout << "------------------------------" << endl;
    if(alapletszam < 2){
        throw out_of_range("Nem megfelelo alap letszam!");
    }
    cout << "Adja meg a csapat edzojenek nevet (" << k_old->getEdzo().getNev().c_str() << "): ";
    String foedzo;
    cin.clear();
    cin >> foedzo;
    cout << "------------------------------" << endl;
    Kosar* k = new Kosar(nev, alapletszam, foedzo, new PomPomLany(k_old->operator[](0)->getNev()));
    if(k_old->meret() > 1){
        for(size_t i = 1; i < k_old->meret(); ++i){
            k->hozzaad(new PomPomLany(k_old->operator[](i)->getNev()));
        }
    }
    cout << "Megfeleloek az adatok?" << endl;
    k->kiir();
    int menuid;
    do{
        cout << "1. igen, mentes." << endl;
        cout << "2. nem, vissza a fomenube." << endl;
        menuid = felhasznaloInput();
        if(menuid == 1){
            *k_old = *k;
            try{
                FajlbaIr(egyesulet);
                cout << "Sikeres mentes!" << endl;
            }catch(const exception & error){
                cout << error.what() << endl;
            }
            menuid = 2;
        }
    }while(menuid != 2);
    delete k;
}
// kezilabda módosítása menü
void KezilabdaModositasMenu(Kezilabda* k_old, Egyesulet& egyesulet){
    int menuid;
    do{
        cout << "------------------------------" << endl;
        cout << "Kezilabda csapat modositasa:" << endl;
        cout << "1. Csapat modositasa"<< endl;
        cout << "2. Csapat tamogatasa"<< endl;
        cout << "3. Vissza a fomenube"<< endl;
        menuid = felhasznaloInput();
        switch(menuid){
            case 1:
                KezilabdaModositas(k_old, egyesulet);
                menuid = 3;
            break;
            case 2:
                {
                    cout << "------------------------------" << endl;
                    cout << "Kezilabda csapat tamogatasa:" << endl;
                    cout << "Adja meg az osszeget: ";
                    double osszeg;
                    cin >> osszeg;
                    cout << "Adja meg a datumot (yyyy.mm.dd): ";
                    String datum;
                    cin >> datum;
                    try{
                        k_old->tamogatas(osszeg, datum);
                        cout << "Sikeres tamogatas!" << endl;
                        FajlbaIr(egyesulet);
                        cout << "Sikeres mentes!" << endl;
                    }catch(const exception & error){
                        cout << "------------------------------" << endl;
                        cout << error.what() << endl;
                    }
                    menuid = 3;
                }
            break;
            default:
                break;
        }
    }while(menuid != 3);
}
// kezilabda módosítása
void KezilabdaModositas(Kezilabda* k_old, Egyesulet& egyesulet){
    cout << "------------------------------" << endl;
    cout << "Kezilabda csapat modositasa:" << endl;
    cout << "Adja meg a csapat nevet (" << k_old->getNev().c_str() << "): ";
    String nev;
    cin.clear();
    cin >> nev;
    cout << "------------------------------" << endl;
    int alapletszam;
    cout << "Adja meg a csapat alap letszamat (min. 2) (" << k_old->getAlapletszam() << "): ";
    cin.clear();
    cin >> alapletszam;
    cout << "------------------------------" << endl;
    if(alapletszam < 2){
        throw out_of_range("Nem megfelelo alap letszam!");
    }
    cout << "Adja meg a csapat edzojenek nevet (" << k_old->getEdzo().getNev().c_str() << "): ";
    String foedzo;
    cin.clear();
    cin >> foedzo;
    cout << "------------------------------" << endl;
    cout << "Adja meg a csapat tamogatasanak osszeget (" << k_old->getTamogatasOsszeg() << "): ";
    double osszeg;
    cin.clear();
    cin >> osszeg;
    cout << "------------------------------" << endl;
    cout << "Adja meg a csapat utolso tamogatasanak idejet (yyyy.mm.dd)(" << k_old->getTamogatasOsszeg() << "): ";
    String datum;
    cin.clear();
    cin >> datum;
    cout << "------------------------------" << endl;
    Kezilabda* k = new Kezilabda(nev, alapletszam, foedzo, osszeg, datum);
    cout << "Megfeleloek az adatok?" << endl;
    k->kiir();
    int menuid;
    do{
        cout << "1. igen, mentes." << endl;
        cout << "2. nem, vissza a fomenube." << endl;
        menuid = felhasznaloInput();
        if(menuid == 1){
            *k_old = *k;
            try{
                FajlbaIr(egyesulet);
                cout << "Sikeres mentes!" << endl;
            }catch(const exception & error){
                cout << error.what() << endl;
            }
            menuid = 2;
        }
    }while(menuid != 2);
    delete k;
}
// csapat törlése menü
int CsapatTorlesMenu(Egyesulet& egyesulet, int index){
    try{
        int menuid;
        do{
            Csapat* cs = egyesulet[(size_t)index];
            cout << "Ezt a csapatot szeretne torolni?" << endl;
            cs->kiir();
            cout << "1. igen, torlom a csapatot" << endl;
            cout << "2. nem, vissza a fomenube" << endl;
            menuid = felhasznaloInput();
            if(menuid == 1){
                menuid = CsapatTorles((size_t)index, egyesulet);
            }
        }while(menuid != 2);
    }catch(const exception& err){
        cout << err.what() << endl;
    }
    return 0;
}
// csapat törlése
int CsapatTorles(size_t index, Egyesulet& egyesulet){
    try{
        egyesulet.eltavolit(index);
        cout << "Sikeres torles!" << endl;
        FajlbaIr(egyesulet);
        cout << "Sikeres mentes!" << endl;
    }catch(const exception& err){
        cout << err.what() << endl;
    }
    return 2;
}

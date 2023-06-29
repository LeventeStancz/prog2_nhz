#include <iostream>
#include "egyesulet.h"
#include "string.h"
#include "teszt.h"
#include "fajlkezeles.h"
#include "tipusok.h"
#include "db_muveletek.h"
#include "input_seged.h"
#include "memtrace.h"

using namespace std;

Egyesulet* F_Beolvas(){
    try{
        return FajlBeolvas();
    }catch(const exception & error){
        cout << error.what() << endl;
        return nullptr;
    }
}

bool F_Ir(Egyesulet& e){
    try{
        cout << "Mentes!" << endl;
        FajlbaIr(e);
        return true;
    }catch(const exception & error){
        cout << error.what() << endl;
        return false;
    }
}

//1. menupont
void CsapatokKiirasa(Egyesulet& e);
//2. menupont
void Ujcsapat(Egyesulet& e);
//3. menupont
void CsapatModositas(Egyesulet& e);
//4. menupont
void CsapatTorles(Egyesulet& e);
//5.menupont
void Teszt();

int main()
{
    Teszt();
    #ifndef CPORTA

    cout << "A program megfelelo mukodesehez ne hasznaljon ekezetes karaktereket es a megadott minta szerint adjon meg specialis ertekeket!" << endl;
    Egyesulet* egyesulet = F_Beolvas();
    if(egyesulet == nullptr){
        cout << "Nincs megadva egyesulet.\nAdja meg az egyesulet nevet:" << endl;
        cout << ">> ";
        String nev;
        cin.clear();
        cin >> nev;
        if(nev.size() == 0){
            cout << "Nem adott meg egyesulet nevet." << endl;
            return 0;
        }
        egyesulet = new Egyesulet(nev);
        if(!F_Ir(*egyesulet)){
            return 0;
        }
    }

    int menuid;
    do {
        cout << "------------------------------" << endl;
        cout << "Egyesulet: " << egyesulet->getNev() << endl;
        cout << "------------------------------" << endl;
        cout << "Fomenu" << endl;
        cout << "1. Csapatok" << endl;
        cout << "2. Uj csapat felvetele" << endl;
        cout << "3. Csapat modositasa" << endl;
        cout << "4. Csapat torlese" << endl;
        cout << "5. Programteszt futtatasa" << endl;
        cout << "6. Kilepes" << endl;

        menuid = felhasznaloInput();

        if(menuid == -1) break;

        switch (menuid) {
            case 1:
                CsapatokKiirasa(*egyesulet);
                cout << "------------------------------" << endl;
                break;
            case 2:
                Ujcsapat(*egyesulet);
                cout << "------------------------------" << endl;
                break;
            case 3:
                CsapatModositas(*egyesulet);
                cout << "------------------------------" << endl;
                break;
            case 4:
                CsapatTorles(*egyesulet);
                cout << "------------------------------" << endl;
                break;
            case 5:
                Teszt();
                cout << "------------------------------" << endl;
                break;
            default:
                break;
        }
    }while(menuid != 6);
    delete egyesulet;
    return 0;

    #endif
}


//1. menupont
void CsapatokKiirasa(Egyesulet& egyesulet) {
    int menuid;
    do{
        cout << "------------------------------" << endl;
        egyesulet.kiir();
        cout << "------------------------------" << endl;
        cout << "1. Vissza a fomenube" << endl;
        menuid = felhasznaloInput();
    }while(menuid != 1);
}


//2. menupont
void Ujcsapat(Egyesulet& egyesulet) {
    int menuid;
    do{
        cout << "------------------------------" << endl;
        cout << "Uj csapat felvetele:" << endl;
        cout << "1. Labdarugo csapat felvetele" << endl;
        cout << "2. Kosarlabda csapat felvetele" << endl;
        cout << "3. Kezilabda csapat felvetele" << endl;
        cout << "4. Vissza a fomenube" << endl;
        cout << "------------------------------" << endl;
        menuid = felhasznaloInput();
        switch(menuid){
            case 1:
                try{
                    menuid = LabdarugoFelvetel(egyesulet);
                }catch(const exception& error){
                    cout << error.what() << endl;
                }
            break;
            case 2:
                try{
                    menuid = KosarFelvetel(egyesulet);
                }catch(const exception& error){
                    cout << error.what() << endl;
                }
            break;
            case 3:
                try{
                    menuid = KezilabdaFelvetel(egyesulet);
                }catch(const exception& error){
                    cout << error.what() << endl;
                }
            break;
            default:
                break;
        }
    }while(menuid != 4);
}


//3. menupont
void CsapatModositas(Egyesulet& egyesulet) {
    int menuid;
    do{
        cout << "------------------------------" << endl;
        cout << "Csapat modositasa:" << endl;
        egyesulet.kiir();
        cout << "Adja meg a modositani kivant csapat id-jet." << endl;
        cout << "------------------------------" << endl;
        cout << "0. Vissza a fomenube" << endl;
        menuid = felhasznaloInput();
        if(menuid != 0){
            try{
                menuid = CsapatModositasMenu(egyesulet, (menuid-1));
            }catch(const exception& error){
                cout << error.what() << endl;
            }
        }
    }while(menuid != 0);
}


//4. menupont
void CsapatTorles(Egyesulet& egyesulet) {
    int menuid;
    do{
        cout << "------------------------------" << endl;
        cout << "Csapat torlese:" << endl;
        egyesulet.kiir();
        cout << "Adja meg a torolni kivant csapat id-jet." << endl;
        cout << "------------------------------" << endl;
        cout << "0. Vissza a fomenube" << endl;
        menuid = felhasznaloInput();
        if(menuid != 0){
            try{
                menuid = CsapatTorlesMenu(egyesulet, (menuid-1));
            }catch(const exception& error){
                cout << error.what() << endl;
            }
        }
    }while(menuid != 0);
}


//5. menupont
void Teszt() {
    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;
    TesztFuttatas();
}



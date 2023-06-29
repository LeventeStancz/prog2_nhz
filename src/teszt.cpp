#include "string.h"
#include "egyesulet.h"
#include "labdarugo.h"
#include "kosar.h"
#include "kezilabda.h"
#include "gtest_lite.h"
#include <iostream>
using namespace std;
/// Tesztek
void EgyesuletTesztek();
void LabdarugoTesztek();
void KosarTesztek();
void KezilabdaTesztek();
/// Tesztek futtatása
void TesztFuttatas(){
    cout << "Tesztesetek futtatasa" << endl;
    cout << "------------------------------" << endl;
    cout << "Egyesulet tesztek:" << endl;
    EgyesuletTesztek();
    cout << "------------------------------" << endl;
    cout << "Labdarugo tesztek:" << endl;
    LabdarugoTesztek();
    cout << "------------------------------" << endl;
    cout << "Kosar tesztek:" << endl;
    KosarTesztek();
    cout << "------------------------------" << endl;
    cout << "Kezilabda tesztek:" << endl;
    KezilabdaTesztek();
}
/// Egyesület tesztjei
void EgyesuletTesztek(){
    TEST(Egyesulet, Letrehozas){
        String e_nev("Ferihegyi Egyesulet");
        Egyesulet* egyesulet = new Egyesulet(e_nev);
        EXPECT_STREQ("Ferihegyi Egyesulet", egyesulet->getNev().c_str());
        delete egyesulet;
    } ENDM

    TEST(Egyesulet, Csapat hozzaadas){
        String e_nev("Ferihegyi Egyesulet");
        Egyesulet* egyesulet = new Egyesulet(e_nev);
        String cs_nev("Ferihegyi Csapat");
        String foedzo("Nagy Ferenc");
        String masodedzo("Fekete Pista");
        Labdarugo* csapat = new Labdarugo(cs_nev, 22, foedzo, masodedzo);
        EXPECT_NO_THROW(egyesulet->hozzaad(csapat));
        EXPECT_EQ((size_t)1, egyesulet->getMeret());
        delete egyesulet;
    } ENDM

    TEST(Egyesulet, Csapat eltavolitas){
        String e_nev("Ferihegyi Egyesulet");
        Egyesulet* egyesulet = new Egyesulet(e_nev);
        String cs_nev("Ferihegyi Csapat");
        String foedzo("Nagy Ferenc");
        String masodedzo("Fekete Pista");
        Labdarugo* csapat = new Labdarugo(cs_nev, 22, foedzo, masodedzo);
        egyesulet->hozzaad(csapat);
        EXPECT_NO_THROW(egyesulet->eltavolit(0));
        EXPECT_EQ((size_t)0, egyesulet->getMeret());
        delete egyesulet;
    } ENDM

    TEST(Egyesulet, Csapat eltavolitas - HIBA){
        String e_nev("Ferihegyi Egyesulet");
        Egyesulet* egyesulet = new Egyesulet(e_nev);
        String cs_nev("Ferihegyi Csapat");
        String foedzo("Nagy Ferenc");
        String masodedzo("Fekete Pista");
        Labdarugo* csapat = new Labdarugo(cs_nev, 22, foedzo, masodedzo);
        egyesulet->hozzaad(csapat);
        EXPECT_THROW(egyesulet->eltavolit(10), std::out_of_range&);
        delete egyesulet;
    } ENDM

    TEST(Egyesulet, Index operator){
        String e_nev("Ferihegyi Egyesulet");
        Egyesulet* egyesulet = new Egyesulet(e_nev);
        String cs_nev("Ferihegyi Csapat");
        String foedzo("Nagy Ferenc");
        String masodedzo("Fekete Pista");
        Labdarugo* csapat = new Labdarugo(cs_nev, 22, foedzo, masodedzo);
        egyesulet->hozzaad(csapat);
        EXPECT_NO_THROW(egyesulet->operator[](0));
        delete egyesulet;
    } ENDM

    TEST(Egyesulet, Index operator - HIBA){
        String e_nev("Ferihegyi Egyesulet");
        Egyesulet* egyesulet = new Egyesulet(e_nev);
        String cs_nev("Ferihegyi Csapat");
        String foedzo("Nagy Ferenc");
        String masodedzo("Fekete Pista");
        Labdarugo* csapat = new Labdarugo(cs_nev, 22, foedzo, masodedzo);
        egyesulet->hozzaad(csapat);
        EXPECT_THROW(egyesulet->operator[](10), std::out_of_range&);
        delete egyesulet;
    } ENDM
}
/// Labdarugo tesztjei
void LabdarugoTesztek(){
    TEST(Labdarugo, getNev){
        Labdarugo* labdarugo = new Labdarugo(String("Labda FC"),
                                                             11,
                                                             String("Kis Pista"),
                                                             String("Kerekes Zoltan")
                                                             );
        EXPECT_STREQ("Labda FC", labdarugo->getNev().c_str());
        delete labdarugo;
    } ENDM

    TEST(Labdarugo, getFoedzo){
        Labdarugo* labdarugo = new Labdarugo(String("Labda FC"),
                                                             11,
                                                             String("Kis Pista"),
                                                             String("Kerekes Zoltan")
                                                             );
        EXPECT_STREQ("Kis Pista", labdarugo->getFoedzo().getNev().c_str());
        delete labdarugo;
    } ENDM

    TEST(Labdarugo, getMasodedzo){
        Labdarugo* labdarugo = new Labdarugo(String("Labda FC"),
                                                             11,
                                                             String("Kis Pista"),
                                                             String("Kerekes Zoltan")
                                                             );
        EXPECT_STREQ("Kerekes Zoltan", labdarugo->getMasodedzo().getNev().c_str());
        delete labdarugo;
    } ENDM

    TEST(Labdarugo, getAlapletszam){
        Labdarugo* labdarugo = new Labdarugo(String("Labda FC"),
                                                             11,
                                                             String("Kis Pista"),
                                                             String("Kerekes Zoltan")
                                                             );
        EXPECT_EQ(11, labdarugo->getAlapletszam());
        delete labdarugo;
    } ENDM

    TEST(Labdarugo, ertekado operator){
        Labdarugo* labdarugo1 = new Labdarugo(String("Bomba FC"),
                                                             20,
                                                             String("Nagy Ferko"),
                                                             String("Boros Peti")
                                                             );
        Labdarugo* labdarugo2 = new Labdarugo(String("Labda FC"),
                                                             11,
                                                             String("Kis Pista"),
                                                             String("Kerekes Zoltan")
                                                             );
        *labdarugo1 = *labdarugo2;
        delete labdarugo2;
        EXPECT_STREQ("Labda FC", labdarugo1->getNev().c_str());
        EXPECT_EQ(11, labdarugo1->getAlapletszam());
        EXPECT_STREQ("Kis Pista", labdarugo1->getFoedzo().getNev().c_str());
        EXPECT_STREQ("Kerekes Zoltan", labdarugo1->getMasodedzo().getNev().c_str());
        delete labdarugo1;
    } ENDM
}
/// Kosar tesztjei
void KosarTesztek(){
    TEST(Kosar, getNev){
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_STREQ("Dobo FC", kosar->getNev().c_str());
        delete kosar;
    } ENDM

    TEST(Kosar, getEdzo){
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_STREQ("Szenes Adam", kosar->getEdzo().getNev().c_str());
        delete kosar;
    } ENDM

    TEST(Kosar, getAlapletszam){
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_EQ(11, kosar->getAlapletszam());
        delete kosar;
    } ENDM

    TEST(Kosar, getMeret){
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_EQ((size_t)1, kosar->meret());
        delete kosar;
    } ENDM

    TEST(Kosar, PomPomLany hozzaadas){
        PomPomLany* lany = new PomPomLany(String("Gombos Reka"));
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_NO_THROW(kosar->hozzaad(lany));
        EXPECT_EQ((size_t)2, kosar->meret());
        delete kosar;
    } ENDM

    TEST(Kosar, PomPomLany eltavolitas){
        PomPomLany* lany = new PomPomLany(String("Gombos Reka"));
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_NO_THROW(kosar->hozzaad(lany));
        EXPECT_NO_THROW(kosar->eltavolit((size_t)1));
        EXPECT_EQ((size_t)1, kosar->meret());
        delete kosar;
    } ENDM

    TEST(Kosar, PomPomLany eltavolitas - HIBA1){
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_THROW(kosar->eltavolit((size_t)0), std::invalid_argument&);
        delete kosar;
    } ENDM

    TEST(Kosar, PomPomLany eltavolitas - HIBA2){
        PomPomLany* lany = new PomPomLany(String("Gombos Reka"));
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_NO_THROW(kosar->hozzaad(lany));
        EXPECT_THROW(kosar->eltavolit((size_t)10), std::out_of_range&);
        delete kosar;
    } ENDM

    TEST(Kosar, index operator){
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_NO_THROW(kosar->operator[]((size_t)0));
        delete kosar;
    } ENDM

    TEST(Kosar, index operator - HIBA){
        Kosar* kosar = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        EXPECT_THROW(kosar->operator[]((size_t)10), std::out_of_range&);
        delete kosar;
    } ENDM

    TEST(Kosar, ertekado operator){
        Kosar* kosar1 = new Kosar(String("Dobo FC"), 11, String("Szenes Adam"), new PomPomLany(String("Gombos Reka")));
        Kosar* kosar2 = new Kosar(String("Keresztes FC"), 20, String("Boros Peti"), new PomPomLany(String("Nagy Rebeka")));
        *kosar1 = *kosar2;
        delete kosar2;
        EXPECT_STREQ("Keresztes FC", kosar1->getNev().c_str());
        EXPECT_EQ(20, kosar1->getAlapletszam());
        EXPECT_STREQ("Boros Peti", kosar1->getEdzo().getNev().c_str());
        EXPECT_STREQ("Gombos Reka", kosar1->operator[]((size_t)0)->getNev().c_str());
        EXPECT_STREQ("Nagy Rebeka", kosar1->operator[]((size_t)1)->getNev().c_str());
        delete kosar1;
    } ENDM
}
/// Kezilabda tesztjei
void KezilabdaTesztek(){
    TEST(Kezilabda, getNev){
        Kezilabda* kezilabda = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        EXPECT_STREQ("Kez FC", kezilabda->getNev().c_str());
        delete kezilabda;
    } ENDM

    TEST(Kezilabda, getEdzo){
        Kezilabda* kezilabda = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        EXPECT_STREQ("Nagy Pista", kezilabda->getEdzo().getNev().c_str());
        delete kezilabda;
    } ENDM

    TEST(Kezilabda, getTamogatasOsszeg){
        Kezilabda* kezilabda = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        EXPECT_EQ(10000, kezilabda->getTamogatasOsszeg());
        delete kezilabda;
    } ENDM

    TEST(Kezilabda, getAlapletszam){
        Kezilabda* kezilabda = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        EXPECT_EQ(11, kezilabda->getAlapletszam());
        delete kezilabda;
    } ENDM

    TEST(Kezilabda, getUtolsoTamogatas){
        Kezilabda* kezilabda = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        EXPECT_STREQ("2023.05.28", kezilabda->getUtolsoTamogatas().c_str());
        delete kezilabda;
    } ENDM

    TEST(Kezilabda, Tamogatas){
        Kezilabda* kezilabda = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        EXPECT_NO_THROW(kezilabda->tamogatas(10000, String("2024.10.28")));
        EXPECT_EQ(20000, kezilabda->getTamogatasOsszeg());
        delete kezilabda;
    } ENDM

    TEST(Kezilabda, Tamogatas - HIBA){
        Kezilabda* kezilabda = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        EXPECT_THROW(kezilabda->tamogatas(10000, String("2023.10.28")), std::invalid_argument&);
        delete kezilabda;
    } ENDM

    TEST(Kezilabda, ertekado operator){
        Kezilabda* kezilabda1 = new Kezilabda(String("Kez FC"),
                                                             11,
                                                             String("Nagy Pista"),
                                                             10000,
                                                             String("2023.05.28")
                                                             );
        Kezilabda* kezilabda2 = new Kezilabda(String("Boros FC"),
                                                             20,
                                                             String("Kis Erika"),
                                                             20000,
                                                             String("2020.05.28")
                                                             );
        *kezilabda1 = *kezilabda2;
        delete kezilabda2;
        EXPECT_STREQ("Boros FC", kezilabda1->getNev().c_str());
        EXPECT_EQ(20, kezilabda1->getAlapletszam());
        EXPECT_STREQ("Kis Erika", kezilabda1->getEdzo().getNev().c_str());
        EXPECT_EQ(20000, kezilabda1->getTamogatasOsszeg());
        EXPECT_STREQ("2020.05.28", kezilabda1->getUtolsoTamogatas().c_str());
        delete kezilabda1;
    } ENDM
}

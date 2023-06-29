#ifndef KEZILABDA_H_INCLUDED
#define KEZILABDA_H_INCLUDED
#include "string.h"
#include "csapat.h"
#include "edzo.h"
#include "memtrace.h"
/**
 * Kezilabda osztály.
 * Az edzo a csapat edzője,
 * a tamogatas_osszeg a jelenlegi összeg amit a csapat,
 * támogatásokból birtokol,
 * az utolso_tamogatas egy dátum, hogy mikor kapta az,
 * az utolsó támogatását a csapat
 */
class Kezilabda:public Csapat{
private:
    Edzo edzo;  ///< A csapat edzője
    int tamogatas_osszeg;   ///< A csapat támogatásának összege
    String utolso_tamogatas;    ///< A csapat utolsó támogatásának az ideje
public:
    /// Default konstruktor
    /// @param lnev - egy String tipusu név
    /// @param asz - int tipusu alaplétszám
    /// @param edz - String tipusu edző
    /// @param t_osszeg - int tipusú támogatás összeg
    /// @param u_tamogatas - String tipusú utolsó támogatás
    Kezilabda(String lnev, int asz, String edz, int t_osszeg, String u_tamogatas);
    /// Destruktor
    ~Kezilabda();
    /// Tamogatás összegének lekérdezése
    /// @return int támogatás összeg
    int getTamogatasOsszeg() const;
    /// Utolsó támogatás idejének lekérdezése
    /// @return String utolsó támogatás
    String getUtolsoTamogatas() const;
    /// Csapat tipúsának lekérdezése
    /// @return int tipus
    int getTipus() const;
    /// Edző lekérdezése
    /// @return Edzo edző
    Edzo getEdzo() const;
    /// Csapat adatainak kiírása a konzolra
    void kiir() const;
    /// Csapat támogatása
    /// @param osszeg - támogatás összege
    /// @param datum - támogatás ideje (yyyy.mm.dd)
    void tamogatas(int osszeg, String datum);
    /// Értékadó operátor.
    /// @param masik - jobboldali Csapat
    /// @return baoldali (módosított) Csapat (referenciája)
    Kezilabda& operator=(const Kezilabda& masik);
};

#endif // KEZILABDA_H_INCLUDED

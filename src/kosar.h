#ifndef KOSAR_H_INCLUDED
#define KOSAR_H_INCLUDED
#include "string.h"
#include "csapat.h"
#include "edzo.h"
#include "pompomlany.h"
#include "memtrace.h"
/**
 * Kezilabda osztály.
 * Az edzo a csapat edzője,
 * a lanyok egy tároló, melyben PomPomLany osztály pointereket tárolok,
 * a hossz a tároló aktuális hossza
 */
class Kosar:public Csapat{
private:
    Edzo edzo;  ///< A csapat edzője
    PomPomLany** lanyok;    ///< PomPomLany pointereket tároló tömb
    size_t hossz;   ///< a tároló aktuális mérete
private:
    /// Másoló konstruktor tiltása
    Kosar(const Kosar& masik);
public:
    /// Default konstruktor
    /// @param lnev - egy String tipusu név
    /// @param asz - int tipusu alaplétszám
    /// @param foedz - String tipusu edző
    /// @param lany - PomPomLany tipusu pompom lány
    Kosar(const String& lnev, int asz, const String& foedz, PomPomLany* lany);
    /// Destruktor
    ~Kosar();
    /// Aktuális méret lekérdezése
    /// @return size_t méret
    size_t meret() const;
    /// Csapat tipúsának lekérdezése
    /// @return int tipus
    int getTipus() const;
    /// Edző lekérdezése
    /// @return Edzo edző
    Edzo getEdzo() const;
    /// Csapat adatainak kiírása a konzolra
    void kiir() const;
    /// PomPomLany hozzáadása a tárolóba
    /// @param add_lany - a PomPomLany pointere
    void hozzaad(PomPomLany* add_lany);
    /// PomPomLany eltávolítása a tárolóból
    /// @param index - a PomPomLany indexe
    void eltavolit(size_t index);
    /// index operátor
    /// @param index - a PomPomLany indexe
    /// @return PomPomLany* - pointer a PomPomLany-ra
    PomPomLany* operator[](size_t index) const;
    /// Értékadó operátor.
    /// @param masik - jobboldali Csapat
    /// @return baoldali (módosított) Csapat (referenciája)
    Kosar& operator=(const Kosar& masik);
};
#endif // KOSAR_H_INCLUDED

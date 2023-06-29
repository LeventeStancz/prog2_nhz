#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED
#include "string.h"
#include "memtrace.h"
/**
 * Csapat osztály.
 * A nev-ben van a csapat neve,
 * az alapletszam a csapat alap létszáma
 */
class Csapat{
protected:
    String nev;    ///< csapat neve
    int alapletszam;    ///< csapat létszáma
public:
    /// Default konstruktor
    /// @param nv - egy String tipusu név
    /// @param asz - int tipusu alaplétszám
    Csapat(String nv, int asz);
    /// Név lekérdezése
    /// @return Sztring név
    String getNev() const;
    /// Alaplétszám lekérdezése
    /// @return int alaplétszám
    int getAlapletszam() const;
    /// Kiirja a csapat nevét és alaplétszámát
    virtual void kiir() const;
    /// Osztály tipusának lekérdezése
    virtual int getTipus() const = 0;
    /// Destruktor
    virtual ~Csapat();
    /// Értékadó operátor
    /// @param masik - jobboldali Csapat
    /// @return baoldali (módosított) csapat (referenciája)
    Csapat& operator=(const Csapat& masik);
};
#endif // CSAPAT_H_INCLUDED

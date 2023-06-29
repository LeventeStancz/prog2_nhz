#ifndef LABDARUGO_H_INCLUDED
#define LABDARUGO_H_INCLUDED
#include "string.h"
#include "csapat.h"
#include "edzo.h"
#include "memtrace.h"
/**
 * Labdarugo osztály.
 * Az foedzo a csapat elsőszámú edzője,
 * masodedzo a csapat másodszámú edzője
 */
class Labdarugo:public Csapat{
    Edzo foedzo;    ///< A csapat elsőszámú edzője
    Edzo masodedzo;    ///< A csapat masodszámú edzője
public:
    /// Default konstruktor
    /// @param lnev - egy String tipusu név
    /// @param asz - int tipusu alaplétszám
    /// @param foedz - String tipusu edző
    /// @param masod - String tipusu edző
    Labdarugo(String lnev, int asz, String foedz, String masod);
    /// Destruktor
    ~Labdarugo();
    /// Csapat tipúsának lekérdezése
    /// @return int tipus
    int getTipus() const;
    /// Fő edző lekérdezése
    /// @return Edzo edző
    Edzo getFoedzo() const;
    /// Másod edző lekérdezése
    /// @return Edzo edző
    Edzo getMasodedzo() const;
    /// Csapat adatainak kiírása a konzolra
    void kiir() const;
    /// Értékadó operátor.
    /// @param masik - jobboldali Csapat
    /// @return baoldali (módosított) Csapat (referenciája)
    Labdarugo& operator=(const Labdarugo& masik);
};
#endif // LABDARUGO_H_INCLUDED

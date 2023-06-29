#ifndef EGYESULET_H_INCLUDED
#define EGYESULET_H_INCLUDED
#include "string.h"
#include "csapat.h"
#include "memtrace.h"
/**
 * Egyesulet osztály.
 * A csapatok egy csapatokat tárolü dinamikus tömb,
 * a meret a tároló aktuális mérete,
 * a nev-ben van az egyesület neve
 */
class Egyesulet{
private:
    Csapat** csapatok;   ///< Csapat pointereket tároló tömb
    size_t meret;   ///< A tároló aktuális mérete
    String nev;    ///< Az egyesület neve
private:
    /// Másoló tiltása
    Egyesulet(const Egyesulet& masik);
    /// Értékadó tiltása
    Egyesulet& operator=(const Egyesulet& masik);
    /// Csapatok felszabadítása a tárolóban
    void deleteCsapatok();
public:
    /// Default konstruktor
    /// @param nv - egy String tipusu név
    Egyesulet(String nv);
    /// Destruktor
    ~Egyesulet();
    /// Méret lekérdezése
    /// @return site_t méret
    size_t getMeret() const;
    /// Név lekérdezése
    /// @return String név
    String getNev() const;
    /// Kiírja az egyesület nevét és a csapatokat (a csapatok kiir() fgv.-ét) a konzolra
    void kiir() const;
    /// Csapat hozzáadása a tárolóhoz
    /// @param add - A hozzáadni kivánt csapat pointere
    void hozzaad(Csapat* add);
    /// Csapat eltávolítása a tárolóból
    /// @param index - Az eltávolítani kivánt csapat indexe
    void eltavolit(size_t index);
    /// index operátor
    /// @param index - csapat indexe
    /// @return csapat pointere
    Csapat* operator[](size_t index) const;
};
#endif // EGYESULET_H_INCLUDED

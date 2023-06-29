#ifndef EGYESULET_H_INCLUDED
#define EGYESULET_H_INCLUDED
#include "string.h"
#include "csapat.h"
#include "memtrace.h"
/**
 * Egyesulet oszt�ly.
 * A csapatok egy csapatokat t�rol� dinamikus t�mb,
 * a meret a t�rol� aktu�lis m�rete,
 * a nev-ben van az egyes�let neve
 */
class Egyesulet{
private:
    Csapat** csapatok;   ///< Csapat pointereket t�rol� t�mb
    size_t meret;   ///< A t�rol� aktu�lis m�rete
    String nev;    ///< Az egyes�let neve
private:
    /// M�sol� tilt�sa
    Egyesulet(const Egyesulet& masik);
    /// �rt�kad� tilt�sa
    Egyesulet& operator=(const Egyesulet& masik);
    /// Csapatok felszabad�t�sa a t�rol�ban
    void deleteCsapatok();
public:
    /// Default konstruktor
    /// @param nv - egy String tipusu n�v
    Egyesulet(String nv);
    /// Destruktor
    ~Egyesulet();
    /// M�ret lek�rdez�se
    /// @return site_t m�ret
    size_t getMeret() const;
    /// N�v lek�rdez�se
    /// @return String n�v
    String getNev() const;
    /// Ki�rja az egyes�let nev�t �s a csapatokat (a csapatok kiir() fgv.-�t) a konzolra
    void kiir() const;
    /// Csapat hozz�ad�sa a t�rol�hoz
    /// @param add - A hozz�adni kiv�nt csapat pointere
    void hozzaad(Csapat* add);
    /// Csapat elt�vol�t�sa a t�rol�b�l
    /// @param index - Az elt�vol�tani kiv�nt csapat indexe
    void eltavolit(size_t index);
    /// index oper�tor
    /// @param index - csapat indexe
    /// @return csapat pointere
    Csapat* operator[](size_t index) const;
};
#endif // EGYESULET_H_INCLUDED

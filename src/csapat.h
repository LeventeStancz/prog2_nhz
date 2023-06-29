#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED
#include "string.h"
#include "memtrace.h"
/**
 * Csapat oszt�ly.
 * A nev-ben van a csapat neve,
 * az alapletszam a csapat alap l�tsz�ma
 */
class Csapat{
protected:
    String nev;    ///< csapat neve
    int alapletszam;    ///< csapat l�tsz�ma
public:
    /// Default konstruktor
    /// @param nv - egy String tipusu n�v
    /// @param asz - int tipusu alapl�tsz�m
    Csapat(String nv, int asz);
    /// N�v lek�rdez�se
    /// @return Sztring n�v
    String getNev() const;
    /// Alapl�tsz�m lek�rdez�se
    /// @return int alapl�tsz�m
    int getAlapletszam() const;
    /// Kiirja a csapat nev�t �s alapl�tsz�m�t
    virtual void kiir() const;
    /// Oszt�ly tipus�nak lek�rdez�se
    virtual int getTipus() const = 0;
    /// Destruktor
    virtual ~Csapat();
    /// �rt�kad� oper�tor
    /// @param masik - jobboldali Csapat
    /// @return baoldali (m�dos�tott) csapat (referenci�ja)
    Csapat& operator=(const Csapat& masik);
};
#endif // CSAPAT_H_INCLUDED

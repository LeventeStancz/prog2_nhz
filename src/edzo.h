#ifndef EDZO_H_INCLUDED
#define EDZO_H_INCLUDED
#include "string.h"
#include "ember.h"
#include "memtrace.h"
/**
 * Edzo oszt�ly.
 */
class Edzo:public Ember{
public:
    /// Default konstrukot
    /// @param nv - egy String tipusu n�v
    Edzo(String nv):Ember(nv) {};
    /// N�v lek�rdez�se
    /// @return String n�v
    String getNev() const { return nev; };
    /// N�v be�ll�t�sa
    /// @param String n�v
    void setNev(String ertek) { this->nev = ertek; };
    /// Destruktor
    ~Edzo(){ };
};
#endif // EDZO_H_INCLUDED

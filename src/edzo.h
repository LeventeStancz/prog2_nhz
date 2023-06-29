#ifndef EDZO_H_INCLUDED
#define EDZO_H_INCLUDED
#include "string.h"
#include "ember.h"
#include "memtrace.h"
/**
 * Edzo osztály.
 */
class Edzo:public Ember{
public:
    /// Default konstrukot
    /// @param nv - egy String tipusu név
    Edzo(String nv):Ember(nv) {};
    /// Név lekérdezése
    /// @return String név
    String getNev() const { return nev; };
    /// Név beállítása
    /// @param String név
    void setNev(String ertek) { this->nev = ertek; };
    /// Destruktor
    ~Edzo(){ };
};
#endif // EDZO_H_INCLUDED

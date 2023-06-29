#ifndef POMPOMLANY_H_INCLUDED
#define POMPOMLANY_H_INCLUDED
#include "string.h"
#include "ember.h"
#include "memtrace.h"
/**
 * PomPomLany osztály.
 */
class PomPomLany:public Ember{
public:
    /// Default konstrukot
    /// @param nv - egy String tipusu név
    PomPomLany(String nv):Ember(nv) {};
    /// Név lekérdezése
    /// @return String név
    String getNev() const { return nev; };
    /// Destruktor
    ~PomPomLany(){ };
};
#endif // POMPOMLANY_H_INCLUDED

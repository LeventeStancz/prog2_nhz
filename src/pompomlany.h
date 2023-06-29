#ifndef POMPOMLANY_H_INCLUDED
#define POMPOMLANY_H_INCLUDED
#include "string.h"
#include "ember.h"
#include "memtrace.h"
/**
 * PomPomLany oszt�ly.
 */
class PomPomLany:public Ember{
public:
    /// Default konstrukot
    /// @param nv - egy String tipusu n�v
    PomPomLany(String nv):Ember(nv) {};
    /// N�v lek�rdez�se
    /// @return String n�v
    String getNev() const { return nev; };
    /// Destruktor
    ~PomPomLany(){ };
};
#endif // POMPOMLANY_H_INCLUDED

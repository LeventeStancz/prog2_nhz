#ifndef EMBER_H_INCLUDED
#define EMBER_H_INCLUDED
#include "string.h"
#include "memtrace.h"
/**
 * Ember osztály.
 */
class Ember{
protected:
    String nev; ///< Az ember neve
public:
    /// Default konstrukot
    /// @param nv - egy String tipusu név
    Ember(String nv): nev(nv) {};
    /// Destruktor
    virtual ~Ember() {};
};
#endif // EMBER_H_INCLUDED

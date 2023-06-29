#ifndef FAJLKEZELES_H_INCLUDED
#define FAJLKEZELES_H_INCLUDED
#include "egyesulet.h"
#include "memtrace.h"
/// Fájl beolvasása
/// @return Egyesület pointer
Egyesulet* FajlBeolvas();
/// Fájlba írása
/// @param Egyesület referencia
void FajlbaIr(Egyesulet& egyesulet);
#endif // FAJLKEZELES_H_INCLUDED

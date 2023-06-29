#ifndef DB_MUVELETEK_H_INCLUDED
#define DB_MUVELETEK_H_INCLUDED
#include "egyesulet.h"
#include "labdarugo.h"
#include "kosar.h"
#include "kezilabda.h"
#include "memtrace.h"
/// Csapat módosítása menü
/// @param egyesulet - Egyesület referencia
/// @param index - csapat id
int CsapatModositasMenu(Egyesulet& egyesulet, int index);
/// Csapat módosítás
/// @param cs - csapat pointer
/// @param egyesulet - Egyesület referencia
int CsapatModositas(Csapat* cs, Egyesulet& egyesulet);
/// Labdarugo felvétel
/// @param egyesulet - Egyesület referencia
int LabdarugoFelvetel(Egyesulet& egyesulet);
/// Labdarugo módosítás
/// @param l_old - Labdarugo pointer
/// @param egyesulet - Egyesület referencia
void LabdarugoModositas(Labdarugo* l_old, Egyesulet& egyesulet);
/// Kosar felvétel
/// @param egyesulet - Egyesület referencia
int KosarFelvetel(Egyesulet& egyesulet);
/// Kosar módosítás menü
/// @param k_old - Kosar pointer
/// @param egyesulet - Egyesület referencia
void KosarModositasMenu(Kosar* k_old, Egyesulet& egyesulet);
/// Kosar módosítás
/// @param k_old - Kosar pointer
/// @param egyesulet - Egyesület referencia
void KosarModositas(Kosar* k_old, Egyesulet& egyesulet);
/// Kezilabda felvétel
/// @param egyesulet - Egyesület referencia
int KezilabdaFelvetel(Egyesulet& egyesulet);
/// Kezilabda módosítás menü
/// @param k_old - Kezilabda pointer
/// @param egyesulet - Egyesület referencia
void KezilabdaModositasMenu(Kezilabda* k_old, Egyesulet& egyesulet);
/// Kezilabda módosítás
/// @param k_old - Kezilabda pointer
/// @param egyesulet - Egyesület referencia
void KezilabdaModositas(Kezilabda* k_old, Egyesulet& egyesulet);
/// Csapat törlése menü
/// @param egyesulet - Egyesület referencia
/// @param index - Csapat id
int CsapatTorlesMenu(Egyesulet& egyesulet, int index);
/// Csapat törlése
/// @param index - Csapat id
/// @param egyesulet - Egyesület referencia
int CsapatTorles(size_t index, Egyesulet& egyesulet);
#endif // DB_MUVELETEK_H_INCLUDED

#ifndef DB_MUVELETEK_H_INCLUDED
#define DB_MUVELETEK_H_INCLUDED
#include "egyesulet.h"
#include "labdarugo.h"
#include "kosar.h"
#include "kezilabda.h"
#include "memtrace.h"
/// Csapat m�dos�t�sa men�
/// @param egyesulet - Egyes�let referencia
/// @param index - csapat id
int CsapatModositasMenu(Egyesulet& egyesulet, int index);
/// Csapat m�dos�t�s
/// @param cs - csapat pointer
/// @param egyesulet - Egyes�let referencia
int CsapatModositas(Csapat* cs, Egyesulet& egyesulet);
/// Labdarugo felv�tel
/// @param egyesulet - Egyes�let referencia
int LabdarugoFelvetel(Egyesulet& egyesulet);
/// Labdarugo m�dos�t�s
/// @param l_old - Labdarugo pointer
/// @param egyesulet - Egyes�let referencia
void LabdarugoModositas(Labdarugo* l_old, Egyesulet& egyesulet);
/// Kosar felv�tel
/// @param egyesulet - Egyes�let referencia
int KosarFelvetel(Egyesulet& egyesulet);
/// Kosar m�dos�t�s men�
/// @param k_old - Kosar pointer
/// @param egyesulet - Egyes�let referencia
void KosarModositasMenu(Kosar* k_old, Egyesulet& egyesulet);
/// Kosar m�dos�t�s
/// @param k_old - Kosar pointer
/// @param egyesulet - Egyes�let referencia
void KosarModositas(Kosar* k_old, Egyesulet& egyesulet);
/// Kezilabda felv�tel
/// @param egyesulet - Egyes�let referencia
int KezilabdaFelvetel(Egyesulet& egyesulet);
/// Kezilabda m�dos�t�s men�
/// @param k_old - Kezilabda pointer
/// @param egyesulet - Egyes�let referencia
void KezilabdaModositasMenu(Kezilabda* k_old, Egyesulet& egyesulet);
/// Kezilabda m�dos�t�s
/// @param k_old - Kezilabda pointer
/// @param egyesulet - Egyes�let referencia
void KezilabdaModositas(Kezilabda* k_old, Egyesulet& egyesulet);
/// Csapat t�rl�se men�
/// @param egyesulet - Egyes�let referencia
/// @param index - Csapat id
int CsapatTorlesMenu(Egyesulet& egyesulet, int index);
/// Csapat t�rl�se
/// @param index - Csapat id
/// @param egyesulet - Egyes�let referencia
int CsapatTorles(size_t index, Egyesulet& egyesulet);
#endif // DB_MUVELETEK_H_INCLUDED

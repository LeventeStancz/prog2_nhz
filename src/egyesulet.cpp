#include "egyesulet.h"
#include "string.h"
#include "csapat.h"
#include "memtrace.h"
// az �sszes t�rolt csapat felszabad�t�sa
void Egyesulet::deleteCsapatok(){
    if (csapatok != nullptr) {
        for (size_t i = 0; i < meret; ++i) {
            delete csapatok[i];
        }
        delete[] csapatok;
        csapatok = nullptr;
    }
    meret = 0;
}
// default konstruktor
Egyesulet::Egyesulet(String nv):meret(0),nev(nv){
    csapatok = nullptr;
};
// destruktor
Egyesulet::~Egyesulet(){
    deleteCsapatok();
}
// aktu�lis m�ret lek�rdez�se
size_t Egyesulet::getMeret() const{ return meret; };
// egyes�let nev�nek lek�rdez�se
String Egyesulet::getNev() const{ return nev; };
// egyes�let adatainak �s a t�rolt csapatok adatainak ki�r�sa a konzolra
void Egyesulet::kiir() const{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Az egyesulet neve: " << nev << std::endl;
    std::cout << "Csapatok:" << std::endl;
    std::cout << "------------------------------" << std::endl;
    if(meret == 0){
        std::cout << "Az egyesuletnek jelenleg nincs csapata." << std::endl;
    }else{
        for(size_t i = 0; i < meret; ++i){
            std::cout << "id: " << (i+1) << "." << std::endl;
            csapatok[i]->kiir();
            std::cout << "------------------------------" << std::endl;
        }
    }
}
// csapat hozz�ad�sa a t�rol�hoz
void Egyesulet::hozzaad(Csapat* add){
    // ter�let lefoglal�sa
    Csapat** tmp = new Csapat*[meret+1];
    // jelenlegi adatok �tm�sol�sa
    for(size_t i = 0; i < meret; ++i){
        tmp[i] = csapatok[i];
    }
    // �j csapat beilleszt�se
    tmp[meret] = add;
    // r�giek t�rl�se
    delete[] csapatok;
    // fel�l�r�sa
    csapatok = tmp;
    // m�ret n�vel�se
    ++meret;
}
// csapat elt�vol�t�sa a t�rol�b�l
void Egyesulet::eltavolit(size_t index){
    // index kezel�se
    if(index >= meret){
        throw std::out_of_range("Nem megfelelo id!");
    }
    // csapat t�rl�se
    delete csapatok[index];
    // adatok cs�sztat�sa
    for(size_t i = index; i < meret - 1; ++i){
        csapatok[i] = csapatok[i+1];
    }
    // �j ter�let lefoglal�sa
    Csapat** tmp = new Csapat*[meret-1];
    // adatok �tm�sol�sa
    for (size_t i = 0; i < meret - 1; ++i) {
        tmp[i] = csapatok[i];
    }
    // r�giek t�rl�se
    delete[] csapatok;
    // fel�l�r�s
    csapatok = tmp;
    // m�ret cs�kkent�se
    --meret;
}
// index oper�tor
Csapat* Egyesulet::operator[](size_t index) const{
    // index kezel�se
    if(index >= meret){
        throw std::out_of_range("Nem megfelelo index!");
    }
    return csapatok[index];
}

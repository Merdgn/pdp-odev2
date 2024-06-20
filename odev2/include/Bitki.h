#ifndef BITKI_H
#define BITKI_H
#include "Canli.h"

struct BITKI
{
    Canli super;
    void (*yoket)(struct BITKI*);
    char* (*gorunum)(struct BITKI*);
};

typedef struct BITKI* Bitki;
char* bitki_gorunum(struct BITKI* bitki);
Bitki bitki_yarat(int deger , char* tip, int satir , int sutun);
void bitki_yoket(struct BITKI* bitki);

#endif 

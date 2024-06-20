#ifndef PIRE_H
#define PIRE_H
#include "Bocek.h"

struct PIRE
{
    Bocek super;
    void (*yoket)(struct PIRE*);
    char* (*gorunum)(struct PIRE*);
};

typedef struct PIRE* Pire;
char* pire_gorunum(struct PIRE* pire);
Pire pire_yarat(int deger  , char* tip, int satir , int sutun);
void pire_yoket(struct PIRE* pire);


#endif 

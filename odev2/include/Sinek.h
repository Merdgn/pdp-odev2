#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK
{
    Bocek super;
    void (*yoket)(struct SINEK*);
    char* (*gorunum)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Sinek sinek_yarat(int deger, char* tip, int satir , int sutun);
char* sinek_gorunum(struct SINEK* sinek);
void sinek_yoket(struct SINEK* sinek);

#endif 

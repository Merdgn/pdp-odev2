#ifndef BOCEK_H
#define BOCEK_H
#include "Canli.h"

struct BOCEK
{
    Canli super;
    void (*yoket)(struct BOCEK*);
    char* (*gorunum)(struct BOCEK*);
};

typedef struct BOCEK* Bocek;
char* bocek_gorunum(struct BOCEK* bocek);
Bocek bocek_yarat(int deger , char* tip, int satir , int sutun);
void BocekYoket(struct BOCEK* bocek);

#endif 

#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CANLI {
    char* (*gorunum)(const struct CANLI*);
    char* tip;
    int sutun;
    int satir;
    int deger;
    void (*yoket)(struct CANLI*);
};

typedef struct CANLI* Canli;

Canli canli_yarat(int deger , char* tip , int satir , int sutun);
void canli_yoket(struct CANLI* canli);
char* gorunum(const struct CANLI* canli);

#endif

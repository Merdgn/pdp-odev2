#ifndef HABITAT_H
#define HABITAT_H
#include "LinkedList.h"
#include <stdbool.h>
#include <math.h>

struct HABITAT
{
    LinkedListPtr habitat;
    void (* ekranaBastir)(struct LinkedList*);
    void (* simulasyonuBaslat)(struct LinkedList*);
    void (* yoket)(struct HABITAT*);
};

typedef struct HABITAT* Habitat;

Habitat habitat_yarat(struct LinkedList*);
void habitat_yoket(struct HABITAT*);
void similasyon(struct LinkedList*);
void habitat_yoket(struct HABITAT*);
void ekranaBastir(struct LinkedList*);
bool karsilastir(struct CANLI* , struct CANLI* );
void durumGuncelle(Canli c1 ,Canli c2 , Canli* w);
#endif 

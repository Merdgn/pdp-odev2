#include "../include/Pire.h"

Pire pire_yarat(int deger , char* tip, int satir , int sutun){
    Pire yeniPire = malloc(sizeof(struct PIRE));
    yeniPire->super = bocek_yarat(deger, tip ,satir , sutun);
    yeniPire->yoket = pire_yoket;
    yeniPire->gorunum=pire_gorunum;
    
    return yeniPire;
}

void pire_yoket(struct PIRE* pire){
    if (pire == NULL)
    {
        return;
    }
    pire->super->yoket(pire->super);
    free(pire);
}

char* pire_gorunum(struct PIRE* pire){

    return pire->super->gorunum(pire->super);
}

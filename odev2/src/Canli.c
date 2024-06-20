#include "../include/Canli.h"

Canli canli_yarat(int deger , char* tip, int satir , int sutun){
    Canli canli = malloc(sizeof (struct CANLI));
    canli->tip = tip;
    canli->deger = deger;
    canli->gorunum = gorunum;
    canli->satir = satir;
    canli->sutun = sutun;
    canli->yoket = canli_yoket;
    return canli;

}

void canli_yoket(struct CANLI* canli){
    if (canli == NULL)
    {
        return;
    }
    free(canli->tip);
    free(canli);    
} 

char* gorunum(const struct CANLI* canli) {
    return canli->tip;
}
#include "../include/Bocek.h"

Bocek bocek_yarat(int deger , char* tip, int satir , int sutun){
    Bocek yeniBocek = malloc(sizeof (struct BOCEK));
    yeniBocek->gorunum = bocek_gorunum; 
    yeniBocek->super = canli_yarat(deger ,tip,satir ,sutun);
    yeniBocek->yoket = BocekYoket;
    return yeniBocek;
}

char* bocek_gorunum(struct BOCEK* bocek){
  
    return bocek->super->gorunum(bocek->super);
    
}

void BocekYoket(struct BOCEK* bocek) {
    if (bocek == NULL)
    {
        return;
    }
    bocek->super->yoket(bocek->super);
    free(bocek);
}
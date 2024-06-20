#include "../include/Bitki.h"

char* bitki_gorunum(struct BITKI* bitki){
    return bitki->super->gorunum(bitki->super);
}
Bitki bitki_yarat(int deger , char* tip, int satir , int sutun){
    Bitki yeniBitki = malloc(sizeof (struct BITKI));
    yeniBitki->gorunum = bitki_gorunum;
    yeniBitki->yoket = bitki_yoket;
    yeniBitki->super = canli_yarat(deger,tip , satir , sutun);
    return yeniBitki;
}
void bitki_yoket(struct BITKI* bitki){
    if (bitki == NULL)
    {
        return;
    }
    bitki->super->yoket(bitki->super);
    free(bitki);
}
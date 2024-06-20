#include "../include/Sinek.h"

char* sinek_gorunum(struct SINEK* sinek)
{
    return sinek->super->gorunum(sinek->super);
}

Sinek sinek_yarat(int deger, char* tip , int satir , int sutun)
{
    Sinek yeniSinek = malloc(sizeof(struct SINEK));
    yeniSinek->gorunum = sinek_gorunum;
    yeniSinek->yoket = sinek_yoket;
    yeniSinek->super = bocek_yarat(deger, tip , satir , sutun);
    return yeniSinek;
}

void sinek_yoket(struct SINEK* sinek)
{
    if (sinek == NULL)
    {
        return;
    }
    sinek->super->yoket(sinek->super);
    free(sinek);
}

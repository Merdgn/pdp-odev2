#include "../include/Habitat.h"

Habitat habitat_yarat(struct LinkedList* liste){
    Habitat yeni_habitat = malloc(sizeof(struct HABITAT));
    if (yeni_habitat == NULL) {
        printf("Bellek hatasi: Habitat olusturulamadi.\n");
        exit(EXIT_FAILURE);
    }
    
    yeni_habitat->habitat = liste;
    yeni_habitat->yoket = habitat_yoket;
    yeni_habitat->simulasyonuBaslat = similasyon;
    yeni_habitat->ekranaBastir = ekranaBastir;
    
    return yeni_habitat;
}

void habitat_yoket(struct HABITAT* habitat){
    if (habitat == NULL){
        return;
    }
    destroyLinkedList(habitat->habitat);
    free(habitat);
}

void similasyon(struct LinkedList* liste){
    Canli winner = NULL;
    NodePtr canliNode = liste->head;
    
    while (canliNode != NULL) {
        ekranaBastir(liste);
        system("cls");
        if (winner == NULL)
            durumGuncelle(canliNode->data , canliNode->next->data , &winner);
        else
            durumGuncelle(winner , canliNode->data , &winner );

        canliNode= canliNode->next;
    }
    if (winner != NULL) {
        ekranaBastir(liste);
        printf("Kazanan: %s : (%d, %d)\n", winner->tip , winner->satir , winner->sutun );
        
    }
}

void durumGuncelle(Canli c1, Canli c2, Canli* winner){
    if (c2 == NULL || strcmp(c2->tip, "X") == 0) {
        return; // Geçersiz durum, işlem yapma
    }
    
    if (winner == NULL) {
        *winner = c1;
    } else {
        if (karsilastir(c1, c2)) {
            *winner = c1;
        } else {
            *winner = c2;
        }
        
        if (*winner == c1) {
            c2->tip = "X";
        } else {
            c1->tip = "X";
        }
    }
}

void ekranaBastir(struct LinkedList* liste){
    NodePtr simdikiCanliNode = liste->head;
    
    for (int i = 0; i < liste->satir; i++) {
        for (int j = 0; j < liste->sutun; j++) {
            printf(" %s ", simdikiCanliNode->data->gorunum(simdikiCanliNode->data));
            simdikiCanliNode = simdikiCanliNode->next;
        }
        printf("\n");
    }
}

bool karsilastir(struct CANLI* c1, struct CANLI* c2){
    if (c1 == NULL || c2 == NULL) {
        return false; // Geçersiz durum, işlem yapma
    }

    char* c1Tip = c1->tip;
    char* c2Tip = c2->tip;
    
    switch (c1Tip[0]) {
        case 'B':
            switch (c2Tip[0]) {
                case 'B':
                    return c1->deger > c2->deger;
                case 'S':
                case 'P':
                    return true;
                default:
                    return false;
            }
        case 'C':
            switch (c2Tip[0]) {
                case 'C':
                    return c1->deger > c2->deger;
                case 'B':
                case 'P':
                    return true;
                default:
                    return false;
            }
        case 'S':
            switch (c2Tip[0]) {
                case 'S':
                    return c1->deger > c2->deger;
                case 'P':
                case 'C':
                    return true;
                default:
                    return false;
            }
        case 'P':
            return false;
        default:
            return false;
    }
}

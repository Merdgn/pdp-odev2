#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Canli.h"
#include "../include/Bocek.h"
#include "../include/Bitki.h"
#include "../include/Pire.h"
#include "../include/Sinek.h"
#include "../include/LinkedList.h"
#include "../include/Habitat.h"

#define DOSYA_ADI "Veri.txt"

typedef struct {
    int row;
    int max_col;
    int **matrix;
} Dosya;

Dosya dosyaOku(const char *dosyaAdi) {
    Dosya dosya;
    FILE *dosyaPtr = fopen(dosyaAdi, "r");

    if (dosyaPtr == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    int row = 0, max_col = 0;
    int num, col = 0;
    char karakter;

    // Dosyadan okuma ve satır ve sütun sayılarını hesaplama
    while (fscanf(dosyaPtr, "%d%c", &num, &karakter) == 2) {
        col++;
        if (karakter == '\n') {
            if (col > max_col) {
                max_col = col; // En geniş sütun sayısını bul
            }
            col = 0;
            row++;
        }
    }

    // Son satır için kontrol
    if (col > 0) {
        row++;
        if (col > max_col) {
            max_col = col;
        }
    }

    // Bellekten yer ayırma
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(max_col * sizeof(int));
    }

    // Dosyayı yeniden açma
    rewind(dosyaPtr);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < max_col; j++) {
            if (fscanf(dosyaPtr, "%d", &matrix[i][j]) != 1) {
                matrix[i][j] = 0; // Eğer veri yoksa 0 ata
            }
        }
    }

    // Dosya yapısını doldurma
    dosya.row = row;
    dosya.max_col = max_col;
    dosya.matrix = matrix;

    fclose(dosyaPtr);

    return dosya;
}

void dosyaYaz(const Dosya *dosya, const char *dosyaAdi) {
    FILE *dosyaPtr = fopen(dosyaAdi, "w");

    if (dosyaPtr == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    // Matrisi dosyaya yazma
    for (int i = 0; i < dosya->row; i++) {
        for (int j = 0; j < dosya->max_col; j++) {
            fprintf(dosyaPtr, "%d ", dosya->matrix[i][j]);
        }
        fprintf(dosyaPtr, "\n");
    }

    fclose(dosyaPtr);
}



int main() {
    Dosya veri = dosyaOku(DOSYA_ADI);
    LinkedListPtr liste = createLinkedList(veri.row , veri.max_col);
    for (int i = 0; i < veri.row; i++) {
        for (int j = 0; j < veri.max_col; j++) {
            if (veri.matrix[i][j] >50 && veri.matrix[i][j]<100)
            {
            Canli pire = pire_yarat(veri.matrix[i][j],"P" , i ,j)->super->super;
            insertEnd(liste,pire);
            }
            else if (veri.matrix[i][j] >20 && veri.matrix[i][j]<51)
            {
            Canli sinek = sinek_yarat(veri.matrix[i][j],"S", i ,j)->super->super;
            insertEnd(liste,sinek);
            }   
            else if (veri.matrix[i][j] >9 && veri.matrix[i][j]<21)
            {
            Canli bocek = bocek_yarat( veri.matrix[i][j],"C", i ,j)->super;
            insertEnd(liste,bocek);
            }
            else if (veri.matrix[i][j] >0 && veri.matrix[i][j]<10)
            {
            Canli bitki = bitki_yarat(veri.matrix[i][j],"B", i ,j)->super;
            insertEnd(liste,bitki);
            }
        }
    }
    Habitat doga = habitat_yarat(liste);
    doga->ekranaBastir(doga->habitat);
    printf("\n");
    printf("Devam Etmek Icin Lutfen Tuslama Yapiniz: \n");
    char devam;
    scanf("%c", &devam);
    doga->simulasyonuBaslat(doga->habitat);
    return 0;
}

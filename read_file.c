/*  EL2208 Praktikum Pemecahan Masalah dengan C
 *  Kelompok            : 3
 *  Hari dan Tanggal    : Kamis, 9 April 2020
 *  Nama File           : read_file.c
 *  Deskripsi           : Implementasi fungsi read file
 */

#include <stdio.h>
#include <stdlib.h>

void read_file(FILE* fp, int* row, int* col, int arr[][100])
{
    // KAMUS
    
    char str[100];
    
    // ALGORITMA

    /*  Nilai baris (row) dan kolom (column) telah
        tertera pada text file uji dan kedua nilai akan dibaca
    */

    fgets(str, 4, fp);
    *row = atoi(str);
    fgets(str, 4, fp);
    *col = atoi(str);
    
    /*  Mulai dari baris ke-3 pada text (gen. 1 simulasi),
        tiap sel akan dibaca dengan mengubah tipe data 
        >> char -> int dengan ketentuan:
        - Sel hidup ('X') >> 1
        - Sel mati  ('-') >> 0
    */
    
    for (int i = 0; i < *row; i++){
        if (fgets(str, 100, fp) != NULL){
            for (int j = 0; j < *col; j++){
                if (str[j] == '-'){             // Konversi sel mati "-" menjadi 0
                    arr[i][j] = 0;
                }
                else {                          // Konversi sel hidup "X" menjadi 1
                    arr[i][j] = 1;
                }
            }
        }
    }
}


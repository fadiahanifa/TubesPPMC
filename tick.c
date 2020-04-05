/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 * MODUL 8 – TUGAS BESAR
* Kelompok          : 3
* Hari dan Tanggal  : Minggu, 5 April 2020
* Asisten (NIM)     : Rahma Rizky Alifia (18316003)
* Nama File         : tick.c
* Deskripsi         : Implementasi fungsi tick
*/


#include <stdio.h>
#include <stdlib.h>


void tick(int row, int col, int* arr[][]){
    int arr_nextgen[row][col];
    int i, j, m, n;
    for (i = 0; i < row; i++) {
        for (j = 1; j < col; j++){
            int neighbor_alive = 0;
            for (m = -1; m <= 1; m++){
                for (l = -1; m <= 1; l++){
                    neighbor_alive += 1;
                }
            }
        }
    }
}
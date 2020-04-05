/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 * MODUL 8 – TUGAS BESAR
* Kelompok          : 3
* Hari dan Tanggal  : Minggu, 5 April 2020
* Asisten (NIM)     : Rahma Rizky Alifia (18316003)
* Nama File         : tick.c
* Deskripsi         : Implementasi fungsi tick
*/


#include <stdio.h>
#include <stdlib.h>


void tick(int row, int col, int* arr[row][col]){
    int arr_nextgen[row][col];
    int i, j, m, n;
    for (i = 0; i < row; i++) {
        for (j = 1; j < col; j++){
            int neighbor_alive = 0;
            for (m = -1; m <= 1; m++){
                for (n = -1; n <= 1; n++){
                    neighbor_alive += *arr[((i + m + row) % row)][((j + n + col) % col)];
                }
            }
            neighbor_alive -= *arr[i][j];
            if (*arr[i][j]) {
                if ((neighbor_alive >= 2) && (neighbor_alive < 4)){
                    arr_nextgen[i][j] = 1;
                }
                else {
                    arr_nextgen[i][j] = 0;
                }
            }
            else {
                if (neighbor_alive == 3){
                    arr_nextgen[i][j] = 1;
                }
                else {
                    arr_nextgen[i][j] = 0;
                }
            }
        }
    }
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            *arr[i][j] = arr_nextgen[i][j];
        }
    }
    free(arr_nextgen);
    // fungsi print
}
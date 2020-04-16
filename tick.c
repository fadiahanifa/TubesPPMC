/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 * MODUL 8 – TUGAS BESAR
* Kelompok          : 3
* Hari dan Tanggal  : Kamis, 9 April 2020
* Asisten (NIM)     : Rahma Rizky Alifia (18316003)
* Nama File         : tick.c
* Deskripsi         : Implementasi fungsi tick dan printarray
*/


#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk mencetak array
void printarray(int row, int col, int arr[][100]){
    // Deklarasi Variabel
    int i, j;
    // Looping untuk mengecek tiap elemen
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            // Jika isi array 0 maka print "-" (sel mati)
            if (arr[i][j] == 0){
                printf("-");
            }
            // Jika isi array 1 maka print "X" (sel hidup)
            else if (arr[i][j] == 1){
                printf("X");
            }
        }
        printf("\n");
    }
}

// Fungsi tick untuk melakukan iterasi
// Referensi fungsi didapat dari https://www.geeksforgeeks.org/program-for-conways-game-of-life/
void tick(int row, int col, int arr[][100]){
    // Deklarasi variabel
    int arr_nextgen[row][col];
    int i, j, m, n;

    // Program Fungsi Tick
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++){
            // Mengecek jumlah tetangga hidup
            int neighbor_alive = 0;
            for (m = -1; m <= 1; m++){
                for (n = -1; n <= 1; n++){
                    neighbor_alive += arr[((i + m + row) % row)][((j + n + col) % col)];
                }
            }
            // Mengurangi jumlah tetangga hidup dengan keadaan sel itu sendiri
            neighbor_alive -= arr[i][j];

            // Jika sel hidup -- arr[i][j] == 1
            if (arr[i][j]) {
                // Jika tetangga hidup berada di antara 2 sampai 4, sel akan hidup
                if ((neighbor_alive >= 2) && (neighbor_alive < 4)){
                    arr_nextgen[i][j] = 1;
                }
                // Tetangga hidup dibawah 2 atau diatas 4, sel mati (underpopulation and overpopulation)
                else {
                    arr_nextgen[i][j] = 0;
                }
            }
            // Jika sel mati -- arr[i][j] == 0
            else {
                // Jika tetangga hidup ada tiga maka sel akan hidup (reproduction)
                if (neighbor_alive == 3){
                    arr_nextgen[i][j] = 1;
                }
                // Otherwise sel tidak berubah
                else {
                    arr_nextgen[i][j] = 0;
                }
            }
        }
    }
    // Mengassign arr_nextgen pada arr
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            arr[i][j] = arr_nextgen[i][j];
        }
    }
    // Print Array
    printarray(row, col, arr);
}


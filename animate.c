/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 * MODUL 8 – TUGAS BESAR
* Kelompok          : 3
* Hari dan Tanggal  : Senin, 8 April 2020
* Asisten (NIM)     : Rahma Rizky Alifia (18316003)
* Nama File         : animate.c
* Deskripsi         : Implementasi fungsi tick dan printarray
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//Referensi fungsi https://www.geeksforgeeks.org/time-delay-c/
void delay(float lama){
//Untuk menahan kerja processor sesuai waktu yang diinput
    clock_t t=clock();
    while (clock()<=t+lama);
}

void animate(int row, int col, int arr[][100]){
//Untuk melakukan animate dengan prinsip pengulangan fungsi tick sesuai input yang diberikan disertai penghapusan console
    int itr,i;
    printf("Masukkan jumlah iterasi yang diinginkan : ");
    scanf(" %d", &itr);
    for (i=0;i<itr;i++){
        //system("clear");//untuk mac
        system("cls");//untuk windows
        tick(row, col, arr);
        delay(250);
    }
}

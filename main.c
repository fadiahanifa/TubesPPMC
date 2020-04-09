/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 * MODUL 8 – TUGAS BESAR
* Kelompok          : 3
* Hari dan Tanggal  : Kamis, 9 April 2020
* Asisten (NIM)     : Rahma Rizky Alifia (18316003)
* Nama File         : main.c
* Deskripsi         : Program utama
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tick.c"
#include "read_file.c"

int main(){
//KAMUS
    int menu, out=0;
    FILE* fptr;
    char file_name[50], yesno;
    int row, col;
    int arr[100][100];
//ALGORITMA
Awal:
    printf("CONWAY'S GAME OF LIFE\n");
    printf("Keterangan game:\n");
    printf("\nMenu:");
    printf("\nMasukkan file seed : ");
    scanf(" %s", file_name);
    fptr=fopen(file_name,"r");
    while (fptr==NULL){
        printf("Maaf file Anda kosong atau tidak ada!\n");
        printf("\nMasukkan file seed : ");
        scanf(" %s", file_name);
        fptr=fopen(file_name,"r");
    }
    
    read_file(fptr, &row, &col, arr);

    printarray(row, col, arr);
    do{
        printf("\n1. Animate");
        printf("\n2. Tick");
        printf("\n3. Quit");
        printf("\nMasukkan pilihan (1-3) : ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                //animate(int row, int col, int arr[][col]);
                break;
            case 2:
                tick(row, col, arr);
                break;
            case 3:
                keluar:
                printf("\nApakah Anda ingin memasukkan file seed baru (y/t)?");
                yesno=getchar();
                printf("\n");
                printf("\n");
                if (yesno=='Y'||yesno=='y'){
                    fclose(fptr);
                    goto Awal;
                    printarray(row, col, arr);
                }
                else if (yesno=='T'||yesno=='t'){
                    out=1;
                }
                else{
                    printf("Inputan Anda salah");
                    goto keluar;
                }
                break;
            default :printf("\nInputan Anda salah!");
        }
    }while(out!=1);
    fclose(fptr);
	return(0);
}



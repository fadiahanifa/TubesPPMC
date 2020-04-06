/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 * MODUL 8 – TUGAS BESAR
* Kelompok          : 3
* Hari dan Tanggal  : Senin, 6 April 2020
* Asisten (NIM)     : Rahma Rizky Alifia (18316003)
* Nama File         : main.c
* Deskripsi         : Program utama
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file();
void tick(int row, int col, int arr[row][col]);
void animate(int row, int col, int arr[row][col]);

void tick(int row, int col, int arr[row][col]){
//KAMUS
    int arr_nextgen[row][col];
    int i, j, m, n;
//ALGORITMA
    for (i = 0; i < row; i++) {
        for (j = 1; j < col; j++){
            int neighbor_alive = 0;
            for (m = -1; m <= 1; m++){
                for (n = -1; n <= 1; n++){
                    neighbor_alive += arr[((i + m + row) % row)][((j + n + col) % col)];
                }
            }
            neighbor_alive -= arr[i][j];
            if (arr[i][j]) {
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
            arr[i][j] = arr_nextgen[i][j];
        }
    }
    free(arr_nextgen);
    // fungsi print
}

void animate(int row, int col, int arr[row][col]){
//ALGORITMA
    for (int i = 0; i < 30; i++){
        tick(row, col, arr);
    }
}


int main(){
//KAMUS
    int menu, out;
    FILE* fptr;
    char file_name[50], yesno;
//ALGORITMA
awal:
    printf("CONWAY'S GAME OF LIFE");
    printf("");
    printf("\n\nMenu:");
    printf("\nMasukkan file seed : ");
    gets(file_name);
    fptr=fopen(file_name,"r");
    //read_file();
    do{
        printf("\n1. Animate");
        printf("\n2. Tick");
        printf("\n3. Quit");
        printf("\nMasukkan pilihan (1-3) : ");
        scanf("%d",&menu);
        switch(menu){
            case 1:
                //animate(int row, int col, int arr[row][col]);
                break;
            case 2:
                //tick(int row, int col, int arr[row][col]);
                break;
            case 3:
                printf("\nApakah Anda ingin memasukkan file seed baru (y/t)?\n");
                yesno=getche();
                if (yesno=='Y'||yesno=='y'){
                    fclose(fptr);
                    //read_file();
                }
                else if (yesno=='T'||yesno=='t'){
                    out=1;
                }
                else{
                    printf("\nInputan Anda salah");
                }
                break;
            default :printf("\nInputan Anda salah!");
        }
    }while(out!=1);
    fclose(fptr);
	return(0);
}


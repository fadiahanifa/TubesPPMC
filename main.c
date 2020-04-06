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
void animate();

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
                //animate();
                break;
            case 2:
                //tick();
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


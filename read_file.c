/*  EL2208 Praktikum Pemecahan Masalah dengan C
 *  Kelompok            : 3
 *  Hari dan Tanggal    : Rabu, 8 April 2020
 *  Nama File           : read_file.c
 *  Deskripsi           : Implementasi fungsi read file
 */

#include <stdio.h>
#include <stdlib.h>

int read_file(FILE file_name)
{
    // KAMUS
    
    int row, col;
    
    // ALGORITMA
    
    //  Read file dapat dilakukan apabila file tidak NULL
    if (file_name == NULL) 
    {
        return NULL;    
    }

    /*  Nilai baris (row) dan kolom (column) telah
        tertera pada text file uji dan kedua nilai akan dibaca
    */
    fscanf("%d\n%d\n", &row, &col);
    
    /*  Mulai dari baris ke-3 pada text (gen. 1 simulasi),
        tiap sel akan dibaca dengan mengubah tipe data 
        >> char -> int dengan ketentuan:
        - Sel hidup ('X') >> 1
        - Sel mati  ('-') >> 0
    */
        
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            while (file_name != '\0')
            {
                fscanf(file_name, "%s", arr[row][col]);
                if (arr[row][col] == 'X')               // Konversi sel hidup -> int 1
                {
                    arr[row][col] = '1';
                }
                else if (arr[row][col] == '-')          // Konversi sel mati  -> int 0    
                {
                    arr[row][col] = '0';    
                }
            }     
        }
    }
}

/* 

char* checkAlive (int row, int col, int arr[row][col])
{
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (arr[row][col] == 1)
            {
                arr[row][col] == 'X';
            }
            else if (arr[row][col] == 0)
            {
                arr[row][col] == '-';
            }
        }
    }
}

*/

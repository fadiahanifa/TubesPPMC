/*  EL2208 Praktikum Pemecahan Masalah dengan C
 *  Kelompok            : 3
 *  Hari dan Tanggal    : Rabu, 8 April 2020
 *  Nama File           : readfile.c
 *  Deskripsi           : Implementasi fungsi read file
 */

#include <stdio.h>
#include <stdlib.h>

int readfile(FILE file_name, ...)
{
    // KAMUS
    
    
    
    // ALGORITMA
    
    // Read file dapat dilakukan apabila file tidak NULL
    if (file_name == NULL) 
    {
        return NULL;    
    }

    /*  Nilai baris (row) dan kolom (column) telah
        tertera pada text file uji
    */
    row = ...
    col = ...
    
    /*  Mulai dari baris ke-3 pada text (gen. 1 simulasi),
        
    */
        
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            fscanf(filename, "%s", arr[i][j]);     
        }
    }
}

/*  EL2208 Praktikum Pemecahan Masalah dengan C
 *  Kelompok            : 3
 *  Hari dan Tanggal    : Rabu, 8 April 2020
 *  Nama File           : read_file.c
 *  Deskripsi           : Implementasi fungsi read file
 */

#include <stdio.h>
#include <stdlib.h>

int read_file(FILE *file_name)
{
    // KAMUS
    
    int row, col;
    char temp[i][j];
    
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
    
    while (!feof(file_name))
    {
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row; i++)
            {
                fgets(temp, 1, file_name);
                if (temp[i][j] == 'X')               // Konversi sel hidup -> int 1
                {
                    arr[i][j] = 1;
                }
                else if (temp[i][j] == '-')          // Konversi sel mati  -> int 0    
                {
                    arr[i][j] = 0;    
                }     
            }
        }
    }
}

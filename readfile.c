#include <stdio.h>
#include <stdlib.h>

double getRandomDoubleInRange(double min, double max)
{
    return min + (max-min) * ((double)rand() / RAND_MAX);   
    /*  Fungsi untuk memperoleh nilai random tipe float
        dalam rentang min - max.
        Kenapa float, bukan integer ? 
            Bila user memberi input (min, max) = (0, 1),
            fungsi ini dapat digunakan.
        */
}

// (2)

char* create(int rows, int columns)
{
    char* simulation = (char*)calloc(rows*columns, sizeof(char));
    if(simulation == NULL)
    {
        return NULL;
    }

    for (int y = 1; y < rows - 1; y++)          // (**)
    {
        for(int x = 1; x < columns - 1; x++)    // (**)
        {
            if (getRandomDoubleInRange(0.0, 1.0) <= 0.35)           // Misalkan seeding kalo dapet angka >35%, sel hidup
            {
                *(simulation + y * columns + x) = '-';  // Sel mati
            }
            else
            {
                *(simulation + y * columns + x) = 'X';  // Sel hidup
            }
        }
    }

    return simulation;
}

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
            if (getRandomDoubleInRange(0.0, 1.0) <= 0.35)
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

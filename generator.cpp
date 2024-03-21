#include <iostream>
#include <stdlib.h>
#include <time.h>
void generate_array(int array[],int size_of_array)
{
    int random_number = 0;
    srand (time(NULL));
    for (int i = 0; i<= size_of_array; i++)
    {
        random_number = rand() % 16 + 1;
        array[i] = random_number;
    }
}

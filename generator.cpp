#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
void generate_array(int size_of_array)
{
    std::ofstream Myfile("random_number_file.txt"); 
    if (Myfile.is_open())
    {
        int random_number = 0;
        srand (time(NULL));
        for (int i = 0; i<= size_of_array; i++)
        {
            random_number = rand() % 16 + 1;
            Myfile << random_number << std::endl;
        }
    }
    
    Myfile.close();
}
#include <iostream>
#include <fstream> // Biblioteka do obsługi plików
#include <stdlib.h> // Biblioteka do zarządzania pamięcią i przetwarzania napisów
#include <time.h> // Biblioteka do operacji na czasie

void generate_array(int size_of_array) // Funkcja do generowania tablicy losowych liczb
{
    std::ofstream Myfile("random_number_file.txt"); // Tworzenie obiektu do zapisu do pliku o nazwie "random_number_file.txt"
    if (Myfile.is_open()) // Sprawdzenie, czy udało się otworzyć plik
    {
        int random_number = 0; // Deklaracja zmiennej przechowującej losową liczbę
        srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych
        for (int i = 0; i <= size_of_array; i++) // Pętla generująca losowe liczby i zapisująca je do pliku
        {
            random_number = rand() % 16 + 1; // Generowanie losowej liczby z zakresu od 1 do 16
            Myfile << random_number << std::endl; // Zapisanie wygenerowanej liczby do pliku, zakończenie linii
        }
    }
    
    Myfile.close(); // Zamknięcie pliku
}

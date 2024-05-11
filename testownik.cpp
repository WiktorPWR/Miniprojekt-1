#include <iostream> 
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;

#include "struktury_danych/dynamic_array.cpp"
#include "struktury_danych/TwoWayList.cpp"
#include "struktury_danych/OneWayList.cpp"
//#include "generator.cpp"
#include "struktury_danych/OneWayList+Tail.cpp"

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
};




<<<<<<< HEAD


=======
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
};




>>>>>>> 06c3615fef19bd13fff17b647ee8c711525d9686
int main()
{
    TwoWayList<int> two_way_list;
    DynamicArray<int> dynamic_array;
    SLL1<int> one_way_list1;
    SLL2<int> one_way_list2;

    std::cout << "Jak duzo ma byc w niej elementow? (podaj numer)" << std::endl;
    int ilosc_elementow;
    std::cin >> ilosc_elementow;

    int ilosc_powtorzen;
    std::cout << "Ile razy powtorzyc pomiar?" << std::endl;
    std::cin >> ilosc_powtorzen;
    
    int array[12][ilosc_powtorzen];
    

    for (int i = 0; i < ilosc_powtorzen; i++)
    {
        generate_array(ilosc_elementow);
        std::ifstream plik("random_number_file.txt");
        int wartosc_int;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Push i pomiar czasu dla DynamicArray

        while (plik >> wartosc_int) 
        {
            dynamic_array.push_front(wartosc_int);
        }
        auto start1 = high_resolution_clock::now();

        dynamic_array.push_front(1);
        //dynamic_array.push_back(wartosc_int);

        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
        array[0][i] = duration1.count();

        // Pop i pomiar czasu dla DynamicArray
        auto start2 = high_resolution_clock::now();

            dynamic_array.pop_front();
            //dynamic_array.pop_back();

        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
        array[1][i] = duration2.count();

        dynamic_array.change_value_at_position(2*ilosc_elementow/3);

        auto start12 = high_resolution_clock::now();

        dynamic_array.Find();

        auto stop12 = high_resolution_clock::now();
        auto duration12 = duration_cast<nanoseconds>(stop12 - start12);
        array[11][i] = duration12.count();


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Push i pomiar czasu dla SLL1
        plik.clear();
        plik.seekg(0, std::ios::beg);

        while (plik >> wartosc_int)
        {
            one_way_list1.Pushfront(wartosc_int);
            //one_way_list1.Pushback(wartosc_int);
        }

        auto start3 = high_resolution_clock::now();

            one_way_list1.Pushfront(1);
            //one_way_list1.Pushback(wartosc_int);

        auto stop3 = high_resolution_clock::now();
        auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
        array[2][i] = duration3.count();

        // Pop i pomiar czasu dla SLL1
        auto start4 = high_resolution_clock::now();

            one_way_list1.Dltfront();
            //one_way_list1.Dltback();

        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
        array[3][i] = duration4.count();

        one_way_list1.change_value_at_position(2*ilosc_elementow/3);

        auto start9 = high_resolution_clock::now();

        one_way_list1.Find();

        auto stop9 = high_resolution_clock::now();
        auto duration9 = duration_cast<nanoseconds>(stop9 - start9);
        array[8][i] = duration9.count();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        //std::cout << "Polowa minela" << std::endl;

        // Push i pomiar czasu dla TwoWayList
        plik.clear();
        plik.seekg(0, std::ios::beg);

        while (plik >> wartosc_int)
        {
            two_way_list.push_front(wartosc_int);
            //two_way_list.push_back(wartosc_int);
        }

        auto start5 = high_resolution_clock::now();

            two_way_list.push_front(1);
            //two_way_list.push_back(wartosc_int);

        auto stop5 = high_resolution_clock::now();
        auto duration5 = duration_cast<nanoseconds>(stop5 - start5);
        array[4][i] = duration5.count();

        // Pop i pomiar czasu dla TwoWayList
        auto start6 = high_resolution_clock::now();

            two_way_list.pop_front();
            //two_way_list.pop_back();

        auto stop6 = high_resolution_clock::now();
        auto duration6 = duration_cast<nanoseconds>(stop6 - start6);
        array[5][i] = duration6.count();

        two_way_list.change_value_at_position(2*ilosc_elementow/3);

        auto start11 = high_resolution_clock::now();

        two_way_list.Find();

        auto stop11 = high_resolution_clock::now();
        auto duration11 = duration_cast<nanoseconds>(stop11 - start11);
        array[10][i] = duration11.count();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        // Push i pomiar czasu dla SLL2
        plik.clear();
        plik.seekg(0, std::ios::beg);

        while (plik >> wartosc_int)
        {
            one_way_list2.Pushfront(wartosc_int);
            //one_way_list2.Pushback(wartosc_int);
        }

        auto start7 = high_resolution_clock::now();

            one_way_list2.Pushfront(1);
            //one_way_list2.Pushback(wartosc_int);

        auto stop7 = high_resolution_clock::now();
        auto duration7 = duration_cast<nanoseconds>(stop7 - start7);
        array[6][i] = duration7.count();

        // Pop i pomiar czasu dla SLL2
        auto start8 = high_resolution_clock::now();

            one_way_list2.Dltfront();
            //one_way_list2.Dltback();

        auto stop8 = high_resolution_clock::now();
        auto duration8 = duration_cast<nanoseconds>(stop8 - start8);
        array[7][i] = duration8.count();

        one_way_list2.change_value_at_position(2*ilosc_elementow/3);

        auto start10 = high_resolution_clock::now();

        one_way_list2.Find();

        auto stop10 = high_resolution_clock::now();
        auto duration10 = duration_cast<nanoseconds>(stop10 - start10);
        array[9][i] = duration10.count();

        plik.close();
    }
    
    // // Wyświetlenie wyników
    // long int srednie[8];
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < ilosc_powtorzen; j++)
    //     {
    //         //std::cout << array[i][j] << "\t";
    //         srednie[i] = srednie[i] + array[i][j];
    //     }
    //     //std::cout << std::endl;
    // }
    long double srednie[12] = {0}; // Użyjemy zmiennej double dla dokładniejszych obliczeń średnich

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < ilosc_powtorzen; j++) {
            srednie[i] += array[i][j]; // Dodajemy czas wykonania do sumy
        }
        srednie[i] /= ilosc_powtorzen; // Obliczamy średnią dzieląc przez ilość powtórzeń
        std::cout << srednie[i] << std::endl;
    }




    return 0;
}

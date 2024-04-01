#include <iostream> 
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;

#include "struktury_danych/dynamic_array.cpp"
#include "struktury_danych/TwoWayList.cpp"
#include "struktury_danych/OneWayList.cpp"
#include "generator.cpp"
#include "struktury_danych/OneWayList+Tail.cpp"

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
    
    int array[8][ilosc_powtorzen];
    


    for (int i = 0; i < ilosc_powtorzen; i++)
    {
        generate_array(ilosc_elementow);
        std::ifstream plik("random_number_file.txt");
        int wartosc_int;

        // Push i pomiar czasu dla DynamicArray
        auto start1 = high_resolution_clock::now();
        while (plik >> wartosc_int) 
        {
            dynamic_array.push_front(wartosc_int);
            //dynamic_array.push_back(wartosc_int);
        }
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        array[0][i] = duration1.count();

        // Pop i pomiar czasu dla DynamicArray
        auto start2 = high_resolution_clock::now();
        while (dynamic_array.getSize() > 0) 
        {
            dynamic_array.pop_front();
            //dynamic_array.pop_back();
        }
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        array[1][i] = duration2.count();  

        // Push i pomiar czasu dla SLL1
        plik.clear();
        plik.seekg(0, std::ios::beg);
        auto start3 = high_resolution_clock::now();
        while (plik >> wartosc_int) 
        {
            one_way_list1.Pushfront(wartosc_int);
            //one_way_list1.Pushback(wartosc_int);
        }
        auto stop3 = high_resolution_clock::now();
        auto duration3 = duration_cast<microseconds>(stop3 - start3);
        array[2][i] = duration3.count();

        // Pop i pomiar czasu dla SLL1
        auto start4 = high_resolution_clock::now();
        while (one_way_list1.getSize() > 0) 
        {
            one_way_list1.Dltfront();
            //one_way_list1.Dltback();
        }
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(stop4 - start4);
        array[3][i] = duration4.count();


        //std::cout << "Polowa minela" << std::endl;

        // Push i pomiar czasu dla TwoWayList
        plik.clear();
        plik.seekg(0, std::ios::beg);
        auto start5 = high_resolution_clock::now();
        while (plik >> wartosc_int) 
        {
            two_way_list.push_front(wartosc_int);
            //two_way_list.push_back(wartosc_int);
        }
        auto stop5 = high_resolution_clock::now();
        auto duration5 = duration_cast<microseconds>(stop5 - start5);
        array[4][i] = duration5.count();

        // Pop i pomiar czasu dla TwoWayList
        auto start6 = high_resolution_clock::now();
        while (two_way_list.getSize() > 0) 
        {
            two_way_list.pop_front();
            //two_way_list.pop_back();
        }
        auto stop6 = high_resolution_clock::now();
        auto duration6 = duration_cast<microseconds>(stop6 - start6);
        array[5][i] = duration6.count();

        // Push i pomiar czasu dla SLL2
        plik.clear();
        plik.seekg(0, std::ios::beg);
        auto start7 = high_resolution_clock::now();
        while (plik >> wartosc_int) 
        {
            one_way_list2.Pushfront(wartosc_int);
            //one_way_list2.Pushback(wartosc_int);
        }
        auto stop7 = high_resolution_clock::now();
        auto duration7 = duration_cast<microseconds>(stop7 - start7);
        array[6][i] = duration7.count();

        // Pop i pomiar czasu dla SLL2
        auto start8 = high_resolution_clock::now();
        while (one_way_list2.getSize() > 0) 
        {
            one_way_list2.Dltfront();
            //one_way_list2.Dltback();
        }
        auto stop8 = high_resolution_clock::now();
        auto duration8 = duration_cast<microseconds>(stop8 - start8);
        array[7][i] = duration8.count();

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
    long double srednie[8] = {0}; // Użyjemy zmiennej double dla dokładniejszych obliczeń średnich

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < ilosc_powtorzen; j++) {
            srednie[i] += array[i][j]; // Dodajemy czas wykonania do sumy
        }
        srednie[i] /= ilosc_powtorzen; // Obliczamy średnią dzieląc przez ilość powtórzeń
        std::cout << srednie[i] << std::endl;
    }

    
    return 0;
}

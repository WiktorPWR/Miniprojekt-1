#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std::chrono;
#include "struktury_danych/dynamic_array.cpp"
#include "struktury_danych/TwoWayList.cpp"
#include "struktury_danych/OneWayList.cpp"
#include "struktury_danych/OneWayList+Tail.cpp"
#include "generator.cpp"
//#include "testownik.cpp"

void dynamicArrayMenu(DynamicArray<int>& dynamic_array) {
    // Drugi poziom menu dla tablicy dynamicznej
    int numer_operacji;
    std::cout << "Ustawianie wartosci na ktoych chcesz robic operacje  ? " << std::endl;
    std::cout << "1. Recznie" << std::endl;
    std::cout << "2. Wczytujac z pliku" << std::endl;
    std::cout << "3. Wyswietl tablice" << std::endl;
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 3) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Masz do wyboru albo 1 albo 2 albo 3" << std::endl;
        std::cin >> numer_operacji;
        std::cout << std::endl;
    }
    switch (numer_operacji)
    {
    case 1:
        {
        int funkcja;
        std::cout << "Jaka funkcje chcesz uzyc ?" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. pop back" << std::endl;
        std::cout << "3. push front" << std::endl;
        std::cout << "4. pop front" << std::endl;
        std::cout << "5. push random" << std::endl;
        std::cout << "6. pop random" << std::endl;
        std::cin >> funkcja;

        int ilosc_razy;
        std::cout << "Ile razy ma byc wykonana dana operacja" << std::endl;
        std::cin >> ilosc_razy;

        // Logika wywoływania odpowiednich funkcji operacji na tablicy dynamicznej
        switch (funkcja) {
            case 1:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na koniec: ";
                    std::cin >> element;
                    dynamic_array.push_back(element);
                }
                break;
            case 2:
                for (int i = 0; i < ilosc_razy; ++i) {
                    dynamic_array.pop_back();
                }
                break;
            case 3:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na poczatku: ";
                    std::cin >> element;
                    dynamic_array.push_front(element);
                }
                break;
            case 4:
                for (int i = 0; i < ilosc_razy; ++i) {
                    dynamic_array.pop_front();
                }
                break;
            case 5:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania w losowe miejsce: ";
                    std::cin >> element;
                    dynamic_array.push_random(element);
                }
                break;
            case 6:
                for (int i = 0; i < ilosc_razy; ++i) {
                    dynamic_array.pop_random();
                }
                break;
            default:
                std::cout << "Niepoprawny numer operacji!" << std::endl;
                break;
        }
        break;
        }
    
    case 2:
        {
        int funkcja;
        std::cout << "Jak chcesz dodac wartosci z listy" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. push front" << std::endl;
        std::cout << "3. push random" << std::endl;
        std::cin >> funkcja;

        int wybor_pliku;
        std::cout << "Chcesz uzyc wlasnego pliku czy moze automatycznego ?" << std::endl;
        std::cout << "1. Wlasnego" << std::endl;
        std::cout << "2. Automatycznego" << std::endl;
        std::cin >> wybor_pliku;
        
        std::ifstream plik;

        switch (wybor_pliku)
        {
        case 1:
        {
            std::cout << "Dodaj sciezke pliku" << std::endl;
            std::string sciezka;
            std::cout << "Podaj sciezke do pliku: ";
            std::getline(std::cin, sciezka);
            plik.open(sciezka);
            while(!plik.is_open()) {
                std::cerr << "Nie udalo sie otworzyc pliku.\n";
                std::cout << "Podaj sciezke jeszcze raz" << std::endl;
                std::getline(std::cin, sciezka);
                std::ifstream plik(sciezka);
                return ;
            }
            break;
        }
        
        case 2:
            {
            std::cout << "Jak duzo ma byc w niej elementow (podaj numer)" << std::endl;
            int ilosc_elementow;
            std::cin >> ilosc_elementow;
            generate_array(ilosc_elementow);
            plik.open("random_number_file.txt");
            break;
            }
        }
        

        switch (funkcja)
        {
        case 1:
            {
                int wartosc_int;
                //mierzenie czasu 
                auto start = high_resolution_clock::now();
                while (plik >> wartosc_int) 
                {
                    dynamic_array.push_back(wartosc_int);
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "Czas push back wynosi " << duration.count() << " microseconds" << std::endl;
                break;
            }
        case 2:
            {
                int wartosc_int;
                auto start = high_resolution_clock::now();
                while (plik >> wartosc_int) 
                {
                    dynamic_array.push_front(wartosc_int);
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "Czas push front wynosi " << duration.count() << " microseconds" << std::endl;
                break;
            }
        case 3:
            {
                int wartosc_int;
                auto start = high_resolution_clock::now();
                while (plik >> wartosc_int)
                {
                    dynamic_array.push_random(wartosc_int);
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "Czas push random wynosi " << duration.count() << " microseconds" << std::endl;
                break;
            }
        }

        std::cout << "Wsyztko sie udalo o to wartosci ktore sie znajduja w tej tablicy" << std::endl;
        //dynamic_array.print_array();

        std::cout << "Czy chcesz usunac wszystkie wartosci ?" << std::endl;
        std::cout << "1. Tak za pomoca pop back" << std::endl;
        std::cout << "2. Tak za pomoca pop front" << std::endl;
        std::cout << "3. Tak za pomoca pop random" << std::endl;
        std::cout << "4. Nie zostaw tak jak jest" << std::endl;
        
        int usuwanie;
        std::cin >> usuwanie;
        while (1 > numer_operacji || numer_operacji > 4) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Masz do wyboru albo 1 albo 2" << std::endl;
        std::cin >> numer_operacji;
        std::cout << std::endl;
        }
        switch (usuwanie)
        {
        case 1:
            {

                int size = dynamic_array.getSize();
                auto start = high_resolution_clock::now();
                while (size != 0) 
                {
                    dynamic_array.pop_back();
                    size--;
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "Czas pop back wynosi " << duration.count() << " microseconds" << std::endl;
                break;
            }
        
        case 2:
            {
                int size = dynamic_array.getSize();
                auto start = high_resolution_clock::now();
                while (size != 0)
                {
                    dynamic_array.pop_front();
                    size--;
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "Czas pop front wynosi " << duration.count() << " microseconds" << std::endl;
                break;
            }
        case 3:
            {
                int size = dynamic_array.getSize();
                auto start = high_resolution_clock::now();
                while (size != 0)
                {
                    dynamic_array.pop_random();
                    size--;
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "Czas pop front wynosi " << duration.count() << " microseconds" << std::endl;
                break;
            }
        default:
            {
                break;
            }
        }
        // TO jest koniec glowneegho swwithca
        break;
        }

    case 3:
        {
            dynamic_array.print_array();
            break;
        }


    }

    
}

void auto_test(int funkcja,DynamicArray<int> &dynamic_array,SLL1<int> &one_way_list1,TwoWayList<int> &two_way_list,SLL2<int> &one_way_list2)
{

    std::cout << "Jak duzo ma byc w niej elementow? (podaj numer)" << std::endl;
    int ilosc_elementow;
    std::cin >> ilosc_elementow;

    int ilosc_powtorzen;
    std::cout << "Ile razy powtorzyc pomiar?" << std::endl;
    std::cin >> ilosc_powtorzen;
    
    int array[12][ilosc_powtorzen] = {0};
    
    switch (funkcja)
    {
    case 1:// back
        {
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

        //dynamic_array.push_front(1);
        dynamic_array.push_back(wartosc_int);

        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
        array[0][i] = duration1.count();

        // Pop i pomiar czasu dla DynamicArray
        auto start2 = high_resolution_clock::now();

            //dynamic_array.pop_front();
            dynamic_array.pop_back();

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
            //one_way_list1.Pushfront(wartosc_int);
            one_way_list1.Pushback(wartosc_int);
        }

        auto start3 = high_resolution_clock::now();

            //one_way_list1.Pushfront(1);
            one_way_list1.Pushback(wartosc_int);

        auto stop3 = high_resolution_clock::now();
        auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
        array[2][i] = duration3.count();

        // Pop i pomiar czasu dla SLL1
        auto start4 = high_resolution_clock::now();

            //one_way_list1.Dltfront();
            one_way_list1.Dltback();

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
            //two_way_list.push_front(wartosc_int);
            two_way_list.push_back(wartosc_int);
        }

        auto start5 = high_resolution_clock::now();

            //two_way_list.push_front(1);
            two_way_list.push_back(wartosc_int);

        auto stop5 = high_resolution_clock::now();
        auto duration5 = duration_cast<nanoseconds>(stop5 - start5);
        array[4][i] = duration5.count();

        // Pop i pomiar czasu dla TwoWayList
        auto start6 = high_resolution_clock::now();

            //two_way_list.pop_front();
            two_way_list.pop_back();

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
            //one_way_list2.Pushfront(wartosc_int);
            one_way_list2.Pushback(wartosc_int);
        }

        auto start7 = high_resolution_clock::now();

            //one_way_list2.Pushfront(1);
            one_way_list2.Pushback(wartosc_int);

        auto stop7 = high_resolution_clock::now();
        auto duration7 = duration_cast<nanoseconds>(stop7 - start7);
        array[6][i] = duration7.count();

        // Pop i pomiar czasu dla SLL2
        auto start8 = high_resolution_clock::now();

            //one_way_list2.Dltfront();
            one_way_list2.Dltback();

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
            break;
        }
    
    case 2:// front
        {
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
            
            break;
        }
    case 3:// random
        {
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

            //dynamic_array.push_front(1);
            //dynamic_array.push_back(wartosc_int);
            dynamic_array.push_random(1);

            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
            array[0][i] = duration1.count();

            // Pop i pomiar czasu dla DynamicArray
            auto start2 = high_resolution_clock::now();

                //dynamic_array.pop_front();
                //dynamic_array.pop_back();
                dynamic_array.pop_random();

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
                //one_way_list1.Pushfront(wartosc_int);
                //one_way_list1.Pushback(wartosc_int);
                one_way_list1.Pushback(wartosc_int);
            }

            auto start3 = high_resolution_clock::now();

                //one_way_list1.Pushfront(1);
                //one_way_list1.Pushback(wartosc_int);
                one_way_list1.Addrand(1);

            auto stop3 = high_resolution_clock::now();
            auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
            array[2][i] = duration3.count();

            // Pop i pomiar czasu dla SLL1
            auto start4 = high_resolution_clock::now();

                //one_way_list1.Dltfront();
                //one_way_list1.Dltback();
                one_way_list1.Dltrand();

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
                //two_way_list.push_front(wartosc_int);
                two_way_list.push_back(wartosc_int);
            }

            auto start5 = high_resolution_clock::now();

                //two_way_list.push_front(1);
                //two_way_list.push_back(wartosc_int);
                two_way_list.push_random(1);

            auto stop5 = high_resolution_clock::now();
            auto duration5 = duration_cast<nanoseconds>(stop5 - start5);
            array[4][i] = duration5.count();

            // Pop i pomiar czasu dla TwoWayList
            auto start6 = high_resolution_clock::now();

                //two_way_list.pop_front();
                //two_way_list.pop_back();
                two_way_list.pop_random();

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
                //one_way_list2.Pushfront(wartosc_int);
                one_way_list2.Pushback(wartosc_int);
            }

            auto start7 = high_resolution_clock::now();

                //one_way_list2.Pushfront(1);
                //one_way_list2.Pushback(wartosc_int);
                one_way_list2.Addrand(1);

            auto stop7 = high_resolution_clock::now();
            auto duration7 = duration_cast<nanoseconds>(stop7 - start7);
            array[6][i] = duration7.count();

            // Pop i pomiar czasu dla SLL2
            auto start8 = high_resolution_clock::now();

                //one_way_list2.Dltfront();
                //one_way_list2.Dltback();
                one_way_list2.Dltrand();

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
            
            break;
        }    
    }
    
    long double srednie[12] = {0}; // Użyjemy zmiennej double dla dokładniejszych obliczeń średnich
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < ilosc_powtorzen; j++) {
            srednie[i] += array[i][j]; // Dodajemy czas wykonania do sumy
        }
        srednie[i] /= ilosc_powtorzen; // Obliczamy średnią dzieląc przez ilość powtórzeń
        switch (i)
        {
        case 0:
            std::cout << "Dynamic array push  " << srednie[i] << std::endl;
            break;
        
        case 1:
            std::cout << "Dynamic array pop  " << srednie[i] << std::endl;
            break;

        case 2:
            std::cout << "Dynamic array find  " << srednie[i] << std::endl;
            break;

        case 3:
            std::cout << "One way list push " << srednie[i] << std::endl;
            break;

        case 4:
            std::cout << "One way list pop  " << srednie[i] << std::endl;
            break;

        case 5:
            std::cout << "One way list find " << srednie[i] << std::endl;
            break;

        case 6:
            std::cout << "Two way list push  " << srednie[i] << std::endl;
            break;
        
        case 7:
            std::cout << "Two way list pop " << srednie[i] << std::endl;
            break;

        case 8:
            std::cout << "Two way list find " << srednie[i] << std::endl;
            break;
        
        case 9:
            std::cout << "One way list+tail push " << srednie[i] << std::endl;
            break;
        
        case 10:
            std::cout << "One way list+tail pop " << srednie[i] << std::endl;
            break;
            
        case 11:
            std::cout << "One way list+tail find " << srednie[i] << std::endl;
            break;

        }
        
        //std::cout << srednie[i] << std::endl;
    }
}

void twoWayListMenu(TwoWayList<int>& two_way_list) {
    int numer_operacji;
    std::cout << "Wybierz operacje:" << std::endl;
    std::cout << "1. Recznie" << std::endl;
    std::cout << "2. Wczytaj z pliku" << std::endl;
    std::cout << "3. Wyswietl liste" << std::endl;
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 3) {
        std::cout << std::endl << "Podaj poprawny numer operacji (1, 2 lub 3): ";
        std::cin >> numer_operacji;
        std::cout << std::endl;
    }

    switch (numer_operacji) {
    case 1: {
        int funkcja;
        std::cout << "Wybierz funkcje:" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. pop back" << std::endl;
        std::cout << "3. push front" << std::endl;
        std::cout << "4. pop front" << std::endl;
        std::cout << "5. push random" << std::endl;
        std::cout << "6. pop random" << std::endl;
        std::cin >> funkcja;

        int ilosc_razy;
        std::cout << "Podaj ilosc operacji:" << std::endl;
        std::cin >> ilosc_razy;

        switch (funkcja) {
            case 1:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na końcu: ";
                    std::cin >> element;
                    two_way_list.push_back(element);
                }
                break;
            case 2:
                for (int i = 0; i < ilosc_razy; ++i) {
                    two_way_list.pop_back();
                }
                break;
            case 3:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na poczatku: ";
                    std::cin >> element;
                    two_way_list.push_front(element);
                }
                break;
            case 4:
                for (int i = 0; i < ilosc_razy; ++i) {
                    two_way_list.pop_front();
                }
                break;
            case 5:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania w losowe miejsce: ";
                    std::cin >> element;
                    two_way_list.push_random(element);
                }
                break;
            case 6:
                for (int i = 0; i < ilosc_razy; ++i) {
                    two_way_list.pop_random();
                }
                break;

            default:
                std::cout << "Niepoprawny numer operacji!" << std::endl;
                break;
        }
        break;
    }

    case 2: {
        int funkcja;
        std::cout << "Jak chcesz dodac wartosci z listy" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. push front" << std::endl;
        std::cout << "3. push random" << std::endl;
        std::cin >> funkcja;

        int wybor_pliku;
        std::cout << "Chcesz uzyc wlasnego pliku czy moze automatycznego ?" << std::endl;
        std::cout << "1. Wlasnego" << std::endl;
        std::cout << "2. Automatycznego" << std::endl;
        std::cin >> wybor_pliku;
        
        std::ifstream plik;

        switch (wybor_pliku) {
            case 1: {
                std::cout << "Podaj sciezke do pliku: ";
                std::string sciezka;
                std::cin >> sciezka;
                plik.open(sciezka);
                while (!plik.is_open()) {
                    std::cerr << "Nie udało sie otworzyc pliku.\n";
                    std::cout << "Podaj sciezke jeszcze raz: ";
                    std::cin >> sciezka;
                    plik.open(sciezka);
                }
                break;
            }
            case 2: {
                int ilosc_elementow;
                std::cout << "Podaj ilosc elementów do wygenerowania: ";
                std::cin >> ilosc_elementow;
                generate_array(ilosc_elementow);
                // Otwórz plik do odczytu
                plik.open("random_number_file.txt");
                break;
            }
        }
        
        switch (funkcja) {
            case 1: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    two_way_list.push_back(wartosc_int);
                }
                break;
            }
            case 2: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    two_way_list.push_front(wartosc_int);
                }
                break;
            }
            case 3: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    two_way_list.push_random(wartosc_int);
                }
                break;
            }
        }

        std::cout << "Wszystko sie udało, oto wartosci znajdujace sie w tej liscie:" << std::endl;
        two_way_list.print_TwoWayList();

        std::cout << "Czy chcesz usunac wszystkie wartosci?" << std::endl;
        std::cout << "1. Tak, za pomoca pop back" << std::endl;
        std::cout << "2. Tak, za pomoca pop front" << std::endl;
        std::cout << "3. Tak, za pomoca pop random" << std::endl;
        std::cout << "4. Nie, zostaw tak jak jest" << std::endl;
        
        int usuwanie;
        std::cin >> usuwanie;
        switch (usuwanie) {
            case 1: {
                int size = two_way_list.getSize();
                while (size != 0) {
                    two_way_list.pop_back();
                    size--;
                }
                break;
            }
            case 2: {
                int size = two_way_list.getSize();
                while (size != 0) {
                    two_way_list.pop_front();
                    size--;
                }
                break;
            }
            case 3: {
                int size = two_way_list.getSize();
                while (size != 0) {
                    two_way_list.pop_random();
                    size--;
                }
                break;
            }
            default: {
                break;
            }
        }
        break;
    }

    case 3: {
        two_way_list.print_TwoWayList();
        break;
    }
    }
}

void oneWayListMenu(SLL1<int>& one_way_list)
{
    int numer_operacji;
    std::cout << "Ustawianie wartosci na ktorych chcesz wykonywac operacje?" << std::endl;
    std::cout << "1. Recznie" << std::endl;
    std::cout << "2. Wczytaj z pliku" << std::endl;
    std::cout << "3. Wyswietl liste" << std::endl;
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 3) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ?! Masz do wyboru tylko 1, 2 lub 3." << std::endl;
        std::cin >> numer_operacji;
        std::cout << std::endl;
    }

    switch (numer_operacji)
    {
    case 1:
    {
        int funkcja;
        std::cout << "Wybierz funkcje:" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. pop back" << std::endl;
        std::cout << "3. push front" << std::endl;
        std::cout << "4. pop front" << std::endl;
        std::cout << "5. push random" << std::endl;
        std::cout << "6. pop random" << std::endl;
        std::cin >> funkcja;

        int ilosc_razy;
        std::cout << "Podaj ile razy ma być wykonana dana operacja:" << std::endl;
        std::cin >> ilosc_razy;

        switch (funkcja) {
            case 1:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na koncu: ";
                    std::cin >> element;
                    one_way_list.Pushback(element);
                }
                break;
            case 2:
                for (int i = 0; i < ilosc_razy; ++i) {
                    one_way_list.Dltback();
                }
                break;
            case 3:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na poczatku: ";
                    std::cin >> element;
                    one_way_list.Pushfront(element);
                }
                break;
            case 4:
                for (int i = 0; i < ilosc_razy; ++i) {
                    one_way_list.Dltfront();
                }
                break;
            case 5:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania w losowe miejsce: ";
                    std::cin >> element;
                    one_way_list.Addrand(element);
                }
                break;
            case 6:
                for (int i = 0; i < ilosc_razy; ++i) {
                    one_way_list.Dltrand();
                }
                break;
            default:
                std::cout << "Niepoprawny numer operacji!" << std::endl;
                break;
        }
        break;
    }

    case 2:
    {
        int funkcja;
        std::cout << "Jak chcesz dodac wartosci z listy" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. push front" << std::endl;
        std::cout << "3. push random" << std::endl;
        std::cin >> funkcja;

        std::ifstream plik;

        int wybor_pliku;
        std::cout << "Chcesz uzyc wlasnego pliku czy moze automatycznego ?" << std::endl;
        std::cout << "1. Wlasnego" << std::endl;
        std::cout << "2. Automatycznego" << std::endl;
        std::cin >> wybor_pliku;

        switch (wybor_pliku) {
            case 1: {
                std::cout << "Podaj sciezke do pliku: ";
                std::string sciezka;
                std::cin >> sciezka;
                plik.open(sciezka);
                while (!plik.is_open()) {
                    std::cerr << "Nie udalo sie otworzyć pliku.\n";
                    std::cout << "Podaj sciezke jeszcze raz: ";
                    std::cin >> sciezka;
                    plik.open(sciezka);
                }
                break;
            }
            case 2: {
                int ilosc_elementow;
                std::cout << "Podaj ilosc elementow do wygenerowania: ";
                std::cin >> ilosc_elementow;
                generate_array(ilosc_elementow);
                // Otwórz plik do odczytu
                plik.open("random_number_file.txt");
                break;
            }
        }

        switch (funkcja) {
            case 1: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    one_way_list.Pushback(wartosc_int);
                }
                break;
            }
            case 2: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    one_way_list.Pushfront(wartosc_int);
                }
                break;
            }
            case 3: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    one_way_list.Addrand(wartosc_int);
                }
                break;
            }
        }

        std::cout << "Wszystko sie udalo, oto wartosci znajdujace sie w tej tablicy:" << std::endl;
        one_way_list.Printlist();

        std::cout << "Czy chcesz usunać wszystkie wartosci?" << std::endl;
        std::cout << "1. Tak, za pomoca pop back" << std::endl;
        std::cout << "2. Tak, za pomoca pop front" << std::endl;
        std::cout << "3. Tak, za pomoca pop random" << std::endl;
        std::cout << "4. Nie, zostaw tak jak jest" << std::endl;

        int usuwanie;
        std::cin >> usuwanie;
        switch (usuwanie) {
            case 1: {
                int size = one_way_list.getSize();
                while (size != 0) {
                    one_way_list.Dltback();
                    size--;
                }
                break;
            }
            case 2: {
                int size = one_way_list.getSize();
                while (size != 0) {
                    one_way_list.Dltfront();
                    size--;
                }
                break;
            }
            case 3: {
                int size = one_way_list.getSize();
                while (size != 0) {
                    one_way_list.Dltrand();
                    size--;
                }
                break;
            }
            default: {
                break;
            }
        }
        break;
    }

    case 3: {
        one_way_list.Printlist();
        break;
    }
    }
}

void oneWayList2Menu(SLL2<int>& one_way_list)
{
    int numer_operacji;
    std::cout << "Ustawianie wartosci na ktorych chcesz wykonywac operacje?" << std::endl;
    std::cout << "1. Recznie" << std::endl;
    std::cout << "2. Wczytaj z pliku" << std::endl;
    std::cout << "3. Wyswietl liste" << std::endl;
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 3) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ?! Masz do wyboru tylko 1, 2 lub 3." << std::endl;
        std::cin >> numer_operacji;
        std::cout << std::endl;
    }

    switch (numer_operacji)
    {
    case 1:
    {
        int funkcja;
        std::cout << "Wybierz funkcje:" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. pop back" << std::endl;
        std::cout << "3. push front" << std::endl;
        std::cout << "4. pop front" << std::endl;
        std::cout << "5. push random" << std::endl;
        std::cout << "6. pop random" << std::endl;
        std::cin >> funkcja;

        int ilosc_razy;
        std::cout << "Podaj ile razy ma być wykonana dana operacja:" << std::endl;
        std::cin >> ilosc_razy;

        switch (funkcja) {
            case 1:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na koncu: ";
                    std::cin >> element;
                    one_way_list.Pushback(element);
                }
                break;
            case 2:
                for (int i = 0; i < ilosc_razy; ++i) {
                    one_way_list.Dltback();
                }
                break;
            case 3:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania na poczatku: ";
                    std::cin >> element;
                    one_way_list.Pushfront(element);
                }
                break;
            case 4:
                for (int i = 0; i < ilosc_razy; ++i) {
                    one_way_list.Dltfront();
                }
                break;
            case 5:
                for (int i = 0; i < ilosc_razy; ++i) {
                    int element;
                    std::cout << "Podaj element do dodania w losowe miejsce: ";
                    std::cin >> element;
                    one_way_list.Addrand(element);
                }
                break;
            case 6:
                for (int i = 0; i < ilosc_razy; ++i) {
                    one_way_list.Dltrand();
                }
                break;
            default:
                std::cout << "Niepoprawny numer operacji!" << std::endl;
                break;
        }
        break;
    }

    case 2:
    {
        int funkcja;
        std::cout << "Jak chcesz dodac wartosci z listy" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. push front" << std::endl;
        std::cout << "3. push random" << std::endl;
        std::cin >> funkcja;

        std::ifstream plik;

        int wybor_pliku;
        std::cout << "Chcesz uzyc wlasnego pliku czy moze automatycznego ?" << std::endl;
        std::cout << "1. Wlasnego" << std::endl;
        std::cout << "2. Automatycznego" << std::endl;
        std::cin >> wybor_pliku;

        switch (wybor_pliku) {
            case 1: {
                std::cout << "Podaj sciezke do pliku: ";
                std::string sciezka;
                std::cin >> sciezka;
                plik.open(sciezka);
                while (!plik.is_open()) {
                    std::cerr << "Nie udalo sie otworzyć pliku.\n";
                    std::cout << "Podaj sciezke jeszcze raz: ";
                    std::cin >> sciezka;
                    plik.open(sciezka);
                }
                break;
            }
            case 2: {
                int ilosc_elementow;
                std::cout << "Podaj ilosc elementow do wygenerowania: ";
                std::cin >> ilosc_elementow;
                generate_array(ilosc_elementow);
                // Otwórz plik do odczytu
                plik.open("random_number_file.txt");
                break;
            }
        }

        switch (funkcja) {
            case 1: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    one_way_list.Pushback(wartosc_int);
                }
                break;
            }
            case 2: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    one_way_list.Pushfront(wartosc_int);
                }
                break;
            }
            case 3: {
                int wartosc_int;
                while (plik >> wartosc_int) {
                    one_way_list.Addrand(wartosc_int);
                }
                break;
            }
        }

        std::cout << "Wszystko sie udalo, oto wartosci znajdujace sie w tej tablicy:" << std::endl;
        one_way_list.Printlist();

        std::cout << "Czy chcesz usunać wszystkie wartosci?" << std::endl;
        std::cout << "1. Tak, za pomoca pop back" << std::endl;
        std::cout << "2. Tak, za pomoca pop front" << std::endl;
        std::cout << "3. Tak, za pomoca pop random" << std::endl;
        std::cout << "4. Nie, zostaw tak jak jest" << std::endl;

        int usuwanie;
        std::cin >> usuwanie;
        switch (usuwanie) {
            case 1: {
                int size = one_way_list.getSize();
                while (size != 0) {
                    one_way_list.Dltback();
                    size--;
                }
                break;
            }
            case 2: {
                int size = one_way_list.getSize();
                while (size != 0) {
                    one_way_list.Dltfront();
                    size--;
                }
                break;
            }
            case 3: {
                int size = one_way_list.getSize();
                while (size != 0) {
                    one_way_list.Dltrand();
                    size--;
                }
                break;
            }
            default: {
                break;
            }
        }
        break;
    }

    case 3: {
        one_way_list.Printlist();
        break;
    }
    }
}

int main() {
    DynamicArray<int> dynamic_array; // Tablica dynamiczna jest tworzona przed pętlą, aby zachować jej trwałość przez cały czas działania programu
    SLL1<int> one_way_list; 
    SLL2<int> one_way_list_tail;
    TwoWayList<int> two_way_list;
    // Pierwszy poziom menu 
    while (true) {
        std::cout << "Wybierz strukture do operacji" << std::endl;
        std::cout << "1. Tablica dynamiczna" << std::endl;
        std::cout << "2. Lista jednokierunkowa" << std::endl;
        std::cout << "3. Lista jednokierunkowa + Tail" << std::endl;
        std::cout << "4. Lista dwukierunkowa" << std::endl;
        std::cout << "5. Wyjdz z programu" << std::endl;
        std::cout << "6. Auto test" << std::endl;

        int numer_listy;
        std::cin >> numer_listy;

        while (1 > numer_listy || numer_listy > 7) {
            std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Do wyboru 1, 2, 3, 4, 5, 6" << std::endl;
            std::cin >> numer_listy;
            std::cout << std::endl;
        }

        switch (numer_listy) {
            case 1: {
                dynamicArrayMenu(dynamic_array);
                break;
            }
            case 2:
                oneWayListMenu(one_way_list);
                break;
            case 3: {
                oneWayList2Menu(one_way_list_tail);
                break;
            }
            case 4:{
                twoWayListMenu(two_way_list);
                break;
            }
            case 5:
                return 0; // Wyjście z programu, jeśli użytkownik wybierze tę opcję

            case 6:
                {
                    std::cout << "Podaj dla jakiej funckji chcesz wykonac testy dla wszystkich struktur" << std::endl;
                    std::cout << "1. Push back i pop back oraz find tej funkcji" << std::endl;
                    std::cout << "2. Push front i pop front oraz find tej funckji " << std::endl;
                    std::cout << "3. Push random i pop random oraz find tej funckji" << std::endl;
                    int funckja;
                    std::cin >> funckja;
                    auto_test(funckja,dynamic_array,one_way_list,two_way_list,one_way_list_tail);

                }
                break;
        }
    }

    return 0;
}


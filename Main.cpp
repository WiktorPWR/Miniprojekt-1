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

        int numer_listy;
        std::cin >> numer_listy;

        while (1 > numer_listy || numer_listy > 4) {
            std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Do wyboru 1, 2, 3" << std::endl;
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
            }
            case 5:
                return 0; // Wyjście z programu, jeśli użytkownik wybierze tę opcję
        }
    }

    return 0;
}


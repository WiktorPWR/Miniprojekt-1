#include <iostream>
#include <string>
#include <fstream>
#include "dynamic_array.cpp"
#include "TwoWayList.cpp"
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
        std::cout << "7. Zczytaj z pliku" << std::endl;
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

        std::cout << "Dodaj sciezke pliku" << std::endl;
        std::string sciezka;
        std::cout << "Podaj sciezke do pliku: ";
        std::getline(std::cin, sciezka);
        std::ifstream plik(sciezka);
        while(!plik.is_open()) {
            std::cerr << "Nie udalo sie otworzyc pliku.\n";
            std::cout << "Podaj sciezke jeszcze raz" << std::endl;
            std::getline(std::cin, sciezka);
            std::ifstream plik(sciezka);
            return ;
        }

        switch (funkcja)
        {
        case 1:
            {
                int wartosc_int;
                while (plik >> wartosc_int) 
                {
                    dynamic_array.push_back(wartosc_int);
                }
                break;
            }
        case 2:
            {
                int wartosc_int;
                while (plik >> wartosc_int) 
                {
                    dynamic_array.push_front(wartosc_int);
                }
                break;
            }
        case 3:
            {

                int wartosc_int;
                while (plik >> wartosc_int)
                {
                    dynamic_array.push_random(wartosc_int);
                }
                break;
            }
        }

        std::cout << "Wsyztko sie udalo o to wartosci ktore sie znajduja w tej tablicy" << std::endl;
        dynamic_array.print_array();

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
                while (size != 0) 
                {
                    dynamic_array.pop_back();
                    size--;
                }
                break;
            }
        
        case 2:
            {
                int size = dynamic_array.getSize();
                while (size != 0)
                {
                    dynamic_array.pop_front();
                    size--;
                }
                break;
            }
        case 3:
            {
                int size = dynamic_array.getSize();
                while (size != 0)
                {
                    dynamic_array.pop_random();
                    size--;
                }
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
    // Drugi poziom menu dla listy dwukierunkowej
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
        std::cout << "7. Zczytaj z pliku" << std::endl;
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
    
    case 2:
        {
        int funkcja;
        std::cout << "Jak chcesz dodac wartosci z listy" << std::endl;
        std::cout << "1. push back" << std::endl;
        std::cout << "2. push front" << std::endl;
        std::cout << "3. push random" << std::endl;
        std::cin >> funkcja;

        std::cout << "Dodaj sciezke pliku" << std::endl;
        std::string sciezka;
        std::cout << "Podaj sciezke do pliku: ";
        std::getline(std::cin, sciezka);
        std::ifstream plik(sciezka);
        while(!plik.is_open()) {
            std::cerr << "Nie udalo sie otworzyc pliku.\n";
            std::cout << "Podaj sciezke jeszcze raz" << std::endl;
            std::getline(std::cin, sciezka);
            std::ifstream plik(sciezka);
            return ;
        }

        switch (funkcja)
        {
        case 1:
            {
                int wartosc_int;
                while (plik >> wartosc_int) 
                {
                    two_way_list.push_back(wartosc_int);
                }
                break;
            }
        case 2:
            {
                int wartosc_int;
                while (plik >> wartosc_int) 
                {
                    two_way_list.push_front(wartosc_int);
                }
                break;
            }
        case 3:
            {

                int wartosc_int;
                while (plik >> wartosc_int)
                {
                    two_way_list.push_random(wartosc_int);
                }
                break;
            }
        }

        std::cout << "Wsyztko sie udalo o to wartosci ktore sie znajduja w tej tablicy" << std::endl;
        two_way_list.print_TwoWayList();

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

                int size = two_way_list.getSize();
                while (size != 0) 
                {
                    two_way_list.pop_back();
                    size--;
                }
                break;
            }
        
        case 2:
            {
                int size = two_way_list.getSize();
                while (size != 0)
                {
                    two_way_list.pop_front();
                    size--;
                }
                break;
            }
        case 3:
            {
                int size = two_way_list.getSize();
                while (size != 0)
                {
                    two_way_list.pop_random();
                    size--;
                }
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
            two_way_list.print_TwoWayList();
            break;
        }
    }
}

int main() {
    DynamicArray<int> dynamic_array; // Tablica dynamiczna jest tworzona przed pętlą, aby zachować jej trwałość przez cały czas działania programu
    TwoWayList<int> two_way_list;
    // Pierwszy poziom menu 
    while (true) {
        std::cout << "Wybierz strukture do operacji" << std::endl;
        std::cout << "1. Tablica dynamiczna" << std::endl;
        std::cout << "2. Lista jednokierunkowa" << std::endl;
        std::cout << "3. Lista dwukierunkowa" << std::endl;
        std::cout << "4. Wyjdz z programu" << std::endl;

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
                // Implementuj menu dla listy jednokierunkowej
                break;
            case 3: {
                twoWayListMenu(two_way_list);
                break;
            }
            case 4:
                return 0; // Wyjście z programu, jeśli użytkownik wybierze tę opcję
        }
    }

    return 0;
}


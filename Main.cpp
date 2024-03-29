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
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 2) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Masz do wyboru albo 1 albo 2" << std::endl;
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
        std::cout << "3. push random" << std::endl;// tutaj dodaj ta implementacje do tego 
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

                // Miejsce na zaaplikowanie random
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
                // Usuwanie za pomoca random
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
    }

    
}

void twoWayListMenu(TwoWayList<int>& two_way_list) {
    // Drugi poziom menu dla listy dwukierunkowej
    int numer_operacji;
    std::cout << "Jaka operacje chcesz wykonac na tej liscie ? " << std::endl;
    std::cout << "1. Dodanie do listy" << std::endl;
    std::cout << "2. Usuniecie elementu z listy" << std::endl;
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 2) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Masz do wyboru albo 1 albo 2" << std::endl;
        std::cin >> numer_operacji;
        std::cout << std::endl;
    }

    int numer_miejsca;
    std::cout << "Na jakim miejscu w tablicy chcesz wykonac dana operacje ?" << std::endl;
    std::cout << "1. Na poczatek listy" << std::endl;
    std::cout << "2. Na koniec listy" << std::endl;
    std::cout << "3. Losowe miejsce w liscie" << std::endl;
    std::cin >> numer_miejsca;

    while (1 > numer_miejsca || numer_miejsca > 3) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Masz do wyboru 1,2,3" << std::endl;
        std::cin >> numer_miejsca;
        std::cout << std::endl;
    }

    int ilosc_razy;
    std::cout << "Ile razy ma byc wykonana dana operacja" << std::endl;
    std::cin >> ilosc_razy;

    // Tutaj możesz dodać logikę wywoływania odpowiednich funkcji operacji na liście dwukierunkowej
}

int main() {
    // Pierwszy poziom menu 
    std::cout << "Wybierz strukture do operacji" << std::endl;
    std::cout << "1. Tablica dynamiczna" << std::endl;
    std::cout << "2. Lista jednokierunkowa" << std::endl;
    std::cout << "3. Lista dwukierunkowa" << std::endl;

    int numer_listy;
    std::cin >> numer_listy;

    while (1 > numer_listy || numer_listy > 3) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUMIESZ ?! Do wyboru 1, 2, 3" << std::endl;
        std::cin >> numer_listy;
        std::cout << std::endl;
    }

    switch (numer_listy) {
        case 1: {
            DynamicArray<int> dynamic_array;
            dynamicArrayMenu(dynamic_array);
            break;
        }
        case 2:
            // Implementuj menu dla listy jednokierunkowej
            break;
        case 3: {
            TwoWayList<int> two_way_list;
            twoWayListMenu(two_way_list);
            break;
        }
    }

    return 0;
}

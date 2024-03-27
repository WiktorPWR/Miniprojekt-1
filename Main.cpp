#include <iostream>
#include <string>
#include "dynamic_array.cpp"
#include "TwoWayList.cpp"
#include "generator.cpp"

void dynamicArrayMenu() {
    DynamicArray<int> dynamic_array;

    // Drugi poziom menu dla tablicy dynamicznej
    int numer_operacji;
    std::cout << "Jaka operacje chcesz wykonac na tej liscie ? " << std::endl;
    std::cout << "1. Dodanie do listy" << std::endl;
    std::cout << "2. Usuniecie elementu z listy" << std::endl;
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 2) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUEMISZ ?! Masz do wyboru albo 1 albo 2" << std::endl;
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
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUEMISZ ?! Masz do wyboru 1,2,3" << std::endl;
        std::cin >> numer_miejsca;
        std::cout << std::endl;
    }

    int ilosc_razy;
    std::cout << "Ile razu ma byc wykonana dana operacja" << std::endl;
    std::cin >> ilosc_razy;

    // Tutaj możesz dodać logikę wywoływania odpowiednich funkcji operacji na tablicy dynamicznej
}

void twoWayListMenu() {
    TwoWayList<int> two_way_list;

    // Drugi poziom menu dla listy dwukierunkowej
    int numer_operacji;
    std::cout << "Jaka operacje chcesz wykonac na tej liscie ? " << std::endl;
    std::cout << "1. Dodanie do listy" << std::endl;
    std::cout << "2. Usuniecie elementu z listy" << std::endl;
    std::cin >> numer_operacji;

    while (1 > numer_operacji || numer_operacji > 2) {
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUEMISZ ?! Masz do wyboru albo 1 albo 2" << std::endl;
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
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUEMISZ ?! Masz do wyboru 1,2,3" << std::endl;
        std::cin >> numer_miejsca;
        std::cout << std::endl;
    }

    int ilosc_razy;
    std::cout << "Ile razu ma byc wykonana dana operacja" << std::endl;
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
        std::cout << std::endl << "PODAJ POPRAWNY NUMER ROZUEMISZ ?! Do wyboru 1, 2, 3" << std::endl;
        std::cin >> numer_listy;
        std::cout << std::endl;
    }

    switch (numer_listy) {
        case 1:
            dynamicArrayMenu();
            break;
        case 2:
            // Tutaj będziesz implementować menu dla listy jednokierunkowej
            break;
        case 3:
            twoWayListMenu();
            break;
    }

    return 0;
}

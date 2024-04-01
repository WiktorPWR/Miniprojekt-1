#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class SLL2 {
private:
    int size = 0; // Inicjalizacja rozmiaru listy na 0
    struct Node { // Struktura węzła listy
        T value; // Wartość przechowywana w węźle
        struct Node *next; // Wskaźnik do następnego węzła
    };
    struct Node *head = NULL; // Wskaźnik na początek listy
    struct Node *tail = NULL; // Wskaźnik na koniec listy

public:
    int Value; // Zmienna publiczna Value
    SLL2 *Next; // Wskaźnik na następny element listy, publiczny

    SLL2() { // Konstruktor
        srand(time(0)); // Inicjalizacja generatora liczb pseudolosowych
    }

    void Pushfront(T data) { // Dodawanie elementu na początek listy
        Node *newnode = new Node(); // Tworzenie nowego węzła
        if(head == NULL){ // Sprawdzenie, czy lista jest pusta
            newnode->next = head; // Ustawienie wskaźnika next nowego węzła na początek listy
            newnode->value = data; // Przypisanie nowej wartości do nowego węzła
            head = newnode; // Ustawienie głowy listy na nowy węzeł
            tail = newnode; // Ustawienie ogona listy na nowy węzeł
        } else { // Jeśli lista nie jest pusta
            newnode->next = head; // Ustawienie wskaźnika next nowego węzła na początek listy
            newnode->value = data; // Przypisanie nowej wartości do nowego węzła
            head = newnode; // Ustawienie głowy listy na nowy węzeł
        }
        size += 1; // Zwiększenie rozmiaru listy
    }

    void Pushback(T data) { // Dodawanie elementu na koniec listy
        Node *newnode = new Node(); // Tworzenie nowego węzła
        newnode->value = data; // Przypisanie nowej wartości do nowego węzła
        newnode->next = NULL; // Ustawienie wskaźnika next nowego węzła na null

        if (head == NULL) { // Jeśli lista jest pusta
            head = newnode; // Ustawienie głowy listy na nowy węzeł
            tail = newnode; // Ustawienie ogona listy na nowy węzeł
        } else { // Jeśli lista nie jest pusta
            tail->next = newnode; // Ustawienie wskaźnika next dla ostatniego węzła na nowy węzeł
            tail = newnode; // Aktualizacja ogona listy na nowy węzeł
        }
        size += 1; // Zwiększenie rozmiaru listy
    }

    void Dltback() { // Usuwanie ostatniego elementu z listy
        if (head == nullptr) { // Jeśli lista jest pusta
            return; // Zakończ funkcję
        }
        if (head->next == nullptr) { // Jeśli lista ma tylko jeden element
            delete head; // Usuń głowę listy
            head = nullptr; // Ustaw wskaźnik na głowę na null
            tail = nullptr; // Ustaw wskaźnik na ogon na null
            size = 0; // Zresetuj rozmiar listy
            return; // Zakończ funkcję
        }
        Node* prev = nullptr; // Wskaźnik na poprzedni węzeł
        Node* current = head; // Wskaźnik na bieżący węzeł
        while (current->next != nullptr) { // Przesuwanie się po liście, aż dojdziemy do przedostatniego elementu
            prev = current; // Ustawienie wskaźnika na poprzedni węzeł na bieżący węzeł
            current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
        }
        delete current; // Usunięcie ostatniego elementu
        tail = prev; // Aktualizacja wskaźnika na ogon listy
        prev->next = nullptr; // Ustawienie wskaźnika next na poprzednim węźle na null
        size--; // Zmniejszenie rozmiaru listy
    }

    void Dltrand(){ // Usuwanie losowego elementu z listy
        if (head == NULL) { // Jeśli lista jest pusta
            return; // Zakończ funkcję
        } else { // Jeśli lista nie jest pusta
            int rand = std::rand() % size + 1; // Wylosowanie liczby od 1 do rozmiaru listy
            Node *current = head; // Ustawienie wskaźnika na bieżący węzeł na początek listy
            Node *a; // Wskaźnik pomocniczy na poprzedni węzeł
            if(rand > 1){ // Jeśli losowa liczba jest większa niż 1
                for(int i = 1; i < rand; i++){ // Przesuwanie się po liście do losowej pozycji
                    a = current; // Ustawienie wskaźnika pomocniczego na bieżący węzeł
                    current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
                }
                Node *next; // Wskaźnik na następny węzeł
                next = current->next; // Ustawienie wskaźnika na następny węzeł na następny węzeł bieżącego węzła
                a->next = next; // Aktualizacja wskaźnika next na poprzednim węźle na następny węzeł
                delete current; // Usunięcie bieżącego węzła
            }
            else if(rand == 1){ // Jeśli losowa liczba jest równa 1
                a = current; // Ustawienie wskaźnika pomocniczego na bieżący węzeł
                current= current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
                delete a; // Usunięcie wskaźnika pomocniczego
                head = current; // Aktualizacja głowy listy
            }
            else if(rand == size){ // Jeśli losowa liczba jest równa rozmiarowi listy
                while (current != NULL) { // Dopóki nie osiągnięto końca listy
                    a = current; // Ustawienie wskaźnika pomocniczego na bieżący węzeł
                    current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
                    if(current->next == NULL){ // Jeśli następny węzeł nie istnieje
                        delete current; // Usunięcie bieżącego węzła
                        a->next = NULL; // Ustawienie wskaźnika next na poprzednim węźle na null
                        tail = a; // Aktualizacja ogona listy
                        break; // Zakończ pętlę
                    }
                }
            }
        }
        size -= 1; // Zmniejszenie rozmiaru listy
    }

    void Addrand(T data) { // Dodawanie elementu na losową pozycję w liście
        int randIndex = std::rand() % (size + 1); // Losowanie indeksu od 0 do rozmiaru listy
        Node *newNode = new Node(); // Tworzenie nowego węzła
        newNode->value = data; // Przypisanie nowej wartości do nowego węzła

        if (randIndex == 0) { // Jeśli losowy indeks wynosi 0
            newNode->next = head; // Ustawienie wskaźnika next nowego węzła na głowę listy
            head = newNode; // Aktualizacja głowy listy na nowy węzeł
            if (tail == NULL) { // Jeśli ogon listy nie istnieje
                tail = newNode; // Ustawienie ogona listy na nowy węzeł
            }
        } else { // Jeśli losowy indeks nie jest równy 0
            Node *current = head; // Ustawienie wskaźnika na bieżący węzeł na początek listy
            for (int i = 1; i < randIndex && current != NULL; i++) { // Przesuwanie się po liście do losowej pozycji
                current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
            }
            if (current != NULL) { // Jeśli bieżący węzeł istnieje
                newNode->next = current->next; // Ustawienie wskaźnika next nowego węzła na następny węzeł bieżącego węzła
                current->next = newNode; // Aktualizacja wskaźnika next bieżącego węzła na nowy węzeł
                if (newNode->next == NULL) { // Jeśli nowy węzeł jest dodawany na koniec listy
                    tail = newNode; // Aktualizacja ogona listy na nowy węzeł
                }
            } else { // Jeśli bieżący węzeł nie istnieje (lista jest pusta lub indeks wykracza poza jej zakres)
                if (head == NULL) { // Jeśli głowa listy nie istnieje (lista jest pusta)
                    head = newNode; // Ustawienie głowy listy na nowy węzeł
                }
                if (tail != NULL) { // Jeśli ogon listy istnieje
                    tail->next = newNode; // Ustawienie wskaźnika next ogona listy na nowy węzeł
                }
                tail = newNode; // Aktualizacja ogona listy na nowy węzeł
            }
        }
        size++; // Zwiększenie rozmiaru listy
    }

    void Printlist() { // Wyświetlanie zawartości listy
        if (head == NULL) { // Jeśli lista jest pusta
            std::cout << "lista jest pusta"; // Wyświetl komunikat
        } else { // Jeśli lista nie jest pusta
            Node *current = head; // Ustawienie wskaźnika na bieżący węzeł na początek listy
            while (current != NULL) { // Dopóki nie dojdziemy do końca listy
                std::cout << current->value << " "; // Wyświetl wartość bieżącego węzła
                current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
            }
            std::cout << "\n Head: " << head->value << "\n Tail: " << tail->value; // Wyświetlenie wartości głowy i ogona listy
        }
        std::cout << "\n Ilosc elementow: " << size << "\n\n"; // Wyświetlenie liczby elementów w liście
    };

    ~SLL2() { // Destruktor
        while (head != nullptr) { // Dopóki istnieją węzły w liście
            Node *temp = head; // Przechowanie wskaźnika na głowę listy w zmiennej tymczasowej
            head = head->next; // Przesunięcie wskaźnika na głowę listy na następny węzeł
            delete temp; // Usunięcie węzła, na który wskazuje wskaźnik tymczasowy
        }
        size = 0; // Zresetowanie rozmiaru listy
    }

    void Dltfront() { // Usuwanie pierwszego elementu z listy
        if (head != NULL) { // Jeśli lista nie jest pusta
            Node *a = head; // Przechowanie wskaźnika na głowę listy w zmiennej tymczasowej
            head = head->next; // Przesunięcie wskaźnika na głowę listy na następny węzeł
            delete a; // Usunięcie węzła, na który wskazuje wskaźnik tymczasowy
            size -= 1; // Zmniejszenie rozmiaru listy

            if (head == NULL) { // Jeśli głowa listy jest pusta (lista jest pusta)
                tail = NULL; // Ustawienie ogona listy na null
            }
        }
    }

    void Find() { // Wyszukiwanie losowej liczby w liście
        if (head == NULL) { // Jeśli lista jest pusta
            std::cout << "lista jest pusta"; // Wyświetl komunikat
        } else { // Jeśli lista nie jest pusta
            Node *current = head; // Ustawienie wskaźnika na bieżący węzeł na początek listy
            int pozycja = 1; // Inicjalizacja zmiennej przechowującej pozycję w liście
            int znalezienia = 0; // Inicjalizacja zmiennej przechowującej liczbę znalezionych elementów
            int rand = std::rand() % 100 + 1; // Wylosowanie liczby od 1 do 100
            std::cout << "szukanie randomowej liczby: " << rand << "\n"; // Wyświetlenie losowej liczby
            while (current != NULL) { // Dopóki nie dojdziemy do końca listy
                if(current->value == rand){ // Jeśli wartość bieżącego węzła jest równa losowej liczbie
                    std::cout << "znaleziono liczbe na " << pozycja << " miejscu! \n"; // Wyświetl informację o znalezieniu liczby
                    znalezienia += 1; // Zwiększenie liczby znalezionych elementów
                }
                pozycja += 1; // Zwiększenie pozycji w liście
                current = current->next; // Przesunięcie wskaźnika na bieżący węzeł na następny węzeł
            }
            if(znalezienia == 0){ // Jeśli nie znaleziono żadnego elementu
                std::cout << "Nie znaleziono podanej liczby na liscie. \n\n"; // Wyświetl komunikat
            }
        }
    }

    int getSize() { // Pobieranie rozmiaru listy
        return size; // Zwrócenie rozmiaru listy
    }
};

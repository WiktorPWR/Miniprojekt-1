#include <iostream> // Biblioteka do operacji wejścia/wyjścia
#include <time.h> // Biblioteka do zarządzania czasem

template <typename T> // Szablon klasy priorytetowej
class PriorityQueue {
private:
    struct Cell { // Struktura komórki listy dwukierunkowej
        int priority; // Priorytet
        T data; // Dane
        Cell* prev; // Wskaźnik na poprzedni element
        Cell* next; // Wskaźnik na następny element
    };

    Cell* head = nullptr; // Wskaźnik na głowę kolejki
    Cell* tail = nullptr; // Wskaźnik na ogon kolejki
    int size = 0; // Rozmiar kolejki

public:
    PriorityQueue() { // Konstruktor
        srand(time(0)); // Inicjalizacja generatora liczb pseudolosowych
    }

    ~PriorityQueue() { // Destruktor
        while (head != nullptr) { // Pętla usuwająca wszystkie elementy kolejki
            Cell* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr; // Ustawienie wskaźnika na ogon na nullptr
        size = 0; // Resetowanie rozmiaru kolejki
    }

    void insert(T new_data, int priority) { // Metoda dodająca element z określonym priorytetem
        Cell* newcell = new Cell(); // Tworzenie nowej komórki
        newcell->data = new_data; // Ustawienie danych komórki
        newcell->priority = priority; // Ustawienie priorytetu komórki

        if (head == nullptr || priority > head->priority) { // Dodanie na początek kolejki, jeśli priorytet nowego elementu jest większy od priorytetu głowy
            newcell->next = head;
            newcell->prev = nullptr;
            if (head != nullptr) {
                head->prev = newcell;
            } else {
                tail = newcell;
            }
            head = newcell;
        } else { // Dodanie w odpowiednim miejscu kolejki
            Cell* current = head;
            while (current->next != nullptr && priority <= current->next->priority) {
                current = current->next;
            }
            newcell->next = current->next;
            newcell->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newcell;
            } else {
                tail = newcell;
            }
            current->next = newcell;
        }
        size++; // Zwiększenie rozmiaru kolejki
    }

    T extract_max() { // Metoda usuwająca i zwracająca element o najwyższym priorytecie
        if (size == 0) {
            throw std::runtime_error("Priority queue is empty"); // Wyjątek gdy kolejka jest pusta
        }
        T max_data = head->data;
        Cell* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
        return max_data;
    }

    T find_max() { // Metoda zwracająca element o najwyższym priorytecie
        if (size == 0) {
            throw std::runtime_error("Priority queue is empty"); // Wyjątek gdy kolejka jest pusta
        }
        return head->data;
    }

    void modify_key(T element, int new_priority) { // Metoda modyfikująca priorytet elementu
        Cell* current = head;
        while (current != nullptr && current->data != element) {
            current = current->next;
        }
        if (current == nullptr) {
            throw std::runtime_error("Element not found in priority queue"); // Wyjątek gdy element nie został znaleziony
        }
        current->priority = new_priority;
        Cell* prev = current->prev;
        Cell* next = current->next;
        if (prev != nullptr && prev->priority < new_priority) { // Przesunięcie elementu na początek kolejki
            if (next != nullptr) {
                next->prev = prev;
            } else {
                tail = prev;
            }
            prev->next = next;
            current->prev = nullptr;
            current->next = head;
            head->prev = current;
            head = current;
        } else if (next != nullptr && next->priority > new_priority) { // Przesunięcie elementu na koniec kolejki
            if (prev != nullptr) {
                prev->next = next;
            } else {
                head = next;
            }
            next->prev = prev;
            current->prev = tail;
            current->next = nullptr;
            tail->next = current;
            tail = current;
        }
    }

    int return_size() { // Metoda zwracająca rozmiar kolejki
        return size;
    }

    void print_PriorityQueue() { // Metoda wypisująca zawartość kolejki
        Cell* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};


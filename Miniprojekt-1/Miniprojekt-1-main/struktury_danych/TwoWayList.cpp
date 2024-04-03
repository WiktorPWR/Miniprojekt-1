#include <iostream>
#include <time.h>
template <typename T> class TwoWayList
{
private:

    int capacity;
    int size; // Rozmiar tablicy mowiacy ile jest elementow w tablicy
    struct Cell // Strukt jednej komurki
    {
        T data; // Dane przechowywane w danej komurce
        struct Cell *prev; // pointer do adresu ja poprzedzajacego 
        struct Cell *next; // pointer do adresu nastepnego po niej
    };
    struct Cell *head = nullptr; // pointer head ktory odnosci sie do pierwszego adresu w liscie
    struct Cell *tail = nullptr; // pointer tail  ktory odnosi sie do ostatniego adresu w liscie

public:

    TwoWayList()
    {
        size = 0;
        capacity = 1;
        srand(time(0));
    }

    ~TwoWayList() {// Destruktor klasy
        while (head != nullptr) { // Pętla wykonuje się dopóki istnieją węzły na liście
            Cell *temp = head; // Tworzenie tymczasowego wskaźnika na początek listy
            head = head->next; // Przesunięcie wskaźnika na następny węzeł w liście
            delete temp; // Usunięcie węzła, na który wskazuje tymczasowy wskaźnik
        }
        tail = nullptr;
        size = 0; // Zresetowanie wartości size na 0
    }

    void change_value_at_position(int location) //ustawanie wartosci podanej przez uzytkownika na konkretnym miejscu
    {

        Cell *cell = head; // utworzenie pointera ktory bedzie rowny head
        for (int i=0;i<=location;i++) // przeiterowanie przez elementy w liscie az do momentu kiedy nasza lokalizacja bedzie sie zgadzac z adresem w kotry chcemy wpisac
        {
            cell = cell->next; // ustawienie prevcell na nastepny adres
        }
        cell->data = 18;

    }

    void Addtofind(int ilosc_elemntow){
        std::cout<< "Na jakim miejscu dodać liczbę 18?" << ilosc_elemntow/3 << " " << ilosc_elemntow/2 << " " << 2*ilosc_elemntow/3;
        int data;
        std::cin >> data;
        change_value_at_position(data, 18);
    }
    
    void push_front(T new_data)
    {
        Cell *newcell = new Cell();
        newcell->next = head;
        newcell->prev = nullptr;
        newcell->data = new_data;
        if (head != nullptr) 
        {
            head->prev = newcell;
        }
        head = newcell;
        if (tail == nullptr) 
        {
            tail = newcell; // Jeśli lista jest pusta, ustawiamy też tail
        }
        size++;
    }
    
    void push_back(T new_data)
    {
        Cell *newcell = new Cell();
        newcell->next  = nullptr;
        if (head == nullptr)
        {
            newcell->prev = nullptr;
            newcell->data = new_data;
            head = newcell;
        }
        else
        {
            newcell->prev = tail;
            tail->next = newcell;
            newcell->data = new_data;
        }
        tail = newcell;
        size++;
    }

    void push_random(T new_data)
    {
        if (size == 0) // Sprawdź, czy lista jest pusta
        {
            push_front(new_data); // Jeśli lista jest pusta, użyj funkcji push_front
            return; // Zakończ funkcję
        }

        Cell *prevcell = head;
        int location = std::rand() % size;
        for (int i = 1; i < location; i++) // Poprawka warunku pętli
        {
            prevcell = prevcell->next;
        }
        Cell *newcell = new Cell();
        newcell->data = new_data;
        newcell->next = prevcell->next;
        prevcell->next = newcell;
        newcell->prev = prevcell;
        if (newcell->next != nullptr)
        {
            newcell->next->prev = newcell;
        }
        else
        {
            tail = newcell; // Aktualizacja tail, jeśli nowy element jest dodawany na końcu listy
        }
        size++;
    }

    void pop_back() 
    {
        if (head == nullptr) 
        {
            return;
        }

        if (head == tail) 
        { // Jest tylko jeden element w liście
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
        } else {
            Cell *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            size--;
        }
    }

    void pop_front()
    {
        if (head == nullptr) 
        {
            return;
        }

        if (head == tail) 
        { // Jest tylko jeden element w liście
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
        } else {
            Cell *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            size--;
        }
    }

    void pop_random() 
    {
        if (size != 0) {
            int location = std::rand() % size;
            if (location == 0) {
                // Usunięcie pierwszego elementu
                Cell* temp = head;
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
                delete temp;
            } else {
                // Usunięcie elementu na losowej pozycji
                Cell* prevcell = head;
                for (int i = 0; i < location; i++) {
                    prevcell = prevcell->next;
                }
                prevcell->prev->next = prevcell->next;
                if (prevcell->next != nullptr) {
                    prevcell->next->prev = prevcell->prev;
                }
                delete prevcell;
            }
            size--;
        }
    }

    void print_TwoWayList()
    {
        Cell *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }

    int getSize()
    {
        return size;
    }

    void Find(){
        Cell *front = head;
        Cell *back = tail;
        while (front != nullptr && back != nullptr && front != back && front->prev != back) {
            if (front->data == 18 || back->data == 18) {
                break;
            }
            front = front->next;
            back = back->prev;
        }
    }
};


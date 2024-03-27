#include <iostream>
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
        }

        void change_value_at_position(int location, T new_data) //ustawanie wartosci podanej przez uzytkownika na konkretnym miejscu
        {
            Cell *prevcell = head; // utworzenie pointera ktory bedzie rowny head
            for (int i=0;i<=location;i++) // przeiterowanie przez elementy w liscie az do momentu kiedy nasza lokalizacja bedzie sie zgadzac z adresem w kotry chcemy wpisac
            {
                prevcell = prevcell->next; // ustawienie prevcell na nastepny adres
            }
            Cell *newcell = new Cell(); // utworzenie nowej komurki
            newcell->data = new_data; // przypisanie pointera nowej komurki do nowej danej podanej przez urzytkownika
            newcell->next = prevcell->next; // przypisanie wartosci adresu nastepujacego po nowej komurce do wartsoci next poprzedniej komurki
            prevcell->next = newcell; //
            newcell->prev = prevcell;
            if (newcell->next != nullptr)
            {
                newcell->next->prev = newcell;
            }

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
            } else {
                Cell *temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
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
            } else {
                Cell *temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
        }

        void print_TwoWayList()
        {
            Cell *current = head;
            while (current != nullptr)
            {
                std::cout << current->data << std::endl;
                current = current->next;
            }
        }
};
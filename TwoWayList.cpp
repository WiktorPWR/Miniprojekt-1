#include <iostream>
template <typename T> class TwoWayList
{
    private:

        int size;
        int capacity;
        struct Cell
        {
            T data;
            struct Cell *prev;
            struct Cell *next;
        };
        struct Cell *head = nullptr;
        struct Cell *tail = nullptr;

    public:

        TwoWayList()
        {
            size = 0;
            capacity = 1;
        }

        void change_value_at_position(int location, T new_data)
        {
            Cell *prevcell = head;
            for (int i=0;i<=location;i++)
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
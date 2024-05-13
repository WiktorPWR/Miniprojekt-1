
#include <cstdlib>
#include <iostream>

template <typename T> 
class Priority_queue 
{
private:
    int size;   // Ilość elementów w kolejce
    int capacity;   // Wielkość fizyczna tablicy
    struct Node 
    {
        T input; // Wartość elementu
        int priority; // Priorytet elementu
        Node(T value, int prio) : input(value), priority(prio) {} // Konstruktor struktury Node
    };
    Node** array = nullptr;    // Tablica wskaźników do obiektów typu Node

public:
    Priority_queue() : size(0), capacity(1)
    {
        array = new Node*[capacity];    // Alokacja pamięci na tablicę wskaźników do obiektów Node
    }
   
    int returnSize() { return size; } // Zwraca rozmiar kolejki

    int getCapacity() { return capacity; } // Zwraca pojemność kolejki

    void insert(T value, int priority)
    {
        Node* node = new Node(value, priority); // Tworzenie nowego elementu
        grow_array(); // Sprawdzenie i ewentualne zwiększenie rozmiaru tablicy
        size++;
        int child = size;
        array[child] = node;

        // Naprawa kopca
        while (child > 1 && array[child]->priority > array[child/2]->priority)
        {
            swap(array[child], array[child/2]);
            child = child / 2;
        }
    }

    void Heapify(int index_of_element)
    {
        int largest = index_of_element;
        int left_child = 2 * index_of_element;
        int right_child = 2 * index_of_element + 1;

        // Sprawdzenie, czy lewy i prawy potomek nie jest NULL i czy ich priorytet jest większy
        if (left_child <= size && array[left_child] != nullptr && array[left_child]->priority > array[largest]->priority)
            largest = left_child;
        if (right_child <= size && array[right_child] != nullptr && array[right_child]->priority > array[largest]->priority)
            largest = right_child;

        // Jeśli największy element nie jest aktualny, zamień i napraw kopiec rekurencyjnie
        if (largest != index_of_element)
        {
            swap(array[largest], array[index_of_element]);
            Heapify(largest);
        }
    }

    T extract_max()
    {
        if (size == 0)
        {
            throw std::logic_error("Kolejka jest pusta");
        }
        T max_element = array[1]->input; // Zapisanie wartości maksymalnego elementu
        array[1] = array[size]; // Przeniesienie ostatniego elementu na miejsce maksymalnego
        array[size] = nullptr; // Usunięcie referencji na ostatni element
        shrink_array(); // Sprawdzenie i ewentualne zmniejszenie rozmiaru tablicy
        size--;
        Heapify(1); // Naprawa kopca
        return max_element; // Zwrócenie maksymalnego elementu
    }

    T find_max()
    {
        if (size == 0 || array[1] == nullptr)
        {
            throw std::logic_error("Kolejka jest pusta");
        }
        return array[1]->input; // Zwrócenie wartości maksymalnego elementu
    }

    void modify_key(T value_of_element, int priority)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] != nullptr && array[i]->input == value_of_element)
            {
                std::cout << " Został znaleziony element o wartości " << value_of_element << std::endl;
                array[i]->priority = priority; // Zmiana priorytetu znalezionego elementu
                // Sprawdź, czy nowy priorytet jest większy niż priorytet rodzica
                if (i > 0 && array[i]->priority > array[(i - 1) / 2]->priority)
                {
                    // Napraw kopiec w górę, jeśli nowy priorytet jest większy
                    while (i > 0 && array[i]->priority > array[(i - 1) / 2]->priority)
                    {
                        swap(array[i], array[(i - 1) / 2]); // Zamień elementy
                        i = (i - 1) / 2;
                    }
                }
                else // Jeśli nowy priorytet jest mniejszy lub równy niż priorytet rodzica, napraw kopiec w dół
                {
                    Heapify(i);
                }
                break; // Zakończ pętlę po znalezieniu elementu
            }
        }
    }

    void swap(Node*& value_1, Node*& value_2)
    {
        Node* temp = value_1;
        value_1 = value_2;
        value_2 = temp;
    }

    void grow_array()
    {
        if (size == capacity)
        {
            Node** newlist = new Node*[capacity * 2]; // Tworzenie nowej tablicy o dwukrotnie większym rozmiarze
            capacity *= 2; // Zwiększenie pojemności kolejki
            for (int i = 1; i <= size; i++)
            {
                newlist[i] = array[i]; // Kopiowanie elementów do nowej tablicy
            }
            delete[] array; // Usunięcie starej tablicy
            array = newlist; // Przypisanie nowej tablicy
        }
    }

    void shrink_array()
    {
        if (size <= capacity / 4)
        {
            Node** newlist = new Node*[capacity / 2]; // Tworzenie nowej tablicy o połowę mniejszym rozmiarze
            capacity /= 2; // Zmniejszenie pojemności kolejki
            for (int i = 1; i <= size; i++)
            {
                newlist[i] = array[i]; // Kopiowanie elementów do nowej tablicy
            }
            delete[] array; // Usunięcie starej tablicy
            array = newlist; // Przypisanie nowej tablicy
        }
    }

    void print_array()
    {
        for (int i = 1; i <= size; i++)
        {
            std::cout << array[i]->input << " ";
        }
        std::cout << "Rozmiar: " << returnSize() << ", Pojemność: " << getCapacity() << std::endl;
    }

    ~Priority_queue()
    {
        for (int i = 1; i <= size; i++)
        {
            delete array[i];
        }
        delete[] array;
    }
};
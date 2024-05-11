#include <cstdlib>
#include <time.h>
#include <iostream>
template <typename T> class Priority_queue // zdefinowanie klasy jako szablon 
{
    private:
        int size;   //ilosc elementow w tej talbicy
        int capacity;   //wielkosc fizyczna tablicy
        Node* array = nullptr;    //utworznuie zmiennej array i przypisanie jej od razu wartosc NULL 
        struct Node 
        {
            T input;
            int priority;
            Node* child_1;
            Node* child_2;
            Node(T value, int prio) : input(value), priority(prio), child_1(nullptr), child_2(nullptr) {}
        };

    public:
        Priority_queue()  //lista inicjalizacyjna array(nullptr) jest tak zapobiegawczo i moze zostac pominiety
        {
            capacity = 1;   //dajemy rozmiar tablicy by w ogole moc ja stworzyc
            size = 0;   //nie mamy jeszcze zadnych elementow zatem nasz rozmiar bedzie rony 0
            array = new T[capacity];    //zaalokowanie nowej tablicy array o type T
        }
       
        int returnSize(){return size;} // funkcja zwraca rozmiar talblicy

        int getCapasity(){return capacity;} // funckja zwraca pojhemnosc talbicy

        void insert(T value,  int priority)  //funckja ma za zadanie wlozyc na ostatnie miejsce listy, element o wartosci przez nas zdefinowanej i pozniej zwieksza jej rozmiar 
        {
            Node *node = new Node(value,priority);
       
            grow_array();
            size++;
            int child = size;
            array[child] = node; // przypisujemy na mijescu size nasza wartosc ktora uzywamy

            while(child > 1 && array[child]->priority > array[child/2]->priority)//prownywanie dziecka z jego rodzicami do czasu az nie bedzie zachowayn warunek ze rodzic bedzie wiekszy niz dziecko
            {
                swap(array[child],array[child/2]);
                child = child/2;
            }
        }

        void Heapify(int index_of_element)
        {
            int largest = index_of_element;
            if(2*index_of_element <= size && array[2*index_of_element]->priority > array[largest])
            {
                largest = 2*index_of_element;
            }
            else if(2*index_of_element + 1 <= size && array[2*index_of_element + 1]->priority > array[largest])
            {
                largest = 2*index_of_element + 1;
            }
            else if(largest != index_of_element)
            {
                swap(array[largest],array[index_of_element]);
                Heapify(largest);
            }

        }
        
        T extract_max() //funckja majaca na celu ,,wyrzucenie ostatniego elemtnetu z tablicy"
        {
            if(size == 0)
            {
                throw std::logic_error("Kopiec jest pusty");
            }
            T max_element = array[0];// element maksymalny
            array[0] = array[size - 1];
            array[size - 1] = T(); 
            shrink_array();
            size--; // pomnijeszenie rozmiary talbicy o jeden
            Heapify(0);
            return max_element;
        }

        T find_max()
        { 
            return array[0];
        }

        modify_key(T value_of_element,int priority)
        {
            for(int i=0;i<=size;i++)
            {
                if(array[i]->value = value_of_element)
                {
                    array[i]->priority = priority;
                }
            }
        }

        void swap(T& value_1, T& value_2)
        {
            T zmienna_tymczasowa = value_1;
            value_1 = value_2;
            value_2 = zmienna_tymczasowa;
        }

        void grow_array() // funckja sprawdzajaca czy mozna ziwekszysc rozmiar tablicy jezeli tak robi to
        {
            if (size == capacity) // jezeli rozmiar tablicy jest rowny jej pojemnosci 
            {
                T* newlist = new T[capacity*2];  //tworzymy nowa liste o dwa razy wieskzym rozmiarze 
                capacity = capacity*2; //tutaj zwiekszamy pojemnosc listy dwukrotnie ale tym razem samej zmiennej
                for(int i=0;i<size;i++) // petla ktora bedzie iterowac tyle razy jaki jest rozmiar listy (ile jest tam jej elementow)
                {
                    newlist[i] = array[i];  // wartosci ze starej listy zapisujemy do nowej listy przez nas stworzonej
                }
                delete[] array; // usuwamy stara liste z pamieci
                array = newlist; // przypisujemy nowa liste do starej nazwwy tej zmiennej
            } else {
                return; // jezeli nie trzeba to wychodzimy z funckji
            }
        }

        void shrink_array() // funkcja sprawdzajaca czy mozna zmniejszyc rozmiar tablicy
        {
            if (size == capacity/2) // jezeli rozmiar funkcji jest o polowe mniejsza niz polowa rozmairu
            {
                capacity = capacity/2; 
                T* newlist = new T[capacity]; // tworzymy nowa liste ktora bedzie miala o polowe pomnijeszony rozmiar niz wczesniej 
                for(int i=0;i<size;i++)
                {
                    newlist[i] = array[i]; // ponone przypisanie elemetow starej listy no nowej listy
                }
                delete[] array; // usuniecie starej tablicy
                array = newlist; // przypisanie do zmiennej array nowej tablicy 
            } else {
                return;
            }
        }

        void print_array() // funckja majaca na celu wydrukowanie calosci elementow oraz wyswietlisc rozmiar i pojemnosc tablicy
        {
            for(int i=0;i<size;i++)
            {
                std::cout << array[i] << " ";
            }
            std::cout << "Size is " << returnSize() << std::endl << "Capasity is " << getCapasity() << std::endl;
        }

        ~Priority_queue() //dekonostruktor
        {
            delete[] array; // usuwa caly array z pamiecie
        }

};



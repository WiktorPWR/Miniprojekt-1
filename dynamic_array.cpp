#include <iostream>
#include <string>

template <typename T> class DynamicArray // zdefinowanie klasy jako szablon 
{
    private:
        int size;   //ilosc elementow w tej talbicy
        int capacity;   //wielkosc fizyczna tablicy
        T* array = NULL;    //utworznuie zmiennej array i przypisanie jej od razu wartosc NULL 

    public:
        DynamicArray()  //lista inicjalizacyjna array(nullptr) jest tak zapobiegawczo i moze zostac pominiety
        {
            capacity = 1;   //dajemy rozmiar tablicy by w ogole moc ja stworzyc
            size = 0;   //nie mamy jeszcze zadnych elementow zatem nasz rozmiar bedzie rony 0
            array = new T[capacity];    //zaalokowanie nowej tablicy array o type T
        }
       
        int getSize(){return size;} // funkcja zwraca rozmiar talblicy

        int getCapasity(){return capacity;} // funckja zwraca pojhemnosc talbicy

        void push_back(T value)  //funckja ma za zadanie wlozyc na ostatnie miejsce listy, element o wartosci przez nas zdefinowanej i pozniej zwieksza jej rozmiar 
        {
            if(size == capacity)    //jezeli rozmiar jest rowny pojemnosci czyli osiagnelismy maks naszej listy
            {
                T* newlist = new T[capacity*2];  //tworzymy nowa liste o dwa razy wieskzym rozmiarze 
                capacity = capacity*2; //tutaj zwiekszamy pojemnosc listy dwukrotnie ale tym razem samej zmiennej
                for(int i=0;i<size;i++) // petla ktora bedzie iterowac tyle razy jaki jest rozmiar listy (ile jest tam jej elementow)
                {
                    newlist[i] = array[i];  // wartosci ze starej listy zapisujemy do nowej listy przez nas stworzonej
                }
                delete[] array; // usuwamy stara liste z pamieci
                array = newlist; // przypisujemy nowa liste do starej nazwwy tej zmiennej
            }
            array[size] = value; // przypisujemy na mijescu size nasza wartosc ktora uzywamy
            size++; // zwiekszamy rozmiar talbicy tym razem w samej zmiennej
            
        }
        
        void pop_back() //funckja majaca na celu ,,wyrzucenie ostatniego elemtnetu z tablicy"
        {
            array[size-1] = T(); //przyrownujemy wartosc ostatniego elementu talbicy do wartosc 0.
            //T() to yrazenie ktore tworzy nowy obiekt typu T przy uzyciu konstruktora domyslnego a wartosc domylsna to jest 0
            if(size == capacity/2 ) //jezeli rozmiar tablicy jest rowny polowie pojemnosci naszej tablicy czyli ilosc elemetow spadnie ponizej polowy mozliwsoci tablicy
            {
                capacity = capacity/2; 
                T* newlist = new T[capacity]; // tworzymy nowa liste ktora bedzie miala o polowe pomnijeszony rozmiar niz wczesniej 
                for(int i=0;i<size;i++)
                {
                    newlist[i] = array[i]; // ponone przypisanie elemetow starej listy no nowej listy
                }
                delete[] array; // usuniecie starej tablicy
                array = newlist; // przypisanie do zmiennej array nowej tablicy 
            }
            size -= 1; // pomnijeszenie rozmiary talbicy o jeden
        }

        void print_array() // funckja majaca na celu wydrukowanie calosci elementow oraz wyswietlisc rozmiar i pojemnosc tablicy
        {
            for(int i=0;i<size;i++)
            {
                std::cout << array[i] << std::endl;
            }
            std::cout << "Size is " << getSize() << std::endl << "Capasity is " << getCapasity() << std::endl;
        }

        void change_value_at_position(int location, T value) // funckja majaca na celu zmiene wartosci w daenj konktretej lokalizacji 
        {
            array[location] = value;
        }
        
        ~DynamicArray() //dekonostruktor
        {
            delete[] array; // usuwa caly array z pamiecie
        }

};

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
                newcell->next = newcell;
                newcell->prev = newcell;
            }

        }
        

        void push_front(T new_data)
        {
            Cell *newcell = new Cell();
            newcell->next = head;
            newcell->prev = nullptr;
            newcell->data = new_data;
            head = newcell;
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

        void print_double_list()
        {
            Cell *current = head;
            while (current != nullptr)
            {
                std::cout << current->data << std::endl;
                current = current->next;
            }
        } 
};

int main()
{
    TwoWayList <int> clasa; 
    for (int i = 0; i <= 10; i++)
    {
        clasa.push_front(i);
    }
    clasa.print_double_list();
    std::cout << "hello" << std::endl;
    return 0;
}
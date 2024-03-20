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
            grow_array();
            array[size] = value; // przypisujemy na mijescu size nasza wartosc ktora uzywamy
            size++; // zwiekszamy rozmiar talbicy tym razem w samej zmiennej
        }
        
        void pop_back() //funckja majaca na celu ,,wyrzucenie ostatniego elemtnetu z tablicy"
        {
            array[size-1] = T(); //przyrownujemy wartosc ostatniego elementu talbicy do wartosc 0.
            //T() to yrazenie ktore tworzy nowy obiekt typu T przy uzyciu konstruktora domyslnego a wartosc domylsna to jest 0
            shrink_array();
            size--; // pomnijeszenie rozmiary talbicy o jeden
        }

        void push_front(T value) // funckja majaca na celu ,,wsadzenie" nowego elementu o wartosci value na poczatek tablicy
        {
            grow_array();
            for (int i = size;i >= 0; i--)// iteruje przez wysztkie elemetny w arrayu
            {
                array[i+1] = array[i]; // wartosci komurek zostana przesuniete o jeden w prawo w tablicy  
            }
            array[0] = value; // przypisanie nowej wartosci do pierwszego elementu w tablicy
            size++; // zwiekszenie rozmairu tablicy
        }

        void pop_front() // funckja majaca na celu wyrzucenie pierwszego elementu
        {
            shrink_array();
            for (int i = 0;i <= size; i++) // iterowanie przez wsyzstkie elementy w liscie
            {
                array[i] = array[i+1]; // wartosci komurek sa nadpisywane przez wartosci o jeden w lewo
            }
            size--; // zmniejszenie rozmiaru tablicy
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



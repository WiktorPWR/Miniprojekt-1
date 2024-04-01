#include <iostream>
#include <cstdlib>
#include <time.h>

template <typename T> class SLL1 {

private:
    int size = 0;// Utworzenie zeminnej size ktora bedzie przetzymywac ile jest obiektow w naszej liscie
    struct Node { // Utworzenie struktu ktory bedzie symbolizowac nasze wezly w tablicy
        T value;// posiada on zmeinna w ktorej bedzie przetzymywana wartosc 
        struct Node *next;// jak i rowniez pointer do elementu nastepnego w liscie
    };
    struct Node *head = NULL; // Pointer do pierwszego miejsca w tablicy
public:

    SLL1()// Konstruktor klasy
    {
        srand(time(0));// Zainicjowanie generator liczb zmiennych
    }

    void Pushfront(T data) { // Funckja ,,wkładająca" element na pierwsze miejsca w liscie

        Node *newnode = new Node();// Utworznie nowego obiektu typu Node 
        newnode->next = head;// Przypisanie pointera nowego obiektu do head(poszczatku naszej lsity)
        newnode->value = data;// Pypiszanie wartosci nowego obiektu do zmiennej podaj przez uzytkownika
        head = newnode;// Przypisanie pointer head do nowego wezła by mogł na niego wskazywać
        size += 1;// Zwiekszenie rozmiaru o jeden w tablicy
    };

     void Pushback(T data) { // Funckja ,,wkładajaca" element na ostatnie miejsce w liscie
        Node* newnode = new Node();// Utowrznie nowego obiektu typu Node
        newnode->value = data;// Przypisanie pointera nowego obiektu do head(poszczatku naszej lsity)
        newnode->next = nullptr; // Jako ze to koniec listy to pointer next nowego obiektu przypisujemy do nullptr poniewaz nie wskazuje on na zaden inny obikrt
        if (head == nullptr) {// sprawdzneie czy lista jest pusta 
            head = newnode;// Jezli  lista jest pusta nastepuje przypisanie pointer head do nowego wezła by mogł na niego wskazywać
        } else {
            Node* current = head;//Jezlei nie jest pusta tworzymy nowy wskaznik ktory wskazzuje na head
            while (current->next != nullptr) {// Nastepuje przejscie przez cala liste az do momentu kiedy poinetr next komurki bedzie nullptr
                current = current->next;
            }
            current->next = newnode;// Przypisanie wartosci pointera ostatniejgo miejsca w tablicy do nowego wezla przez nas utworzonego
        }
        size++;// zwiekszenie rozmiaru o jeden
    }


    void Dltback() {// Funkcja majaca na celu
    if (head == nullptr) {
        return; // Lista jest pusta, nie ma nic do usunięcia
    }

    Node* current = head;// Utworzenie nowej zmiennej current pointujacej na head(poczatek listy)
    Node* prev = nullptr;// Utworzenei nowej zmiennej prev pointujacej do niczego. Ma ona na celu znalezienie przed ostatniego elementu w liscie 

    while (current->next != nullptr) { // przejscie przez cala liste
        prev = current;
        current = current->next;
    }

    if (prev != nullptr) {// Kiedy jestesmy na przed ostatnim mijescu w talbicy
        delete current;// usuwamy aktualny ostani element w tablicy
        prev->next = nullptr; // Ustawienie wskaźnika next poprzedniego elementu na nullptr
    } else {
        // Usuwamy pierwszy element z listy
        delete head;// usuniecie pierwszego lememtu w talbicy
        head = nullptr;// przypisanie wartosci head jako nullptr
    }

    size--;// zmniejszenie rozmairu tablicy o jeden
}

    

   void Dltrand() {
    if (head != nullptr) { // Jezeli lista jest pusta
        int randIndex = std::rand() % size; // Losowy indeks od 0 do size 
        Node *current = head;// przypisanie pointera current do head
        Node *prev = nullptr;// przypisanie prev na nullpritn. Zmiennea to bedzie wskazywac na element poprzedzajacy elelnt do usuniecie

        if (randIndex > 0) {// Jezeli bedzie operowac na kazdym innym adresie niz pierwszy
            for (int i = 0; i < randIndex; i++) {// przechodzimy przez cala tablice az do miejsca randIndex ktore wybralismy
                prev = current;// przypisanie wartosci prev do elemntu poprzedzajcego nasz do usuniecie
                current = current->next;// przypisanie wartosci current do miejsca ktore chcmy usunac
            }
            if (prev != nullptr) {// jezeli jest elment poprzedzajcy nasz lsite
                prev->next = current->next;// przypisanei pointerowi poprzedzajacego elementu do wartosci nastpenej po current
            } else {
                head = current->next;// Jezlei nie mma elemntu poprzedzajacego wowczas head przypisujemy do wartosci current->next czyli w tym wypadku nullprt
            }
            delete current;// usuniecie naszego wezla
        } else {
            head = head->next;// Wartość pointera head zostaje zaktualizowana, aby wskazywała na następny węzeł po usuwanym węźle 
            delete current;
        }
        size--;// zmniejszenie rozmiaru o jeden
    }
}

    void Addrand(T data) {
    if (head != nullptr) {
        int randIndex = std::rand() % size; // Losowy indeks od 0 do size - 1
        Node *current = head;
        Node *prev = nullptr;
        Node *newNode = new Node();
        newNode->value = data;

        if (randIndex > 0) {
            for (int i = 0; i < randIndex; i++) {
                prev = current;
                current = current->next;
            }
            newNode->next = current;
            prev->next = newNode;
        } else {
            newNode->next = current;
            head = newNode;
        }
        size++;
    } else {
        Pushback(data);
    }
}

    void Printlist() {
        if (head == NULL) {
            std::cout << "lista jest pusta";
        } else {
            Node *current = head;
            while (current != NULL) {
                std::cout << current->value << " ";
                current = current->next;
            }
        }
        std::cout << "\n Ilosc elementow: " << size << "\n";

    };

    ~SLL1() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;

        }
        size = 0;
    }

    void Dltfront() {
        Node *a;
        a = head;
        head = head->next;
        delete a;
        size -= 1;
    }

    void Find(){
        if (head == NULL) {
            std::cout << "lista jest pusta";
        } else {
            Node *current = head;
            int pozycja = 1;
            int znalezienia = 0;
            int rand = std::rand() % 100 + 1;
            std::cout << "szukanie randomowej liczby: " << rand << "\n";
            while (current != NULL) {
                if(current->value == rand){
                    std::cout << "znaleziono liczbe na " << pozycja << " miejscu! \n";
                    znalezienia += 1;
                }
                pozycja += 1;
                current = current->next;
            }
            if(znalezienia == 0){ std::cout << "Nie znaleziono podanej liczby na liscie. \n";}
        }


    }

    int getSize()
    {
        return size;
    }

};


#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T> class SLL2 {

private:
    int size = 0;
    struct Node {
        T value;
        struct Node *next;
    };
    struct Node *head = NULL;
    struct Node *tail = NULL;

public:
    int Value;
    SLL2 *Next;

    SLL2()
    {
        srand(time(0));
    }

    void Pushfront(T data) {

        //int rand = std::rand() % 100 + 1;
        Node *newnode = new Node();
        if(head == NULL){
        newnode->next = head;
        newnode->value = data;
        head = newnode;
        tail = newnode;
        } else {
            newnode->next = head;
            newnode->value = data;
            head = newnode;
        }
        size += 1;
    }


    void Pushback(T data) {
    Node *newnode = new Node();
    newnode->value = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    size += 1;
};


    void Dltback() {
    if (head == nullptr) {
        return; // Lista jest pusta, nie ma nic do usunięcia
    }

    // Jeśli lista ma tylko jeden element, usuwamy go i aktualizujemy wskaźniki head i tail
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    // Znajdujemy przedostatni element
    Node* prev = nullptr;
    Node* current = head;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    // Usuwamy ostatni element
    delete current;

    // Aktualizujemy wskaźniki head, tail i rozmiar listy
    tail = prev;
    prev->next = nullptr;
    size--;
}

    void Dltrand(){
        if (head == NULL) {
            //std::cout << "lista jest pusta";
        } else {
            int rand = std::rand() % size + 1;
            //std::cout << "usuwanie " << rand << " elementu. \n";
            Node *current = head;
            Node *a;
            if(rand > 1){
                for(int i = 1; i < rand; i++){
                    a = current;
                    current = current->next;
                }
                Node *next;
                next = current->next;
                a->next = next;
                delete current;
            }
            else if(rand == 1){
                a = current;
                current= current->next;
                delete a;
                head = current;
            }
            else if(rand == size){
                while (current != NULL) {
                    a = current;
                    current = current->next;
                    if(current->next == NULL){
                        delete current;
                        a->next = NULL;
                        tail = a;
                        break;
                    }

                }
            }

        }
        size -= 1;

    }

    void Addrand(T data) {
    int randIndex = std::rand() % (size + 1); // Losuj indeks od 0 do rozmiaru listy
    Node *newNode = new Node();
    newNode->value = data;

    if (randIndex == 0) {
        // Dodaj na początek listy
        newNode->next = head;
        head = newNode;
        if (tail == NULL) {
            // Lista była pusta, więc ustawiamy również ogon
            tail = newNode;
        }
    } else {
        // Szukaj miejsca w liście, gdzie należy dodać nowy element
        Node *current = head;
        for (int i = 1; i < randIndex && current != NULL; i++) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == NULL) {
                // Nowy element został dodany na koniec listy, więc aktualizujemy ogon
                tail = newNode;
            }
        } else {
            // Lista jest pusta lub indeks wykracza poza jej zakres, więc dodaj na koniec
            if (head == NULL) {
                head = newNode;
            }
            if (tail != NULL) {
                tail->next = newNode;
            }
            tail = newNode;
        }
    }
    size++;
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
            std::cout << "\n Head: " << head->value << "\n Tail: " << tail->value;
        }
        std::cout << "\n Ilosc elementow: " << size << "\n\n";

    };

    ~SLL2() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;

        }
        size = 0;
    }

    void Dltfront() {
    if (head != NULL) {
        Node *a = head;
        head = head->next;
        delete a;
        size -= 1;

        // Aktualizacja tail, jeśli usuwany był ostatni element
        if (head == NULL) {
            tail = NULL;
        }
    }
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
            if(znalezienia == 0){ std::cout << "Nie znaleziono podanej liczby na liscie. \n\n";}
        }


    }

    int getSize()
    {
        return size;
    }
};






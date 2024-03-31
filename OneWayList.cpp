#include <iostream>
#include <cstdlib>
#include <time.h>

template <typename T> class SLL1 {

private:
    int size = 0;
    struct Node {
        T value;
        struct Node *next;
    };
    struct Node *head = NULL;
public:
    int Value;
    SLL1 *Next;

    SLL1()
    {
        srand(time(0));
    }

    void Pushfront(T data) {

        Node *newnode = new Node();
        newnode->next = head;
        newnode->value = data;
        head = newnode;
        size += 1;
    };

     void Pushback(T data) {
        Node* newnode = new Node();
        newnode->value = data;
        newnode->next = nullptr;
        if (head == nullptr) {
            head = newnode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newnode;
        }
        size++;
    }


    void Dltback() {
    if (head == nullptr) {
        return; // Lista jest pusta, nie ma nic do usunięcia
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    if (prev != nullptr) {
        delete current;
        prev->next = nullptr; // Ustawienie wskaźnika next poprzedniego elementu na nullptr
    } else {
        // Usuwamy pierwszy element z listy
        delete head;
        head = nullptr;
    }

    size--;
}

    

   void Dltrand() {
    if (head != nullptr) {
        int randIndex = std::rand() % size; // Losowy indeks od 0 do size - 1
        Node *current = head;
        Node *prev = nullptr;

        if (randIndex > 0) {
            for (int i = 0; i < randIndex; i++) {
                prev = current;
                current = current->next;
            }
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        } else {
            head = head->next;
            delete current;
        }
        size--;
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


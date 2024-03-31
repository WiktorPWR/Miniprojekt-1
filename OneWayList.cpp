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

    void Pushfront(T data) {

        //int rand = std::rand() % 100 + 1;
        Node *newnode = new Node();
        newnode->next = head;
        newnode->value = data;
        head = newnode;
        size += 1;
    };

    void Pushback(T data) {
    if (head == NULL) {
        head = new Node();
        head->value = data;
        head->next = NULL;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node();
        current->next->value = data;
        current->next->next = NULL;
    }
    size += 1;
};


    void Dltback() {
    if (head != NULL) {
        Node *current = head;
        Node *prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        delete current;
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            // Usuwamy pierwszy element z listy
            head = NULL;
        }
        size -= 1;
    }
    }

    

    void Dltrand(){
        if (head == NULL) {
            std::cout << "lista jest pusta";
        } else {
            srand(time(0));
            int rand = std::rand() % size + 1;
            std::cout << "usuwanie " << rand << " elementu. \n";
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
            }else{
                a = current;
                current= current->next;
                delete a;
                head = current;
            }

        }
        size -= 1;

    }

    void Addrand(T data){
        if (head == NULL) {
            std::cout << "lista jest pusta";
        } else {
            srand(time(0));
            int rand = std::rand() % size + 1;
            std::cout << "dodawanie elementu na " << rand << " miejscu. \n";
            Node *current = head;
            Node *a;
            Node *New = new Node();
            if(rand > 1){
                for(int i = 1; i < rand; i++){
                    a = current;
                    current = current->next;
                }
                New->next = current;
                a->next = New;
            }else{
                New->next = current;
                head = New;
            }
            New->value = data;

        }
        size += 1;

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


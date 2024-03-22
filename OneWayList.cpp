#include <iostream>
#include <cstdlib>
#include <time.h>

template <typename T> class SLL {

private:
    int size = 0;
    struct Node {
        T value;
        struct Node *next;
    };
    struct Node *head = NULL;
public:
    int Value;
    SLL *Next;

    void Pushfront() {

        int rand = std::rand() % 100 + 1;
        Node *newnode = new Node();
        newnode->next = head;
        newnode->value = rand;
        head = newnode;
        size += 1;
    };

    void Pushback(T data) {

        if (head == NULL) {
            std::cout << "lista jest pusta";
        } else {
            Node *current = head;
            Node *newnode = new Node();
            while (current != NULL) {
                current = current->next;
                if(current->next == NULL){
                   current->next = newnode;
                   newnode->next = NULL;
                   newnode->value = data;
                   break;
                }

            }
        }
        size += 1;
    };

    void Dltback(){
        if (head == NULL) {
            std::cout << "lista jest pusta";
        } else {
            Node *current = head;
            Node *a = current;
            while (current != NULL) {
                a = current;
                current = current->next;
                if(current->next == NULL){
                    delete current;
                    a->next = NULL;
                    break;
                }

            }
        }
        size -= 1;

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

    void Addrand(){
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
            New->value = 69;

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

    ~SLL() {
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

};




int main() {
    SLL <int> lista;
    srand(time(0));

    std::cout << "Generowanie 10 liczb od przodu. \n";
    for(int i = 0; i < 10; i++){
        lista.Pushfront();}
    lista.Printlist();

    lista.Find();

    lista.Dltrand();
    lista.Printlist();

    lista.Addrand();
    lista.Printlist();

    std::cout << "Usuwanie liczby z przodu. \n";
    lista.Dltfront();
    lista.Printlist();

    std::cout << "Usuwanie liczby z konca. \n";
    lista.Dltback();
    lista.Printlist();

    std::cout << "Dodawanie liczby od konca. \n";
    lista.Pushback(69);
    lista.Printlist();

    std::cout << "Zwalnianie pamieci. \n";
    lista.~SLL();
    lista.Printlist();



    return 0;

}

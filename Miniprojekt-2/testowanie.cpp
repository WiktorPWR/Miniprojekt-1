#include "..\Miniprojekt-2\kopiec.cpp"
int main() {
    Priority_queue<int> pq; // Utworzenie obiektu kolejki priorytetowej dla typu int

    // Dodanie kilku elementów do kolejki
    pq.insert(10, 1);
    pq.insert(20, 2);
    pq.insert(30, 3);
    pq.insert(40, 4);
    pq.insert(50, 5);

    // Usunięcie największego elementu i ponowne wyświetlenie kolejki
    pq.extract_max();
    
    pq.modify_key(20,10);
    pq.print_array();

    return 0;
}
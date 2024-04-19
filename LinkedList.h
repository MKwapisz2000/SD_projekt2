#pragma once

// Klasa reprezentująca pojedynczy element listy
class Nod {
public:
    int data; // Dane przechowywane w elemencie
    int priority; // Priorytet elementu
    Nod* next; // Wskaźnik na następny element

    Nod(int d, int prio) : data(d), priority(prio), next(nullptr) {}
};

// Klasa reprezentująca listę priorytetową
class LinkedList {
private:
    Nod* head; // Wskaźnik na pierwszy element listy

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    // Metoda dodająca element o priorytecie p
    void insert(int e, int p);

    // Metoda usuwająca element o największym priorytecie
    void extract_max();

    // Metoda zwracająca (podejrzenie) element o największym priorytecie
    int find_max() const;

    // Metoda modyfikująca priorytet elementu e na p
    void modify_key(int e, int p);

    // Metoda zwiększająca priorytet elementu o indeksie index na p
    void increase_key(int index, int p);

    // Metoda zmniejszająca priorytet elementu o indeksie index na p
    void decrease_key(int index, int p);

    // Metoda zwracająca rozmiar listy
    int return_size() const;

    // Metoda wyświetlająca zawartość listy
    void show() const;

    // Metoda czyszcząca listę
    void clear();
};



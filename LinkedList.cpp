#include "LinkedList.h"
#include <iostream>

using namespace std;

// Konstruktor dla elementu listy (Nod)
Nod::Nod(int d, int prio) : data(d), priority(prio), next(nullptr) {}

// Implementacja konstruktora LinkedList
LinkedList::LinkedList() : head(nullptr) {}

// Implementacja destruktora
LinkedList::~LinkedList() 
{
    clear(); // Wywołanie metody clear() aby zwolnić pamięć po obiekcie LinkedList
}

// Metoda dodająca element o priorytecie p
void LinkedList::insert(int e, int p)
{
    Nod* newNode = new Nod(e, p); // Utworzenie nowego węzła
    // Sprawdzenie czy lista jest pusta lub czy nowy element ma najwyższy priorytet
    if (!head || p > head->priority) 
    {
        newNode->next = head; // Nowy element staje się głową listy
        head = newNode;
    } 
    else 
    {
        Nod* curr = head;
        // Szukanie miejsca dla nowego elementu w liście
        while (curr->next && curr->next->priority >= p) 
        {
            curr = curr->next;
        }
        newNode->next = curr->next; // Wstawienie nowego elementu
        curr->next = newNode;
    }
}

// Implementacja metody extract_max
void LinkedList::extract_max() 
{
    if (!head) 
    {
        cout << "Lista jest pusta!" << endl; // Komunikat o błędzie, jeśli lista jest pusta
        return;
    }
    Nod* temp = head;
    head = head->next; // Przesunięcie głowy listy na kolejny element
    delete temp; // Zwolnienie pamięci zajmowanej przez usuwany element
}

// Implementacja metody find_max
// Jeśli elementy mają ten sam priorytet, stosowana jest zasada FIFO (First In, First Out)
void LinkedList::find_max() const 
{
    if (!head) 
    {
        cout << "Lista jest pusta!" << endl; // Komunikat o błędzie, jeśli lista jest pusta
        return;
    }

    // Wyświetlenie informacji o elemencie o najwyższym priorytecie
    cout << "Maksymalny priorytet znajduje sie na poczatku listy i wynosi: ";
    cout << head->priority << ", a wartosc elementu to: " << head->data << endl;

    int j = 0;
    Nod* curr = head->next;
    // Sprawdzenie czy istnieją inne elementy o tym samym priorytecie
    while (curr && curr->priority == head->priority) 
    {
        // Wyświetlenie informacji o innych elementach o tym samym priorytecie
        cout << "Inny element o tym samym priorytecie to: ";
        cout << curr->priority << ", a wartosc elementu to: " << curr->data << endl;
        curr = curr->next;
        j++;
    }

    // Wyświetlenie komunikatu, jeśli nie ma innych elementów o tym samym priorytecie
    if (j == 0) 
    {
        cout << "Brak innych elementow o tym samym priorytecie" << endl;
    }
}

// Implementacja metody modify_key
void LinkedList::modify_key(int e, int p) 
{
    Nod* prev = nullptr;
    Nod* curr = head;
    int index = 0; // Zmienna przechowująca aktualny indeks

    // Szukanie elementu o danej wartości
    while (curr && curr->data != e) 
    {
        prev = curr;
        curr = curr->next;
        index++;
    }

    // Jeśli nie znaleziono elementu, wyświetl komunikat o błędzie
    if (!curr) 
    {
        cout << "Element o wartosci " << e << " nie istnieje na liscie." << endl;
        return;
    }

    // Jeśli element ma być przesunięty do przodu, usuń go z obecnej pozycji
    if (p > curr->priority) 
    {
        if (prev) 
        {
            prev->next = curr->next; // Usunięcie elementu z listy
        } 
        else 
        {
            head = curr->next; // Aktualizacja głowy listy, jeśli usuwany element był na początku
        }

        // Przeszukiwanie listy w celu znalezienia miejsca do wstawienia elementu
        Nod* temp = head;
        Nod* prev_temp = nullptr;
        while (temp && temp->priority >= p) 
        {
            prev_temp = temp;
            temp = temp->next;
        }

        // Wstawienie elementu na odpowiednie miejsce w liście
        if (prev_temp) 
        {
            curr->next = prev_temp->next;
            prev_temp->next = curr;
        }
        else 
        {
            curr->next = head;
            head = curr;
        }
    }
    // Jeśli element ma być przesunięty do tyłu, usuń go z obecnej pozycji
    else if (p < curr->priority) 
    {
        if (prev) {
            prev->next = curr->next; // Usunięcie elementu z listy
        } 
        else 
        {
            head = curr->next; // Aktualizacja głowy listy, jeśli usuwany element był na początku
        }

        // Przeszukiwanie listy w celu znalezienia miejsca do wstawienia elementu
        Nod* temp = head;
        Nod* prev_temp = nullptr;
        while (temp && temp->priority < p) 
        {
            prev_temp = temp;
            temp = temp->next;
        }

        // Wstawienie elementu na odpowiednie miejsce w liście
        if (prev_temp) 
        {
            curr->next = prev_temp->next;
            prev_temp->next = curr;
        } 
        else 
        {
            curr->next = head;
            head = curr;
        }
    }

    // Aktualizacja priorytetu elementu
    curr->priority = p;

    // Wyświetlenie informacji o indeksie zmienionego priorytetu
    cout << "Zmieniono priorytet elementu o wartosci " << e << " pod indeksem " << index << endl;
}

// Implementacja metody increase_key
void LinkedList::increase_key(int index, int p) 
{
    if (index < 0 || index >= return_size()) 
    {
        cout << "Indeks poza zakresem!" << endl; // Komunikat o błędzie
        return;
    }

    Nod* curr = head;
    // Przesunięcie do elementu o danym indeksie
    for (int i = 0; i < index; i++) 
    {
        curr = curr->next;
    }

    // Jeśli nowy priorytet jest mniejszy lub równy obecnemu, zwróć błąd
    if (p <= curr->priority) 
    {
        cout << "Nowy priorytet musi byc wiekszy niz obecny!" << endl;
        return;
    }

    // Zaktualizuj priorytet elementu
    curr->priority = p;

    // Przesuń element w górę kolejki, jeśli to konieczne
    while (curr->next && curr->next->priority < p) 
    {
        Nod* temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        curr = temp;
    }
}

// Implementacja metody decrease_key
void LinkedList::decrease_key(int index, int p) 
{
    if (index < 0 || index >= return_size()) 
    {
        cout << "Indeks poza zakresem!" << endl; // Komunikat o błędzie
        return;
    }

    Nod* curr = head;
    // Przesunięcie do elementu o danym indeksie
    for (int i = 0; i < index; i++) 
    {
        curr = curr->next;
    }

    // Jeśli nowy priorytet jest większy lub równy obecnemu, zwróć błąd
    if (p >= curr->priority) 
    {
        cout << "Nowy priorytet musi byc mniejszy niz obecny!" << endl;
        return;
    }

    // Zaktualizuj priorytet elementu
    curr->priority = p;

    // Przesuń element w dół kolejki, jeśli to konieczne
    while (curr->next && curr->next->priority > p) 
    {
        Nod* temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        curr = temp;
    }
}

// Implementacja metody return_size
int LinkedList::return_size() const 
{
    int count = 0;
    Nod* curr = head;
    // Przechodzenie po liście i zliczanie elementów
    while (curr) 
    {
        count++;
        curr = curr->next;
    }
    return count;
}

// Implementacja metody show
void LinkedList::show() const 
{
    Nod* curr = head;
    cout << "POCZATEK" << endl;
    int i = 0;
    // Przechodzenie po liście i wyświetlanie wartości oraz priorytetów elementów
    while (curr) {
        cout << i + 1 << ".) " << curr->priority << endl;
        curr = curr->next;
        i++;
    }
    cout << "KONIEC" << endl;
}

// Implementacja metody clear
void LinkedList::clear() 
{
    while (head) {
        Nod* temp = head;
        head = head->next;
        delete temp; // Zwolnienie pamięci zajmowanej przez usuwany element
    }
}


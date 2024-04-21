#include <iostream> 
#include "LinkedList.h" 

using namespace std;

// Destruktor
LinkedList::~LinkedList() {
    clear(); // Wywołanie metody clear() aby zwolnić pamięć
}

// Metoda dodająca element o priorytecie p
// Jeśli elementy mają ten sam priorytet, stosowana jest zasada FIFO (First In, First Out)
void LinkedList::insert(int e, int p) {
    Nod* newNode = new Nod(e, p); // Utworzenie nowego węzła
    // Sprawdzenie czy lista jest pusta lub czy nowy element ma najwyższy priorytet
    if (!head || p > head->priority) {
        newNode->next = head; // Nowy element staje się głową listy
        head = newNode;
    } else {
        Nod* curr = head;
        // Szukanie miejsca dla nowego elementu w liście
        while (curr->next && curr->next->priority >= p) {
            curr = curr->next;
        }
        newNode->next = curr->next; // Wstawienie nowego elementu
        curr->next = newNode;
    }
}

// Metoda usuwająca element o najwyższym priorytecie
void LinkedList::extract_max() {
    if (!head) {
        cout << "Lista jest pusta!" << endl; // Komunikat o błędzie
        return;
    }
    Nod* temp = head;
    head = head->next; // Przesunięcie głowy listy na kolejny element
    delete temp; // Zwolnienie pamięci zajmowanej przez usuwany element
}

// Metoda zwracająca (podejrzenie) element o najwyższym priorytecie
int LinkedList::find_max() const {
    if (!head) {
        cout << "Lista jest pusta!" << endl; // Komunikat o błędzie
        return -1; // Wartość specjalna w przypadku pustej listy
    }
    return head->data; // Zwrócenie wartości pierwszego elementu
}

// Metoda modyfikująca priorytet elementu o danej wartości
void LinkedList::modify_key(int e, int p) {
    Nod* prev = nullptr;
    Nod* curr = head;

    // Szukanie elementu o danej wartości
    while (curr && curr->data != e) {
        prev = curr;
        curr = curr->next;
    }

    // Jeśli nie znaleziono elementu, wyświetl komunikat o błędzie
    if (!curr) {
        cout << "Element o wartości " << e << " nie istnieje na liście." << endl;
        return;
    }

    // Jeśli element ma być przesunięty do przodu, usuń go z obecnej pozycji
    if (p > curr->priority) {
        if (prev) {
            prev->next = curr->next; // Usunięcie elementu z listy
        } else {
            head = curr->next; // Aktualizacja głowy listy, jeśli usuwany element był na początku
        }

        // Przeszukiwanie listy w celu znalezienia miejsca do wstawienia elementu
        Nod* temp = head;
        Nod* prev_temp = nullptr;
        while (temp && temp->priority >= p) {
            prev_temp = temp;
            temp = temp->next;
        }

        // Wstawienie elementu na odpowiednie miejsce w liście
        if (prev_temp) {
            curr->next = prev_temp->next;
            prev_temp->next = curr;
        } else {
            curr->next = head;
            head = curr;
        }
    }
    // Jeśli element ma być przesunięty do tyłu, usuń go z obecnej pozycji
    else if (p < curr->priority) {
        if (prev) {
            prev->next = curr->next; // Usunięcie elementu z listy
        } else {
            head = curr->next; // Aktualizacja głowy listy, jeśli usuwany element był na początku
        }

        // Przeszukiwanie listy w celu znalezienia miejsca do wstawienia elementu
        Nod* temp = head;
        Nod* prev_temp = nullptr;
        while (temp && temp->priority < p) {
            prev_temp = temp;
            temp = temp->next;
        }

        // Wstawienie elementu na odpowiednie miejsce w liście
        if (prev_temp) {
            curr->next = prev_temp->next;
            prev_temp->next = curr;
        } else {
            curr->next = head;
            head = curr;
        }
    }

    // Aktualizacja priorytetu elementu
    curr->priority = p;
}


/// Metoda zwiększająca priorytet elementu o danym indeksie
void LinkedList::increase_key(int index, int p) {
    if (index < 0 || index >= return_size()) {
        cout << "Indeks poza zakresem!" << endl; // Komunikat o błędzie
        return;
    }

    Nod* curr = head;
    // Przesunięcie do elementu o danym indeksie
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    // Jeśli nowy priorytet jest mniejszy lub równy obecnemu, zwróć błąd
    if (p <= curr->priority) {
        cout << "Nowy priorytet musi być większy niż obecny!" << endl;
        return;
    }

    // Zaktualizuj priorytet elementu
    curr->priority = p;

    // Przesuń element w górę kolejki, jeśli to konieczne
    while (curr->next && curr->next->priority < p) {
        Nod* temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        curr = temp;
    }
}

// Metoda zmniejszająca priorytet elementu o danym indeksie
void LinkedList::decrease_key(int index, int p) {
    if (index < 0 || index >= return_size()) {
        cout << "Indeks poza zakresem!" << endl; // Komunikat o błędzie
        return;
    }

    Nod* curr = head;
    // Przesunięcie do elementu o danym indeksie
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    // Jeśli nowy priorytet jest większy lub równy obecnemu, zwróć błąd
    if (p >= curr->priority) {
        cout << "Nowy priorytet musi być mniejszy niż obecny!" << endl;
        return;
    }

    // Zaktualizuj priorytet elementu
    curr->priority = p;

    // Przesuń element w dół kolejki, jeśli to konieczne
    while (curr->next && curr->next->priority > p) {
        Nod* temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        curr = temp;
    }
}


// Metoda zwracająca rozmiar listy
int LinkedList::return_size() const {
    int count = 0;
    Nod* curr = head;
    // Przechodzenie po liście i zliczanie elementów
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// Metoda wyświetlająca zawartość listy
void LinkedList::show() const {
    Nod* curr = head;
    cout << "POCZATEK" << endl;
    int i = 0;
    // Przechodzenie po liście i wyświetlanie wartości oraz priorytetów elementów
    while (curr) {
        cout << i +1<< ".) " << curr->priority << endl;
        curr = curr->next;
        i++;
    }
    cout << "KONIEC" << endl;
}

// Metoda czyszcząca listę
void LinkedList::clear() {
    while (head) {
        Nod* temp = head;
        head = head->next;
        delete temp; // Zwolnienie pamięci zajmowanej przez usuwany element
    }
}

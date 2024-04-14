#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    Heap h1;
    h1.insert(9, 6);
    h1.insert(2, 2);
    h1.insert(10, 4);
    h1.insert(8, 9);
    h1.insert(3, 1);
    h1.insert(1, 9);
    h1.insert(2, 0);
    h1.insert(2, 20);
    cout << "rozmiar: ";
    cout<<h1.return_size();
    cout << endl;

    h1.show();
    cout << endl;
    h1.extract_max();
    h1.show();
    h1.find_max();
    return 0;
}


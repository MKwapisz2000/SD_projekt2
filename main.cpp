#include <iostream>
#include <fstream>
#include <chrono>
#include "Heap.h"

using namespace std;

int main()
{

	//..............................OBIEKTY POSZCZEGOLNYCH STRUKTUR...........................................


	Heap h1;
	
	//.......................................................................................................
   


    //..............................WCZYTANIE DANYCH Z PLIKU...............................................

    // Licznik całkowitego czasu wykonania
    auto total_time = 0ns;

    // Liczba pomiarów
    int measurements = 10;

    // Wczytywanie danych z pliku i pomiar czasu 10 razy
    for (int i = 0; i < 10; ++i)
    {
        // Wczytywanie danych z pliku
        ifstream plik;
        string nazwa = "dane_2k_pop1.txt";

        plik.open(nazwa, ios::out);
        if (!plik.good())
        {
            cout << "Blad przy otwarciu pliku." << endl;
            return -1;
        }

        int liczba;
        int priorytet;
        while (plik >> liczba >> priorytet)
        {
            h1.insert(liczba, priorytet);
        }
        plik.close();

    //.....................................................................................................




    //..................................POMIAR CZASU......................................................
        
    // Pomiar czasu dla pojedynczego wywołania funkcji 
        auto begin = chrono::high_resolution_clock::now();
        h1.insert(8, 10);
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

        // Dodanie czasu do całkowitego czasu wykonania
        total_time += elapsed;

        // Czyszczenie struktury
        h1.clear();

    }

    // Obliczenie średniego czasu wykonania
    auto average_time = total_time / measurements;
    
    // Wyświetlenie wyniku średniego czasu wykonania
    cout << "Sredni czas wykonania: " << average_time.count() << " nanosekund" << endl;
   
    //.....................................................................................................

    return 0;
}


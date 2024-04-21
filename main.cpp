#include <iostream>
#include <fstream>
#include <chrono>
#include "Heap.h"
#include "LinkedList.h"

using namespace std;

int main()
{

	//..............................OBIEKTY POSZCZEGOLNYCH STRUKTUR...........................................

	Heap h1;
	LinkedList l1;

	//.......................................................................................................
   
    

    //..............................WCZYTANIE DANYCH Z PLIKU...............................................

    // Licznik całkowitego czasu wykonania
    //auto total_time = 0ns;

    // Liczba pomiarów
    //int measurements = 100;

    // Wczytywanie danych z pliku i pomiar czasu 100 razy
    //for (int i = 0; i < 100; ++i)
    //{
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
			l1.insert(liczba, priorytet);
        }
        plik.close();
        

    //.....................................................................................................




    //..................................POMIAR CZASU......................................................
    /*
    // Pomiar czasu dla pojedynczego wywołania funkcji 
        auto begin = chrono::high_resolution_clock::now();
        h1.modify_key(3850,121);
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
   */
    //.....................................................................................................
   




    //..................................MENU...............................................................

		int zmienna1;
		char zmienna2;
		int e;
		int p;
		
		cout << "KOLEJKA PRIORYTETOWA OPARTA NA STRUKTURACH DANYCH:" << endl
			<< "[1] Kopiec" << endl
			<< "[2] Lista Wiazana" << endl;
		cout << "Przechodze do struktury numer: ";
		cin >> zmienna1;
		system("cls");
		switch (zmienna1)
		{
		case 1:
		{
			cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl
				<< "[a] insert(e, p)" << endl
				<< "[b] extract_max()" << endl
				<< "[c] finf_max()" << endl
				<< "[d] modify_key(e, p)" << endl
				<< "[e] return_size()" << endl;

			cout << "Przechodze do funkcji: ";
			cin >> zmienna2;

			switch (zmienna2)
			{
			case 'a':
			{
				cout << "Podaj wartosc elementu ktory chcesz dodac oraz jego priorytet: ";
				cin >> e >> p;
				h1.insert(e, p);
				cout << endl;
				system("cls");
				cout << "Obecny rozmiar: " << h1.return_size() << endl;
				h1.show();

				break;
			}

			case 'b':
			{
				h1.extract_max();
				cout << endl;
				system("cls");
				cout << "Obecny rozmiar: " << h1.return_size() << endl;
				h1.show();

				break;
			}

			case 'c':
			{
				h1.find_max();

				break;
			}

			case 'd':
			{
				cout << "Podaj wartosc elementu ktorego priorytet chcesz zmienic oraz jego nowy priorytet: ";
				cin >> e >> p;
				h1.modify_key(e, p);
				cout << endl;

				cout << "Obecny rozmiar: " << h1.return_size() << endl;
				h1.show();

				break;
			}

			case 'e':
			{
				cout << "Obecny rozmiar: " << h1.return_size() << endl;

				break;
			}


			default:
				break;
			}


		}

		case 2:
		{
			cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl
				<< "[a] insert(e, p)" << endl
				<< "[b] extract_max()" << endl
				<< "[c] finf_max()" << endl
				<< "[d] modify_key(e, p)" << endl
				<< "[e] return_size()" << endl;

			cout << "Przechodze do funkcji: ";
			cin >> zmienna2;

			switch (zmienna2)
			{
			case 'a':
			{
				cout << "Podaj wartosc elementu ktory chcesz dodac oraz jego priorytet: ";
				cin >> e >> p;
				//h1.insert(e, p);
				cout << endl;
				system("cls");
				//cout << "Obecny rozmiar: " << h1.return_size() << endl;
				//h1.show();

				break;
			}

			case 'b':
			{
				//h1.extract_max();
				cout << endl;
				system("cls");
				//cout << "Obecny rozmiar: " << h1.return_size() << endl;
				//h1.show();

				break;
			}

			case 'c':
			{
				//h1.find_max();

				break;
			}

			case 'd':
			{
				cout << "Podaj wartosc elementu ktorego priorytet chcesz zmienic oraz jego nowy priorytet: ";
				cin >> e >> p;
				//h1.modify_key(e, p);
				cout << endl;

				//cout << "Obecny rozmiar: " << h1.return_size() << endl;
				//h1.show();

				break;
			}

			case 'e':
			{
				//cout << "Obecny rozmiar: " << h1.return_size() << endl;

				break;
			}


			default:
				break;
			}
		}
		}
    //.....................................................................................................







    return 0;
}


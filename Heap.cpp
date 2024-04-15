#include <iostream>
#include "Heap.h"

using namespace std;

Node::Node(): element(0), priority(0) 
{}

Node::Node(int e, int p): element(e), priority(p)
{}

Heap::Heap()
{
	tab = nullptr;
	size = 0;
	capacity = 0;
}

Heap::~Heap()
{
	/*
	for (int i = 0; i < size; ++i)
	{
		delete &tab[i];
	}*/

	delete[] tab;
}

void Heap::increase_capacity()
{
	int new_capacity;
	if (capacity == 0)
	{
		new_capacity = 1;
	}
	else
	{
		new_capacity = 2 * capacity;
	}

	Node* new_tab = new Node[new_capacity];
	for (int i = 0; i < size; i++)
	{
		new_tab[i] = tab[i];
	}
	delete[] tab;
	tab = new_tab;
	capacity = new_capacity;
}

void Heap::insert(int e, int p)
{
	//Zwiekszenie pojemnosci tablicy
	if (size >= capacity)
	{
		increase_capacity();
	}

	//Stworzenie nowego wêz³a (elementu klejki)
	Node* new_node = new Node(e, p);

	//Dodanie wêz³a na koniec kopca (by zachowaæ ci¹g³oœæ kopca)
	if (size == 0)
	{
		tab[0].priority = new_node->priority;
		tab[0].element = new_node->element;
	}

	else
	{
		tab[size].priority = new_node->priority;
		tab[size].element = new_node->element;

		//Indeks w tablicy elementu w³aœnie dodanego
		int i = size;

		//Indeks w tablicy rodzica w³aœnie dodanego elementu
		int j = (i - 1) / 2;

		//Zmieniamy ustawienie wêz³a dopóki jego priorytet jest wiêkszy od jego rodzica i nie jest korzeniem
		while ((tab[i].priority > tab[j].priority) &&  (i!=0))
		{
			Node temp = tab[j];
			tab[j] = tab[i];
			tab[i] = temp;
			i = j;
			j = (i - 1) / 2;
		}
	}


	//Zwiêkszenie rozmiaru
	size++;
}

void Heap::extract_max()
{
	//Sprawdzamy czy kopiec nie jest juz pusty
	if (size == 0)
	{
		cout << "Kopiec jest juz pusty" << endl;
		return;
	}

	Node p = tab[0];

	tab[0] = tab[size - 1];
	size--;

	//indeks rodzica (zaczynamy od korzenia)
	int i = 0;

	//indeks lewego dziecka
	int jL = 2 * i + 1;

	//indeks prawego dziecka
	int jP = 2 * i + 2;

	while (i < size)
	{
		//Sprawdzamy czy priorytet rodzica jes mniejszy ni¿ priorytet dziecka lewego
		if (tab[i].priority < tab[jL].priority)
		{
			//Zamieniamy rodzica z dzieckiem lewym
			Node temp = tab[i];
			tab[i] = tab[jL];
			tab[jL] = temp;

			i = jL;
			jL = 2 * i + 1;
			jP = 2 * i + 2;
		}
		else
		{
			//Sprawdzamy czy priorytet rodzica jes mniejszy ni¿ priorytet dziecka prawego
			if (tab[i].priority < tab[jP].priority)
			{
				//Zamieniamy rodzica z dzieckiem prawym
				Node temp = tab[i];
				tab[i] = tab[jP];
				tab[jP] = temp;

				i = jP;
				jL = 2 * i + 1;
				jP = 2 * i + 2;
			}
		}

		//Sprawdzamy czy wezel jest juz na wlasciwym miejscu (czy jego dzieci maja prioirytet mnijeszy/równy jemu)
		if ((tab[i].priority >= tab[jL].priority) && (tab[i].priority >= tab[jP].priority))
		{
			break;
		}
	}

	cout << "Elementem usunietym byl element o priorytecie " << p.priority << " i wartosci " << p.element << endl;
	cout << "Obecnie elementem o najwiekszym priorytecie jest " << tab[0].priority << " i wartosci " << tab[0].element << endl;
}

void Heap::find_max() const
{
	cout << "Maksymlany priorytet znajduje sie w korzeniu i wynosi: ";

	//Najwiekszy priorytet znajduje sie w korzeniu
	cout << tab[0].priority << ", a wrtosc elementu to: " << tab[0].element << endl;
	{
		cout << "Inne elementy o tym priorytecie to: " << endl;
		int j = 0;

		//Iteruejmy po elementach szukajac takiego, ktory ma element rowny korzeniowi
		for (int i = 1; i < size; i++)
		{
			if (tab[i].priority == tab[0].priority)
			{
				cout << tab[i].priority << ", a wartosc elementu to: " << tab[i].element << endl;
				j++;
			}
		}

		if (j == 0)
		{
			cout << "Brak innych elementow o tym priorytecie" << endl;
		}
	}
}

void Heap::modify_key(int e, int p)
{
	//Sprawdzenie czy zadany priorytet jest wiekszy czy mniejszy od obecnego
	for (int i = 0; i < size; i++)
	{
		if (tab[i].element == e)
		{
			if (p > tab[i].priority)
			{
				increase_key(e, p, i);
			}

			else
			{
				decrease_key(e, p, i);
			}
		}
	}
}

void Heap::increase_key(int e, int p, int i)
{
	//Zmiana priorytetu
	tab[i].priority = p;

	//Indeks dziecka
	int child = i;

	//Indeks rodzica
	int parent = (child - 1) / 2;

	//Wykonujemy dopóki priorytet dziecka jest wiêkszy ni¿ rodzica i jednoczeœnie dziecko nie jest korzeniem
	while ((tab[child].priority > tab[parent].priority) && (child != 0))
	{
		//Zamiana miejscami rodzica z dzieckiem
		Node temp = tab[parent];
		tab[parent] = tab[child];
		tab[child] = temp;

		child = parent;
		parent = (child - 1) / 2;
	}	
}

void Heap::decrease_key(int e, int p, int i)
{
	//Zmiana priorytetu
	tab[i].priority = p;

	//Indeks rodzica
	int parent = i;

	//Indeks dziecka lewego
	int childL = parent * 2 +1;

	//Indeks dziecka prawego
	int childP = parent * 2 + 2;

	while (parent < size)
	{
		//Sprawdzamy czy priorytet rodzica jes mniejszy ni¿ priorytet dziecka lewego
		if (tab[parent].priority < tab[childL].priority)
		{
			//Zamieniamy rodzica z dzieckiem lewym
			Node temp = tab[parent];
			tab[parent] = tab[childL];
			tab[childL] = temp;

			parent = childL;
			childL = parent * 2 + 1;
			childP = parent * 2 + 2;
		}

		else
		{
			//Sprawdzamy czy priorytet rodzica jes mniejszy ni¿ priorytet dziecka prawego
			if (tab[parent].priority < tab[childP].priority)
			{
				//Zamieniamy rodzica z dzieckiem prawym
				Node temp = tab[parent];
				tab[parent] = tab[childP];
				tab[childP] = temp;

				parent = childP;
				childL = parent * 2 + 1;
				childP = parent * 2 + 2;
			}
		}

		//Sprawdzamy czy wezel jest juz na wlasciwym miejscu (czy jego dzieci maja prioirytet mnijeszy/równy jemu)
		if ((tab[parent].priority >= tab[childL].priority) && (tab[parent].priority >= tab[childP].priority))
		{
			break;
		}
	}
}



int Heap::return_size() 
{
	return size;
}

void Heap::show() const
{
	cout << "POCZATEK" <<endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ".) " << tab[i].priority << endl;
	}
	cout << "KONIEC" << endl;
}


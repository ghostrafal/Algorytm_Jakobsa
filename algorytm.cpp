// Algorytm_Jakobsa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>


using namespace std;

void Sortowanie(int tab[], int size, int **tab2)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(tab[j], tab[j + 1]);
				swap(tab2[j - 1][0], tab2[j][0]);
				swap(tab2[j - 1][1], tab2[j][1]);
			}
		}
	}
}

int main()
{
	ifstream plik;
	string zmienna;
	int n = 0;
	int i;


	cout << "Podaj nazwe pliku wejsciowego:  ";
	cin >> zmienna;
	cout << endl;

	/* otwieramy plik */
	plik.open(zmienna);

	/* sprawdzamy czy plik sie otworzyl */
	if (!plik.good() == true)
	{
		cout << "Nie mozna otworzyc pliku\n";
		return -1;
	}

	/* pobieramy liczbe zadan */
	plik >> n;

	/* unikamy bledu dla n<=0 */
	if (n <= 0)
	{
		cout << "Bledny plik z danymi\n";
		return -1;
	}

	/* tworzymy dynamiczna tablice na dane */
	int** tablica = new int*[n];
	for (i = 0; i < n; ++i)
	{
		tablica[i] = new int[1];
	}

	int* C = new int[n + 1];
	int* pi = new int[n + 1];

	C[0] = 0;
	pi[0] = 0;


	/* wczytuje dane  */
	for (i = 0; i<n; ++i)
	{
		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
			plik >> tablica[i][0];
		else
		{
			cout << "Bledny wymiar pliku\n";
			return -1;
		}
		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
			plik >> tablica[i][1];
		else
		{
			cout << "Bledny wymiar pliku\n";
			return -1;
		}
	}

	for (i = 0; i<n; ++i)
	{
		pi[i + 1] = tablica[i][0];
	}

	Sortowanie(pi, n + 1, tablica);

	for (i = 1; i<n + 1; ++i)
		C[i] = max(C[i - 1], pi[i]) + tablica[i - 1][1];


	cout << C[n] << endl;

	/* zwolnienie pamieci */
	for (i = 0; i<n; ++i)
		delete[]tablica[i];
	delete[]tablica;
	tablica = NULL;

	return 0;
}

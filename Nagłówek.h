#pragma once
#ifndef _nazwa_pliku_
#define _nazwa_pliku_
#include <iostream>
#include <time.h> 

template<typename Typ,int Wymiar> 
class Dane
{
	Typ tab[Wymiar];
public:
	const Typ& operator [] (unsigned int index)const
	{
		if (index < Wymiar) return tab[index];
		exit(EXIT_FAILURE);
	}
	 Typ& operator [] (unsigned int index)
	{
		if (index < Wymiar) return tab[index];
		exit(EXIT_FAILURE);
	}
	void Inicjuj_losowo();


};

//Insertion sort
template <typename Typ, int Wymiar>
Dane<Typ, Wymiar> Sortowanie_wstawianie(Dane < Typ, Wymiar> D, unsigned long Wielkosc)
{
	
	Typ element;
	unsigned long j;
	for (unsigned long i = 1; i < Wielkosc; ++i)
	{
		element = D[i];
		j = i-1;
		while ((j>=0)&&(D[j]>element))
		{
			D[j + 1] = D[j];
			if (j) {
				j--;
			}
			else
			{
				break;
			}
		}
		D[j] = element;
		//std::cout << D << std::endl << std::endl;
	}



	return D;

}
//buble sort
template <typename Typ, int Wymiar>
Dane<Typ, Wymiar> Sortowanie_bombelkowe(Dane < Typ, Wymiar> D, unsigned long Wielkosc)
{
	unsigned long  przesunie_ciekonca = 0;
	bool zmiana = 1;
	Typ Wiekszy;
	while (zmiana)
	{
		zmiana = 0;	
		for (unsigned int i = Wielkosc - 1; i > przesunie_ciekonca; --i)
		{
			if (D[i] < D[i - 1])
			{
				zmiana = 1;
				Wiekszy = D[i - 1];
				D[i - 1] = D[i];
				D[i] = Wiekszy;
			}
		}
		++przesunie_ciekonca;
	}
	return D;
}
//Wyswietlanie
template <typename Typ, int Wymiar>
std::ostream& operator << (std::ostream &Strm, const Dane<Typ, Wymiar> &D)
{
	for (int i =0;i<Wymiar;++i)
	{
		Strm << D[i] << " ";
	}
	return Strm;
}
//Inicjacja tablicy od max do min
template<typename Typ, int Wymiar>
void Dane<Typ, Wymiar>::Inicjuj_losowo()
{
	srand(time(0));
	unsigned long a = Wymiar;
	for (Typ &i : tab)
	{
		i = a--;
	}
}
//heap sort
template<typename Typ,int Wymiar>
Dane<Typ, Wymiar> Sortowanie_kopcowanie(Dane <Typ, Wymiar> D, unsigned long Wielkosc)
{

	return D;
}


#endif

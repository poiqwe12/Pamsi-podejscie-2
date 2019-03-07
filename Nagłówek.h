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
template <typename Typ, int Wymiar>
Dane<Typ, Wymiar> Sortowanie_bombelkowe(Dane < Typ, Wymiar> &D, unsigned int Wielkosc)
{
	unsigned long  przesunie_ciekonca = 0;
	bool zmiana = 1;
	while (zmiana)
	{
		zmiana = 0;
		++przesunie_ciekonca;
		for (unsigned int i = Wielkosc - 1 ; i > przesunie_ciekonca; --i)
		{
			if (D[i] < D[i - 1])
			{
				zmiana = 1;
				Typ Wiekszy= D[i-1];
				D[i - 1] = D[i];
				D[i] = Wiekszy;
			}
		}
	}
	return D;
}



template <typename Typ, int Wymiar>
std::ostream& operator << (std::ostream &Strm, const Dane<Typ, Wymiar> &D)
{
	for (int i =0;i<Wymiar;++i)
	{
		Strm << D[i] << " ";
	}
	return Strm;
}
template<typename Typ, int Wymiar>
void Dane<Typ, Wymiar>::Inicjuj_losowo()
{
	srand(time(0));
	for (Typ &i : tab)
	{
		i = rand();
	}
}



#endif

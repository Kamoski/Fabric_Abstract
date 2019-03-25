//*******************
//
// morse
//
// Klasa abstrakcyjna udostêpniaj¹ca interfejs dla klas outputuj¹cych morse'a,
// s³u¿y równie¿ jako prze³¹cznik w fabryce abstrakcyjnej factory do zmiany typu outputu morse'a
//
// Autor: 
// Kamil Krêcichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Krêcichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
//
//*******************

#ifndef _MORSE_
#define _MORSE_
#include <string>
#include <map>

class morse
{
public:
	//Konstr -> nie trzeba copy
	morse();

	//Destr
	~morse();

	//Metody interfejsu
	virtual void convert(std::string txtToConvert) = 0;
	virtual void convert(int integerToConvert) = 0;
	virtual void convert(double doubleToConvert) = 0;
	
	//Metoda pozwalaj¹ca dzieciom t³umaczyæ morsa
	const char* translate(char znak) const;

	//oper = nie potrzebny
};

#endif // !_MORSE_
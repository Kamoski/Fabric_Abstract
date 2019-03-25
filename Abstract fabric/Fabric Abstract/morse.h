//*******************
//
// morse
//
// Klasa abstrakcyjna udost�pniaj�ca interfejs dla klas outputuj�cych morse'a,
// s�u�y r�wnie� jako prze��cznik w fabryce abstrakcyjnej factory do zmiany typu outputu morse'a
//
// Autor: 
// Kamil Kr�cichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Kr�cichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
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
	
	//Metoda pozwalaj�ca dzieciom t�umaczy� morsa
	const char* translate(char znak) const;

	//oper = nie potrzebny
};

#endif // !_MORSE_
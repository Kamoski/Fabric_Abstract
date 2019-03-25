//*******************
//
// factory
//
// Klasa fabryki abstrakcyjnej kieruj¹ca sposobem w jaki urz¹dzenie
// nadaje sygna³ morse'a, do dzia³ania niezbêdny morse.h
//
// Autor: 
// Kamil Krêcichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Krêcichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
//
//*******************

#ifndef _FACTORY_
#define _FACTORY_

#include <string>
#include "morse.h"

class factory
{

public:
	//Konstr
	factory();
	factory(factory&copy);

	//Destr
	~factory();

	//Metody okreœlaj¹ce dzia³anie morse
	void convert(std::string txtToConvert) const;
	void convert(int integerToConvert) const;
	void convert(double doubleToConvert) const;
	
	//Settery
	void setExternalInfo(std::string prodOrders );
	void setOutput(int switcher);

	//Gettery
	morse* getAcctualMachine();
	std::string getAcctualOrders();

	//Bez oper = -> default daje rade

	enum morses {
		beep = 1
		, blink = 2
		, console = 3
		, disk = 4
	};


private:
	morse *switchOutput;
	std::string orders;
};

#endif _FACTORY_

//*******************
//
// factory
//
// Klasa fabryki abstrakcyjnej kieruj�ca sposobem w jaki urz�dzenie
// nadaje sygna� morse'a, do dzia�ania niezb�dny morse.h
//
// Autor: 
// Kamil Kr�cichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Kr�cichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
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

	//Metody okre�laj�ce dzia�anie morse
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

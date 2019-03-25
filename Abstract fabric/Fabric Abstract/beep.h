//*******************
//
// beep
//
// Klasa pozwalaj�ca na wydawanie d�wi�k�w z konsoli w alfabecie morse'a
// do poprawnego dzia�ania niezb�dna morse.h
//
// Autor: 
// Kamil Kr�cichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Kr�cichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
//
//*******************

#ifndef _BEEP_
#define _BEEP_
#include "morse.h"
#include <string>

namespace beeper {
	class beep : public morse
	{
	public:
		//Konstr (bez copy, default wystarczajacy)
		beep();
		beep(std::string prodOrders);
		
		//Destr
		~beep();
		
		// Settery nie obecne -> wy��cznie poprzez rozkazy
		
		// Gettery
		int getFrequency() const ;
		int getPauseLetterTime() const ;
		int getDotBeepTime() const ;
		int getDashBeepTime() const ;
		int getCharPauseTime() const ;

		//Fun z interfejsu morse'a
		void convert(std::string txtToConvert);
		void convert(int integerToConvert);
		void convert(double doubleToConvert);

	private:
		beep& operator=(beep& obj);
		void parseOrders(std::string orders);
		int Frequency, pauseLetterTime, dotBeepTime, dashBeepTime, charPauseTime;
	};
}
#endif _BEEP_
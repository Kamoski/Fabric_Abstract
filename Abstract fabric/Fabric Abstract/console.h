//*******************
//
// console
//
// Klasa pozwalaj¹ca na wypiswanie w konsoli systemowej wiadomoœci
// w alfabecie morse'a
//
// Autor: 
// Kamil Krêcichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Krêcichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
//
//*******************


#ifndef _CONSOLE_
#define _CONSOLE_
#include "morse.h"
#include <string>

namespace consoler {
	class console : public morse
	{
	public:
		// Konstr
		console();
		console(std::string prodOrders);
		// Destr
		~console();
		
		// Settery nieobecne -> tylko poprzez rozkazy

		// Gettery
		int getPauseLetterTime() const;
		int getDotWriteTime() const;
		int getDashWriteTime() const;
		int getCharPauseTime() const;

		// Fun z interfejsu morse'a
		void convert(std::string txtToConvert);
		void convert(int integerToConvert);
		void convert(double doubleToConvert);

	private:
		void parseOrders(std::string orders);
		console& operator = (console& obj);
		int pauseLetterTime, dotWriteTime, dashWriteTime, charPauseTime;
	};
}
#endif // !_CONSOLE_
//*******************
//
// blink
//
// Klasa pozwalaj�ca na sygnalizowanie alfabetem morse'a za pomoc�
// diody od przycisku caps-lock
//
// Autor: 
// Kamil Kr�cichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Kr�cichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
//
//*******************


#ifndef _BLINK_
#define _BLINK_
#include "morse.h"
#include <string>

namespace blinker {
	class blink : public morse
	{
	public:
		//Konstr
		blink();
		blink(std::string prodOrders);
		
		//Destr
		~blink();

		//Setery nie obecne -> wy��cznie za pomoc� rozkaz�w

		//Gettery
		int getPauseLetterTime() const ;
		int getDotBlinkTime() const ;
		int getDashBlinkTime() const ;
		int getCharPauseTime() const ;
		
		//Fun z interfejsu morse'a
		void convert(std::string txtToConvert);
		void convert(int integerToConvert);
		void convert(double doubleToConvert);

	private:
		void capsLockBlink();
		blink& operator=(blink& obj);
		void parseOrders(std::string orders);
		int pauseLetterTime, dotBlinkTime, dashBlinkTime, charPauseTime;
	};
}
#endif // !_BLINK_
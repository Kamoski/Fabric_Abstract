//*******************
//
// disk
//
// Klasa pozwalaj�ca na zapis do pliku wiadomo�ci w alfabecie morse'a
// do dzia�ania niezb�dny morse.h
//
// Autor: 
// Kamil Kr�cichwost 22 grudnia
//
// Autor:						Descp.																Dnia:
// Kamil Kr�cichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		22.12.2018
//
//*******************

#ifndef _DISK_
#define _DISK_
#include "morse.h"
#include <string>
#include <fstream>

namespace filer {
	class disk : public morse
	{
	public:
		// Konstr
		disk();
		disk(std::string prodOrders);
		// Destr
		~disk();

		// Setery nieobecne -> tylko przez rozkazy

		// Gettery
		std::string getFileName() const;

		// Fun z interfejsu morse'a
		void convert(std::string txtToConvert);
		void convert(int integerToConvert);
		void convert(double doubleToConvert);

	private:
		std::ofstream file;
		disk& operator = (disk&obj);
		std::string FileName;
	};
}
#endif // !_DISK_
#define _CRT_SECURE_NO_WARNINGS

#include "beep.h"
#include <Windows.h>



beeper::beep::beep()
	:
	morse()
	, Frequency(1000)
	, pauseLetterTime(50)
	, dotBeepTime(180)
	, dashBeepTime(540)
	, charPauseTime(60)
{

}

beeper::beep::beep(std::string prodOrders)
	:
	morse()
	, Frequency(1000)
	, pauseLetterTime(50)
	, dotBeepTime(180)
	, dashBeepTime(540)
	, charPauseTime(60)
{
	parseOrders(prodOrders);
}


beeper::beep::~beep() 
{

}

int beeper::beep::getFrequency() const
{
	return Frequency;
}

int beeper::beep::getPauseLetterTime() const
{
	return pauseLetterTime;
}

int beeper::beep::getDotBeepTime() const
{
	return dotBeepTime;
}

int beeper::beep::getDashBeepTime() const
{
	return dashBeepTime;
}

int beeper::beep::getCharPauseTime() const
{
	return charPauseTime;
}

void beeper::beep::convert(std::string txtToConvert)
{
	int j;
	int temp = 0;
	while (txtToConvert[temp] != '\0')
		temp++;
	const char *tempTab;
	for (int i = 0; i < temp; i++) {
		tempTab = translate(txtToConvert[i]);
		j = 0;
		while (tempTab[j] != '\0') {
			if (tempTab[j] == '.') {
				Beep(Frequency, dotBeepTime);
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '_') {
				Beep(Frequency, dashBeepTime);
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '+') {
				Sleep(charPauseTime);
			}
			j++;
		}
		if (tempTab[j] != '+')
			Sleep(charPauseTime);
	}
}

void beeper::beep::convert(int integerToConvert)
{
	std::string tempNumber = std::to_string(integerToConvert);
	char *txtToConvert = new char[tempNumber.length() + 1];
	strcpy(txtToConvert, tempNumber.c_str());

	int j;
	int temp = 0;
	while (txtToConvert[temp] != '\0')
		temp++;
	const char *tempTab;
	for (int i = 0; i < temp; i++) {
		tempTab = translate(txtToConvert[i]);
		j = 0;
		while (tempTab[j] != '\0') {
			if (tempTab[j] == '.') {
				Beep(Frequency, dotBeepTime);
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '_') {
				Beep(Frequency, dashBeepTime);
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '+') {
				Sleep(charPauseTime);
			}
			j++;
		}
		if (tempTab[j] != '+')
			Sleep(charPauseTime);
	}
}

void beeper::beep::convert(double doubleToConvert)
{
	std::string tempNumber = std::to_string(doubleToConvert);
	char *txtToConvert = new char[tempNumber.length() + 1];
	strcpy(txtToConvert, tempNumber.c_str());

	int j;
	int temp = 0;
	while (txtToConvert[temp] != '\0')
		temp++;
	const char *tempTab;
	for (int i = 0; i < temp; i++) {
		tempTab = translate(txtToConvert[i]);
		j = 0;
		while (tempTab[j] != '\0') {
			if (tempTab[j] == '.') {
				Beep(Frequency, dotBeepTime);
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '_') {
				Beep(Frequency, dashBeepTime);
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '+') {
				Sleep(charPauseTime);
			}
			j++;
		}
		if (tempTab[j] != '+')
			Sleep(charPauseTime);
	}

}

void beeper::beep::parseOrders(std::string orders)
{
	int parsedOrders[5];
	for (int i = 0; i < 5; i++) {
		parsedOrders[i] = 0;
	}

	char *ordersTab = new char[orders.length() + 1];
	strcpy(ordersTab, orders.c_str());

	int iter = 0;
	int iter2 = 0;
	bool not_0 = false;
	char x = ' ';
	int localCheck = 0;

	while (ordersTab[iter] != '\0') {
		x = ordersTab[iter];
		
		if ((int(x) >= 48) && (int(x) <= 57)) {
			if ( (int(x) == 48) && (not_0 == false) ) {
				++iter;
			}
			else 
			{
				parsedOrders[localCheck] = parsedOrders[localCheck]*10 + (int(x) - '0');
				++iter;
				iter2 = iter2+10;
				not_0 = true;
			}
		}
		else if (int(x) == 32) {
			not_0 = false;
			++iter;
			++localCheck;
		}
	}

	if (parsedOrders[0] != 0)
		Frequency = parsedOrders[0];
	if (parsedOrders[1] != 0)
		pauseLetterTime = parsedOrders[1];
	if (parsedOrders[2] != 0)
		dotBeepTime = parsedOrders[2];
	if (parsedOrders[3] != 0)
		dashBeepTime = parsedOrders[3];
	if (parsedOrders[4] != 0)
		charPauseTime =	parsedOrders[4];

}

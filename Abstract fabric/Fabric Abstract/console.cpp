#define _CRT_SECURE_NO_WARNINGS

#include "console.h"
#include <Windows.h>


consoler::console::console()
	:
	morse()
	, pauseLetterTime(0)
	, charPauseTime(0)
	, dotWriteTime(0)
	, dashWriteTime(0)
{
}

consoler::console::console(std::string prodOrders)
	:
	morse()
	, pauseLetterTime(0)
	, charPauseTime(0)
	, dotWriteTime(0)
	, dashWriteTime(0)
{
	parseOrders(prodOrders);
}

consoler::console::~console()
{
}

int consoler::console::getPauseLetterTime() const
{
	return pauseLetterTime;
}

int consoler::console::getDotWriteTime() const
{
	return dotWriteTime;
}

int consoler::console::getDashWriteTime() const
{
	return dashWriteTime;
}

int consoler::console::getCharPauseTime() const
{
	return charPauseTime;
}

void consoler::console::convert(std::string txtToConvert)
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
				printf("%c", '.');
				Sleep(dotWriteTime);
			}
			else if (tempTab[j] == '_') {
				printf("%c", '_');
				Sleep(dashWriteTime);
			}
			else if (tempTab[j] == '+') {
				Sleep(charPauseTime);
			}
			j++;
		}
		if (tempTab[j] != '+')
			Sleep(pauseLetterTime);
	}
}

void consoler::console::convert(int integerToConvert)
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
				printf("%c", '.');
				Sleep(dotWriteTime);
			}
			else if (tempTab[j] == '_') {
				printf("%c", '_');
				Sleep(dashWriteTime);
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

void consoler::console::convert(double doubleToConvert)
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
				printf("%c", '.');
				Sleep(dotWriteTime);
			}
			else if (tempTab[j] == '_') {
				printf("%c", '_');
				Sleep(dashWriteTime);
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

void consoler::console::parseOrders(std::string orders)
{
	int parsedOrders[4];
	for (int i = 0; i < 4; i++) {
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
			if ((int(x) == 48) && (not_0 == false)) {
				++iter;
			}
			else
			{
				parsedOrders[localCheck] = parsedOrders[localCheck] * 10 + (int(x) - '0');
				++iter;
				iter2 = iter2 + 10;
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
		pauseLetterTime = parsedOrders[1];
	if (parsedOrders[1] != 0)
		dotWriteTime = parsedOrders[2];
	if (parsedOrders[2] != 0)
		dashWriteTime = parsedOrders[3];
	if (parsedOrders[3] != 0)
		charPauseTime = parsedOrders[4];
}

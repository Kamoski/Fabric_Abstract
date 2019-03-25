#define _WIN32_WINNT_ 0x403
#define _CRT_SECURE_NO_WARNINGS

#include "blink.h"
#include <Windows.h>



blinker::blink::blink()
	:
	morse()
	, pauseLetterTime(50)
	, dotBlinkTime(180)
	, dashBlinkTime(540)
	, charPauseTime(60)
{
}

blinker::blink::blink(std::string prodOrders)
	:
	morse()
	, pauseLetterTime(50)
	, dotBlinkTime(180)
	, dashBlinkTime(540)
	, charPauseTime(60)
{
	parseOrders(prodOrders);
}


blinker::blink::~blink()
{
}

int blinker::blink::getPauseLetterTime() const
{
	return pauseLetterTime;
}

int blinker::blink::getDotBlinkTime() const
{
	return dotBlinkTime;
}

int blinker::blink::getDashBlinkTime() const
{
	return dashBlinkTime;
}

int blinker::blink::getCharPauseTime() const
{
	return charPauseTime;
}

void blinker::blink::convert(std::string txtToConvert)
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
				capsLockBlink();
				Sleep(dotBlinkTime);
				capsLockBlink();
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '_') {
				capsLockBlink();
				Sleep(dashBlinkTime);
				capsLockBlink();
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
void blinker::blink::convert(int integerToConvert)
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
				capsLockBlink();
				Sleep(dotBlinkTime);
				capsLockBlink();
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '_') {
				capsLockBlink();
				Sleep(dotBlinkTime);
				capsLockBlink();
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
void blinker::blink::convert(double doubleToConvert)
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
				capsLockBlink();
				Sleep(dashBlinkTime);
				capsLockBlink();
				Sleep(charPauseTime);
			}
			else if (tempTab[j] == '_') {
				capsLockBlink();
				Sleep(dashBlinkTime);
				capsLockBlink();
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


void blinker::blink::parseOrders(std::string orders)
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
		dotBlinkTime = parsedOrders[2];
	if (parsedOrders[2] != 0)
		dashBlinkTime = parsedOrders[3];
	if (parsedOrders[3] != 0)
		charPauseTime = parsedOrders[4];
}

void blinker::blink::capsLockBlink()
{
	INPUT in[2];
	in[0].type = INPUT_KEYBOARD;
	in[0].ki.wVk = VK_CAPITAL;
	in[0].ki.wScan = 0;
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;
	in[0].ki.dwExtraInfo = 0;
	in[1] = in[0];
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(2, in, sizeof(INPUT));
}

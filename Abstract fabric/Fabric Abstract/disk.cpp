#define _CRT_SECURE_NO_WARNINGS

#include "disk.h"
#include <fstream>


filer::disk::disk()
	:
	morse()
	, FileName("file.txt")
{
	file.open(FileName, std::ios::app);
}

filer::disk::disk(std::string prodOrders)
	:
	morse()
	, FileName("file.txt")
{
	if (prodOrders != " ") {
		FileName = prodOrders;
	}
	file.open(FileName, std::ios::app);
}


filer::disk::~disk()
{
	file.close();
}


std::string filer::disk::getFileName() const
{
	return FileName;
}

void filer::disk::convert(std::string txtToConvert)
{
	//std::ofstream file;
	//file.open(FileName, std::ios::app);

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
				file << ".";
			}
			else if (tempTab[j] == '_') {
				file << "_";
			}
			else if (tempTab[j] == '+') {
				file << " ";
			}
			j++;
		}
		if (tempTab[j] != '+')
			file << " ";
	}
	//file.close();
}

void filer::disk::convert(int integerToConvert)
{
	std::string tempNumber = std::to_string(integerToConvert);
	char *txtToConvert = new char[tempNumber.length() + 1];
	strcpy(txtToConvert, tempNumber.c_str());

	//std::ofstream file;
	//file.open(FileName, std::ios::app);

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
				file << ".";
			}
			else if (tempTab[j] == '_') {
				file << "_";
			}
			else if (tempTab[j] == '+') {
				file << " ";
			}
			j++;
		}
		if (tempTab[j] != '+')
			file << " ";
	}
	//file.close();
}

void filer::disk::convert(double doubleToConvert)
{
	std::string tempNumber = std::to_string(doubleToConvert);
	char *txtToConvert = new char[tempNumber.length() + 1];
	strcpy(txtToConvert, tempNumber.c_str());

	/*std::ofstream file;
	file.open(FileName, std::ios::app);*/

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
				file << ".";
			}
			else if (tempTab[j] == '_') {
				file << "_";
			}
			else if (tempTab[j] == '+') {
				file << " ";
			}
			j++;
		}
		if (tempTab[j] != '+')
			file << " ";
	}
	//file.close();
}

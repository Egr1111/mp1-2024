#include "strock.h"
#include <algorithm>
#include <string>


//
int Strock::getStrockLength() {
	return strock.length();
}
//
int Strock::getSimvolIndex(char simv) {
	for (int i = 0; i < strock.length(); i++)
	{
		if (strock[i] == simv) {
			return i;
		}
	}
	return -1;
}
//
bool Strock::changeSimvolByIndex(int ind, char simvAcc) {

	if (ind < 0 || ind >= strock.length())
		return false;

	strock[ind] = simvAcc;


	return true;

}
//
//
bool Strock::checkOnPalidrom() {

	std::string str2;

	for (int i = strock.length() - 1; i > -1; i--)
	{
		str2 += strock[i];
	}
	if (strock == str2)
		return true;
	else
		return false;
}

void Strock::countAlp() {

	std::string str2;
	int* count = new int[strock.length()];

	for (int i = 0; i < strock.length(); i++)
	{
		if (str2.find(strock[i]) == std::string::npos) {
			count[str2.length()] = 1;
			str2 += strock[i];
		}
		else
			count[str2.find(strock[i])] += 1;
	}

	for (int i = 0; i < str2.length(); i++)
	{
		std::cout << str2[i] << " " << count[i] << "\n";
	}

}

bool Strock::getUnderStrock(std::string str) {
	if (strock.find(str) == std::string::npos)
		return false;

	return true;
}






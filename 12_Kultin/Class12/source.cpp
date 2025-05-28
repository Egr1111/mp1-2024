#include "strock.h"

void main() {
	Strock str("qwerttrww"), str2("aaaaaaaaaaaaaa");
	std::cout << str.getStrockLength() << "\n";
	std::cout << str.getSimvolIndex('w') << "\n";
	str.changeSimvolByIndex(0, 'w');
	str.getStrock();
	std::cout << str.checkOnPalidrom() << "\n";
	str.countAlp();
	Strock str3 = str + str2;
	str3.getStrock();

	str += str3;

	str.getStrock();

	str[0] = 'a';
	char y = str[1];
}


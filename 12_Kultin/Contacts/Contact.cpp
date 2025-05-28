#include "Contact.h"

void main() {
	setlocale(LC_ALL, "RU");
	Contact c1("a", "b", "c"), c2("d", "e", "f", 879249294, 23, 4, 5);
	std::vector<Contact> arr = { c1, c2 }, arr2;

	std::cout << arr[0].name << " " << arr[0].secName << " " << arr[0].fathName << "\n";
	arr[0].changeContact("aa", "ab", "", 287424424, 12, 323, 42);
	std::cout << arr[0].name << " " << arr[0].secName << " " << arr[0].fathName << " " << arr[0].dateBorn[0] << arr[0].dateBorn[1] << arr[0].dateBorn[2] << "\n";
	int con1 = findContactByFIO(arr, "aa", "ab", "c");
	int con2 = findContactByFIO(arr, "aa", "b", "c");
	std::cout << con1 << " " << con2 << "\n";

	con1 = findContactByNum(arr, 287424424);
	con2 = findContactByNum(arr, 2937492);
	std::cout << con1 << " " << con2 << "\n";

	arr2 = getContactsOnLetter(arr, 'a');
	std::cout << arr2.size() << "\n";
	for (int i = 0; i < arr2.size(); i++)
	{
		Contact con1 = arr2[i];
		std::cout << con1.name << " " << con1.secName << " " << con1.fathName << " " << con1.dateBorn[0] << con1.dateBorn[1] << con1.dateBorn[2] << "\n";
	}

	std::cout << getLengthContacts(arr) << "\n";

	arr2.clear();

	arr[0].addIntoChousen();

	getIsChousen(arr, arr2);
	
	arr[0].removeFromChousen();

	arr2.clear();

	getIsChousen(arr, arr2);

	//getContactsInFile(arr);

	getContactsFromFile("C:/Users/AAAAAAAAAAAAAAAAAAAA/source/repos/mp1-2024/12_Kultin/Contacts/contacts.txt");
}
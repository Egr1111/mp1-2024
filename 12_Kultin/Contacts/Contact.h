#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <algorithm>


class Contact
{
public:
	int number = 0;
	std::string name;
	std::string secName;
	std::string fathName;
	std::vector<int> dateBorn = { 1, 1, 1 };
	bool isChousen = false;


	Contact(std::string name1, std::string secName1, std::string fathName1, int number1 = NULL, int day = NULL, int month = NULL, int year = NULL) {
		if (number1 != NULL)
			number = number1;
		name = name1;
		secName = secName1;
		fathName = fathName1;
		if (day != NULL && month != NULL && year != NULL) {
			dateBorn[0] = day;
			dateBorn[1] = month;
			dateBorn[2] = year;
		}


	}
	bool changeContact(std::string name1, std::string secName1, std::string fathName1, int number1 = NULL, int day = NULL, int month = NULL, int year = NULL) {
		if (number1 != NULL)
			number = number1;
		if (name1 != "")
			name = name1;
		if (secName1 != "")
			secName = secName1;
		if (fathName1 != "")
			fathName = fathName1;
		if (day != NULL && month != NULL && year != NULL) {
			dateBorn[0] = day;
			dateBorn[1] = month;
			dateBorn[2] = year;
		}
		return true;
	}
	void addIntoChousen() {
		isChousen = true;
		std::cout << "Контакт добавлен в избранные\n";
	}
	void removeFromChousen() {
		isChousen = false;
		std::cout << "Контакт удален из избранных\n";
	}


};

int findContactByFIO(std::vector<Contact> arr, std::string name1, std::string secName1, std::string fathName1) {


	for (int i = 0; i < arr.size(); i++)
	{
		Contact cont = arr[i];

		if (cont.name == name1 && cont.secName == secName1 && cont.fathName == fathName1)
			return i;
	}

	return -1;

}

int findContactByNum(std::vector<Contact> arr, int number1) {
	for (int i = 0; i < arr.size(); i++)
	{
		Contact cont = arr[i];
		if (cont.number == number1)
			return i;
	}
	return -1;
}

std::vector<Contact> getContactsOnLetter(std::vector<Contact> arr1, char letter) {
	std::vector<Contact> arr2;
	for (int i = 0; i < arr1.size(); i++)
	{
		Contact cont = arr1[i];
		if (cont.secName[0] == letter)
			arr2.push_back(cont);

	}
	return arr2;
}

int getLengthContacts(std::vector<Contact> arr) {
	return arr.size();
}

void getIsChousen(std::vector<Contact> arr1, std::vector<Contact> arr2) {
	for (int i = 0; i < arr1.size(); i++)
	{
		Contact cont = arr1[i];
		if (cont.isChousen) {
			arr2.push_back(cont);
		}
	}
	if (arr2.size() > 0) {
		for (int i = 0; i < arr2.size(); i++)
		{
			Contact cont = arr2[i];
			std::cout << cont.secName << " " << cont.name << " " << cont.fathName << "\n";

		}
		std::cout << "Выведены все избранные контакты\n";
	}
	else
		std::cout << "Избранных контактов нет\n";

}
void getContactsInFile(std::vector<Contact> arr) {
	std::ofstream contacts;
	contacts.open("contacts.txt");
	contacts << "Фамилия; Имя; Отчество; Номер телефона(По умолчанию 0); Является избранным; Дата рождения(ДД/ММ/ГГГГ) По умолчанию 1/1/1\n";
	for (int i = 0; i < arr.size(); i++)
	{
		Contact cont = arr[i];

		contacts << cont.secName << "; " << cont.name << "; " << cont.fathName << "; " << cont.number << "; ";
		if (cont.isChousen)
			contacts << "Да" << "; ";
		else
			contacts << "Нет" << "; ";

		contacts << cont.dateBorn[0] << "/"
			<< cont.dateBorn[1] << "/" << cont.dateBorn[2] << ";\n";
	}
	contacts.close();
	std::cout << "Файл с вашими контактами создан\n";

}

void getContactsFromFile(std::string path) {
	std::ifstream contacts;
	std::string text;
	std::vector<std::string> arr;
	contacts.open(path);
	while (std::getline(contacts, text))
		arr.push_back(text);


	for (int i = 1; i < arr.size(); i++)
	{
		std::string cont = arr[i];

		int cS2 = 0;
		std::vector<std::string> data;
		if (cont != "Фамилия; Имя; Отчество; Номер телефона(По умолчанию 0); Является избранным; Дата рождения(ДД/ММ/ГГГГ) По умолчанию 1/1/1;") {
			for (int i2 = 0; i2 < cont.size(); i2++)
			{
				cont.erase(std::remove(cont.begin(), cont.end(), ';'), cont.end());
				if (cont[i2] == '/') {
					cS2++;
					if (i2 > 0 && cS2 <= 2) {
						std::string d;
						int c = 1;
						while (i2 - c >= 0 && cont[i2 - c] != ' ' && cont[i2 - c] != '/')
						{
							if (isdigit(cont[i2 - c]))
								d += cont[i2 - c];

							c++;
						}
						std::reverse(d.begin(), d.end());
						data.push_back(d);
					}
					if (i2 > 0 && cS2 == 2) {
						std::string g;
						int c = 1;
						while (isdigit(cont[i2 + c]) && i2 + c < cont.size() && cont[i2 + c] != ' ')
						{
							g += cont[i2 + c];
							c++;
						}

						data.push_back(g);
					}

		

				}
			}

			if (data.size() >= 3) {
				cont.erase(cont.find(data[0] + '/' + data[1] + '/' + data[2]), 2 + data[0].size() + data[1].size() + data[2].size());
				if (data[0] == "")
					data[0] = "1";

				if (data[1] == "")
					data[1] = "1";

				if (data[2] == "")
					data[2] = "1";
			}
			else {
				if (data.size() == 1)
					cont.erase(cont.find(data[0]), 1 + data[0].size());

				while (data.size() < 3)
				{
					data[data.size()] = "1";
				}
			}


			bool Chousen = false;
			if (cont.find(' ' + "Да" + ' ') != std::string::npos || cont.find("Да" + ' ') != std::string::npos || cont.find(' ' + "Да") != std::string::npos)
			{
				Chousen = true;
				if (cont.find(' ' + "Да" + ' '))
					cont.erase(cont.find(' ' + "Да" + ' '), 5);
				if (cont.find(' ' + "Да"))
					cont.erase(cont.find(' ' + "Да"), 4);
				if (cont.find("Да" + ' '))
					cont.erase(cont.find(' ' + "Да" + ' '), 4);
			}
			if (cont.find(" Нет ") != std::string::npos)
				cont.erase(cont.find(" Нет "), 5);
			if (cont.find(" Нет") != std::string::npos)
				cont.erase(cont.find(" Нет"), 4);
			if (cont.find("Нет ") != std::string::npos)
				cont.erase(cont.find("Нет" + ' '), 4);

			std::string numb;
			for (int i2 = 0; i2 < cont.size(); i2++)
			{
				if (std::isdigit(cont[i2]))
					numb += cont[i2];
			}
			cont.erase(cont.find(numb));

			while (cont.find("  ") != std::string::npos)
				cont.erase(cont.find("  "), 2);

			if (cont[0] == ' ')
				cont.erase(cont.begin());
			if (cont[cont.size() - 1] != ' ')
				cont += " ";
				
			std::cout << cont << numb << "; ";

			if (Chousen)
				std::cout << "Да; ";
			else
				std::cout << "Нет; ";


			std::cout << numb << " " << data[0] << "/" << data[1] << "/" << data[2] << ";\n";


			std::reverse(numb.begin(), numb.end());
		}
	}


	contacts.close();
}

// Поиск в строке: find find_first_of find_last_of
//Contact::~Contact() {
//	delete[] dateBorn;
//
//}



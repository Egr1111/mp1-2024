#pragma once
#include "iostream";

class Event
{
	private:
		int id;
		std::string name;
		std::string descr;
		int year;
		int month;
		int day;

	public:
		Event createEvent(int year, int month, int day);
		void deleteEvent(Event event);
		Event getEventDate(Event event);
		
		

};

bool checkDays(int year, int month, int day) {
	if (year > 0 && month > 0 && month < 13 && day > 0 && day < 32) {

		if (year % 4 == 0 && year % 100 != 0 && month == 2 && day < 29 ||
			year % 4 != 0 && month == 2 && day < 30 ||
			month != 2 && month % 2 == 0 && day < 31 ||
			month != 2 && month % 2 != 0 && day < 32
			)
			return true;
	}

	return false;
}

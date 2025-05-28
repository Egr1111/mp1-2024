#pragma once
#include <iostream>



class Strock
{	
	private:
		std::string strock;
	public:
		
		Strock (std::string str) {
			strock = str;
		}

		void getStrock()
		{
			std::cout << strock << "\n";
		}

		int getStrockLength();

		int getSimvolIndex(char simv);

		bool changeSimvolByIndex(int ind, char simvAcc);

		bool checkOnPalidrom();

		void countAlp();

		bool getUnderStrock(std::string str);

		Strock operator+(Strock const&str) {
			Strock res(strock + str.strock);
			
			return res;
		}

		Strock& operator+=(Strock const& str) {
			strock += str.strock;
			return *this;

		}

		char& operator[](int i) {
			return strock[i];
		}

		const char& operator[](int i) const {
			return strock[i];
		}

};


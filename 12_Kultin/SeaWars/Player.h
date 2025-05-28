#pragma once
#include <iostream>
#include <vector>


class User
{

	public:
		int mapShips[10][10];
		int liveShips = 20;
		int coordShip[10][4][3];

		User() {
			for (int i = 0; i < 10; i++)
			{
				for (int in = 0; in < 10; in++)
					mapShips[i][in] = 0;
			}
		}
		virtual int shoot(int x, int y);
		virtual void showMap(bool toFriend);
		//~User();

};
class Player: public User
{
public:
	Player();
};


class Comp: public User {
	public:
		Comp();
};

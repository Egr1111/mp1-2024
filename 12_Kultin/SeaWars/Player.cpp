#include "Player.h"
#include <random>
bool checkLocationMultyDeckShip(int map[10][10], int countDeck, int x, int y, char direct) {
	if (direct == 't') {
		for (int i = 0; i < countDeck; i++) {
			if (map[y - 1 - i][x - 1] == 1)
				return false;
		}
	}
	if (direct == 'b') {
		for (int i = 0; i < countDeck; i++) {
			if (map[y - 1 + i][x - 1] == 1)
				return false;
		}
	}
	if (direct == 'r') {
		for (int i = 0; i < countDeck; i++) {
			if (map[y - 1][x - 1 + i] == 1)
				return false;
		}
	}
	if (direct == 'l') {
		for (int i = 0; i < countDeck; i++) {
			if (map[y - 1][x - 1 - i] == 1)
				return false;
		}
	}
	return true;

}
void setAllMultyDeckShipsOnMap(int map[10][10], int countDeck, int x, int y, char direct, int coordShip[10][4][3], int unsetedShips) {
	int setedCell = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int in = 0; in < 10; in++) {
			if (
				(direct == 'r' && x - 1 <= in && in <= x + countDeck - 2 && i == y - 1) ||
				(direct == 'l' && x - countDeck <= in && in <= x - 1 && i == y - 1) ||
				(direct == 'b' && y - 1 <= i && i <= y + countDeck - 2 && in == x - 1) ||
				(direct == 't' && y - countDeck <= i && i <= y - 1 && in == x - 1)
				) {
				int dir = 50000;
				if (direct == 'l')
					dir = 0;
				if (direct == 't')
					dir = 1;
				if (direct == 'r')
					dir = 2;
				if (direct == 'b')
					dir = 3;
				map[i][in] = 1;
				coordShip[4 + 6 - unsetedShips][setedCell][0] = in;
				coordShip[4 + 6 - unsetedShips][setedCell][1] = i;
				coordShip[4 + 6 - unsetedShips][setedCell][2] = dir;
				setedCell++;
			}
		}
	}
}
void setMultyDeckShips(int map[10][10], int countDeck, int countShip, int coordShip[10][4][3], int* unsetedShips) {
	std::cout << "Расставьте " << countDeck << " палубные корабли, для этого введите координаты желаемого положения: в начале введите координаты начальной точки, а затем задайте направление корабля(t - вверх; r - право; b - вниз: l - влево) через пробел\n";

	while (countShip > 0)
	{
		int x = 0, y = 0;
		char direct;
		std::cin >> x >> y >> direct;

		while (x < 1 || x > 10 || y < 1 || y > 10 ||
			(direct == 'r' && x + countDeck - 1 > 10) ||
			(direct == 'l' && x - countDeck + 1 < 1) ||
			(direct == 't' && y - countDeck + 1 < 1) ||
			(direct == 'b' && y + countDeck - 1 > 10) ||
			(direct != 'r' && direct != 'l' && direct != 'b' && direct != 't')
			)
		{
			std::cout << "Введите корректные координаты и направление\n";
			std::cin >> x >> y >> direct;
		}

		while (!checkLocationMultyDeckShip(map, countDeck, x, y, direct)) {
			std::cout << "Эта/эти клетка/клетки уже занята/заняты(Выделена/выделены красным, желтым выделены клетки, занятые неправильно расположенным кораблем). Выберите любую свободную клетку\n";
			for (int i = 0; i < 10; i++)
			{
				for (int in = 0; in < 10; in++) {
					if (
						(direct == 'r' && x - 1 <= in && in <= x + countDeck - 2 && i == y - 1) ||
						(direct == 'l' && x - countDeck <= in && in <= x - 1 && i == y - 1) ||
						(direct == 'b' && y - 1 <= i && i <= y + countDeck - 2 && in == x - 1) ||
						(direct == 't' && y - countDeck <= i && i <= y - 1 && in == x - 1)
						)
					{ 
						if (map[i][in] == 1)
							std::cout << "\033[3;41;30m1\033[0m" << " ";
						else
							std::cout << "\033[3;43;30m1\033[0m" << " ";
					}
					else {
						if (map[i][in] == 1)
							std::cout << "\033[3;42;30m1\033[0m" << " ";
						else
							std::cout << map[i][in] << " ";
					}
				}
				std::cout << "\n";
			}
			std::cin >> x >> y >> direct;
			while (x < 1 || x > 10 || y < 1 || y > 10 ||
				(direct == 'r' && x + countDeck - 1 > 10) ||
				(direct == 'l' && x - countDeck + 1 < 1) ||
				(direct == 't' && y - countDeck + 1 < 1) ||
				(direct == 'b' && y + countDeck - 1 > 10) ||
				(direct != 'r' && direct != 'l' && direct != 'b' && direct != 't'))
			{
				std::cout << "Введите корректные координаты и направление\n";
				std::cin >> x >> y >> direct;
			}
		}
		
		for (int i = 0; i < 10; i++)
		{
			for (int in = 0; in < 10; in++) {
				if (
					(direct == 'r' && x - 1 <= in && in <= x + countDeck - 2 && i == y - 1) ||
					(direct == 'l' && x - countDeck <= in && in <= x - 1 && i == y - 1) ||
					(direct == 'b' && y - 1 <= i && i <= y + countDeck - 2 && in == x - 1) ||
					(direct == 't' && y - countDeck <= i && i <= y - 1 && in == x - 1)
					)
					std::cout << "\033[3;43;30m1\033[0m" << " ";
				else {
					if (map[i][in] == 1)
						std::cout << "\033[3;42;30m1\033[0m" << " ";
					else
						std::cout << map[i][in] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "Вы уверены в позиции корабля?(1 - да; 0 - нет)";
		int booll;
		std::cin >> booll;

		while (booll < 0 && booll > 1)
		{
			std::cin >> booll;
		}
		if (booll == 1) {
			setAllMultyDeckShipsOnMap(map, countDeck, x, y, direct, coordShip, *unsetedShips);
			countShip--;
			(*unsetedShips)--;
		}
		else
			map[y - 1][x - 1] = 0;
		std::cout << "Осталось кораблей: " << countShip << "\n";
		for (int i = 0; i < 10; i++)
		{
			for (int in = 0; in < 10; in++) {

				if (map[i][in] == 1)
					std::cout << "\033[3;42;30m1\033[0m" << " ";
				else
					std::cout << map[i][in] << " ";

			}
			std::cout << "\n";
		}

	}

}
void ranSetMultyDeckShips(int map[10][10], int countDeck, int countShip, std::uniform_int_distribution<> distrib, std::uniform_int_distribution<> directRand, std::mt19937 gen, int coordShips[10][4][3], int *unsetedShips) {
	for (int i = 0; i < countShip; i++)
	{
		int x = distrib(gen);
		int y = distrib(gen);
		int direct = directRand(gen);
		char dir;
		if (direct == 0)
			dir = 'l';
		if (direct == 1)
			dir = 't';
		if (direct == 2)
			dir = 'r';
		if (direct == 3)
			dir = 'b';


		while (map[y - 1][x - 1] == 1 ||

			(direct == 2 && x + countDeck - 1 > 10) ||
			(direct == 1 && y - countDeck + 1 < 1) ||
			(direct == 0 && x - countDeck + 1 < 1) ||
			(direct == 3 && y + countDeck - 1 > 10) ||
			!checkLocationMultyDeckShip(map, countDeck, x, y, dir))
		{
			x = distrib(gen);
			y = distrib(gen);
			direct = directRand(gen);
			if (direct == 0)
				dir = 'l';
			if (direct == 1)
				dir = 't';
			if (direct == 2)
				dir = 'r';
			if (direct == 3)
				dir = 'b';
		}
		int setedCeils = 0;
		setAllMultyDeckShipsOnMap(map, countDeck, x, y, dir, coordShips, (*unsetedShips));
		(*unsetedShips)--;


	}
}


Player::Player() {
	for (int i = 0; i < 10; i++)
	{
		for (int in = 0; in < 10; in++) {
			std::cout << 0 << " ";
		}
		std::cout << "\n";
	}
	std::cout << "Расставьте однопалубные корабли, для этого введите координаты желаемого положения(от 1 до 10), значение которой равно 0, через пробел\n";
	int unSetedShips = 4;
	
	while (unSetedShips > 0)
	{
		int x = 0, y = 0;
		std::cin >> x >> y;

		while (x < 1 || x > 10 || y < 1 || y > 10)
		{
			std::cout << "Введите корректные координаты\n";
			std::cin >> x >> y;
		}

		while (mapShips[y - 1][x - 1] == 1) {
			std::cout << "Эта клетка уже занята(Выделена красным). Выберите любую свободную клетку\n";
			for (int i = 0; i < 10; i++)
			{
				for (int in = 0; in < 10; in++) {
					if (i == y - 1 && in == x - 1)
						std::cout << "\033[3;41;30m1\033[0m" << " ";
					else {
						if (mapShips[i][in] == 1)
							std::cout << "\033[3;42;30m1\033[0m" << " ";
						else
							std::cout << mapShips[i][in] << " ";
					}
				}
				std::cout << "\n";
			}
			std::cin >> x >> y;
			while (x < 1 || x > 10 || y < 1 || y > 10)
			{
				std::cout << "Введите корректные координаты\n";
				std::cin >> x >> y;
			}
		}
		mapShips[y - 1][x - 1] = 1;
		for (int i = 0; i < 10; i++)
		{
			for (int in = 0; in < 10; in++) {
				if (i == y - 1 && in == x - 1)
					std::cout << "\033[3;43;30m1\033[0m" << " ";
				else {
					if (mapShips[i][in] == 1)
						std::cout << "\033[3;42;30m1\033[0m" << " ";
					else
						std::cout << mapShips[i][in] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "Вы уверены в позиции корабля?(1 - да; 0 - нет)";
		int booll;
		std::cin >> booll;

		while (booll < 0 && booll > 1)
		{
			std::cin >> booll;
		}
		if (booll == 1) {
			coordShip[4 - unSetedShips][0][0] = x - 1;
			coordShip[4 - unSetedShips][0][1] = y - 1;
			unSetedShips--;
			
		}
		else
			mapShips[y - 1][x - 1] = 0;
		std::cout << "Осталось кораблей: " << unSetedShips << "\n";
		for (int i = 0; i < 10; i++)
		{
			for (int in = 0; in < 10; in++) {

				if (mapShips[i][in] == 1)
					std::cout << "\033[3;42;30m1\033[0m" << " ";
				else
					std::cout << mapShips[i][in] << " ";

			}
			std::cout << "\n";
		}

	}
	
	unSetedShips = 6;
	setMultyDeckShips(mapShips, 2, 3, coordShip, &unSetedShips);
	setMultyDeckShips(mapShips, 3, 2, coordShip, &unSetedShips);
	setMultyDeckShips(mapShips, 4, 1, coordShip, &unSetedShips);

	

	
}
bool checkLive(int map[10][10], int coordShip[10][4][3], int numShip, int countDeck) {
	for (int i = 0; i < countDeck; i++)
	{
		if (map[ coordShip[numShip][i][1] ][ coordShip[numShip][i][0] ] == 1)
			return true;
	}
	for (int i = 0; i < countDeck; i++)
		map[coordShip[numShip][i][1]][coordShip[numShip][i][0]]-=2;
	

	return false;
}

int User::shoot(int x, int y) {
	mapShips[y - 1][x - 1] -= 2;
	
	if (mapShips[y - 1][x - 1] == -1) {
		liveShips--;
		for (int i = 0; i < 4; i++)
		{
			if (coordShip[i][0][0] == x - 1 && coordShip[i][0][1] == y - 1) {
				mapShips[y - 1][x - 1]-= 2;
				return 2;
			}
		}
		for (int i = 4; i < 7; i++)
		{
			int shotedShip = -1;
			for (int in = 0; in < 2; in++) {
				if (coordShip[i][in][0] == x - 1 && coordShip[i][in][1] == y - 1)
					shotedShip = i;
			}
			if (shotedShip > -1) {
				if (!checkLive(mapShips, coordShip, shotedShip, 2))
					return 2;
			}
		}
		for (int i = 7; i < 9; i++)
		{
			int shotedShip = -1;
			for (int in = 0; in < 3; in++) {
				if (coordShip[i][in][0] == x - 1 && coordShip[i][in][1] == y - 1)
					shotedShip = i;
			}
			if (shotedShip > -1) {
				if (!checkLive(mapShips, coordShip, shotedShip, 3))
					return 2;
			}
		}
		for (int in = 0; in < 4; in++) {
			if (coordShip[9][in][0] == x - 1 && coordShip[9][in][1] == y - 1) {
				if (!checkLive(mapShips, coordShip, 9, 4))
					return 2;
			}
		}

		return 1;
	}
	return 0;
}

void User::showMap(bool toFriend) {
	for (int i = 0; i < 10; i++)
	{
		for (int in = 0; in < 10; in++) {
			if (mapShips[i][in] == 1 && toFriend)
				std::cout << "  " << "\033[3;42;30m1\033[0m";
			if (mapShips[i][in] == -1)
				std::cout << " " << "\033[3;41;30m-1\033[0m";
			if (mapShips[i][in] == -2)
				std::cout << " " << "\033[3;44;30m-2\033[0m";
			if (mapShips[i][in] == -3)
				std::cout << " " << "\033[3;100;30m-3\033[0m";
			if (mapShips[i][in] == 0 || mapShips[i][in] == 1 && !toFriend)
				std::cout << "  " << 0;
			if(mapShips[i][in] > 1 || mapShips[i][in] < -3)
				std::cout << "  " << mapShips[i][in];

			
		}
		std::cout << "\n";
	}
	int sK = 1;
	int skk = 3;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "[" << i << " " << coordShip[i][0][2];
		for (int in = 0; in < sK; in++)
		{
			std::cout << "[" << coordShip[i][in][0] << ", " << coordShip[i][in][1] << "], ";
		}
		std::cout << "]; ";
		if (i == 3) {
			sK++;
		}
		if (i == 6) {
			sK++;
		}
		if (i == 8) {
			sK++;
		}

	}
	std::cout << "\n";
}

//User::~User() {
//	delete[] mapShips;
//}

Comp::Comp() {
	int minn = 1;
	int maxx = 10;
	int maxDir = 3;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(minn, maxx);
	std::uniform_int_distribution<> directRand(minn - 1, maxDir);
	std::cout << "Теперь очередь копьютера расставить свои корабли.\n";
	for (int i = 0; i < 4; i++)
	{
		int x = distrib(gen);
		int y = distrib(gen);
		while (mapShips[y - 1][x - 1] == 1)
		{
			x = distrib(gen);
			y = distrib(gen);
		}
		mapShips[y - 1][x - 1] = 1;
		coordShip[i][0][0] = x - 1;
		coordShip[i][0][1] = y - 1;
	}
	int unsetedShips = 6;
	ranSetMultyDeckShips(mapShips, 2, 3, distrib, directRand, gen, coordShip, &unsetedShips);
	/*int x = 9;
	int y = 10;
	int direct = 2;
	char dir;
	if (direct == 0)
		dir = 'l';
	if (direct == 1)
		dir = 't';
	if (direct == 2)
		dir = 'r';
	if (direct == 3)
		dir = 'b';


	while (mapShips[y - 1][x - 1] == 1 ||

		(direct == 2 && x + 3 - 1 > 10) ||
		(direct == 1 && y - 3 + 1 < 1) ||
		(direct == 0 && x - 3 + 1 < 1) ||
		(direct == 3 && y + 3 - 1 > 10) ||
		!checkLocationMultyDeckShip(mapShips, 3, x, y, dir))
	{
		x = distrib(gen);
		y = distrib(gen);
		direct = directRand(gen);
	}
	int setedCeils = 0;
	setAllMultyDeckShipsOnMap(mapShips, 3, x, y, dir, coordShip, unsetedShips);
	
	unsetedShips--;*/
	
	
	ranSetMultyDeckShips(mapShips, 3, 2, distrib, directRand, gen, coordShip, &unsetedShips);
	ranSetMultyDeckShips(mapShips, 4, 1, distrib, directRand, gen, coordShip, &unsetedShips);

	std::cout << "Компьютер закончил расстановку.\n";
}



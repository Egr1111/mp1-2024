#include "Player.h";
#include <random>;
void randomShotPoint(Player p1, int *x, int *y, std::uniform_int_distribution<> distrib, std::mt19937 gen) {
	(*x) = distrib(gen);
	(*y) = distrib(gen);
	while (p1.mapShips[(*y)][(*x)] < 0)
	{
		(*x) = distrib(gen);
		(*y) = distrib(gen);
	}
}

bool searchWounded(int *x, int *y, Player p1) {
	for (int i = 0; i < 10; i++)
	{
		for (int in = 0; in < 10; in++)
		{
			if (p1.mapShips[in][i] == -1) {
				(*x) = i;
				(*y) = in;
				return true;
			}
		}
	}
	return false;
}
bool choiceRightDirection(Player p1, int* x, int* y, int *direct, std::uniform_int_distribution<> dirRand, std::mt19937 gen) {
	if (
		((*x) - 1 < 0 || p1.mapShips[(*y)][(*x) - 1] < 0) &&
		((*x) + 1 > 9 || p1.mapShips[(*y)][(*x) + 1] < 0) &&
		((*y) - 1 < 0 || p1.mapShips[(*y) - 1][(*x)] < 0) &&
		((*y) + 1 > 9 || p1.mapShips[(*y) + 1][(*x)] < 0)
		) {
		if (p1.mapShips[(*y)][(*x)] == -1)
			p1.mapShips[(*y)][(*x)] -= 3;
		return false;
	}

	while (((*direct) == 0 && ((*x) - 1 < 0 || p1.mapShips[(*y)][(*x) - 1] < 0)) ||
		((*direct) == 2 && ((*x) + 1 > 9 || p1.mapShips[(*y)][(*x) + 1] < 0)) ||
		((*direct) == 1 && ((*y) - 1 < 0 || p1.mapShips[(*y) - 1][(*x)] < 0)) ||
		((*direct) == 3 && ((*y) + 1 > 9 || p1.mapShips[(*y) + 1][(*x)] < 0)))
	{
		(*direct) = dirRand(gen);
	}

	if ((*direct) == 0)
		(*x)--;
	if ((*direct) == 1)
		(*y)--;
	if ((*direct) == 2)
		(*x)++;
	if ((*direct) == 3)
		(*y)++;
	return true;
}
void fixMap(Player p1) {
	for (int i = 0; i < 10; i++)
	{
		for (int in = 0; in < 10; in++)
		{
			if (p1.mapShips[in][i] == -4) {
				p1.mapShips[in][i] = -1;
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "Ru");

	int x, y;
	int repl = 1;
	int minn = 0;
	int maxx = 9;
	int dir = 3;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(minn, maxx);
	std::uniform_int_distribution<> dirRand(minn, dir);
	while (repl == 1)
	{
		Player p1;
		Comp p2;
		std::cout << "Все корабли расставлены! Можно начинать!\n";
		while (p1.liveShips > 0 && p2.liveShips > 0)
		{
			std::cout << "Карта игрока\n";
			p1.showMap(true);
			std::cout << "Карта компьютера\n";
			p2.showMap(true);

			std::cout << "Сейчас ваш ход. Для выстрела введите координаты обстреливаемой точки через пробел от 1 до 10(Стрелять по одной и той же координате несколько раз нельзя)\n";
			std::cin >> x >> y;
			while (x < 1 || x > 10 || y < 1 || y > 10 || p2.mapShips[y - 1][x - 1] < 0)
			{
				std::cout << "Введите корректные координаты\n";
				std::cin >> x >> y;
			}

			int shot = p2.shoot(x, y);
			while (shot > 0 && p2.liveShips > 0)
			{
				
				std::cout << "Карта компьютера\n";
				p2.showMap(true);
				std::cout << "Вы попали!";
				if (shot == 2)
					std::cout << "И вы подбили корабль!";
				std::cout << "Вы можете продолжать стрелять до тех пор, пока не промахнетесь\n";
				std::cin >> x >> y;
				while (x < 1 || x > 10 || y < 1 || y > 10 || p2.mapShips[y - 1][x - 1] < 0)
				{
					std::cout << "Введите корректные координаты\n";
					std::cin >> x >> y;
				}
				shot = p2.shoot(x, y);
			}
			
			int countKills = 0;
			int direct = dirRand(gen);
			if (shot == 0) {
				std::cout << "Вы промахнулись! Теперь очередь компьютера стрелять...\n";
				
				
					if (!searchWounded(&x, &y, p1))
						randomShotPoint(p1, &x, &y, distrib, gen);
					else {
						while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
						{
							if (!searchWounded(&x, &y, p1))
								randomShotPoint(p1, &x, &y, distrib, gen);
						}
						fixMap(p1);
					}
				
				
				std::cout << "Выстрел компьютера: " << x + 1 << " " << y + 1 << "\n";
			}
			shot = p1.shoot(x + 1, y + 1);
			std::cout << p1.mapShips[y][x] << "\n";
			while ((shot > 0 && p1.liveShips > 0 && p2.liveShips > 0)) {
				countKills++;
				std::cout << "Компьютер попал!";
				if (shot == 2) {
					std::cout << "И он подбил ваш корабль!";
					countKills = 0;
					if (searchWounded(&x, &y, p1))
						countKills = 1;
				}
				std::cout << "Он продолжает обстрел...\n";


				if (countKills == 1) {
					if (p1.mapShips[y][x] == -1) {
						while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
						{
							if (!searchWounded(&x, &y, p1))
								randomShotPoint(p1, &x, &y, distrib, gen);
						}
						fixMap(p1);
					}
					else {
						if (!searchWounded(&x, &y, p1))
							randomShotPoint(p1, &x, &y, distrib, gen);
						else {
							while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
							{
								if (!searchWounded(&x, &y, p1))
									randomShotPoint(p1, &x, &y, distrib, gen);
							}
							fixMap(p1);
						}
					}
					shot = p1.shoot(x + 1, y + 1);
					std::cout << p1.mapShips[y][x] << "\n";

				}
				else {
					if (countKills > 1) {
						if (direct == 0 && p1.mapShips[y][x - 1] >= 0)
							x--;
						else
						{
							if (direct == 0 && p1.mapShips[y][x - 1] < 0 && p1.mapShips[y][x - 1] > -4)
							{
								
								while (p1.mapShips[y][x] < 0 && x > -1)
									x--;
							}
							if (direct == 0 && x == 0)
							{
								while (p1.mapShips[y][x] < 0 && x < 11)
									x++;
							} 
							if (x == 10 || x == -1) {
								if (!searchWounded(&x, &y, p1))
									randomShotPoint(p1, &x, &y, distrib, gen);
								else {
									while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
									{
										if (!searchWounded(&x, &y, p1))
											randomShotPoint(p1, &x, &y, distrib, gen);
									}
									fixMap(p1);
								}
							}								
						}

						if (direct == 1 && p1.mapShips[y - 1][x] >= 0)
							y--;
						else
						{
							if (direct == 1 && p1.mapShips[y - 1][x] < 0 && p1.mapShips[y - 1][x] > -4)
							{

								while (p1.mapShips[y][x] < 0 && y > -1)
									y--;
							}
							if (direct == 1 && y == 0)
							{
								while (p1.mapShips[y][x] < 0 && y < 11)
									y++;
							}
							if (y == 10 || y == -1) {
								if (!searchWounded(&x, &y, p1))
									randomShotPoint(p1, &x, &y, distrib, gen);
								else {
									while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
									{
										if (!searchWounded(&x, &y, p1))
											randomShotPoint(p1, &x, &y, distrib, gen);
									}
									fixMap(p1);
								}
							}
						}
						if (direct == 2 && p1.mapShips[y][x + 1] >= 0)
							x++;
						else
						{
							if (direct == 2 && p1.mapShips[y][x + 1] < 0 && p1.mapShips[y][x + 1] > -4)
							{
								while (p1.mapShips[y][x] < 0 && x < 11)
									x++;
							}
							if (direct == 0 && x == 9)
							{
								while (p1.mapShips[y][x] < 0 && x > -1)
									x--;
							}
							if (x == 10 || x == -1) {
								if (!searchWounded(&x, &y, p1))
									randomShotPoint(p1, &x, &y, distrib, gen);
								else {
									while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
									{
										if (!searchWounded(&x, &y, p1))
											randomShotPoint(p1, &x, &y, distrib, gen);
									}
									fixMap(p1);
								}
							}
						}
						if (direct == 3 && p1.mapShips[y + 1][x] >= 0)
							y++;
						else
						{
							if (direct == 3 && p1.mapShips[y + 1][x] < 0 && p1.mapShips[y + 1][x] > -4)
							{
								while (p1.mapShips[y][x] < 0 && y < 11)
									y++;
							}
							if (direct == 0 && y == 9)
							{
								while (p1.mapShips[y][x] < 0 && y > -1)
									y--;
							}
							if (y == 10 || y == -1) {
								if (!searchWounded(&x, &y, p1))
									randomShotPoint(p1, &x, &y, distrib, gen);
								else {
									while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
									{
										if (!searchWounded(&x, &y, p1))
											randomShotPoint(p1, &x, &y, distrib, gen);
									}
									fixMap(p1);
								}
							}
						}
						shot = p1.shoot(x + 1, y + 1);
					}
					if (countKills == 0)
					{
						if (!searchWounded(&x, &y, p1))
							randomShotPoint(p1, &x, &y, distrib, gen);
						else {
							while (!choiceRightDirection(p1, &x, &y, &direct, dirRand, gen))
							{
								if (!searchWounded(&x, &y, p1))
									randomShotPoint(p1, &x, &y, distrib, gen);
							}
							fixMap(p1);
						}
						shot = p1.shoot(x + 1, y + 1);
						std::cout << p1.mapShips[y][x] << "\n";

					}
				}
				std::cout << "Выстрел компьютера: " << x + 1 << " " << y + 1 << " " << direct << "\n";

			}

		}
		
		std::cout << "Игра окончена! ";
		if (p1.liveShips == 0)
			std::cout << "К сожалению вы проиграли. ";
		else
			std::cout << "Поздравляем вас с победой! ";
		std::cout << "Хотите начать новую игру?(1 - Да; 0 - Нет)\n";
		std::cin >> repl;
		while (repl != 1 && repl != 0)
		{
			std::cout << "Введите корректное значение\n";
			std::cin >> repl;
		}
	}
		return 0;
}


//1 1
//1
//2 1
//1
//3 1
//1
//4 1
//1
//5 1 r
//1
//7 1 r 
//1
//9 1 r
//1
//1 2 r 
//1
//4 2 r 
//1
//7 2 r
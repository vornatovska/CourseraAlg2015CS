#include <clocale>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include player.h

enum direction{h,v};



// карта розміром в 13 рядків та 29 стовбчиків
const int s = 13, c = 29;
char map[s][c] = {
		"  0123456789     0123456789 ",
		" #----------#   #----------#",
		"0|          |  0|          |",
		"1|          |  1|          |",
		"2|          |  2|          |",
		"3|          |  3|          |",
		"4|          |  4|          |",
		"5|          |  5|          |",
		"6|          |  6|          |",
		"7|          |  7|          |",
		"8|          |  8|          |",
		"9|          |  9|          |",
		" #----------#   #----------#" };

player human;
player computer;

void map_init(char map[s][c]);
void show (char map[s][c]);
int input(char&, char&);
void test();
int check_ending();

char numbers[10] = { '0','1','2','3','4','5','6','7','8','9'};

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int message = 0; // змінна зберігає код повідомлення
	srand( static_cast<unsigned int>(time(NULL)) );

	human.ships_init(); // створення масиву людини
	computer.ships_init(); // створення масиву компютера
	map_init(map); 
	while (message != 2)
	{
		int user_input = 0;
		system("cls"); // очищення екрану
		show(map);     
		if (message == 1) // код повідомлення 1 - введено неправельне значення
			std::cout << "Ви ввели неправильні дані!\n";
		message = 0;   
		

		char character, digit;
		user_input = input(character, digit); 
		if (user_input == 1)
		{
			message = 1;
			continue; 
		}

		human.turn(computer,character, digit);
		computer.turn(human);
		message = check_ending();
	}
	_getch();
	return 0;
}

void map_init(char map[s][c])
{
	for (int i=0;i < 10; i++)
	{
		for (int j=0; j < 10; j++)
		{
			if (human.ships[i][j] == 2)
				map[i+2][j+2] = 'К';
		}
	}
}
void show(char map[s][c])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{			
			if (computer.hits[i][j] == 1 && human.ships[i][j] == 3)
			{
				map[i+2][j+2] = 'Х';
			}
			else if (computer.hits[i][j] == 1 && human.ships[i][j] != 3)
			{
				map[i+2][j+2] = 'О';
			}
			if (computer.ships[i][j] == 3 && human.hits[i][j] == 1)
			{
				map[i+2][j+2+15] = 'Х';
			}
			else if (computer.ships[i][j] != 3 && human.hits[i][j] == 1)
			{
				map[i+2][j+2+15] = 'O';
			}
		} 
	} 
	
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
}
// ввід координат
int input(char& character, char& digit)
{
	character = _getche(); // ввід горизонтальної координати
	int match = 0;
	for (int i = 0; i < 10; i++)
		if (numbers[i] == character)
		{
			match = 1;
			character = i;
		}
	if (match == 0)	
		return 1;
	std::cout << '-';
	match = 0;
	digit = _getche(); // ввід вертикальної координати
	for (int i = 0; i < 10; i++)
		if (numbers[i] == digit)
		{
			match = 1;
			digit = i;
		}
	if (match == 0)
		return 1;
	return 0;	
}

void test()
{
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << human.hits[i][j];
		}
		std::cout << "  ";
		for (int j = 0; j < 10; j++)
		{
			std::cout << computer.hits[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << human.ships[i][j];
		}
		std::cout << "  ";
		for (int j = 0; j < 10; j++)
		{
			std::cout << computer.ships[i][j];
		}
		std::cout << std::endl;
	}
}

int check_ending()
{
	int flag = 0;
	int human_flag = 0;
	int computer_flag = 0;
	for (int i=0; i<10;i++)
	{
		for (int j=0; j<10;j++)
		{
			if (human.ships[i][j] == 2)
				human_flag = 1; // у гравця ше є цілі кораблі
			if (computer.ships[i][j] == 2)
				computer_flag = 1; // в компютера ще є цілі кораблі
		}
	}
	if (human_flag == 0)
		flag = 2;
	if (computer_flag == 0)
		flag = 1;
	if (flag == 1)
	{
		std::cout << "Виграв гравець!\n";
		return 2;
	}
	if (flag == 2)
	{
		std::cout << "Виграв компютер!\n";
		return 2;
	}
}

void player::ships_init()
{
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			ships[i][j] = 1;
			hits[i][j] = 0;
		}
	}

	// розстановка кораблів
	set(4);
	set(3);
	set(3);
	set(2);
	set(2);
	set(2);
	set(1);
	set(1);
	set(1);
	set(1);
}

void player::set (int deck)
{
	int my = deck - 1;
	bool isset = 0;
	int s,c;
	direction dir;
	while (isset == 0) // перевірка чи вдалось розмістити корабель
	{
		dir = static_cast<direction>(rand()%2); // вибираємо напрямок
		
		s = rand()%10; 
		c = rand()%10;
		int e = 0;
		switch (dir)
		{
		case h:
			if (ships[s][c+deck-1] == 1)
			{
				e = place_ship(s,c,dir,deck); 
				if (e == 0)
				{
					for (int i = 0; i < deck; i++)
					{
						ships[s][c+i] = 2; 
					}
					isset = 1;
				}
			}
			break;
		case v:
			if (ships[s+deck-1][c] == 1)
			{
				e = place_ship(s,c,dir,deck);
				if (e == 0)
				{
					for (int i = 0; i < deck; i++)
					{
						ships[s+i][c] = 2;
					}
					isset = 1;
				}
			}
			break;
		} 
	} 
} 


int player::place_ship(int s, int c, direction dir, int deck)
{
	int e = 0;
	switch (dir)
	{
		case h:
		if (ships[s-1][c-1] == 2)
		{
			e = 1;
			
		}
		if (ships[s-1][c+deck] == 2)
		{
			e = 1;
			
		}
		if (ships[s+1][c-1] == 2)
		{
			e = 1;
			
		}
		if (ships[s+1][c+deck] == 2)
		{
			e = 1;
			
		}

		if (ships[s][c-1] == 2)
		{
			e = 1;
			
		}
		if (ships[s][c+deck] == 2)
		{
			e = 1;
			
		}
		for (int i = 0; i < deck; i++)
		{
			if (ships[s-1][c+i] == 2)
			{
				e = 1;	
			}
			if (ships[s+1][c+i] == 2)
			{
				e = 1;
			}
		}
		break;
	case v:
		if (ships[s-1][c-1] == 2)
		{
			e = 1;		
		}
		if (ships[s-1][c+1] == 2)
		{
			e = 1;
		}
		if (ships[s+deck][c-1] == 2)
		{
			e = 1;
		}
		if (ships[s+deck][c+1] == 2)
		{
			e = 1;	
		}
		if (ships[s-1][c] == 2)
		{
			e = 1;	
		}
		if (ships[s+deck][c] == 2)
		{
			e = 1;
		}
		for (int i = 0; i < deck; i++)
		{
			if (ships[s+i][c-1] == 2)
			{
				e = 1;
			}
			if (ships[s+i][c+1] == 2)
			{
				e = 1;
			}
		}
		break;
	}
	return e;
}
void player::turn(player& enemy)
{
	bool flag = 0;
	while (flag == 0)
	{
		int character = rand()%10; // координати по яких стрілятиме компютер
		int digit = rand()%10;     // рандом
		if (hits[character][digit] != 1) // перевірка, чи не вибирав компютер ці координати
		{
			hits[character][digit] = 1;
			flag = 1;
			if (enemy.ships[character][digit] == 2)
			{
				enemy.ships[character][digit] = 3;
			}
		}
	}
}

void player::turn(player& enemy, int character, int digit)
{
	hits[character][digit] = 1;
	if (enemy.ships[character][digit] == 2)
	{
		enemy.ships[character][digit] = 3;
	}
}

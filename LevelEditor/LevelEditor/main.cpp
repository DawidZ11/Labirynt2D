#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

bool board[100][100];
bool check[100][100];
int sx, sy;
char chboard;

std::string fileName;

std::fstream file;

int posx = 0, posy = 0, sizex = 0, sizey = 0;

float rposx, rposy, rsizex, rsizey;

void drawBoard()
{
	for (int i = 0; i < sy; i++)
	{
		for (int j = 0; j < sx; j++)
		{
			if (board[i][j] == false)
				std::cout << "[ ]";
			else
				std::cout << "[#]";
		}
		std::cout << std::endl;
	}
}

void checkboard()
{
	for (int i = 0; i < sy; i++)
	{
		for (int j = 0; j < sx; j++)
		{
			if (check[i][j] == false)
				std::cout << "[ ]";
			else
				std::cout << "[#]";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::cout << "Nazwa planszy: ";
	std::cin >> fileName;

	system("cls");

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			board[i][j] = false;
			check[i][j] = false;
		}

	file.open(fileName, std::ios::out);
	if (!file.good())
		return -1;

	std::cout << "Rozmiar planszy: ";
	std::cin >> sx >> sy;

	while (posx >= 0)
	{
		system("cls");
		drawBoard();

		std::cout << "Sciana(x, y, w, h): ";
		std::cin >> posx >> posy >> sizex >> sizey;

		posx--;
		posy--;


		if (posx < 0)
			break;

		for(int i = posy; i < posy+sizey; i++)
			for(int j = posx; j < posx+sizex; j++)
				check[i][j] = true;

		system("cls");
		checkboard();
		std::cout << std::endl << "OK?(t/n): ";
		std::cin >> chboard;

		if (chboard == 't')
		{

			for (int i = 0; i < sx; i++)
				for (int j = 0; j < sy; j++)
				{
					board[i][j] = check[i][j];
				}

			rposx = (float)posx / (float)sx;
			rposy = (float)posy / (float)sy;

			rsizex = (float)sizex / (float)sx;
			rsizey = (float)sizey / (float)sy;

			file << rposx << std::endl << rposy << std::endl << rsizex << std::endl << rsizey << std::endl << std::endl;
		}
		else
		{
			for (int i = 0; i < sx; i++)
				for (int j = 0; j < sy; j++)
				{
					check[i][j] = board[i][j];

				}
		}
	}

	file.close();

	std::cin.get();
	std::cin.get();
	return 0;
}
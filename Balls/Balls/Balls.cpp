#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

CONST std::string NAME_OUTPUT_FILE = "OUTPUT.txt";
CONST std::string MESSAGE_INPUT_NAME_FILE = "Введите имя входного файла: ";
CONST std::string MESSAGE_ERROR_NO_FILE = "Файл не существует!";
CONST std::string MESSAGE_ERROR_NO_BALLS = "Нет ни одного шара!";
CONST std::string MESSAGE_ERROR_OVERFLOW = "Максимальное число шаров - 100000!";
CONST int ERROR_NO_FILE = 1;
CONST int ERROR_NO_BALLS = 2;
CONST int ERROR_OVERFLOW = 3;
CONST char RUSSIAN_LANGUAGE[] = "RUS";

std::string GetUserAnswer()
{
	std::string fileName;
	std::cout << MESSAGE_INPUT_NAME_FILE;
	std::cin >> fileName;
	return fileName;
}

int main()
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	std::string fileName;
	fileName = GetUserAnswer();
	std::fstream fileInput(fileName);

	if (!fileInput.good())
	{
		std::cout << MESSAGE_ERROR_NO_FILE;
		return ERROR_NO_FILE;
	}

	int numberOfBalls = 0;
	fileInput >> numberOfBalls;

	if (numberOfBalls == 0)
	{
		std::cout << MESSAGE_ERROR_NO_BALLS;
		return ERROR_NO_BALLS;
	}

	if (numberOfBalls > 100000)
	{
		std::cout << MESSAGE_ERROR_OVERFLOW;
		return ERROR_OVERFLOW;
	}

	char dirBall = ' ';
	int dirBallRight = 0;
	int numberCollisions = 0;

	for (int i = 0; i <= numberOfBalls; i++)
	{
		fileInput.get(dirBall);
		if (dirBall == '>')
		{
			dirBallRight++;
		}
		if (dirBall == '<')
		{
			numberCollisions += dirBallRight;
		}
	}

	std::ofstream fileOutput(NAME_OUTPUT_FILE);
	fileOutput << numberCollisions;

	return 0;
}
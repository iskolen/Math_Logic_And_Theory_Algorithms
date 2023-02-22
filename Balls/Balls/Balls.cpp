/*
	Петров Вадим ПС-22
	Вариант 14.17. Шары (5)
	Задача:
		По горизонтально расположенному желобу бесконечной длины катятся с 
		одинаковой скоростью N металлических шаров (1 ≤ N ≤ 105). 
		Некоторые шары катятся вправо, некоторые влево. Сталкиваясь, 
		шары испытывают абсолютно упругое соударение (то есть меняют направление движения, 
		сохраняя скорость). Зная расположение шаров в желобе  и направление их движения, 
		сосчитать количество столкновений (соударений) пар шаров.
	Среда разработки: Microsoft Visual Studio 2017
*/

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

CONST std::string NAME_OUTPUT_FILE = "OUTPUT.txt";
CONST std::string MESSAGE_INPUT_NAME_FILE = "Введите имя входного файла: ";
CONST std::string MESSAGE_ERROR_NO_FILE = "Файл не существует!";
CONST std::string MESSAGE_ERROR_NO_BALLS = "Минимальное число шаров - 1!";
CONST std::string MESSAGE_ERROR_OVERFLOW = "Максимальное число шаров - 100000!";
CONST std::string MESSAGE_ERROR_WRONG_CHAR = "Введён некорректный символ, допустимые - '>','<'";
CONST int ERROR_NO_FILE = 1;
CONST int ERROR_NO_BALLS = 2;
CONST int ERROR_OVERFLOW = 3;
CONST int ERROR_WRONG_CHAR = 4;
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

	if (numberOfBalls > 100000)
	{
		std::cout << MESSAGE_ERROR_OVERFLOW;
		return ERROR_OVERFLOW;
	}
	if (numberOfBalls < 1)
	{
		std::cout << MESSAGE_ERROR_NO_BALLS;
		return ERROR_NO_BALLS;
	}

	char dirBall = ' ';
	int dirBallRight = 0;
	long long numberCollisions = 0;

	fileInput.get();
	for (int i = 1; i <= numberOfBalls; i++)
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
		if (dirBall != '>' && dirBall != '<')
		{
			std::cout << MESSAGE_ERROR_WRONG_CHAR;
			return ERROR_WRONG_CHAR;
		}
	}

	std::ofstream fileOutput(NAME_OUTPUT_FILE);
	fileOutput << numberCollisions;

	return 0;
}
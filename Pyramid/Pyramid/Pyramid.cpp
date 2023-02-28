/*
	Петров Вадим ПС-22
	Вариант 4.2. Пирамида (5)
	Задача:
		Ниже изображен пример пирамиды или треугольника из чисел. 
		Найти наибольшую сумму чисел, расположенных на пути из 
		верхней точки треугольника до основания. 
                        
						7
					  3	  8
					8   1   6
				  4   2   3   0

		Каждый шаг на пути происходит в направлении вниз по диагонали 
		(влево или вправо). Треугольник составлен из целых чисел от -10^5 до 10^5.
	Среда разработки: Microsoft Visual Studio 2017
*/

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

CONST std::string NAME_OUTPUT_FILE = "OUTPUT.txt";
CONST std::string MESSAGE_INPUT_NAME_FILE = "Введите имя входного файла: ";
CONST std::string MESSAGE_ERROR_MIN_LINE = "Минимальное количество строк - 1!";
CONST std::string MESSAGE_ERROR_MAX_LINE = "Максимальное количество строк - 300!";
CONST std::string MESSAGE_ERROR_NO_FILE = "Файл не существует!";
CONST int ERROR_NO_FILE = 1;
CONST int ERROR_MIN_LINE = 2;
CONST int ERROR_MAX_LINE = 3;
CONST char RUSSIAN_LANGUAGE[] = "RUS";

std::string GetUserAnswer()
{
	std::string fileName;
	std::cout << MESSAGE_INPUT_NAME_FILE;
	std::cin >> fileName;
	return fileName;
}

std::vector <int> path;

int MaxNumberOfPath(int tri[300][300], int m, int n)
{
	path.push_back(tri[0][0]);
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (tri[i + 1][j] > tri[i + 1][j + 1])
			{
				path.push_back(tri[i][j]);
				tri[i][j] += tri[i + 1][j];
			}
			else
			{
				tri[i][j] += tri[i + 1][j + 1];
			}
		}
	}
	return tri[0][0];
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

	int numberOfLines = 0;
	int maxNumber = 0;
	fileInput >> numberOfLines;

	if (numberOfLines < 1)
	{
		std::cout << MESSAGE_ERROR_MIN_LINE;
		return ERROR_MIN_LINE;
	}

	if (numberOfLines > 300)
	{
		std::cout << MESSAGE_ERROR_MAX_LINE;
		return ERROR_MAX_LINE;
	}

	int tri[300][300] = { 0 };
	fileInput.get();
	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			fileInput >> tri[i][j];
		}
		fileInput.get();
	}

	maxNumber = MaxNumberOfPath(tri, numberOfLines, numberOfLines);

	std::ofstream fileOutput(NAME_OUTPUT_FILE);
	fileOutput << maxNumber;
	fileOutput << std::endl;
	for (int i = 0; i < path.size(); i++) {
		fileOutput << path[i] << " ";
	}

	return 0;
}
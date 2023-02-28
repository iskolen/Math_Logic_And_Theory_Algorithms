/*
	Петров Вадим ПС-22
	Вариант 3.1. Что в имени твоем? (5)
	Задача:
		В алфавите племени мумба-юмба только три буквы, которые обозначаются как A, B и D.
		Юношам в день совершеннолетия принято давать взрослые имена, 
		состоящие ровно из N букв (1 ≤ N ≤ 35). Повторение букв в имени не ограничивается. 
		Если юноша не может представить вождю скальп врага, 
		то в имени присутствует подстрока BAD (возможно, в нескольких экземплярах), 
		иначе такие имена категорически запрещаются. 
		Сколько разных имен может быть в племени мумба-юмба для юношей, 
		запоздавших в развитии (не представивших скальп)?
	Среда разработки: Microsoft Visual Studio 2017
*/

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

CONST std::string NAME_OUTPUT_FILE = "OUTPUT.txt";
CONST std::string MESSAGE_INPUT_NAME_FILE = "Введите имя входного файла: ";
CONST std::string MESSAGE_ERROR_MIN_LETTER = "Минимальное количество букв - 1!";
CONST std::string MESSAGE_ERROR_MAX_LETTER = "Максимальное количество букв - 35!";
CONST std::string MESSAGE_ERROR_NO_FILE = "Файл не существует!";
CONST int ERROR_NO_FILE = 1;
CONST int ERROR_MIN_LETTER = 2;
CONST int ERROR_MAX_LETTER = 3;
CONST char RUSSIAN_LANGUAGE[] = "RUS";

std::string GetUserAnswer()
{
	std::string fileName;
	std::cout << MESSAGE_INPUT_NAME_FILE;
	std::cin >> fileName;
	return fileName;
}

int FindNumberOfNames(int numberOfLetters)
{
	int numberOfNames = 0;
	int numer;
	
	numer = std::pow(3, numberOfLetters);
	std::cout << numer;

	return numberOfNames;
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

	int numberOfLetters = 0;
	long long numberOfNames = 0;
	fileInput >> numberOfLetters;

	if (numberOfLetters < 1)
	{
		std::cout << MESSAGE_ERROR_MIN_LETTER;
		return ERROR_MIN_LETTER;
	}

	if (numberOfLetters > 35)
	{
		std::cout << MESSAGE_ERROR_MAX_LETTER;
		return ERROR_MAX_LETTER;
	}

	numberOfNames = FindNumberOfNames(numberOfLetters);

	std::ofstream fileOutput(NAME_OUTPUT_FILE);
	fileOutput << numberOfNames;

	return 0;
}
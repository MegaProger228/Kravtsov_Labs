/*
Кравцов Владислав Дмитриевич
Лабораторная работа №3.
Вариант №8
Задание:Написать программу, которая во вводимом с клавиатуры тексте удалит все пробелы,
знаки табуляции и выведет количество удаленных символов на экран.
*/

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "conio.h"

#define SIZE 256

void get_string_and_size(char*);
void delete_symbols(char*);

int main(void)
{
	char defaultString[SIZE];

	get_string_and_size(defaultString); //Получение строки
	
	delete_symbols(defaultString);

	_getch();
	return 0;
}

void get_string_and_size(char *string)
{
	int  sizeOfString, countOfTabSymbols = 0;
	printf("Enter text: ");
	fgets(string, SIZE, stdin);
	sizeOfString = strlen(string);
	while (sizeOfString <= 2) // Ввод Предложения
	{
		printf("Too short string. Try again: ");
		fgets(string, SIZE, stdin);
		sizeOfString = strlen(string);
	}
}
void delete_symbols(char *string)
{
	int  sizeOfString, countOfDeletedSymbols = 0, k = 0;
	char changedString[SIZE];
	sizeOfString = strlen(string);

	for (int i = 0; i < sizeOfString; i++) //Подсчет всех пробелов и знаков табуляции
	{
		if (string[i] == ' ' || string[i] == '\t' || string[i] == '\v')
		{
			countOfDeletedSymbols++;
		}
		else
		{
			changedString[k] = string[i];
			k++;
		}
	}
	changedString[k] = '\0';
	printf("Changed string : %s\nCount of deleted symbols : %d.", changedString, countOfDeletedSymbols);
}
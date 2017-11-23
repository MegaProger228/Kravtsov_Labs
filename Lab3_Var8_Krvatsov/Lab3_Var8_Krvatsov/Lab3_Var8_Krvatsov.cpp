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

int main(void)
{
	int  SizeOfString, CountOfSymbols = 0;
	char DefaultString[SIZE], ChangedString[SIZE] = "";
	printf("Enter text: ");
	fgets(DefaultString, 256, stdin);
	SizeOfString = strlen(DefaultString);
	while (SizeOfString <= 2) // Ввод Предложения
	{
		printf("Too short string. Try again: ");
		fgets(DefaultString, 256, stdin);
		SizeOfString = strlen(DefaultString);
	}
	printf("\nResult string: ");
	for (int i = 0; i < SizeOfString; i++) //Подсчет всех пробелов и знаков табуляции
	{
		if (DefaultString[i] == ' ' || DefaultString[i] == '\t' || DefaultString[i] == '\v')
		{
			CountOfSymbols++;
		}
		else
		{
			printf("%c", DefaultString[i]);
		}
	}
	printf("\n");
	printf("\nCount of deleted symbols %d", CountOfSymbols);
	_getch();
	return 0;
}
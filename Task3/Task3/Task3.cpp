/*

Кравцов Владислав Дмитриевич

Лабораторная работа №2.

Вариант №8

Задание:Написать программу, которая построчно выводит сумму первого и последнего, второго и предпоследнего и т.д.
элементов массива. Если количество элементов нечетное, то в конце выводит центральный элемент массива.

Массив и его длина вводятся пользователем.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "conio.h"
#include "windows.h"
#define SIZE 100
int scanf_check_int();

int main()

{
	int Array[SIZE] = { 0 }, summ = 0, length = 0;
	printf("Please, enter the lenght of the array: ");
	length = scanf_check_int();
	while (length < 0)
	{
		printf("Please try again and enter a positive number: ");
		length = scanf_check_int();
	}
	for (int i = 0; i < length; i++)
	{
		printf("Please enter element %d: ", i);
		Array[i] = scanf_check_int();
	}
	for (int i = 0; i < length / 2; i++)
	{
		summ = Array[i] + Array[length - i - 1];
		printf("Summ of %d and %d element is %d (%d + %d = %d) \n", i, length - i - 1, summ, Array[i], Array[length - i - 1], summ);
	}
	if (length % 2 == 1)
	{
		printf("Center element (with number %d) is %d",length / 2, Array[length / 2]);
	}
	_getch();
	return 0;
}
int scanf_check_int()
{
	int number;
	while (!scanf("%d", &number))
	{
		while (getchar() != '\n');
		printf("Please try again and enter a positive number: ");
	}
	if (getchar() != '\n')
	{
		while (getchar() != '\n');
		printf("Please try again and enter a positive number: ");
		number = scanf_check_int();
	}
	return number;
}


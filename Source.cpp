#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

#include <stdio.h>
#include <conio.h>

#define DYUMS  39370.08
#define YARDS 1093.61

using namespace std;

int main()

{

	printf("Type count of km \n");
	float yards = 0.0, dyums = 0.0/*, YARDS = 1093.61, DYUMS = 39370.08*/;
	float kilometers;
	scanf_s("%f", &kilometers); 

	// Получение и вывод ярдов
	yards = kilometers * YARDS;
	printf("Count of yards = ");
	printf("%f", yards);
	printf("\n");


	// Получение и вывод дюймов
	dyums = kilometers * DYUMS;
	printf("Count of dyums = ");
	printf("%f", dyums);
	printf("\n");


	_getch();

	return 0;

}

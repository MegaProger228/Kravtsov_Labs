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
	//scanf_s("%f", &kilometers); 

	int result = scanf_s("%f", &kilometers);

	if (result == 1)
	{
		yards = kilometers * YARDS;
		printf("Count of yards = ");
		printf("%f", yards);
		printf("\n");



		dyums = kilometers * DYUMS;
		printf("Count of dyums = ");
		printf("%f", dyums);
		printf("\n");


		_getch();
	}
	else
		printf("You typed wrong value! \n");
	return 0;

}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>


#define DYUMS  39370.08
#define YARDS 1093.61


using namespace std;

int main()
{
	printf("Type count of km \n");
	double yards = 0, dyums = 0;
	int kilometers;
	scanf("%d", &kilometers); // %d - для ввода целых, %f - для ввода вещественных


	//  Получение ярдов
	yards = kilometers * YARDS;
	printf("%f", &yards);
	printf("\n");


	//  Получение дюймов
	dyums = kilometers * DYUMS;
	printf("%f", &dyums);
	printf("\n");



	_getch();
	return 0;
}


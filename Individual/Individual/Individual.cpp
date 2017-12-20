#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <time.h>

#define COUNT 5

struct Aminities_st
{
	char name[1000];
	char code[1000];
	char price[1000];
	char points[1000];

};

struct Used_aminities_st
{
	char t_number[11];
	char code[1000];
	char date[1000];
	char time[1000];
	char time_of_using[1000];
	int converted_time_of_using;
	int count = 0;
};

struct Clients_st
{
	char name[1000];
	char t_number[11];
	char date_s[11];
	char date_e[11];
	char bill[1000];
	char credit[1000];
};

struct Settings
{
	char code_1[1000];
	char code_2[1000];
};

struct Date
{
	char day[3];
	char month[3];
	char year[5];
};


int file_not_exist(FILE*, FILE*, FILE*, FILE*);
void fill_data(Clients_st*, Aminities_st*, Used_aminities_st*, FILE*, FILE*, FILE*);
void fill_clients(Clients_st*, FILE*);
void fill_aminities(Aminities_st*, FILE*);
void fill_used_aminities(Used_aminities_st*, FILE*);
void convert_time_of_using(Used_aminities_st*);
int CharToInt32(char*);
int Compare(char*, char*);
int Compare_date(int, int, char*);
void Report( char*, char*,Clients_st*, Aminities_st*, Used_aminities_st*,  FILE*);

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE *clients = NULL;
	FILE *aminities = NULL;
	FILE *used_aminities = NULL;
	FILE *report = NULL;

	clients = fopen("Clients.txt", "r");
	aminities = fopen("Aminities.txt", "r");
	used_aminities = fopen("Used_aminities.txt", "r");
	report = fopen("Report.txt", "w");

	if (file_not_exist(clients, aminities, used_aminities, report))
	{
		return 0;
	}

	struct Clients_st people[10];
	struct Aminities_st amin[50];
	struct Used_aminities_st used_amin[50];
	struct Settings settings = {"", ""};
	struct Date dt;

	
	fill_data(people, amin, used_amin, clients, aminities, used_aminities); // Filling structures with data.

	fclose(clients);
	fclose(aminities);
	fclose(used_aminities);

	convert_time_of_using(used_amin);//Converting data from string to int32

	printf("Type first rate code: ");
	scanf("%s", settings.code_1);
	printf("\nType second rate code: ");
	scanf("%s", settings.code_2);

	Report(settings.code_1, settings.code_2, people, amin, used_amin, report);


	fclose(report);
	return 0;
}

int file_not_exist(FILE *clients, FILE *aminities, FILE *used_aminities, FILE *report)
{
	if (clients == NULL || aminities == NULL || used_aminities == NULL || report == NULL)
	{
		printf("One or more files does not exist! Check your data!\n\n");
		return true;
	}
	{
		printf("All files were succesfully found!\n\n");
		return false;
	}
}
void fill_clients(Clients_st *people, FILE *clients)
{
	char chr[1000];
	int k = 0, s = 0;
	for (int i = 0; i < COUNT; i++){
		fgets(chr, 1000, clients);
		if (!feof(clients))
		{
			chr[strlen(chr) - 1] = ',';
		}
		//Getting name
		while (chr[k] != ',')
		{
			people[i].name[k] = chr[k];
			k++;
		}
		people[i].name[k] = '\0';
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}
		//Getting telephone number
		while (chr[k] != ',')
		{
			people[i].t_number[s] = chr[k];
			k++;
			s++;
		}
		people[i].t_number[s] = '\0';
		k += 2;
		s = 0;

		//Getting date of starting deal
		while (chr[k] != ',')
		{
			people[i].date_s[s] = chr[k];
			s++;
			k++;
		}
		people[i].date_s[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting date of ending deal
		while (chr[k] != ',')
		{
			people[i].date_e[s] = chr[k];
			s++;
			k++;
		}
		people[i].date_e[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting bill
		while (chr[k] != ',')
		{
			people[i].bill[s] = chr[k];
			s++;
			k++;
		}
		people[i].bill[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting credit
		while (chr[k] != ',' && k != strlen(chr))
		{
			people[i].credit[s] = chr[k];
			s++;
			k++;
		}
		people[i].credit[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}




		//printf("%s %s %s %s %s %s\n", people[i].name, people[i].t_number, people[i].date_s, people[i].date_e, people[i].bill, people[i].credit);
		k = 0;
	}
}
void fill_aminities(Aminities_st *amin, FILE *aminities)
{
	char rd[1000], chr[1001];
	int k = 0, s = 0, sch = 0;
	while (!feof(aminities)) {
		fgets(rd, 1000, aminities);
		strcpy(chr, rd);
		if (!feof(aminities))
		{
			chr[strlen(rd) - 1] = ',';
		}
		

		//Getting name
		while (chr[k] != ',')
		{
			amin[sch].name[k] = chr[k];
			k++;
		}
		amin[sch].name[k] = '\0';
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}
		
		//Getting code
		while (chr[k] != ',')
		{
			amin[sch].code[s] = chr[k];
			k++;
			s++;
		}
		amin[sch].code[s] = '\0';
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}
		s = 0;

		//Getting price
		while (chr[k] != ',')
		{
			amin[sch].price[s] = chr[k];
			k++;
			s++;
		}
		amin[sch].price[s] = '\0';
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}
		s = 0;

		//Getting points
		while (chr[k] != ',')
		{
			amin[sch].points[s] = chr[k];
			k++;
			s++;
		}
		amin[sch].points[s] = '\0';
		s = 0;
		//printf("%s %s %s %s\n", amin[sch].name, amin[sch].code, amin[sch].price, amin[sch].points);
		sch++;
		k = 0;
	}
}
void fill_used_aminities(Used_aminities_st *used_amin, FILE *used_aminities)
{
	char rd[1000], chr[1001];
	int k = 0, s = 0, sch = 0;
	while (!feof(used_aminities)) {
		fgets(rd, 1000, used_aminities);
		strcpy(chr, rd);
		if (!feof(used_aminities))
		{
			chr[strlen(rd) - 1] = ',';
		}

		//Getting telephone number
		while (chr[k] != ',')
		{
			used_amin[sch].t_number[k] = chr[k];
			k++;
		}
		used_amin[sch].t_number[k] = '\0';
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting code
		while (chr[k] != ',')
		{
			used_amin[sch].code[s] = chr[k];
			k++;
			s++;
		}
		used_amin[sch].code[s] = '\0';
		k++;
		s = 0;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting date
		while (chr[k] != ',')
		{
			used_amin[sch].date[s] = chr[k];
			k++;
			s++;
		}
		used_amin[sch].date[s] = '\0';
		s = 0;
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting time
		while (chr[k] != ',')
		{
			used_amin[sch].time[s] = chr[k];
			k++;
			s++;
		}
		used_amin[sch].time[s] = '\0';
		s = 0;
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}

		//Getting time of using
		while (chr[k] != ',')
		{
			used_amin[sch].time_of_using[s] = chr[k];
			s++;
			k++;
		}
		used_amin[sch].time_of_using[s] = '\0';
		s = 0;
		k++;
		if (chr[k] == ' ')
		{
			k++;
		}

		//printf("{%s} {%s} {%s} {%s} {%s} {%d}\n", used_amin[sch].t_number, used_amin[sch].code, used_amin[sch].date, used_amin[sch].time, used_amin[sch].time_of_using, sch);
		k = 0;
		sch++;
		used_amin[1].count++;
	}
}
void fill_data(Clients_st *people, Aminities_st *amin, Used_aminities_st *used_amin, FILE *clients, FILE *aminities, FILE *used_aminities)
{
	fill_clients(people, clients);
	fill_aminities(amin, aminities);
	fill_used_aminities(used_amin, used_aminities);
	printf("Data was loaded succesfully\n\n");
}
void convert_time_of_using(Used_aminities_st *used_amin)
{
	for (int i = 0; i < used_amin[1].count; i++)
	{
		used_amin[i].converted_time_of_using = CharToInt32(used_amin[i].time_of_using);
	}
}
int CharToInt32(char *x)
{
	if (x != "#")
	{
		int len = strlen(x), razr = 1, res = 0;
		for (int i = 0; i < len - 1; i++)
		{
			razr *= 10;
		}

		for (int i = 0; i < len; i++)
		{
			switch (x[i])
			{
			case '1': {res += razr; razr /= 10; break; }
			case '2': {res += 2 * razr; razr /= 10; break; }
			case '3': {res += 3 * razr; razr /= 10; break; }
			case '4': {res += 4 * razr; razr /= 10; break; }
			case '5': {res += 5 * razr; razr /= 10; break; }
			case '6': {res += 6 * razr; razr /= 10; break; }
			case '7': {res += 7 * razr; razr /= 10; break; }
			case '8': {res += 8 * razr; razr /= 10; break; }
			case '9': {res += 9 * razr; razr /= 10; break; }
			case '0': {razr /= 10; break; }
			}
		}
		return res;
	}
	else
		return 1;
}
int Compare(char *a, char *b)
{
	if (strlen(a) == strlen(b))
	{
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] != b[i])
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}
int Compare_date(int m, int y, char *b)
{
	char month[3] = { b[3], b[4], '\0' }, year[5] = { b[6], b[7], b[8], b[9], '\0' };
	if (CharToInt32(month) == m && CharToInt32(year) == y)
	{
		return true;
	}
	else 
		return false;
}
void Report(char *ami1, char *ami2, Clients_st *clients, Aminities_st *aminities, Used_aminities_st *used_aminities, FILE *report)
{
	time_t t;
	struct tm *nabor;
	time(&t);
	nabor = localtime(&t);
	int year;
	int month;
	year = nabor->tm_year += 1900;
	month = nabor->tm_mon + 1;

	int summ = 0, summ_each = 0;
	for (int i = 0; i < COUNT; i++)
	{
		for (int j = 0; j < used_aminities[1].count; j++)
		{
			if (Compare(used_aminities[j].t_number, clients[i].t_number) && (Compare(used_aminities[j].code, ami1) ||Compare(used_aminities[j].code, ami2)) && Compare_date(month, year, used_aminities[j].date))
			{
				summ_each += used_aminities[j].converted_time_of_using;
			}
		}
		fprintf(report, "User %s was using this function by %d seconds\n", clients[i].name, summ_each);
		summ += summ_each;
		summ_each = 0;
	}
	fprintf(report, "All users was using this function by %d seconds\n", summ);
}
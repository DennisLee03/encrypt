#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <math.h>
double MyRand(double a, double b);
int main()
{
	FILE *f1, *f2;
	char txt[5000];
	int txtcode[5000], shift[5000];
	int i, j;
	int len, pickseed;
	f1 = fopen("letter.txt", "r");
	f2 = fopen("w_06_code.txt", "w");
	if (f1 == NULL) printf("Cannot open file - letter.txt\n");
	if (f2 == NULL) printf("Cannot open file - w_06_code.txt\n");
	j = 0;
	while (fscanf(f1, "%c", &txt[j]) != EOF)
	{
		j++;
	}
	txt[j] = '\0';
	len = strlen(txt);
	printf("The total no. of characters are %d\n", len);
	if (len <= 1000)
	{
		printf("Please add more words in your letter.\n");
		exit(0);
	}
	cout << "Please input your 8 digits student ID No. (excluding English character)"
		<< endl;
	cin >> pickseed;
	srand(pickseed);
	for (i = 0; i<len; i++)
	{
		shift[i] = (int)(MyRand(0, 5));
		switch (shift[i])
		{
		case(0) :
			txtcode[i] = ~txt[i];
			break;
		case(1) :
		case(3) :
		case(5) :
			txtcode[i] = txt[i] << shift[i];
			break;
		case(2) :
			txtcode[i] = txt[i] + 104;
			break;
		case(4) :
			txtcode[i] = txt[i] - 2022;
			break;
		}
		fprintf(f2, "%10d", txtcode[i]);
		fprintf(f2, "%10d\n", shift[i]);
	}
	fclose(f1);
	fclose(f2);
	cout << "Your letter has been encrypted and saved in w_063_code.txt" << endl;
	return(0);
}
double MyRand(double a, double b)
{
	return((b - a + 1)*rand() / (double)RAND_MAX + a);
}
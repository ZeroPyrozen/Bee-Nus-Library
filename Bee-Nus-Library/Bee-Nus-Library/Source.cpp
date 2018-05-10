#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<Windows.h>

struct Shelf
{
	char bookTitle[40];
	char bookAuthor[40];
	char bookISBN[30];
	char bookPublisher[40];
	char bookDescription[100];
	int bookYear;
	bool isAvailable;
	struct Shelf *left, *right;
}*root = NULL;
void spacing()
{
	int i;
	for (i = 0; i < 25; i++)
		puts("");
}
void titleScreen()
{
	printf("____  _____  _____  __  __ __ __   __   __    __ ____  _____   ___  _____ _  _\n");
	printf("||=)  ||==   ||==   ||\\ || || ||  ((    ||    || ||=)  ||_//  ||=|| ||_// \\\\// \n");
	printf("||_)) ||___  ||___  || \\|| \\\\_// \\_))   ||__| || ||_)) || \\\\  || || || \\\\  //  \n");
	printf("\n");
	printf("\n");
}
void adminMenu()
{
	int menu;
	do
	{
		system("cls");
		spacing();
		printf("\t\t[Logged in as Admin]\n\n1. Insert New Book\n2. Search Book\n3. ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			break;
		case 2:
			break;
		}
	} while (menu != 0);

}
int main()
{
	int menu;
	titleScreen();
	getchar();
	do
	{
		system("cls");
		spacing();
		printf("\t\t[BeeNUS Library]\n\n1. Login as Admin\n2. Login as User\n3. Exit\nChoose [1..3]: ");
		scanf("%d", &menu);
		fflush(stdin);
		switch (menu)
		{
		case 1:
			break;
		case 2:
			break;
		}
	} while (menu != 3);
	return 0;
}
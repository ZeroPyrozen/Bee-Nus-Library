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
	int bookQuantity;
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

void insertNodeTree(struct Shelf** node)
{

}

void adminMenu()
{
	int menu;
	do
	{
		system("cls");
		spacing();
		printf("\t\t[Logged in as Admin]\n\n1. Search Book\n2. Insert New Book\n3. Update Book Information\n4. Remove Book from Database\n0. Exit\nChoose [0..4]: ");
		scanf("%d", &menu);
		fflush(stdin);
		switch (menu)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			break;
		}
	} while (menu != 0);
}

void userMenu()
{
	int menu;
	do
	{
		system("cls");
		spacing();
		printf("\t\t[Logged in as User]\n\n1. Search Book\n2. Borrow a Book\n3. Return a Book\nChoose[0..3]: ");
		scanf("%d", &menu);
		fflush(stdin);
		switch (menu)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
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
			adminMenu();
			break;
		case 2:
			userMenu();
			break;
		}
	} while (menu != 3);
	return 0;
}
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
	printf("\n\n\n\t\t\t____  _____  _____  __  __ __ __   __   __    __ ____  _____   ___  _____ _  _\n");
	printf("\t\t\t||=)  ||==   ||==   ||\\ || || ||  ((    ||    || ||=)  ||_//  ||=|| ||_// \\\\// \n");
	printf("\t\t\t||_)) ||___  ||___  || \\|| \\\\_// \\_))   ||__| || ||_)) || \\\\  || || || \\\\  //  \n");
	printf("\n");
	printf("\t\t\t\t\t\tPress \"Enter\" to Continue...\n");
}

void insertNodeTree(struct Shelf** node,char bookTitle[],char bookAuthor[], char bookISBN[], char bookPublisher[], char bookDescription[], int bookYear,int bookQuantity, bool isAvailable)
{
	if (node == NULL)
	{
		*node = (struct Shelf*)malloc(sizeof(struct Shelf));
		(*node)->left = (*node)->right = NULL;
		strcpy((*node)->bookTitle, bookTitle);
		strcpy((*node)->bookAuthor, bookAuthor);
		strcpy((*node)->bookISBN, bookISBN);
		strcpy((*node)->bookPublisher, bookPublisher);
		strcpy((*node)->bookDescription, bookDescription);
		(*node)->bookYear = bookYear;
		(*node)->bookQuantity = bookQuantity;
		(*node)->isAvailable = isAvailable;
	}
	else if (strcmp(bookISBN, (*node)->bookISBN) < 0)
		insertNodeTree(&(*node)->left, bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
	else if (strcmp(bookISBN, (*node)->bookISBN) > 0)
		insertNodeTree(&(*node)->right, bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
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
		rewind(stdin);
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
		printf("\t\t[Logged in as User]\n\n1. Search Book\n2. Borrow a Book\n3. Return a Book\n0. Exit to Main Menu\nChoose[0..3]: ");
		scanf("%d", &menu);
		rewind(stdin);
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
	char loginAdmin[100];
	char loginPass[100];
	titleScreen();
	getchar();
	do
	{
		system("cls");
		spacing();
		printf("\t\t[BeeNUS Library]\n\n1. Login as Admin\n2. Login as User\n3. Exit\nChoose [1..3]: ");
		scanf("%d", &menu);
		rewind(stdin);
		//rewind(stdin);
		switch (menu)
		{
		case 1:
			strcpy(loginAdmin, "");
			strcpy(loginPass, "");
			do
			{
				printf("Insert ID : ");
				scanf("%[^\n]", &loginAdmin);
				rewind(stdin);
			} while (strlen(loginAdmin) < 1);
			do
			{
				printf("Insert Password : ");
				scanf("%[^\n]", loginPass);
				rewind(stdin);
			} while (strlen(loginPass) < 1);
			if (strcmp(loginAdmin, "Admin") == 0 && strcmp(loginPass, "Admin") == 0)
			{
				printf("Welcome Admin!\n");
				Sleep(1000);
				adminMenu();
			}
			else
			{
				printf("Wrong Password and/or ID.\nPress \"Enter to Continue\"...");
				getchar();
			}
				
			break;
		case 2:
			userMenu();
			break;
		}
	} while (menu != 3);
	return 0;
}
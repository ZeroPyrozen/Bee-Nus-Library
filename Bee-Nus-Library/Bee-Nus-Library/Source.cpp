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
	char bookISBN[40];
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

void insertNodeTree(struct Shelf** node, char bookTitle[], char bookAuthor[], char bookISBN[], char bookPublisher[], char bookDescription[], int bookYear, int bookQuantity, bool isAvailable)
{
	if (*node == NULL)
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
struct Shelf* searchNode(struct Shelf**temp, char bookISBN[])
{
	if (*temp == NULL)
		return NULL;
	else if (strcmp((*temp)->bookISBN, bookISBN) == 0)
		return *temp;
	else if (strcmp(bookISBN, (*temp)->bookISBN) < 0)
		searchNode(&(*temp)->left, bookISBN);
	else if (strcmp(bookISBN, (*temp)->bookISBN) > 0)
		searchNode(&(*temp)->right, bookISBN);
}
void addNewBook()
{
	char bookTitle[100];
	char bookAuthor[100];
	char bookISBN[100];
	char bookPublisher[100];
	char bookDescription[100];
	int bookYear;
	int bookQuantity;
	int flag, i, length;
	bool isAvailable;
	system("cls");
	spacing();
	do
	{
		flag = 0;
		printf("Insert Book Title [Max 40 Chars]: ");
		scanf("%[^\n]", &bookTitle);
		rewind(stdin);
		if (strlen(bookTitle) < 1 || strlen(bookTitle) > 40)
			printf("Please Insert Book Title with Less than 40 Characters!\n");
		else
			flag = 1;
	} while (flag == 0);
	do
	{
		flag = 0;
		printf("Insert Book Author\'s Name [Max 40 Chars]: ");
		scanf("%[^\n]", &bookAuthor);
		rewind(stdin);
		if (strlen(bookAuthor) < 1 || strlen(bookAuthor) > 40)
			printf("Please Insert Author\'s Name with Less than 40 Characters!\n");
		else
			flag = 1;
	} while (flag == 0);
	do
	{
		flag = 0;
		printf("Insert Book\'s ISBN [10/13 Digits]: ");
		scanf("%s", &bookISBN);
		rewind(stdin);
		if (strlen(bookISBN) != 10 && strlen(bookISBN) != 13)
		{
			printf("Please Insert ISBN with 10 or 13 Digits Only!\n");
			flag = 0;
		}
		else
		{
			flag = 1;
			if (searchNode(&root, bookISBN) == NULL)
			{
				length = strlen(bookISBN);
				for (i = 0; i < length; i++)
				{
					if (!isdigit(bookISBN[i]))
					{
						printf("Please Insert ISBN with Digits Only!\n");
						flag = 0;
						break;
					}
				}
			}
			else
			{
				printf("Please Insert New ISBN Only! [Duplicate ISBN Detected]\n");
				flag = 0;
			}
		}
	} while (flag == 0);
	do
	{
		flag = 0;
		printf("Insert Book Publisher [Max 40 Chars]: ");
		scanf("%[^\n]", &bookPublisher);
		rewind(stdin);
		if (strlen(bookPublisher) > 40 || strlen(bookPublisher) < 1)
			printf("Please Insert Book Publisher with Less than 40 Characters!\n");
		else
			flag = 1;
	} while (flag == 0);
	do
	{
		flag = 0;
		printf("Insert Book Description [Max 70 Chars]: ");
		scanf("%[^\n]", &bookDescription);
		rewind(stdin);
		if (strlen(bookDescription) > 70 || strlen(bookDescription) < 1)
			printf("Please Insert Book Description with Less than 70 Characters!\n");
		else
			flag = 1;
	} while (flag == 0);
	do
	{
		flag = 0;
		printf("Insert Published Year: ");
		scanf("%d", &bookYear);
		rewind(stdin);
		if (bookYear <= 0)
			printf("Please Input Valid Year!\n");
		else
			flag = 1;
	} while (flag == 0);
	do
	{
		flag = 0;
		printf("Insert Book Quantity: ");
		scanf("%d", &bookQuantity);
		rewind(stdin);
		if (bookQuantity <= 0)
			printf("Please Input Valid Quantity!\n");
		else
			flag = 1;
	} while (flag == 0);
	isAvailable = true;
	insertNodeTree(&root, bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
	printf("\n\nSuccessfully Insert New Book!\n\nPress \"Enter\" to Continue...\n");
	getchar();
}
void showDescription(char temp[])
{
	int length, i;
	length = strlen(temp);
	for (i = 0; i < length; i++)
	{
		if (i == 0)
			printf("\t\t%c", temp[i]);
		else if (i % 10 == 0)
		{
			if(isspace(temp[i]))
				printf("\n%c", temp[i]);
			else
				printf("%c", temp[i]);
		}
		else
			printf("%c",temp[i]);
	}
}
void searchByISBN()
{
	char bookISBN[100];
	struct Shelf *temp;
	system("cls");
	spacing();
	printf("Insert Book\'s ISBN [10/13 Digits]: ");
	scanf("%s", &bookISBN);
	rewind(stdin);
	if (strlen(bookISBN) < 1)
	{
		printf("Please Insert ISBN with 10 or 13 Digits Only!\nReturning to Admin Menu...\n");
		Sleep(1000);
	}
	else
	{
		temp = searchNode(&root, bookISBN);
		printf("\t\t\t[Search Result]\n");
		if (temp == NULL)
			printf("Nothing Found!\nReturning to Admin Menu...\n\nPress \"Enter\" to Continue");
		else
		{
			printf("Title				: %s\n", temp->bookTitle);
			printf("Author				: %s\n", temp->bookAuthor);
			printf("ISBN				: %s\n", temp->bookISBN);
			printf("Publisher			: %s\n", temp->bookPublisher);
			printf("Description			: \n\n");
			showDescription(temp->bookDescription);
			printf("\nPublished Year	: %d\n", temp->bookYear);
			printf("Book Quantity		: %d\n", temp->bookQuantity);
			printf("Status				: %s\n", temp->isAvailable ? "Available" : "Borrowed");
			printf("\nPress \"Enter\" to Return to Admin Menu...");
		}
		getchar();
	}
}

void traverseTree(struct Shelf** temp, int counter)
{
	if (*temp == NULL)
		return;
	traverseTree(&(*temp)->left, counter);
	printf("Title				: %s\n", (*temp)->bookTitle);
	printf("Author				: %s\n", (*temp)->bookAuthor);
	printf("ISBN				: %s\n", (*temp)->bookISBN);
	printf("Publisher			: %s\n", (*temp)->bookPublisher);
	printf("Description			: \n\n");
	showDescription((*temp)->bookDescription);
	printf("\nPublished Year	: %d\n", (*temp)->bookYear);
	printf("Book Quantity		: %d\n", (*temp)->bookQuantity);
	printf("Status				: %s\n", (*temp)->isAvailable ? "Available" : "Borrowed");
	if ((counter + 10) % 10 == 0)
	{
		printf("\n\nPage %d\n\n[Showing Data from %d - %d]\n", (counter % 10) + 1, (counter % 10) * 10 + 1, counter+1);
		printf("Press \"Enter\" to Continue to Next Page...\n");
		getchar();
	}
	counter++;
	traverseTree(&(*temp)->left, counter);
}

void printAll()
{
	int i = 0;
	if (root == NULL)
		printf("There is No Data!\nPress \"Enter\" to Continue...");
	else
		traverseTree(&root, i);
	getchar();

}

void adminMenu()
{
	int menu;
	do
	{
		system("cls");
		spacing();
		printf("\t\t[Logged in as Admin]\n\n1. Search Book\n2. Insert New Book\n3. Update Book Information\n4. Remove Book from Database\n5. View All Book[Debug]\n0. Exit\nChoose [0..4]: ");
		scanf("%d", &menu);
		rewind(stdin);
		switch (menu)
		{
		case 1:
			searchByISBN();
			break;
		case 2:
			addNewBook();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printAll();
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
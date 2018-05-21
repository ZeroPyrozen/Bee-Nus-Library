#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<Windows.h>
#include<conio.h>
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
	struct Shelf *nextPT, *prevPT; //For Linked List Push Tail Only
	struct Shelf *nextPQ, *prevPQ; //For Linked List Priority Queue
	struct Shelf *leftBST, *rightBST; //For Binary Search Tree
	struct Shelf *leftAVL, *rightAVL; //For AVL Tree
}*rootBST = NULL,*headPQ=NULL,*tailPQ=NULL,*headPT=NULL,*tailPT=NULL,*rootAVL=NULL;
//Appearance
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

//Insertion Logic
//Binary Search Tree
void insertNodeBST(struct Shelf** node, char bookTitle[], char bookAuthor[], char bookISBN[], char bookPublisher[], char bookDescription[], int bookYear, int bookQuantity, bool isAvailable)
{
	if (*node == NULL)
	{
		//Node Initialization
		*node = (struct Shelf*)malloc(sizeof(struct Shelf));
		(*node)->leftBST = (*node)->rightBST = NULL;
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
		insertNodeBST(&(*node)->leftBST, bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
	else if (strcmp(bookISBN, (*node)->bookISBN) > 0)
		insertNodeBST(&(*node)->rightBST, bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
}

//Linked List Push Tail Only
struct Shelf* insertNodePushTail(char bookTitle[], char bookAuthor[], char bookISBN[], char bookPublisher[], char bookDescription[], int bookYear, int bookQuantity, bool isAvailable)
{
	//Node Initialization
	struct Shelf *node = (struct Shelf*)malloc(sizeof(struct Shelf));
	node->nextPT = node->prevPT = NULL;
	strcpy(node->bookTitle, bookTitle);
	strcpy(node->bookAuthor, bookAuthor);
	strcpy(node->bookISBN, bookISBN);
	strcpy(node->bookPublisher, bookPublisher);
	strcpy(node->bookDescription, bookDescription);
	node->bookYear = bookYear;
	node->bookQuantity = bookQuantity;
	node->isAvailable = isAvailable;
	//Node Insertion
	if (headPT == NULL)
	{
		headPT = tailPT = node;
		headPT->prevPT = tailPT->nextPT = NULL;
	}
	else
	{
		tailPT->nextPT = node;
		node->prevPT = tailPT;
		tailPT = node;
		tailPT->nextPT = NULL;
	}
	return node;
}

//Linked List Priority Queue
struct Shelf* insertNodePushPriority(char bookTitle[], char bookAuthor[], char bookISBN[], char bookPublisher[], char bookDescription[], int bookYear, int bookQuantity, bool isAvailable)
{
	//Node Initialization
	struct Shelf *swap;
	struct Shelf *node = (struct Shelf*)malloc(sizeof(struct Shelf));
	node->nextPQ = node->prevPQ = NULL;
	strcpy(node->bookTitle, bookTitle);
	strcpy(node->bookAuthor, bookAuthor);
	strcpy(node->bookISBN, bookISBN);
	strcpy(node->bookPublisher, bookPublisher);
	strcpy(node->bookDescription, bookDescription);
	node->bookYear = bookYear;
	node->bookQuantity = bookQuantity;
	node->isAvailable = isAvailable;
	//Node Insertion
	if (headPQ == NULL) //There is No Linked List
	{
		headPQ = tailPQ = node;
		headPQ->prevPQ = tailPQ->nextPQ = NULL;
	}
	else
	{
		if (strcmp(headPQ->bookISBN, node->bookISBN) > 0) //Push Head
		{
			headPQ->prevPQ = node;
			node->nextPQ = headPQ;
			headPQ = node;
			headPQ->prevPQ = NULL;
		}
		else if (strcmp(tailPQ->bookISBN, node->bookISBN) < 0) //Push Tail
		{
			tailPQ->nextPQ = node;
			node->prevPQ = tailPQ;
			tailPQ = node;
			tailPQ->nextPQ = NULL;
		}
		else //Push Mid
		{
			swap = headPQ; //Initialize Temporal Varible
			while (swap != NULL) //Traverse All Node in Linked List
			{
				if (strcmp(swap->bookISBN, node->bookISBN) > 0)
					break;
				swap = swap->nextPQ;
			}
			//Swapping
			swap->prevPQ->nextPQ = node;
			node->prevPQ = swap->prevPQ;
			swap->prevPQ = node;
			node->nextPQ = swap;
		}
	}
	return node;
}

//AVL Tree
struct Shelf* insertNodeAVLTree(struct Shelf** node, char bookTitle[], char bookAuthor[], char bookISBN[], char bookPublisher[], char bookDescription[], int bookYear, int bookQuantity, bool isAvailable)
{
	//Insertion

	//Balancing

	return *node;
}

//Search Logic
struct Shelf* searchNode(struct Shelf**temp, char bookISBN[])
{
	if (*temp == NULL)
		return NULL;
	else if (strcmp((*temp)->bookISBN, bookISBN) == 0)
		return *temp;
	else if (strcmp(bookISBN, (*temp)->bookISBN) < 0)
		searchNode(&(*temp)->leftBST, bookISBN);
	else if (strcmp(bookISBN, (*temp)->bookISBN) > 0)
		searchNode(&(*temp)->rightBST, bookISBN);
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
			if (searchNode(&rootBST, bookISBN) == NULL)
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
	insertNodeBST(&rootBST, bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
	insertNodePushTail(bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
	insertNodePushPriority(bookTitle, bookAuthor, bookISBN, bookPublisher, bookDescription, bookYear, bookQuantity, isAvailable);
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
		temp = searchNode(&rootBST, bookISBN);
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

void traverseBST(struct Shelf** temp, int counter) //In Order Traverse Sequence
{
	if (*temp == NULL)
		return;
	traverseBST(&(*temp)->leftBST, counter);
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
	traverseBST(&(*temp)->leftBST, counter);
}
void traverseLinkedList()
{
	char navigation; //View Navigation
	int counter;
	struct Shelf *temp;
	temp = headPQ; //Initialization
	navigation = 39;
	do
	{
		system("cls");
		spacing();
		if(navigation==39||navigation==37)
		{
			for (counter = 0; counter < 5 && temp != NULL; counter++)
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
				if (navigation == 39)
					temp = temp->nextPQ;
				else if (navigation == 37)
					temp = temp->prevPQ;
			}
		}
		if (temp == NULL)
		{
			printf("You Have Reached The End of File!\n");
			if (navigation == 39)
				temp = tailPQ;
			else
				temp = headPQ;
		}
		printf("[<-Previous Page]|[Exit to Menu]|[Next Page->]\n");
		navigation = _getch();
		rewind(stdin);
		if (navigation != 39 && navigation != 37 && navigation != 27)
		{
			printf("Use Escape/Arrow Left/Arrow Right Button to Navigate...\n");
		}
	} while (navigation != 27);
}
void printAll()
{
	int i = 0;
	//if (rootBST == NULL) //No Tree
	//	printf("There is No Data!\nPress \"Enter\" to Continue...");
	//else
	//{

	//	traverseBST(&rootBST, i); //Traverse All Node in Tree
	//}
	if (headPQ == NULL)
		printf("There is No Data!\nPress \"Enter\" to Continue...");
	else
		traverseLinkedList();
}

void adminMenu()
{
	int menu;
	do
	{
		system("cls");
		spacing();
		printf("\t\t[Logged in as Admin]\n\n1. Search Book\n2. Insert New Book\n3. Update Book Information\n4. Remove Book from Database\n5. View All Book [Debug]\n6. Search Comparison [Debug]\n0. Exit\nChoose [0..4]: ");
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
		case 6:
			break;
		case 0:
			break;
		}
	} while (menu != 0);
}

void userMenu()
{
	int menu;
	//User Menu Loop
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
			//Search Book
			break;
		case 2:
			//Borrow Book
			break;
		case 3:
			//Return Book
			break;
		case 0:
			//Exit to Main Menu
			break;
		}
	} while (menu != 0);
}
int main()
{
	int menu; //Menu Navigation
	char loginAdmin[100];
	char loginPass[100]; 
	//Show Application Title
	titleScreen();
	getchar();
	//Main Menu Loop
	do
	{
		system("cls");
		spacing();
		printf("\t\t[BeeNUS Library]\n\n1. Login as Admin\n2. Login as User\n3. Exit\nChoose [1..3]: ");
		scanf("%d", &menu);
		rewind(stdin);
		switch (menu)
		{
		case 1:
			//Login as Admin
			strcpy(loginAdmin, "");
			strcpy(loginPass, "");
			//Login Validation
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
				//Enter to Admin Menu
				adminMenu();
			}
			else
			{
				printf("Wrong Password and/or ID.\nPress \"Enter to Continue\"...");
				getchar();
				//Return to Main Menu
			}
			break;
		case 2:
			//Login as User - Enter to User Main Menu
			userMenu();
			break;
		}
	} while (menu != 3);
	return 0;
}
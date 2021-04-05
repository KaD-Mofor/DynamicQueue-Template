#include "DynamicQueue.h"
#include <iostream>
#include <string>
using namespace std;

//Constants for the menu choice
const int ENQUEUE_CHOICE = 1,
DEQUEUE_CHOICE = 2,
DISPLAY_CHOICE = 3,
QUIT_CHOICE = 0;

//Function Prototype
void menu(int&);
int getQueueSize();
void enqueueItem(DynamicQueue<string>&);
void dequeueItem(DynamicQueue<string>&);
void displayQueueItems(DynamicQueue<string>&);

int main() {

	int choice;

	//Create the stack
	DynamicQueue<string> newQueue;

	do
	{
		//Get the user's mwnu choice
		menu(choice);

		try
		{
			//Perform the user's choice
			if (choice != QUIT_CHOICE)
			{
				switch (choice)
				{
				case ENQUEUE_CHOICE: enqueueItem(newQueue); break;
				case DEQUEUE_CHOICE: dequeueItem(newQueue); break;
				case DISPLAY_CHOICE: displayQueueItems(newQueue); break;
				}
			}
		}
		catch (bool ex)
		{
			cout << "\nThe Queue is empty!\n" << endl;
		}

	} while (choice != QUIT_CHOICE);

	return 0;
}


void menu(int& choice)
{
	cout << "What do you want to do?\n"
		<< "[" << ENQUEUE_CHOICE
		<< "] Enqueue an item \n"
		<< "[" << DEQUEUE_CHOICE
		<< "] Dequeue an item \n"
		<< "[" << DISPLAY_CHOICE
		<< "] Display items in queue\n"
		<< "[" << QUIT_CHOICE
		<< "] Quit the program\n" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	//Input validation
	while (choice <QUIT_CHOICE || choice >DISPLAY_CHOICE)
	{
		cout << "Enter a valid choice: ";
		cin >> choice;
	}
}

int getQueueSize()
{
	int queueSize;
	cout << "\nHow many items do you want to add to queue? ";
	cin >> queueSize;

	return queueSize;
}

//Pushing items onto stack
void enqueueItem(DynamicQueue<string>& newQueue)
{
	string item;

	int queueSize = getQueueSize();
	cin.ignore();   //clear the input console

	for (int i = 0; i < queueSize; i++)
	{
		cout << "\nEnter an item: ";
		getline(cin, item);
		newQueue.enqueue(item);
	}
	cout << endl;
}

//Popping items off the top from a stack
void dequeueItem(DynamicQueue<string>& newQueue)
{
	string item = " ";

	newQueue.dequeue(item);
	if (item != " ") {
		cout << "\n" << item << " was removed from queue.\n" << endl;
	}
}


void displayQueueItems(DynamicQueue<string>& newQueue) {

	string item = " ";

	newQueue.display(item);
	if (item != " ") {
		cout << "\n" << item << endl;
	}
}


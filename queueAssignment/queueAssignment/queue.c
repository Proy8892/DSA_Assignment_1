#include "queue.h"
#include <stdlib.h>

void initializeQueue(Queue* queue)// Function to initialize the queue by setting head and tail to NULL
{
	queue->head = NULL;// Set the head of the queue to NULL
	queue->tail = NULL;// Set the tail of the queue to NULL
}
int isEmpty(Queue* queue) // Function to check if the queue is empty
{
	return queue->head == NULL;// Return 1 (true) if the head of the queue is NULL, indicating that the queue is empty
}
int enqueue(Queue* queue, User user) // Function to add a user to the end of the queue
{

	QueueNode* newNode = malloc(sizeof(QueueNode));// Allocate memory for a new node in the queue

	if (newNode == NULL)//Check if memory allocation failed 
    {
		return 1;// Return 1 to indicate an error if memory allocation fails
    }

	newNode->user = user;// Set the user information in the new node
	newNode->next = NULL;// Set the next pointer of the new node to NULL, as it will be the last node in the queue

	if (isEmpty(queue))//Check if the queue is empty 
    {
		queue->head = newNode;// If the queue is empty, set both head and tail to the new node
		queue->tail = newNode;// Set the tail of the queue to the new node
    }
    else 
	{
		queue->tail->next = newNode;// If the queue is not empty, link the current tail to the new node and update the tail pointer
		queue->tail = newNode;// Update the tail of the queue to the new node
    }

    return 0;
}

int dequeue(Queue* queue, User* user)// Function to remove a user from the front of the queue
{

	if (isEmpty(queue))//Check if the queue is empty
    {
		return 1;// Return 1 to indicate an error if the queue is empty
    }

	QueueNode* temp = queue->head;// Store the current head node in a temporary variable

	*user = temp->user;// Copy the user information from the head node to the provided user pointer

	queue->head = queue->head->next;// Update the head of the queue to the next node

	if (queue->head == NULL)//Check if the queue is now empty after the dequeue operation
	{
		queue->tail = NULL;// If the queue is empty, set the tail to NULL as well
    }

	free(temp);// Free the memory allocated for the old head node

    return 0;
}
void makeRandomUsername(char username[])//Function to generate a random username consisting of 10 characters (letters and digits) 
{

	char letters[] =
		"abcdefghijklmnopqrstuvwxyz0123456789";// Array of characters to choose from for the username

	for (int i = 0; i < 10; i++)// Loop to generate each character of the username
	{

		int index = rand() % strlen(letters);// Generate a random index to select a character from the letters array

		username[i] = letters[index];// Assign the randomly selected character to the current position in the username array
	}

	username[10] = '\0';// Null-terminate the username string
}
User makeRandomUser()// Function to generate a random user with a random username, level, and faction
	{

	User user;// Declare a User variable to hold the generated user information

	makeRandomUsername(user.username);// Generate a random username for the user

	user.level = (rand() % 60) + 1;// Generate a random level for the user between 1 and 60

	int choice = rand() % 3;// Generate a random choice to determine the faction of the user (0 for red, 1 for blue, 2 for green)

	if (choice == 0)// If the choice is 0, assign the faction "red" to the user
		strcpy(user.faction, "red");// If the choice is 1, assign the faction "blue" to the user
	else if (choice == 1)// If the choice is 1, assign the faction "blue" to the user
		strcpy(user.faction, "blue");// If the choice is 2, assign the faction "green" to the user
		else
		strcpy(user.faction, "green");// If the choice is 2, assign the faction "green" to the user

	return user;// Return the generated user
	}


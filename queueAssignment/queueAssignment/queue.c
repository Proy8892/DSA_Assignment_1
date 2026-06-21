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

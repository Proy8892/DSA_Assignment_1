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

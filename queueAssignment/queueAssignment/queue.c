#include "queue.h"
#include <stdlib.h>

void initializeQueue(Queue* queue)// Function to initialize the queue by setting head and tail to NULL
{
	queue->head = NULL;// Set the head of the queue to NULL
	queue->tail = NULL;// Set the tail of the queue to NULL
}

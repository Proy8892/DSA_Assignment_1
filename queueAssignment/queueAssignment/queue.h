#ifndef QUEUE_H
#define QUEUE_H

#define USERNAME_SIZE 11// 10 characters + null terminator

typedef struct//User structure to hold user information 
{
	char username[USERNAME_SIZE];// Username of the user
	int level;// Level of the user
	char faction[10];// Faction of the user
} User;//User structure to hold user information

typedef struct QueueNode// Node structure for the queue, containing a User and a pointer to the next node
{
	User user;// User information stored in the node
	struct QueueNode* next;// Pointer to the next node in the queue
} QueueNode;// Node structure for the queue, containing a User and a pointer to the next node

typedef struct // Queue structure containing pointers to the head and tail of the queue
{
	QueueNode* head;// Pointer to the head of the queue
	QueueNode* tail;// Pointer to the tail of the queue
} Queue;
void initializeQueue(Queue* queue);// Function prototype for initializing the queue
int isEmpty(Queue* queue);

#endif
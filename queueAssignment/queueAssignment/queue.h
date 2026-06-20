#ifndef QUEUE_H
#define QUEUE_H

#define USERNAME_SIZE 11

typedef struct {
    char username[USERNAME_SIZE];
    int level;
    char faction[10];
} User;

typedef struct QueueNode {
    User user;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* head;
    QueueNode* tail;
} Queue;

#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main(int argc, char* argv[])//Main function to execute the program, taking command-line arguments for the number of users to generate and enqueue 
{

	Queue queue;// Declared a Queue variable to hold the queue of users
	User user;// Declared a User variable to hold the user information when dequeuing

	if (argc != 2) // Checks if the number of command-line arguments is not equal to 2 (the program name and the number of users)
    {
		printf("Usage: queue numberOfUsers\n");// Print a usage message to the user indicating how to run the program correctly
		return 1;// Returns 1 to indicate an error if the number of command-line arguments is incorrect
    }

	int numberOfUsers = atoi(argv[1]);// Convert the second command-line argument (number of users) from a string to an integer using atoi

	srand(time(NULL));// Seed the random number generator with the current time to ensure different random values each time the program is run

	initializeQueue(&queue);// Initialize the queue by calling the initializeQueue function, passing a pointer to the queue variable

	addRandomUsers(&queue, numberOfUsers);// Add the specified number of random users to the queue by calling the addRandomUsers function, passing a pointer to the queue and the number of users

	while (!isEmpty(&queue)) // Loop to dequeue and print user information until the queue is empty, checking if the queue is not empty using the isEmpty function
    {

		dequeue(&queue, &user);// Dequeue a user from the queue by calling the dequeue function, passing a pointer to the queue and a pointer to the user variable to store the dequeued user information

		printf("Username: %s\n", user.username);// Print the username of the dequeued user to the console
		printf("Level: %d\n", user.level);// Print the level of the dequeued user to the console
		printf("Faction: %s\n", user.faction);// Print the faction of the dequeued user to the console
		printf("-----------------\n");// Print a separator line for better readability between user information
    }

    return 0;
}
/*
 * Example: Insert the node in linkedlist with priority.
 * 	    Each structure has property prio.
 * 	    you have to insert new node with accending priority.
 * 
 * Author: Girish Bhangale <girishbhangale@outlook.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node 
{
	int data;
	int prio;
	struct node* next;
};


struct node * creaate_node() 
{
	struct node *new_node = malloc(sizeof(*new_node));
	new_node->next = NULL;
	printf("Enter the data: ");
	scanf(" %d", &new_node->data);
	printf("Set thr priority of node: ");
	scanf(" %d", &new_node->prio);
	return new_node;	
}

void insert_prio_node(struct node **indirect) 
{
	struct node *new_node = creaate_node();
	
	while(*indirect != NULL &&  (*indirect)->prio < new_node->prio)
		indirect = &(*indirect)->next;
	
	new_node->next = *indirect;
	*indirect = new_node;
}

void display(struct node *head) 
{
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	while(head != NULL) {
		printf("%d [%d]\t", head->data, head->prio);
		head = head->next;
	}
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

}

int main() 
{
	int choice = 0;
	struct node *head = NULL;
	do{
		printf("- - - Choice - - -\n\
			\r1. Insert Node\n\
			\r9. Display\n\
			\r0. EXIT\n\n\
			\rEnter your choice: ");
		scanf(" %d", &choice);
		switch(choice) {
			case 1: insert_prio_node(&head);
				break;
			case 9: display(head);
				break;
			case 0: exit(EXIT_SUCCESS);
				break;
			default: printf("X-X-X Invalid Choice X-X-X");
		}
	} while(choice);
	return 0;
}

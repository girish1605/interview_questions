/*
 * Singly Linked List
 * Author: Girish Bhangale <girishbhangale@outlook.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node {
	int data;
	struct node *next;
};

struct node * create_node() {
	struct node *new_node = (struct node *)malloc(sizeof(*new_node));
	printf("Enter the data: ");
	scanf(" %d", &new_node->data);
	new_node->next = NULL;
	return new_node;
}

void insert_node_at_begining(struct node **indirect) {
	struct node *tmp = create_node();
	tmp->next = *indirect;
	*indirect = tmp;
}

void insert_node_at_end(struct node **indirect) {
	struct node *tmp = create_node();
	while(*indirect != NULL)
		indirect = &(*indirect)->next;
	*indirect = tmp;
}

void delete_node_at_beginig(struct node **indirect) {
	struct node *tmp = *indirect;
	if(*indirect != NULL) {
		*indirect = (*indirect)->next;
		free(tmp);
	}
}

void delete_node_at_end(struct node **indirect) {
	struct node *tmp = NULL;
	if(*indirect != NULL) {
		while ((*indirect)->next != NULL)
			indirect = &(*indirect)->next;
		free(*indirect);
		*indirect = NULL;
	}
}

void print_list(struct node *head) {
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("LIST: ");
	while(head != NULL) {
		printf(" %d\t", head->data);
		head = head->next;
	}
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\n");
}

int main() {
	int choice = 0;
	struct node * head = NULL;

	do {
		printf("- - - - CHOICE - - - - -\n \
			\r1. Insert node at Begining\n\
			\r2. Insert node at end\n\
			\r3. Delete node from Begining\n\
			\r4. Delete node from  end \n\
			\r9. Print Linked List \n\
			\r0. EXIT\n\n\
			\rEnter your choice: ");
		scanf(" %d", &choice);
		switch(choice) {
			case 1: insert_node_at_begining(&head); break;
			case 2: insert_node_at_end(&head); break;
			case 3: delete_node_at_beginig(&head); break;
			case 4: delete_node_at_end(&head); break;
			case 9: print_list(head); break;
			case 0: exit(EXIT_SUCCESS); break;
			default: printf("X-X-X INVALID CHOICE X-X-X\n\n\
					\rPlease Try Again...");
		}
	} while(choice);

	return 0;
}

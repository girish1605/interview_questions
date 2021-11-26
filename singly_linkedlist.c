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
	struct node *new_node = create_node();
	new_node->next = *indirect;
	*indirect = new_node;
}

void insert_node_at_end(struct node **indirect) {
	struct node *new_node = create_node();
	while(*indirect != NULL)
		indirect = &(*indirect)->next;
	*indirect = new_node;
}

void delete_node_at_beginig(struct node **indirect) {
	struct node *free_soon = *indirect;
	if(*indirect != NULL) {
		*indirect = (*indirect)->next;
		free(free_soon);
	}
}

void delete_node_at_end(struct node **indirect) {
	if(*indirect != NULL) {
		while ((*indirect)->next != NULL)
			indirect = &(*indirect)->next;
		free(*indirect);
		*indirect = NULL;
	}
}

void print_list(struct node *head) {
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("LIST:\t");
	while(head != NULL) {
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\n");
}

/* START: VMWare interview */
void delete_node(struct node ** indirect) {
	struct node *free_soon = *indirect;
	*indirect = (*indirect)->next;
	free(free_soon);
}

void remove_node_greater_than_value(struct node ** indirect) {
	
	int value = 0;
	printf("Enter the maximum value allowable: ");
	scanf(" %d", &value);

	while (*indirect != NULL) {
		if((*indirect)->data > value)
			delete_node(indirect);
		else 
			indirect = &(*indirect)->next;	
	}
}
/* END: VMWare interview */

/* START: Dell interview */
void rotate_linked_list_left(struct node ** indirect) {

	int total_rotation = 0;
	int i;
	struct node ** head_ref = indirect;
	struct node *tmp_head = NULL;
	printf("Enter the number of rotation: ");
	scanf(" %d", &total_rotation);
	

	for(i=0; i < total_rotation && (*indirect) != NULL; i++)
		indirect = &(*indirect)->next;

	if(*indirect == NULL || total_rotation == 0)
		return;

	tmp_head = *indirect;
	*indirect = NULL;
	indirect = &tmp_head->next;
	
	while(*indirect != NULL)
		indirect = &(*indirect)->next;
		
	*indirect = *head_ref;
	*head_ref = tmp_head;
}
/* END: Dell interview */

void cleanup_linked_list(struct node ** indirect) {
	while(*indirect != NULL)
		delete_node(indirect);
}

int main() {
	int choice = 0;
	struct node * head = NULL;

	do {
		printf("- - - - CHOICE - - - - -\n\
			\r1. Insert node at Begining\n\
			\r2. Insert node at end\n\
			\r3. Delete node from Begining\n\
			\r4. Delete node from  end\n\
			\r5. Remove node greater than given value\n\
			\r6. Rotate linked list left by given value\n\
			\r9. Print Linked List\n\
			\r0. EXIT\n\n\
			\rEnter your choice: ");
		scanf(" %d", &choice);
		switch(choice) {
			case 1: insert_node_at_begining(&head); break;
			case 2: insert_node_at_end(&head); break;
			case 3: delete_node_at_beginig(&head); break;
			case 4: delete_node_at_end(&head); break;
			case 5: remove_node_greater_than_value(&head); break;
			case 6: rotate_linked_list_left(&head); break;
			case 9: print_list(head); break;
			case 0: cleanup_linked_list(&head); break;
			default: printf("X-X-X INVALID CHOICE X-X-X\n\n\
					\rPlease Try Again...");
		}
	} while(choice);

	return 0;
}

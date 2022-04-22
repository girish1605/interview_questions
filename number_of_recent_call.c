/*
 * Microsoft 2nd round (designed round) April 20, 2022
 * Problem: Implement the int request(int time_stamp) API 
 * which counts the number of recent requests within a certain time frame.
 * 
 * int request(int t) Adds a new request at time t, where t represents some time in milliseconds, 
 * and returns the number of requests that has happened in the past 1000 milliseconds (including the new request). 
 * Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
 * 
 * request(100)    -> 1
 * request(400)    -> 2
 * request(900)    -> 3
 * request(1200)   -> 3
 * request(1700)   -> 3
 * request(1900)   -> 4
 * request(4000)   -> 1
 * request(5000)   -> 2
 */

#include <stdio.h>
#include <stdlib.h>

const int TIME_FRAME = 1000;

static unsigned int gcount = 0;
static struct node * head = NULL;

struct node {
    int time_stamp;
    struct node* next;
};

struct node * create_node(unsigned int time_stamp) {
    struct node *new_node = malloc(sizeof(*new_node));
    new_node->time_stamp = time_stamp;
    new_node->next = NULL;
    return new_node;
}

void push_node(struct node **indirect, unsigned int time_stamp) {

    static struct node * end_node = NULL;
    struct node * new_node = create_node(time_stamp);

    if(*indirect == NULL) {
        *indirect = new_node;
        end_node = new_node;
    }
    else {
        end_node->next = new_node;
        end_node = new_node;
    }
/* 
    while (*indirect != NULL)
        indirect = &(*indirect)->next;

    *indirect = new_node;
 */
    gcount++;
}


void pop_node_before_certain_time_frame(struct node ** indirect, unsigned int time_stamp) {

    while((*indirect != NULL) &&  (*indirect)->time_stamp < (int)(time_stamp - TIME_FRAME)) {
        struct node * free_soon = *indirect;
        *indirect = (*indirect)->next;
        free(free_soon);
        gcount--;
    } 

}

void display_node(struct node * head) {
    
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \nLIST >  ");
    while(head != NULL) {
        printf("  %d", head->time_stamp);
        head = head->next;
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
}

int request(int time_stamp) {
    push_node(&head, time_stamp);
    pop_node_before_certain_time_frame(&head, time_stamp);

    return gcount;   
}


int main() {
 
    printf("Number in last 1000ms : %d\n", request(100)); 
    printf("Number in last 1000ms : %d\n", request(400)); 
    printf("Number in last 1000ms : %d\n", request(900));
    printf("Number in last 1000ms : %d\n", request(1200));
    printf("Number in last 1000ms : %d\n", request(1700));
    printf("Number in last 1000ms : %d\n", request(1900));
    printf("Number in last 1000ms : %d\n", request(4000));
    printf("Number in last 1000ms : %d\n", request(5000));

    return 0;
}
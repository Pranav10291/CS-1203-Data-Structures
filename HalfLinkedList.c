// WAP that prints the first half of a given Linked List without knowing how many elements in the array
#include<stdio.h>
#include<stdlib.h>
#include<time.h>    //for random number generator seed

struct node{
    int val;
    struct node * next;
};


struct node * generateLinkedList(int n){
    int i;
    struct node * head = NULL;
    struct node * temp = NULL;

    if(n>0){
        head = malloc(sizeof(struct node));
        head->val = rand()%1000;            // assigning a random value to the head->val
        head->next = NULL;                  // assigning NULL to the head->next
        temp = head;
    }

    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
        temp->val = rand()%1000;            // assigning a random value to the temp->val
        temp->next = NULL;                  // assigning NULL to the temp->next
    }
    return head;                            // returning the address of the head of Linked List
}

void printLL(struct node * head, int n){
    struct node * temp = head;
    printf("Complete Linked List = ");
    for(int i=0; i<n; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
    printf(".\n");
}

void HalfLL(struct node * head){
    // We will use the Hare and Tortoise Pointer Algorithm
    // We take two pointers, one will move one step at a time and the other will move two steps at a time
    // When the faster pointer reaches the end of the linked list, the slow pointer will be at the middle of the linked list

    struct node * slow_pointer = head;
    struct node * fast_pointer = head;
    while(fast_pointer != NULL && fast_pointer->next != NULL){
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
    }
    // Now the tortoise is at the middle of the linked list
    
    // Printing the first half of the linked list
    struct node * temp = head;
    int i=0;
    printf("Half Linked List = ");
    while(temp != slow_pointer){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
        i++;
    }
}

void freeLL(struct node * head){
    struct node * prev;
	while(head){             //while head != NULL
		prev = head;
		head = head->next;
		free(prev);            // freeing the previous node after moving the head to the next node
	}
}


int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    struct node * list, tail;           // declaring a new address for linked list
    srand(time(NULL));                  // seeding the random number generator
    list = generateLinkedList(n);       // returns the head of the linked list

    printLL(list, n);
    HalfLL(list);                       // no need to send size of the list since it is irrelevant to the algorithm
    
    freeLL(list);                       // freeing the linked list
    return 0;
}

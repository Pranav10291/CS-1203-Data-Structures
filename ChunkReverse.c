//WAP to Chunk Reverse a Linked List
// Given head pointer of a linked list, and an integer k (1<=k<=n), reverse the first k nodes of the linked list. If k>n, reverse the whole linked list.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
    int val;
    struct Node * next;
};



// Same algorithm as we did in the reversing a linked list
// We use three pointers, one to keep track of the previous node, one to keep track of the current node and one to keep track of the next node
// We will reverse the linked list by changing the next pointer of the current node to the previous node
// We will do this for k nodes
// if k=n, we will reverse the whole linked list 
// We return the address of the new head of the linked list after k nodes
struct Node * chunkReverse(struct Node * head, int k){
    struct Node * current = head;                 
    struct Node * prev = NULL;                 
    struct Node * forward = NULL;              
    if(k==0){                                // Return head if zero chunks are selected 
        return head;
    }
    for(int i=0; i<k && current!=NULL; i++){    // Traverse the linked list for k nodes, if k>n, traverse till the end of the linked list
        forward = current->next;                
        current->next = prev;                   // Change the next pointer of the current node to the previous node
        prev = current;                         // Set the previous node address to the current node address
        current = forward;                      // Set the current node address to the forward node address
    }
    head->next = current;                       // Set the next pointer of the head to the current node address
    head = prev;                                // Set the head to the previous node address
    return head;
}


struct Node * generateLinkedList(int n){
    int i;
    struct Node * head = NULL;
    struct Node * temp = NULL;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct Node));
        head->val = rand()%1000;            
        head->next = NULL;                  
        temp = head;
    }
    // general case
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next;
        temp->val = rand()%1000;            
        temp->next = NULL;                  
    }
    return head;                            
}


void printLinkedList(struct Node * head, int n){
    struct Node * temp = head;
    printf("Complete Linked List = ");
    for(int i=0; i<n; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
    printf(".\n");
}

void deleteLinkedList(struct Node * head){
    struct Node * prev;
	while(head){                
		prev = head;
		head = head->next;
		free(prev);                 // moving ahead one step, free the previous node
	}
}

/*==== main ====*/
int main(int argc, char const *argv[])
{
    int n,k;
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    struct Node * list, *chunk;         
    srand(time(NULL));                  
    list = generateLinkedList(n);       
    printLinkedList(list, n);         

    printf("Enter the value of k: ");
    scanf("%d", &k);

    chunk = chunkReverse(list, k);
    
    printLinkedList(chunk, n);           

    deleteLinkedList(list);                         
    deleteLinkedList(chunk);                         
    return 0;
}
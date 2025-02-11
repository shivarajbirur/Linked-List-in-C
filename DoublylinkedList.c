#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

// Function to create a new node
Node* CreateNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data= data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

// Insert At Start
void insertAtStart(Node** head, int data){
    Node* newNode = CreateNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev=newNode;
    *head=newNode;
}

// Insert At End
void insertAtEnd(Node** head, int data){
    Node* newNode = CreateNode(data);

    if(*head == NULL){
        insertAtStart(head,data);
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->prev=temp;
}

// Function to insert a node at a specific position
void insertAtPosition(Node** head, int data, int position) {
    if(position <= 0){
        printf("Invalid position");
        return;
    }
    if(position == 1){
        insertAtStart(head, data);
        return;
    }

    Node* newNode = CreateNode(data);
    Node* temp = *head;
    int count = 1;
    
    while(temp!= NULL  && count < position-1){
        temp=temp->next;
        count++;
    }

    if(temp == NULL){
        printf("Position out of Bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
// Function to delete a node at the start of the list
void deleteAtStart(Node** head) {
    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if(*head != NULL){
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node at the end of the list
void deleteAtEnd(Node** head) {
    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }

    Node* temp = *head;
    while(temp->next != NULL){
        temp= temp->next;
    }

    if(temp->prev !=NULL){
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}
// Function to delete a node at a specific position
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Invalid position or empty list!\n");
        return;
    }
    if (position == 1) {
        deleteAtStart(head);
        return;
    }

    Node* temp = *head;
    int count=1;

    while(temp != NULL && count < position){
        temp = temp->next;
        count++;
    }

    if(temp == NULL){
        printf("Position out of bounds!\n");
        return;
    }

    if(temp->next != NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    } else { // If deleting the head node
        *head = temp->next;
    }
    free(temp);
}

// Function to search for a value in the list
void searchValue(Node* head, int value) {
    int position = 1;
    while (head != NULL) {
        if (head->data == value) {
            printf("Value %d found at position %d\n", value, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Value %d not found in the list!\n", value);
}

// Function to print a doubly linked list
void PrintList(Node* head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" <-> "); // Indicate the link between nodes
        }
        head = head->next;
    }
    printf(" -> NULL\n");
}

int main(){
    Node* head = NULL;
    deleteAtEnd(&head);
    PrintList(head);
    insertAtEnd(&head,300);
    PrintList(head);
    deleteAtStart(&head);
    PrintList(head);
    insertAtStart(&head,10);
    PrintList(head);
    deleteAtEnd(&head);
    PrintList(head);
    insertAtStart(&head,20);
    PrintList(head);
    insertAtEnd(&head,30);
    PrintList(head);
    insertAtPosition(&head,100,1);
    PrintList(head);
    insertAtPosition(&head,600,6);
    PrintList(head);
    insertAtPosition(&head,800,8);
    PrintList(head);
    insertAtPosition(&head,500,5);
    PrintList(head);
    deleteAtStart(&head);
    PrintList(head);
    deleteAtEnd(&head);
    PrintList(head);
    insertAtStart(&head,10);
    insertAtStart(&head,20);
    insertAtStart(&head,30);
    insertAtStart(&head,40);
    insertAtStart(&head,50);
    PrintList(head);
    deleteAtPosition(&head,1);
    PrintList(head);
    deleteAtPosition(&head,5);
    PrintList(head);
    deleteAtPosition(&head,2);
    PrintList(head);
    searchValue(head,20);
    PrintList(head);
    searchValue(head,200);
    PrintList(head);


}


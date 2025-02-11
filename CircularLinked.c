#include<stdio.h>
#include<stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}
// Insert at the Start (before the head)
void InsertAtStart(Node** tail, int data) {
    Node* newNode = CreateNode(data);

    if (*tail == NULL) {
        // First node case
        newNode->next = newNode;  // Circular link to itself
        *tail = newNode;  // Ensure tail remains at last node
    } else {
        newNode->next = (*tail)->next;  // Point new node to old head
        (*tail)->next = newNode;        // Update tail's next to new node
    }
}

// Function to insert at the end
void InsertAtEnd(Node **tail, int data) {
    Node * newNode = CreateNode(data);

    if(*tail == NULL){
        newNode->next = newNode;
        *tail = newNode;
    } else {
        newNode-> next = (*tail)->next;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
// Function to insert at a specific position
void InsertAtSpecificPosition(Node** tail, int data, int position){
    if(position<1){
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        InsertAtStart(tail, data);
        return;
    }

    Node* newNode = CreateNode(data);

    Node* temp = (*tail)->next;
    int count = 1;

    while(temp != *tail && count < position - 1){
        temp = temp->next;
        count++;
    }

    if(count < position-1){
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    if(temp == *tail){
        *tail = newNode;
    }
}
// Function to delete from the beginning
void deleteAtStart(Node **tail) {
    if (*tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *head = (*tail)->next;
    if (*tail == head) { // Single node case
        free(*tail);
        *tail = NULL;
    } else {
        (*tail)->next = head->next;
        free(head);
    }
}
// Function to delete from the end
void deleteAtEnd(Node **tail) {
    if (*tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *temp = (*tail)->next, *prev = NULL;
    while (temp->next != (*tail)->next) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == (*tail)->next) { // Single node case
        free(*tail);
        *tail = NULL;
    } else {
        prev->next = temp->next;
        *tail = prev;
        free(temp);
    }
}
// Function to search for a value in the list
void searchValue(Node *tail, int key) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *temp = tail->next;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != tail->next);
    
    printf("Value %d not found in the list.\n", key);
}
// Function to display the list
void PrintList(Node *tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *temp = tail->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(HEAD)\n");
}
int main(){
    Node* tail = NULL;
    
    InsertAtEnd(&tail,200);
    PrintList(tail);
    InsertAtStart(&tail,100);
    PrintList(tail);
    InsertAtEnd(&tail,20);
    PrintList(tail);
    InsertAtSpecificPosition(&tail,1000,1);
    PrintList(tail);
    InsertAtSpecificPosition(&tail,3000,3);
    PrintList(tail);
    InsertAtSpecificPosition(&tail,6000,6);
    PrintList(tail);
    InsertAtSpecificPosition(&tail,8000,8);
    PrintList(tail);
    deleteAtStart(&tail);
    PrintList(tail);
    deleteAtEnd(&tail);
    PrintList(tail);
    searchValue(tail,200);
    searchValue(tail,2000);

}
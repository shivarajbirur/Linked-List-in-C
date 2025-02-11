#include<stdio.h>
#include<stdlib.h>

//Structure for a node
typedef struct node 
{
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* CreateNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Failed to allocate memory");
        return NULL;
    }
    newNode->data = data;
    newNode->next= NULL;
    return newNode;
}
// Insert at the beginning
void InsertAtStart(int data, Node** head){
    Node* newNode = CreateNewNode(data);
    newNode->next= *head;
    *head = newNode;
}
// Insert at the End
void InsertAtEnd(int data, Node** head){
    Node* newNode = CreateNewNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* currentNode = *head;
    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}
// Insert at the Specific Position
void InsertAtPosition(Node** head, int data, int position){
    if(position==1){
        InsertAtStart(data,head);
        return;
    }

    Node* currentNode = *head;
    int currentPosition = 1;

    while((currentPosition < position - 1 ) && currentNode != NULL){
        currentPosition++;
        currentNode = currentNode-> next; 
    }

    if (currentNode == NULL) {
        printf("Can't insert at this position, there are fewer nodes\n");
        return;
    }

    Node* newNode = CreateNewNode(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}
// Delete the first Node
void DeleteAtStart(Node** head){
    if(*head == NULL){
        printf("List is Empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

//Delete At End
void DeleteAtEnd(Node** head){
    if(*head == NULL){
        printf("List is Empty");
        return;
    }

    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }

    Node * currentNode = *head;
    while ((currentNode->next->next!=NULL))
    {
        currentNode = currentNode->next;
    }
    free(currentNode->next);
    currentNode->next=NULL;
    
}
//Delete a Node at a Specific Position
void DeleteAtPosition(Node** head, int position){
    if(*head==NULL){
        printf("List is Empty");
        return;
    }
    if(position==1){
        DeleteAtStart(head);
        return;
    }
    Node* currentNode = *head;
    int currentPosition = 1;

    while((currentPosition < position-1) && currentNode != NULL){
        currentNode= currentNode->next;
        currentPosition++;
    }
    if(currentNode == NULL || currentNode->next == NULL){
        printf("Position out of range\n");
        return;
    }

    Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);

}

// Search for a Key
void SearchKey(Node* head, int key) {
    if (head == NULL) {
        printf("\n List is empty");
        return;
    }

    Node* currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            printf("\n Key is present in the node");
            return;
        }
        currentNode = currentNode->next;
    }

    printf("\n Key is not found in the list");
}
//Print the linked list
void PrintList(Node* head){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    printf("Head -> ");
    while (head != NULL)
    {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main(){
    Node* head = NULL;
    DeleteAtStart(&head);
    PrintList(head);
    InsertAtEnd(300, &head);
    PrintList(head);
    DeleteAtEnd(&head);
    PrintList(head);
    InsertAtStart(30, &head);
    InsertAtStart(20, &head);
    InsertAtStart(10, &head);
    InsertAtStart(5, &head);
    PrintList(head);
    InsertAtEnd(100,&head);
    PrintList(head);
    InsertAtPosition(&head,1,0);
    PrintList(head);
    InsertAtPosition(&head,8,8);
    PrintList(head);
    InsertAtPosition(&head,50,5);
    PrintList(head);
    DeleteAtStart(&head);
    PrintList(head);
    DeleteAtStart(&head);
    PrintList(head);
    DeleteAtEnd(&head);
    PrintList(head);
    DeleteAtPosition(&head,3);
    PrintList(head);
    DeleteAtPosition(&head,5);
    PrintList(head);
    DeleteAtPosition(&head,3);
    PrintList(head);
    DeleteAtPosition(&head,10);
    PrintList(head);
    SearchKey(head,10);
    SearchKey(head,100);
}
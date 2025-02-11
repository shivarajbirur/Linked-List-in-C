# Doubly Linked List (DLL)

## Introduction
A **Doubly Linked List (DLL)** is a type of linked data structure that consists of nodes, where each node contains three components:
1. Data
2. A pointer to the next node in the sequence (`next`)
3. A pointer to the previous node in the sequence (`prev`)

Unlike a Singly Linked List (SLL), a DLL allows traversal in both directions due to the `prev` pointer.

## Advantages of DLL
1. **Bidirectional Traversal**: Traverse the list in both forward and backward directions.
2. **Ease of Deletion**: Deleting a node is easier as we have a pointer to the previous node.
3. **Flexible Insertion**: Insertions at any position (start, end, middle) are more efficient.

## Real-Life Examples
1. **Web Browsers**: The back and forward buttons in browsers use a doubly linked list to store visited pages.
2. **Undo/Redo Operations**: Many applications use DLL to implement undo/redo functionality.
3. **Music Players**: Doubly linked lists are used to navigate playlists forward and backward.

## Comparison with Singly Linked List
| Feature                  | Singly Linked List | Doubly Linked List |
|--------------------------|--------------------|--------------------|
| Traversal Direction      | Forward only       | Forward and Backward |
| Memory Usage            | Less (1 pointer/node) | More (2 pointers/node) |
| Insertion/Deletion Ease | At head/tail only  | Anywhere easily      |
| Reversing the List      | Difficult          | Easier               |

## Real-Life Analogy
A doubly linked list is like a train where each compartment (node) is connected to the next compartment (next pointer) and the previous compartment (prev pointer). This enables you to move forward and backward between compartments.

---

## Implementation in C
Below is the implementation of all essential operations in a doubly linked list:

```c
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
typedef struct Node {
    int data;                  // Data part of the node
    struct Node* next;         // Pointer to the next node
    struct Node* prev;         // Pointer to the previous node
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the start of the list
void insertAtStart(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode; // The new node becomes the head if the list is empty
        return;
    }
    newNode->next = *head; // Link the new node to the current head
    (*head)->prev = newNode;
    *head = newNode;       // Update head to the new node
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode; // The new node becomes the head if the list is empty
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Link the new node to the last node
    newNode->prev = temp; // Link the last node to the new node
}

// Function to insert a node at a specific position
void insertAtPosition(Node** head, int value, int position) {
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtStart(head, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* temp = *head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete a node at the start of the list
void deleteAtStart(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node at the end of the list
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; // The list becomes empty
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
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
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

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to delete a node with a specific value
void deleteNodeWithValue(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list!\n", value);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; // Update head if deleting the first node
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node with value %d deleted!\n", value);
}

int main() {
    Node* head = NULL;

    // Test operations
    insertAtStart(&head, 10);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);
    printList(head);

    deleteAtStart(&head);
    printList(head);

    deleteAtEnd(&head);
    printList(head);

    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    deleteAtPosition(&head, 2);
    printList(head);

    searchValue(head, 40);
    deleteNodeWithValue(&head, 40);
    printList(head);

    return 0;
}
```

---

## Summary of Operations
1. **Create a Node**: Allocate memory for a new node and initialize its pointers to `NULL`.
2. **Insertion**: Handles inserting nodes at the start, end, and a specific position.
3. **Deletion**: Handles deleting nodes at the start, end, a specific position, or by value.
4. **Search**: Locates a node containing a specific value.
5. **Print**: Traverses and prints the list.

This code provides a robust and user-friendly implementation of a doubly linked list, ensuring clear comments, descriptive variable names, and handling of edge cases.

### Notes from algorithms365

#### Websites:
- **Skills Website**: [https://skills.algorithms365.com/](https://skills.algorithms365.com/)  
- **Company Website**: [https://algorithms365.com/](https://algorithms365.com/)  

---

#### Follow & Subscribe on Social Media Platforms:
- **Instagram**: [https://www.instagram.com/algorithms365/](https://www.instagram.com/algorithms365/)  
- **YouTube**: [https://www.youtube.com/@algorithms365](https://www.youtube.com/@algorithms365)  
- **Facebook**: [https://www.facebook.com/algorithms365](https://www.facebook.com/algorithms365)  
- **Twitter (X)**: [https://x.com/algorithms365](https://x.com/algorithms365)  
- **LinkedIn**: [https://www.linkedin.com/company/algorithms365-technologies-llp/](https://www.linkedin.com/company/algorithms365-technologies-llp/)  

---

## Join Our Communities:
- **WhatsApp**: [https://chat.whatsapp.com/K1K7wDMEXG0DJhqMCxFtht](https://chat.whatsapp.com/K1K7wDMEXG0DJhqMCxFtht)  
- **Telegram**: [https://t.me/+hyVHX

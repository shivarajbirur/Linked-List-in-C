# Singly Linked List in C

## Introduction

A **linked list** is a linear data structure where elements are not stored in contiguous memory locations. Instead, each element, called a **node**, contains a value and a pointer to the next node in the sequence.

### Why Linked Lists?

Arrays store elements in contiguous memory locations, which can lead to inefficient memory utilization and difficulty in dynamic resizing. Linked lists address these issues by allocating memory dynamically for each node.

### Advantages of Linked Lists Over Arrays

1. **Dynamic Memory Allocation**: Memory is allocated as required, avoiding memory wastage.
2. **Ease of Insertion and Deletion**: Adding or removing elements is efficient since there is no need to shift elements.
3. **Flexible Size**: Unlike arrays, the size of a linked list is not fixed.

### Disadvantages of Linked Lists

1. **Higher Memory Overhead**: Each node requires extra memory for the pointer.
2. **Sequential Access**: Traversal requires visiting nodes one by one.
3. **Complexity**: Implementation is more complex compared to arrays.

## Singly Linked List

A **singly linked list** is a type of linked list where each node points to the next node in the sequence. The last node points to `NULL`, marking the end of the list.

### Node Structure in C

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

Node* CreateNewNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Failed to allocate memory!");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

## Operations on Singly Linked List

### 1. Insert Operations

#### a. Insert at Start

```c
void InsertAtStart(int data, Node** head) {
    Node* newNode = CreateNewNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}
```

#### b. Insert at End

```c
void InsertAtEnd(int data, Node** head) {
    Node* newNode = CreateNewNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* currentNode = *head;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}
```

#### c. Insert at Position

```c
void insertAtPosition(Node** head, int data, int position) {
    if (*head == NULL) {
        printf("\n List is empty");
        return;
    }

    if (position == 1) {
        InsertAtStart(data, head);
        return;
    }

    Node* currentNode = *head;
    int currentPosition = 1;

    while ((currentPosition < position - 1) && currentNode != NULL) {
        currentPosition++;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Can't insert at this position, there are fewer nodes");
        return;
    }

    Node* newNode = CreateNewNode(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}
```

### 2. Delete Operations

#### a. Delete at Start

```c
void DeleteAtStart(Node** head) {
    if (*head == NULL) {
        printf("\n List is empty");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("\nDeleted the first node");
}
```

#### b. Delete at End

```c
void DeleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("\n List is empty");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* currentNode = *head;
    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }
    free(currentNode->next);
    currentNode->next = NULL;
    printf("\n Node at the end has been deleted");
}
```

#### c. Delete at Position

```c
void DeleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("\n List is empty");
        return;
    }

    if (position == 1) {
        DeleteAtStart(head);
        return;
    }

    int currentPosition = 1;
    Node* currentNode = *head;

    while ((currentPosition < position - 1) && currentNode != NULL) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    if (currentNode == NULL || currentNode->next == NULL) {
        printf("\n Can't perform this operation");
        return;
    }

    Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);
    printf("Deleted node at position %d", position);
}
```

#### d. Delete First Occurrence of a Key

```c
void DeleteFirstOccurrence(Node** head, int key) {
    if (*head == NULL) {
        printf("\n List is empty");
        return;
    }

    Node* currentNode = *head;

    // Check if the first node contains the key
    if (currentNode->data == key) {
        *head = currentNode->next;
        free(currentNode);
        printf("\n Deleted the first occurrence of key %d", key);
        return;
    }

    // Traverse the list to find the key
    while (currentNode->next != NULL && currentNode->next->data != key) {
        currentNode = currentNode->next;
    }

    if (currentNode->next == NULL) {
        printf("\n Key %d not found in the list", key);
        return;
    }

    Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);
    printf("\n Deleted the first occurrence of key %d", key);
}
```

### 3. Print the List

```c
void PrintList(Node* head) {
    Node* currentNode = head;

    if (head == NULL) {
        printf("\n List is empty");
        return;
    }

    printf("\n head-->");
    while (currentNode != NULL) {
        printf(" %d --> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}
```

### 4. Search for a Key

```c
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
```

## Complete Example Program

```c
int main() {
    printf("\nSingly linked list demo!\n");
    Node* head = NULL;

    InsertAtStart(1, &head); // Insert 1 at the start
    InsertAtStart(2, &head); // Insert 2 at the start
    InsertAtStart(3, &head); // Insert 3 at the start
    PrintList(head); // Print the list

    SearchKey(head, 3); // Search for key 3

    InsertAtEnd(5, &head); // Insert 5 at the end
    PrintList(head); // Print the list

    insertAtPosition(&head, 100, 3); // Insert 100 at position 3
    PrintList(head); // Print the list

    DeleteAtStart(&head); // Delete the first node
    PrintList(head); // Print the list

    DeleteAtEnd(&head); // Delete the last node
    PrintList(head); // Print the list

    DeleteAtPosition(&head, 3); // Delete the node at position 3
    PrintList(head); // Print the list

    Delaead, 2); // Delete the first occurrence of key 2
    PrintList(head); // Print the list

    return 0;
}
```

### Summary

Singly linked lists provide a flexible data structure suitable for dynamic memory usage and efficient insertion/deletion. However, they have higher memory overhead and slower access times compared to arrays. By implementing operations like insertion, deletion, searching, and more, linked lists can solve various real-world problems efficiently.

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

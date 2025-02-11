# Circular Linked List

## Introduction
A **Circular Linked List** is a type of linked list where the last node is connected back to the first node, forming a circle. Unlike singly linked lists that end with a `NULL` pointer, circular linked lists provide continuous traversal through the nodes.

---

## Advantages of Circular Linked List
1. **Efficient Traversal:** Traversing all nodes is easy because the last node points back to the first node.
2. **Dynamic Memory Usage:** Like a singly linked list, it grows or shrinks dynamically as needed.
3. **Efficient Implementation of Queues:** Circular linked lists are often used to implement queues, especially in cases like round-robin scheduling.
4. **No Need for Null Termination:** Eliminates the need to check for `NULL` while traversing.
5. **Easier Concatenation:** Joining two circular linked lists is easier compared to singly linked lists.

---

## Real-Life Examples
1. **Round-Robin Scheduling:** Processes in a CPU are managed in a circular queue.
2. **Music Playlists:** Songs can be arranged in a circular list for continuous playback.
3. **Games:** Players in multiplayer games can be stored in a circular list to determine the next turn.

---

## Analogy
A circular linked list is like a group of friends standing in a circle and passing a ball. The ball keeps circulating, and there is no end to the chain.

---

## Circular Linked List vs Singly Linked List

| Feature                      | Circular Linked List                                | Singly Linked List                         |
|------------------------------|----------------------------------------------------|--------------------------------------------|
| **Traversal**                | Infinite, unless explicitly stopped.               | Ends when the `NULL` pointer is reached.   |
| **Memory Usage**             | Eliminates the need for `NULL` pointers.           | Requires a `NULL` pointer at the end.      |
| **Use Cases**                | Suitable for continuous operations or circular queues. | Commonly used for linear data traversal.   |
| **Complexity**               | Slightly more complex due to maintaining circular nature. | Simpler to implement and manage.          |
| **Concatenation**            | Easier to join two circular lists.                 | Requires traversal to find the last node.  |

---

## Circular Linked List Operations in C

### Structure Definition
```c
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

### Create List
```c
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
```

### Insert at the Start
```c
Node* insertAtStart(Node* tail, int value) {
    Node* newNode = createNode(value);

    if (!tail) { // Empty list
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = tail->next;
    tail->next = newNode;
    return tail; // Tail remains the same
}
```

### Insert at the End
```c
Node* insertAtEnd(Node* tail, int value) {
    Node* newNode = createNode(value);

    if (!tail) { // Empty list
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = tail->next;
    tail->next = newNode;
    return newNode; // Update tail to the new node
}
```

### Insert at a Position
```c
Node* insertAtPosition(Node* tail, int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return tail;
    }

    Node* newNode = createNode(value);

    if (!tail) { // Empty list
        if (position == 1) {
            newNode->next = newNode;
            return newNode;
        } else {
            printf("Invalid position!\n");
            free(newNode);
            return tail;
        }
    }

    Node* current = tail->next;
    for (int i = 1; i < position - 1 && current != tail; i++) {
        current = current->next;
    }

    if (current == tail && position > 2) {
        printf("Position out of bounds!\n");
        free(newNode);
        return tail;
    }

    newNode->next = current->next;
    current->next = newNode;

    if (current == tail) {
        return newNode; // Update tail if inserted at the end
    }

    return tail;
}
```

### Delete at Start
```c
Node* deleteAtStart(Node* tail) {
    if (!tail) {
        printf("List is empty!\n");
        return NULL;
    }

    Node* head = tail->next;

    if (head == tail) { // Only one node
        free(head);
        return NULL;
    }

    tail->next = head->next;
    free(head);
    return tail;
}
```

### Delete at End
```c
Node* deleteAtEnd(Node* tail) {
    if (!tail) {
        printf("List is empty!\n");
        return NULL;
    }

    Node* current = tail->next;

    if (current == tail) { // Only one node
        free(current);
        return NULL;
    }

    while (current->next != tail) {
        current = current->next;
    }

    current->next = tail->next;
    free(tail);
    return current; // Update tail to the second last node
}
```

### Delete at Position
```c
Node* deleteAtPosition(Node* tail, int position) {
    if (!tail || position < 1) {
        printf("Invalid operation!\n");
        return tail;
    }

    Node* current = tail->next;

    if (position == 1) { // Delete at start
        return deleteAtStart(tail);
    }

    for (int i = 1; i < position - 1 && current != tail; i++) {
        current = current->next;
    }

    if (current == tail || current->next == tail->next) {
        printf("Position out of bounds!\n");
        return tail;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);

    if (temp == tail) {
        return current; // Update tail if deleted last node
    }

    return tail;
}
```

### Search
```c
int search(Node* tail, int value) {
    if (!tail) {
        return -1; // List is empty
    }

    Node* current = tail->next;
    int position = 1;

    do {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    } while (current != tail->next);

    return -1; // Not found
}
```

### Print
```c
void printList(Node* tail) {
    if (!tail) {
        printf("List is empty!\n");
        return;
    }

    Node* current = tail->next;
    printf("Circular List: ");

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);

    printf("(back to start)\n");
}
```

### Main Method
```c
int main() {
    Node* tail = NULL; // Initialize an empty circular linked list

    // Insert nodes
    tail = insertAtEnd(tail, 10);
    tail = insertAtEnd(tail, 20);
    tail = insertAtStart(tail, 5);
    tail = insertAtPosition(tail, 15, 3);

    // Print the list
    printf("After insertions:\n");
    printList(tail);

    // Search for a value
    int searchValue = 15;
    int position = search(tail, searchValue);
    if (position != -1) {
        printf("Value %d found at position %d\n", searchValue, position);
    } else {
        printf("Value %d not found in the list\n", searchValue);
    }

    // Delete nodes
    tail = deleteAtStart(tail);
    tail = deleteAtEnd(tail);
    tail = deleteAtPosition(tail, 2);

    // Print the list after deletions
    printf("After deletions:\n");
    printList(tail);

    return 0;
}
```

---

## Conclusion
Circular linked lists are versatile and efficient for specific use cases, such as round-robin scheduling or implementing queues. Understanding their structure and operations can help you optimize memory usage and traversal in your programs.

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

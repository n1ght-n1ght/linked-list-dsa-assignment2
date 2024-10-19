#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* position;
typedef struct Node* list;

//Creating new node
position CreateNode(int data) {
    position newNode = malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

//Inserting new node after a given position
void Insert_mid(int X, position P) {
    position newNode = CreateNode(X);
    if (newNode != NULL) {
        newNode->next = P->next;
        P->next = newNode;
    } else {
        printf("Memory allocation failed\n");
    }
}

//Find previous node of given value
position FindPrevious(int X, list L) {
    position P = L;
    while (P->next != NULL && P->next->data != X) {
        P = P->next;
    }
    return P;
}

//Deleting a node with given value
void Delete(int X, list L) {
    position P = FindPrevious(X, L);
    if (P->next != NULL) {
        position tempCell = P->next;
        P->next = tempCell->next;
        free(tempCell);
    } else {
        printf("Node with value %d not found\n", X);
    }
}

//Printing the Linked list
void PrintList(list L) {
    position P = L->next;
    while (P != NULL) {
        printf("%d -> ", P->data);
        P = P->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = CreateNode(0);
    head->next = NULL;

    //Inserting the nodes into the list
    Insert_mid(10, head);
    Insert_mid(20, head);
    Insert_mid(30, head);

    printf("List after insertions:\n");
    PrintList(head);

    //Deleting node from the list
    Delete(20, head);
    printf("List after deleting 20:\n");
    PrintList(head);

    position current = head;
    while (current != NULL) {
        position temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

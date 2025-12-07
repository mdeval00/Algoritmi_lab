#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int random_broj() {
    return rand() % 91+10;
}

Node* push(Node* top) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = random_broj();
    new_node->next = top;
    printf("Push: %d\n", new_node->data);
    return new_node;
}

Node* pop(Node* top) {
    Node* temp = top;
    printf("Pop: %d\n", top->data);
    top = top->next;
    free(temp);
    return top;
}

Node* enqueue(Node* front) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = random_broj();
    new_node->next = NULL;
    printf("Enqueue: %d\n", new_node->data);

    if (front == NULL) {
        return new_node;
    }

    Node* current = front;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;

    return front;
}

Node* dequeue(Node* front) {
    if (front == NULL) {
        printf("Red je prazan!\n");
        return NULL;
    }

    Node* temp = front;
    printf("Dequeue: %d\n", temp->data);

    front = front->next;

    free(temp);
    return front;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void sesti_zad() {

    srand(time(NULL));

    printf("Primjer stoga\n\n");
    Node* stog = NULL;

    stog = push(stog);
    stog = push(stog);
    stog = push(stog);
    printList(stog);

    stog = pop(stog);
    stog = pop(stog);
    printList(stog);

    printf("\nPrimjer reda\n\n");
    Node* front = NULL;

    front = enqueue(front);
    front = enqueue(front);
    front = enqueue(front);
    printList(front);

    front = dequeue(front);
    front = dequeue(front);
    printList(front);

}

int main() {
    
    //sesti_zad();
   

    return 0;
}
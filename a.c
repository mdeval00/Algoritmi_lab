#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[100];
    char surname[100];
    int year;
    struct Person* next;
} Person;

Person* AddToStart(Person* head, char* name, char* surname, int year) {
    Person* newPers = (Person*)malloc(sizeof(Person));
    strcpy(newPers->name, name);
    strcpy(newPers->surname, surname);
    newPers->year = year;
    newPers->next = head;
    newPers->next = head;
    return newPers;
}

void printList(Person* head) {
    Person* current = head;
    while (current != NULL) {
        printf("%s %s (%d)\n", current->name, current->surname, current->year);
        current = current->next;
    }
}

Person* AddToEnd(Person* head, char* name, char* surname, int year) {
    Person* newPers = (Person*)malloc(sizeof(Person));
    strcpy(newPers->name, name);
    strcpy(newPers->surname, surname);
    newPers->year = year;
    newPers->next = NULL;

    Person* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPers;
    return head;
}

Person* findSurname(Person* head, char* surname) {
    Person* current = head;
    while (current != NULL) {
        if (strcmp(current->surname, surname) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Person* eraseEle(Person* head, char* surname) {

    if (strcmp(head->surname, surname) == 0) {
        Person* temp = head->next;
        free(head);
        return temp;
    }

    Person* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->surname, surname) == 0) {
            Person* za_brisanje = current->next;
            current->next = current->next->next;
            free(za_brisanje);
            return head;
        }
        current = current->next;
    }
    return head;
}


int main() {
    Person* head = NULL;

    head = AddToStart(head, "Ana", "Budimir", 1990);
    head = AddToStart(head, "Ivan", "Perisic", 1985);
    head = AddToEnd(head, "Marko", "Rog", 1995);

    printf("Lista:\n");
    printList(head);

    Person* found = findSurname(head, "Perisic");
    if (found != NULL) {
        printf("\nPronadeno: %s %s\n", found->name, found->surname);
    }

    head = eraseEle(head, "Budimir");
    printf("\nLista nakon brisanja:\n");
    printList(head);


    return 0;
}

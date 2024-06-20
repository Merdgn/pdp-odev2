#include "../include/LinkedList.h"
#include <stdlib.h>

// Yeni bir linked list oluşturur
LinkedListPtr createLinkedList(int satir , int sutun) {
    LinkedListPtr list = (LinkedListPtr)malloc(sizeof(struct LinkedList));
    if (list) {
        list->head = NULL;
        list->size = 0;
        list->satir = satir;
        list->sutun = sutun;
    }
    return list;
}

// Linked list'i yok eder ve hafızayı temizler
void destroyLinkedList(LinkedListPtr list) {
    while (list->head != NULL) {
        removeFront(list);
    }
    free(list);
}

// Linked list'in başına yeni bir düğüm ekler
void insertFront(LinkedListPtr list, Canli data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
    }
}

// Linked list'in sonuna yeni bir düğüm ekler
void insertEnd(LinkedListPtr list, Canli data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
        
        if (list->head == NULL) {
            list->head = newNode;
        } else {
            NodePtr current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        list->size++;
    }
}

// Linked list'in başındaki düğümü kaldırır
void removeFront(LinkedListPtr list) {
    if (list->head != NULL) {
        NodePtr temp = list->head;
        list->head = list->head->next;
        list->head->data->yoket(list->head->data);
        free(temp);
        list->size--;
    }
}

// Linked list'in sonundaki düğümü kaldırır
void removeEnd(LinkedListPtr list) {
    if (list->head != NULL) {
        if (list->head->next == NULL) {
            removeFront(list);
        } else {
            NodePtr current = list->head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
            list->size--;
        }
    }
}

// Linked list'in boyutunu döndürür
int getSize(const LinkedListPtr list) {
    return list->size;
}
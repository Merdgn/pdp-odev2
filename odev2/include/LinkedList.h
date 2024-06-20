#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Canli.h"
struct Node {
    Canli data;
    struct Node* next;
};
typedef struct Node* NodePtr;
struct LinkedList {
    NodePtr head;
    int size;
    int sutun;
    int satir;    
};

typedef struct LinkedList* LinkedListPtr;
LinkedListPtr createLinkedList(int satir , int sutun);
void destroyLinkedList(LinkedListPtr list);
void insertFront(LinkedListPtr list, Canli data);
void insertEnd(LinkedListPtr list, Canli data);
void removeFront(LinkedListPtr list);
void removeEnd(LinkedListPtr list);
int getSize(const LinkedListPtr list);

#endif 
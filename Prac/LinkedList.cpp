#include <stdlib.h>

typedef int LData;

typedef struct _node{
    LData data;
    struct _node *next;
} Node;

typedef struct _list{
    Node *cur;
    Node *head;
    int numOfData;
} List;

List* CreateList();
int InsertList(List*, LData);
LData LFirst(List*);
LData LNext(List*);

List* CreateList(){
    List *list;
    Node *dummy;

    list = (List*)malloc(sizeof(List));
    dummy = (Node*)malloc(sizeof(Node));

    list->cur = NULL;
    dummy->next = NULL;
    list->head = dummy;
    list->numOfData = 0;

    return list;
}

int InsertList(List *l, LData data){
    Node *newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = l->head;
    l->head = newNode;
    l->numOfData++;

    return l->numOfData;
}

LData LFirst(List *l){
    l->cur = l->head;
    return l->cur->data;
}

LData LNext(List *l){
    l->cur = l->cur->next;
    return l->cur->data;
}
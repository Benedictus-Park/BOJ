#include <stdlib.h>
#include <string.h>

typedef char DLData;

typedef struct _dnode{
    DLData data;
    struct _dnode *next;
    struct _dnode *prev;
} DNode;

typedef struct _dlist{
    DNode *cur;
    DNode *head;
    DNode *tail;
    int numOfData;
} DList;

DList* CreateDList();
void InsertDList(DList*, DLData);
DLData Next(DList*); // 구현 X
DLData Priv(DList*); // 구현 X

DList* CreateDList(){
    DList *dlist = (DList*)malloc(sizeof(DList));

    dlist->numOfData = 0;

    dlist->cur = NULL;
    dlist->head = (DNode*)malloc(sizeof(DNode));
    dlist->tail = (DNode*)malloc(sizeof(DNode));

    dlist->head->next = dlist->tail;
    dlist->head->prev = NULL;

    dlist->tail->next = NULL;
    dlist->tail->prev = dlist->head;

    return dlist;
}

void InsertDL(DList* dl, DLData d) {
    DNode *newNode = (DNode*)malloc(sizeof(DNode));

    newNode->data = d;
    newNode->next = dl->tail;
    newNode->prev = dl->tail->prev;

    dl->tail->prev->next = newNode;
    dl->tail->prev = newNode;

    dl->numOfData++;
}
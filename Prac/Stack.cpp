#include <stdlib.h>

typedef char SData;

typedef struct _snode{
    SData data;
    struct _snode *next;
    struct _snode *prev;
} SNode;

typedef struct _stack{
    SNode *head;
    SNode *tail;
    int numOfData;
} Stack;

Stack* CreateStack();
void Push(Stack*, SData);
SData Pop(Stack*);
SData Pick(Stack*);
void FreeStack(Stack*);

Stack* CreateStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));

    s->numOfData = 0;

    s->head = (SNode*)malloc(sizeof(SNode));
    s->tail = (SNode*)malloc(sizeof(SNode));

    s->head->next = s->tail;
    s->head->prev = NULL;

    s->tail->next = NULL;
    s->tail->prev = s->head;

    return s;
}

void Push(Stack* s, SData d) {
    SNode *newNode = (SNode*)malloc(sizeof(SNode));

    newNode->data = d;
    newNode->next = s->tail;
    newNode->prev = s->tail->prev;

    s->tail->prev->next = newNode;
    s->tail->prev = newNode;

    s->numOfData++;
}

SData Pop(Stack* s){
    SData rtn = s->tail->prev->data;
    SNode *rm = s->tail->prev;

    s->tail->prev = rm->prev;
    rm->prev->next = rm->next;

    free(rm);
    s->numOfData--;

    return rtn;
}

SData Pick(Stack* s){
    return s->tail->prev->data;
}

void FreeStack(Stack *s){
    for(int i = 0; i < s->numOfData; i++){
        Pop(s);
    }

    free(s->head);
    free(s->tail);
    free(s);
}
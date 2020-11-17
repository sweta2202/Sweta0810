#include<stdint.h>
#ifndef LINKED_H_INCLUDED
#define LINKED_H_INCLUDED

typedef struct _node_ Node;
struct _node_ {
int32_t data;
Node *next;
};

typedef struct _slist_ Slist;

struct _slist_{
Node *head;
Node *tail;
uint32_t length;
};

Slist     slist_new();
uint8_t   slist_lookup(const Slist *list, int32_t key);
uint32_t  slist_length (const Slist *list);
Slist*    slist_addnode_head(Slist *list, int32_t val);
Slist*    slist_addnode_tail(Slist *list, int32_t val);
Slist*    slist_delnode_head(Slist *list);
uint8_t   slist_minNode(Slist *list, int32_t key);
uint8_t   slist_maxNode(Slist *list, int32_t key);
#endif // LINKED_H_INCLUDED


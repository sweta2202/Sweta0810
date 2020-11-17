#include<stdlib.h>
#include<assert.h>
#include"linked.h"

Slist   slist_new(){
Slist s1 = {NULL, NULL, 0};
return s1;
}

uint32_t slist_length(const Slist *list){
assert(list != NULL);
return list->length;
}


static Node* _get_newnode(int32_t val) {
Node *newnode = (Node*)malloc(sizeof(Node));
newnode->data = val;
newnode->next = NULL;
return newnode;

}

Slist*   slist_addnode_head(Slist *list, int32_t val){
 assert(list != NULL);
 Node *newnode = _get_newnode(val);
 newnode->next = list->head;
 list->head = newnode;
 if(list->tail == NULL){
    list->tail =newnode;
 }
 ++list->length;

 assert( (list->length == 1 && list->head == list->tail) ||
         (list->length>1 && list->head != list->tail)
        );

  return list;
 }

Slist*   slist_addnode_tail(Slist *list, int32_t val){
 assert(list != NULL);
 Node *newnode = _get_newnode(val);
 if(list->tail != NULL){
    list->tail->next = newnode;
    list->tail = newnode;
 }
 else{
    list->head =list->tail=newnode;
 }
 ++list->length;
 assert((list->length == 1 && list->head == list->tail)||
        (list->length>1 && list->head != list->tail)
        );

return list;
 }

 uint8_t slist_lookup(const Slist *list, int32_t key)
 {
     assert(list != NULL);
     Node* cur = list->head;
     for(cur = list->head; cur != NULL; cur = cur->next){
        if(cur->data == key){
            break;
        }
     }
     return(cur != NULL);
 }

Slist*    slist_delnode_head(Slist *list){
 assert(list != NULL);
 Node *temp;
 if(list->head != NULL){
    temp = list->head;
    list->head = list->head->next;

if(list->head == NULL){
    list->tail = NULL;
}
 --list->length;
 free(temp);
 }
 return list;
 }


 Slist*    slist_delnode_tail(Slist *list){
 assert(list != NULL);
 Node *last, *cur;

 if (list->tail != NULL) {
    last = list->tail;

    if (list->head == list->tail){
        list->head = list->tail = NULL;
    }
    else {
        for (cur = list->head; cur->next != last; cur =cur->next);
        list->tail = cur;
        cur->next = NULL;
    }
    --list->length;
    free(last);
 }
 return list;
 }
/*
Slist*    slist_minNode(Slist *list, int32_t val){
assert(list != NULL);
Node *cur = list->head;
Node *min;
if(list->head == NULL){
    list->tail == NULL;
}
else{
    min = list->head->data;
    while(cur != NULL)
    {
        if(min>cur->data){
            min = cur->data;
        }
        cur = cur->next;
    }
    printf("minimum value %d\n",min);
}
return list;
}
*/

/*
Slist*    slist_maxNode(Slist *list, int32_t val){
assert(list != NULL);
Node *cur = list->head;
Node *max;
if(list->head == NULL){
    list->tail == NULL;
}
else{
    max = list->head->data;
    while(cur != NULL)
    {
        if(max<cur->data){
            max  = cur->data;
        }
        cur = cur->next;
    }

}
return list;
}
*/
 uint8_t slist_maxNode(Slist *list, int32_t key)
 {
     assert(list != NULL);
     Node* cur = list->head;
     Node *max;

  if(list->head == NULL){
    list->tail == NULL;
}
else{
    max = list->head->data;
     for(cur = list->head; cur != NULL; cur = cur->next)
        {
            if(max<cur->data){
            max  = cur->data;
            break;
        }

     }
     return(cur != NULL);
 }
 return list;
 }

 uint8_t slist_minNode(Slist *list, int32_t key)
 {
     assert(list != NULL);
     Node* cur = list->head;
     Node *min;

  if(list->head == NULL){
    list->tail == NULL;
}
else{
    min = list->head->data;
     for(cur = list->head; cur != NULL; cur = cur->next)
        {
            if(min>cur->data){
            min  = cur->data;
            break;
        }

     }
     return(cur != NULL);
 }
 return list;
 }

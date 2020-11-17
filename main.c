#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked.h"


void test_empty_list(){
Slist s1 = slist_new();
Slist *list = &s1;
assert(slist_length(list)==0);
}

void test_add_at_head(){
Slist s1 = slist_new();
Slist *list = &s1;
assert(slist_length(list) == 0);
list=slist_addnode_head(list,10);
assert(slist_length(list)==1);
list = slist_addnode_head(list,20);
list = slist_addnode_head(list,50);
assert(slist_length(list)==3);
assert(slist_lookup(list,20)==1);
assert(slist_maxNode(list,50)==1);
assert(slist_minNode(list,10)==1);
//assert(slist_maxNode(list,50)==1);
}

void test_delete_head(){
Slist s1 = slist_new();
Slist *list = &s1;
list = slist_addnode_head(list,10);
list = slist_addnode_head(list,20);
list = slist_addnode_head(list,30);
list = slist_delnode_head(list);
assert(slist_length(list)== 2);
assert(slist_lookup(list,30)== 0);
assert(slist_lookup(list,20)== 1);
//assert(slist_maxNode(list,20)==1);

}


void test_delete_tail(){
Slist s1 = slist_new();
Slist *list = &s1;
list = slist_addnode_tail(list,10);
list = slist_addnode_tail(list,20);
list = slist_addnode_tail(list,30);
list = slist_delnode_tail(list);
assert(slist_length(list)== 2);
assert(slist_lookup(list,30)== 0);
assert(slist_lookup(list,20)== 1);
list = slist_addnode_tail(list,40);
assert(slist_length(list) == 3);
assert(slist_lookup(list,40) == 1);

}


int main()
{
    test_add_at_head();
    /*test_empty_list();*/
   // test_delete_head();
   // test_delete_tail();
  // minNode();
     //maxNode();
    return 0;
}

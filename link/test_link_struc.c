#include <stdio.h>  
#include <stdlib.h>
#include <assert.h>
#include "set_link.h"
#include "link.h"
/*
static void test_set__find(void){
  struct set set;
  set;l=malloc(sizeof(struct link));
  set.l->head=malloc(sizeof(struct lelement));
  struct lelement *b=malloc(sizeof(struct lelement));
  struct lelement *c=malloc(sizeof(struct lelement));
  //set->l->head=SENTINEL;
 // printf("%ld\n",set__size(set));
  b->data=2;
  c->data=4;
  b->next=c;
  c->next=SENTINEL;
  set->l->head->data=1;
  set->l->head->next=b;
  printf("%d %d \n",find(set->l,3)->data,find(set->l,2)->next->data);
  assert(find(set->l,3)->data==2 && find(set->l,2)->next->data==2);
  printf( "find passed\n");
  assert(set__find(set,1)==1 && set__find(set,6)==0);
  printf("set_find passed\n");
  assert(set__size(set)==3);
  printf("set__size passed\n");
  set__print(set);
  int z=set__remove(set,1);
  printf("%d\n",z);
  set__print(set);
   z=set__remove(set,4);
    set__print(set);
     z=set__remove(set,2);
    set__print(set);

  set__free(set);

}
*/

static void test__size(void){
  struct set *s=set__empty();
  assert(set__size(s)==0);
  printf("set__size passed\n");
  set__free(s);
}


static void test__add(void){
  struct set *s=set__empty();
  int a=set__add(s,2);
  a=set__add(s,9);
  a=set__add(s,5);
  a=set__add(s,1);
  printf("a=%d size=%ld\n",a,set__size(s));
  printf("set__find=%d\n",set__find(s,2));
  a=set__add(s,3);
  printf("a=%d size=%ld\n",a,set__size(s));
  set__print(s);
  printf("%d %d %d %d %d\n",set__find(s,1),set__find(s,2),set__find(s,9), set__find(s,5),set__find(s,3));
  printf("set__size passed\n");
  set__remove(s,5);
  set__print(s);
  set__remove(s,2);
  set__print(s);
  set__remove(s,1);
  set__print(s);
  set__remove(s,3);
  set__print(s);
  set__remove(s,9);
  set__print(s);
  set__free(s);
}







int main(){
//test_set__find();
test__size();
test__add();

  return 0;
}

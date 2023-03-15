#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "link.h"
#include "set_link.h"

static void test_llm_next(void){
  struct lelement e3={3,NULL};
  struct lelement e2={2,&e3};
  struct lelement e1={1,&e2};
  struct lelement *next=llm__next(&e1);
  assert(next->data==2);
  assert(llm__next(next)->data==3);
  printf("llm__next passed\n");
}





static void test(void){
  struct set set;
  
  struct lelement a;
  struct lelement b;
  a.data=1;
  b.data=2;
  a.next=NULL;
  b.next=NULL;
  struct link lk=lnk__empty();
  set.l=&lk;
  
  int z=lnk__add_head(set.l,&b);;
  assert(z!=0 && set.l->head->data==2);
  z=lnk__add_head(set.l,&a);
  assert(set.l->head->data==1);
  printf("lnk__add_head passed\n");
  struct lelement *c=lnk__remove_head(set.l);
  assert( c->data==1 && set.l->head->data==2);
  printf("lnk__remove_head passed\n");
  //set__free(set);
  
}



static void test_lnk__add_after(void){
  struct link *l=malloc(sizeof(struct link));
  struct lelement *a=malloc(sizeof(struct lelement));
  struct lelement *b=malloc(sizeof(struct lelement));
  struct lelement *c=malloc(sizeof(struct lelement));
  a->data=1;
  b->data=2;
  c->data=3;
  a->next=c;
  c->next=NULL;
  b->next=NULL;
  l->head=a;
  int z=lnk__add_after(l,a,b);
  assert(z!=0 && l->head->data==1);
  assert(l->head->next->data==2);
  assert(l->head->next->next->data==3);
  struct lelement *tmp2=lnk__remove_after(l,a);
  assert(tmp2->data==2 && l->head->data==1);
  assert(l->head->next->data==3);
  printf("link__remove_after passed\n");
  free(a);
  free(b);
  free(c);
  free(l);

}
static void test_remove(void){
 struct set set;

  struct link lk;
  struct lelement d={4,SENTINEL};
   struct lelement c={3,&d};
    struct lelement b={2,&c};
  
  struct lelement a={1,&b};
  lk.head=&a;
  set.l=&lk;
  struct lelement *z=lnk__remove_after(&lk,&c);
  set__print(&set);
  z=lnk__remove_after(&lk,&b);
   set__print(&set);
    z=lnk__remove_after(&lk,&a);
    printf("%d",z->data);
   set__print(&set);
}




int main () {
  //printf("%s\n", __FILE__);
  test();
  test_llm_next();
  test_lnk__add_after();
  test_remove();
  
  
  return EXIT_SUCCESS;
}

#include <assert.h>
#include <stdio.h>

#include "set.h"

static void test_create_set(void) {
  printf("%s", __func__);

  struct set *st = set__empty();

  assert(set__is_empty(st));
  assert(set__size(st) == 0);
  assert(! set__find(st, 11));

  assert(set__remove(st, 78) != 0);

  set__free(st);

  printf("\t empty set OK\n");
}

static void test_set_add(void) {
  printf("%s", __func__);

  struct set *st = set__empty();

  assert(set__is_empty(st));
  assert(set__add(st,8)==0);
  assert(set__add(st,8)!=0);
  assert(set__size(st) == 1);
  assert(set__add(st,9)==0);
  assert( set__find(st, 8));

  //assert(set__remove(st, 78) != 0);

  set__free(st);

  printf("\t set_add OK\n");
}


static void test_set__filter(void){
  struct set *s=set__empty();
  int (*tmp)(int);
  tmp=impair;
  for(int i=0;i<8;i++) 
    set__add(s,i);
  struct set *se=set__filter(tmp,s);
  set__print(se);
  set__free(s);
  set__free(se);
}

int main(void) {
  printf("%s\n", __FILE__);

  test_create_set();
  test_set_add();
  test_set__filter();

  return 0;
}

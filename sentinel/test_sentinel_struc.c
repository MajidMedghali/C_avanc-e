#include <assert.h>
#include <stdio.h>

#include "set.h"
#include "set_sentinel.h"


static void test_set__is_empty (void){
  struct set se={{1,2,3,SET__BOUND}};
  struct set s={{SET__BOUND}};
  assert(set__is_empty(&se)==0);
  assert(set__is_empty(&s)==1);
  printf("set__is_empty passed\n");
}



static void test_set__remove_with_shift (void) {
  //printf("%s", __func__);

  
  struct set st = {{1,2,3,4, SET__BOUND}};

  set__remove(&st, 3);
  assert(st.s[0] == 1);
  assert(st.s[1] == 2);
  assert(st.s[2] == 4);
  assert(st.s[3] == SET__BOUND);

  set__remove(&st, 4);
  assert(st.s[0] == 1);
  assert(st.s[1] == 2);
  assert(st.s[2] == SET__BOUND);

  set__remove(&st, 1);
  assert(st.s[0] == 2);
  assert(st.s[1] == SET__BOUND);

  set__remove(&st, 2);
  assert(st.s[0] == SET__BOUND);
  

  printf("set__remove passed \n");
}


static void test_set__add_with_shift_right (void) {

struct set set={{2,4,5,7,8,SET__BOUND}};
set__add(&set,6);
assert(set.s[3]==6);
assert(set.s[4]==7);
set__add(&set,12);
assert(set.s[6]==12);
assert(set.s[7]==SET__BOUND);
printf("set__add and shift_right are passed\n");

}

static void test_set__find (void) {

struct set set={{2,4,5,7,8,SET__BOUND}};

assert(set__find(&set,2)!=0);
assert(set__find(&set,5)!=0);
assert(set__find(&set,10)==0);
printf("set__find passed\n");

}

static void test_set__filter(void){
  struct set se={{1,2,3,4,6,7,-1}};
  int (*tmp)(int x);
  tmp=impair;
  struct set *s=set__filter(tmp,&se);
  set__print(s);
  set__free(s);
}


int main () {
  printf("%s\n", __FILE__);

  test_set__remove_with_shift();
  test_set__add_with_shift_right();
  test_set__find();
  test_set__is_empty();
  test_set__filter();
  return 0;
}

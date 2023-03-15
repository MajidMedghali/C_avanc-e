#include <stdio.h>
#include <stdlib.h>
#include "set_dynamic.h"
#include <assert.h>


static void test_set_find(void){
    struct set *set=(struct set*)malloc(sizeof(struct set));
    set->s=malloc(sizeof(int)*5);
     for(int i=0;i<4;i++) set->s[i]=2*i; 
    set->capacity=5;
    set->size=4;
    assert(set__find(set,0!=0));
    assert(set__find(set,3)==0);
    assert(find(set->s,set->size,3)==2);
    assert(find(set->s,set->size,2)==1);
    set__free(set);
    printf("find and set__find are passed\n");
}


static void test_shift_right(void){
        struct set *set=(struct set*)malloc(sizeof(struct set));
        set->s=malloc(sizeof(int)*5);
        for(int i=0;i<4;i++) set->s[i]=2*i; 
        set->capacity=5;
        set->size=4;
       int a=set__add(set,1);
       /*for(int i=0;i<6;i++){
        set__print(set);

        set__add(set,i);
       }*/
       printf("%ld %ld\n",set->size,set->capacity);
        assert(set->size==5 && set->capacity==5);
        a=set__add(set,7);
        assert(set->size==6 && set->capacity==10 && a==0);
        a=set__add(set,0);
        assert(set->size==6 && set->capacity==10 && a!=0);
        a=set__add(set,1);
        assert(a!=0);
        printf("-------%d\n",a);
        //set__print(set);
        set__free(set);
        printf("set__add passed\n");
}


static void test_shift_left_set_remove(void){
    struct set *set=(struct set*)malloc(sizeof(struct set));
    set->s=malloc(sizeof(int)*6);
    for(int i=0;i<=4;i++) set->s[i]=2*i; 
    set->capacity=6;
    set->size=5;
    /*for(int i=0;i<5;i++){
        set__print(set);
        set__remove(set,(4-i)*2);
        
   // }
   // set__print(set);*/
     int a=set__remove(set,2);
     assert(set->size==4 && set->capacity==6 && a==0);
    a=set__remove(set,9);
    assert(set->size==4 && set->capacity==6  && a!=0);
     a=set__remove(set,4);
     assert(set->size==3 && set->capacity==3);
  
    //free(set->s);
    set__free(set);
    printf("set__remove passed\n");
}



int main(){
    test_set_find();
    test_shift_right();
    test_shift_left_set_remove();
    printf("good for all\n");
}


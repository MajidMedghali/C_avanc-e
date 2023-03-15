#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set_sentinel.h"



struct set *set__empty(void){
    struct set *set=(struct set*)malloc(sizeof(struct set));
    //struct set set;
    set->s[0]=SET__BOUND;
    return set;

}



int set__is_empty(const struct set* se){
    if(se->s[0]==SET__BOUND) return 1;
    return 0;
}

//1 si c existe 
int set__find(const struct set *se, int c){
   if(se->s[find(se->s,c)]==c) return 1;
   return 0;
}


size_t set__size(const struct set *se){
    size_t r=0;
    while(se->s[r]!=SET__BOUND)
    r++;
    return r;
}


int set__add(struct set *se, int c){
    if(set__size(se)+1==SET__SIZE || c<0 || set__find(se,c)==1) return -1;
    int tmp=find(se->s,c);
    shift_right(se->s,tmp);
    se->s[tmp]=c;
    return 0;
}



int set__remove(struct set *se, int c){
  if(set__is_empty(se) || set__find(se,c)==0) return -1;
  int tmp=find(se->s,c);
  shift_left(se->s,tmp);
  return 0;
}



void set__print(const struct set* se){
    for(size_t i=0;i<set__size(se);i++) printf("%d ",se->s[i]);
    printf("\n");
}

size_t find(int const s[], int c){
    int i=0;
    while(s[i]!=SET__BOUND){
        if(s[i]>=c) return i;
        i++;
    }
    return i;
}


void shift_right(int s[], size_t begin){
    if(s[begin]==SET__BOUND) s[begin+1]=SET__BOUND;
    else{
    int tmp=s[begin];
    int x=s[begin];
    size_t i=begin;
    while(s[i+1]!=SET__BOUND){
        tmp=s[i+1];
        s[i+1]=x;
        x=tmp;
        i++;
    }
    s[i+1]=x;
    s[i+2]=SET__BOUND; 
    }
}


void shift_left(int s[], size_t begin){
size_t i=begin;
while(s[i]!=SET__BOUND){
    s[i]=s[i+1];
    i++;
}    

}


void set__free(struct set* se ){
    free(se);
}

int pair(int a){
    return a%2==0;
}
int impair(int x){
    return x%2!=0;
}


struct set *set__filter(int (*func)(int),const struct set *s){
struct set *se=set__empty();
for(int i=0;i<(int)set__size(s);i++){
    if(func(s->s[i])) set__add(se,s->s[i]);
}
return se;

}




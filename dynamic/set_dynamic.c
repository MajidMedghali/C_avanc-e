#include <stdio.h>
#include <stdlib.h>
#include "set_dynamic.h"


/*struct set* set__empty(){
    struct set *set=(struct set*)malloc(sizeof(struct set));
    set->capacity=0;
    set->size=0;
    set->s=NULL;
    return set;
}*/


struct set *set__empty(){
    struct set *set=malloc(sizeof(struct set));
    set->s=NULL;
    set->capacity=0;
    set->size=0;
    return set;
}
int set__is_empty(const struct set* se){
    return se->size==0 ; 
}


// the end exclu
size_t find(int const s[], size_t end, int c){
    size_t x=0;
    while(x<end && s[x]<c) x++;
    return x;
}


// 0 si c n'existe pas


int set__find(const struct set *se, int c){
    if(se->size==0 || find(se->s,se->size,c)==se->size ) return 0;
    int i=find(se->s,se->size,c);
   return  se->s[i]==c;  
}



/*
int set__find(const struct set *se, int c){
    if(set__is_empty(se)) return 0;
    size_t tmp=find(se->s,se->size,c);
    if(tmp<se->size && se->s[tmp]==c) return 1;
    return 0;

}*/


size_t set__size(const struct set *se){
    return se->size;
}

//end exclus
void shift_right(int *s, size_t begin, size_t end){  
    size_t i=end;
    while(i>=begin+1){
        s[i]=s[i-1];
        i--;
    }  
}    
       
       
        /*int x=s[begin];
        int tmp=s[begin];
        for(size_t t=begin; t<end-1; t++){
            tmp=s[t+1];
            s[t+1]=x;
            x=tmp;
        }
        s[end]=tmp;*/

    


int set__add(struct set *se, int c){
    if(c<0 || set__find(se,c)!=0) return -1;
    int tmp=find(se->s,se->size,c);
    if(se->size==se->capacity){
        if(se->size==0){
            se->size=1;
            se->capacity=1;
            se->s=malloc(sizeof(int));
            se->s[0]=c;
            return 0;
        }
        se->s=realloc(se->s, sizeof(int)*2*(se->capacity));
        se->capacity=(se->capacity)*2;  
    }
    shift_right(se->s,tmp,se->size);
    se->s[tmp]=c;
    se->size++;
    return 0;

}




//to delete the value of the  index begin   
void shift_left(int s[], size_t begin, size_t end){
   if(end!=begin){ 
    size_t tmp=begin;
        while(tmp<=end-1){
            s[tmp]=s[tmp+1];
            tmp++;
    }
   }
}



int set__remove(struct set *se, int c){
    if(c<0 || set__is_empty(se)!=0 || set__find(se,c)==0)
        return -1;
    size_t tmp=find(se->s,se->size,c);
    shift_left(se->s,tmp,se->size-1);
    se->size--;
    if(se->size==0) {
        free(se->s);
        se->capacity=0;
        se->s=NULL;
        return 0;
    }
    if(se->size<=(se->capacity)/2){
        se->s=realloc(se->s,sizeof(int)*(se->capacity)/2);
        se->capacity=(se->capacity)/2;
    }
    return 0;
}


void set__print(const struct set *se){
    for(size_t i=0;i<se->size;i++){
        printf("%d ",se->s[i]);
    }
    printf("\n");
}

void set__free(struct set* se){
    free(se->s);
    free(se);
}



int pair(int a){
    return a%2==0;
}
int impair(int x){
    return x%2!=0;
}

struct set *set__filter(int (*func)(int) ,const struct set *s){
    struct set *se=set__empty();
    for(int i=0;i<(int)s->size;i++){
         if(func(s->s[i])) set__add(se,s->s[i]);
    }
return se;
}




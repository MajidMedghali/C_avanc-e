#include <stdio.h>
#include <stdlib.h>
#include "set_link.h"
#include "link.h"


#define SENTINEL ((struct lelement *) &sentinel)

struct lelement * find(struct link *l, int f){
    struct lelement *tmp=l->head;
    struct lelement *x=tmp;
    if(llm__is_end_mark(tmp) || tmp->data>=f) 
        return tmp;
    while(!llm__is_end_mark(tmp) && tmp->data<f){
        x=tmp;
        tmp=tmp->next;
    }
        return x;
}   

/*-------------------------------------------------------*/

struct set *set__empty(void){
    struct set *se=malloc(sizeof(struct set));
   //se->l=malloc(sizeof(struct link));
   struct link *lk=malloc(sizeof(struct link));
   *lk=lnk__empty();
   se->l=lk;
   return se;
}

/*--------------------------------------------------------------*/
int set__is_empty(const struct set* se){
    return llm__is_end_mark(se->l->head);
}


int set__find(const struct set *se, int c){
    if(set__is_empty(se)) return 0;
    struct lelement *tmp=find(se->l,c);
    if(tmp->data==c) return 1;
    return (!llm__is_end_mark(tmp->next) && tmp->next->data==c);
}


size_t set__size(const struct set *se){
    size_t a=0;
    if(se->l->head == SENTINEL) return a;
    struct lelement *tmp=se->l->head;
    while(!llm__is_end_mark(tmp)){
         tmp=llm__next(tmp);//(tmp);
       // if(llm__is_end_mark(tmp)) printf("oui");
        a++;
    }
    return a;
}

/*----------------------------------------------*/
int set__add(struct set *se, int c){
    if(c<0 ||  set__find(se,c)) 
        return -1;
    struct lelement *add=malloc(sizeof(struct lelement));
    add->data=c;
    add->next=NULL;
    struct lelement *after=find(se->l,c);
    if(set__is_empty(se) || after->data>c){
       int r=lnk__add_head(se->l,add);
        r=0;
        return r;
    }
    int a=lnk__add_after(se->l,after,add);
    a=0;
    return a;
}

/*------------------------------------------------------*/
int set__remove(struct set *se, int c){
    if(c<0 || set__find(se,c)==0 || llm__is_end_mark(se->l->head)) 
        return -1;
    struct lelement *after=find(se->l,c);
    if(se->l->head->data==c){
        struct lelement *tmp=lnk__remove_head(se->l);
        free(tmp);
        return 0;
    }   
    struct lelement *tmp=lnk__remove_after(se->l,after);
    tmp->data=0; /*-------------------*/
    free(tmp);
    return 0;
}

/*------------------------------------------------------------*/
void set__print(const struct set* se){
    struct lelement *tmp=lnk__first(se->l);
    while(!llm__is_end_mark(tmp)){
        printf("%d ",tmp->data);
        tmp=llm__next(tmp);
    }
    printf("\n");
}

/*-------------------------------------------------------------*/
void set__free(struct set *se){
    struct lelement *tmp=lnk__first(se->l);
    struct lelement *x=NULL;
    while(!llm__is_end_mark(tmp)){
        x=tmp->next;
        free(tmp);
        tmp=x;
    }
    free(se->l);
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
    struct lelement *tmp=lnk__first(s->l);
    while(!llm__is_end_mark(tmp)){
        if(func(tmp->data)) set__add(se,tmp->data);
        tmp=llm__next(tmp);
    }
    return se;

}



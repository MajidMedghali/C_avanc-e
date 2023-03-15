#include <assert.h>
#include <limits.h>
#include <stdlib.h>

#include "link.h"

const struct lelement sentinel = {INT_MAX, 
					 (struct lelement *) &sentinel}; 

/*------------------------------------------------------------*/
int llm__is_end_mark(const struct lelement *e){
	if(e==SENTINEL) return 1;
	return 0;
}

/*----------------------------------------------------------*/
struct lelement *llm__next(const struct lelement *e){
	return e->next;
}

/*----------------------------------------------*/
struct link lnk__empty(void){
	struct link lk={.head=SENTINEL};
	return lk;
}
/*------------------------------------------------------------*/
struct lelement *lnk__first(const struct link *l){
	struct lelement *tmp=l->head;
	return tmp;
}
/*----------------------------------------------------------*/
int lnk__add_head(struct link *l, struct lelement *add){
	if(add->next!=NULL || llm__is_end_mark(add)) return 0;
	struct lelement *tmp=l->head;
	l->head=add;
	add->next=tmp;
	return 1;
}
/*------------------------------------------------------------*/
struct lelement *lnk__remove_head(struct link *l){
	if(llm__is_end_mark(l->head)) 
		return NULL;
	struct lelement *tmp=l->head;
	struct lelement *r=tmp->next;
	l->head=r;
	tmp->next=NULL;
	return tmp;
}

/*-----------------------------------------------------------------*/
int lnk__add_after(struct link *l, struct lelement *after, struct lelement * add){
	if(llm__is_end_mark(after) || llm__is_end_mark(add) || after->next==NULL || add->next!=NULL ) 
		return 0;
	add->next=after->next;
	after->next=add;	
	return l->head->data+1;
}


struct lelement *lnk__remove_after(struct link *l, struct lelement *after){
	if(llm__is_end_mark(after->next	) ||after->next==NULL ) return NULL;
	struct lelement *tmp=l->head;
	tmp=after->next;
	after->next=tmp->next;
	tmp->next=NULL;
	return tmp;

}
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct cell{
	int val;
	struct cell *suiv;
};

struct s_fifo{
	struct cell *first;
	struct cell *last;
};
typedef struct s_fifo fifo;

void print_fifo(fifo xs){
	struct cell *c = xs.first;
	printf("[");
	while (c != NULL) {
	   printf("(%d)", c->val);
	   c = c->suiv;
	}
	  printf("]\n");
}

fifo *new_fifo(){
	fifo *new = malloc(sizeof(fifo));
	new->first = NULL;
	new->last = NULL;
	return new;
}

int is_empty(fifo xs){
	return (xs.first == NULL && xs.last == NULL);
}

fifo *add(int x, fifo *xs){
	if(xs == NULL){
		xs = new_fifo();
	}

	struct cell *c = malloc(sizeof(struct cell));
	c->val = x;
	c->suiv = NULL;

	if(is_empty(*xs)){
		xs->first = c;
		xs->last = c;
	}
	else{
		xs->last->suiv = c;
		xs->last = c;
	}

	return xs;
}

fifo *pop(fifo *xs){
	if(!is_empty(*xs)){
		struct cell *c = xs->first;

		xs->first = xs->first->suiv;
		free(c);
		
		if(xs->first == NULL)
			xs->last = NULL;
	}
	return xs;
}

int peek(fifo *xs){
	return xs->first->val;
}

int peekd(fifo *xs){
	assert(!is_empty(*xs));
	return xs->first->val;
}

int main(){
	fifo *ma_file = new_fifo();

	// print_fifo(*ma_file);

	ma_file = add(3, ma_file);
	ma_file = add(5, ma_file);
	// ma_file = add(7, ma_file);

	int val = peekd(ma_file);
	printf("%d\n", val);
	
	// print_fifo(*ma_file);

	return 0;
} 

#include "hashhead.h"

unsigned char hash(const char *str)
{
	unsigned int hash = 0;
	for (; *str; str++)
		hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;
	return hash>>24;
}
void insert(struct node *a[], char *word){
	unsigned char index;
	struct node *n, *p;
	p = findNode(word, a);
	if (p==NULL)
	{
		index = hash(word);
		n = (node*)malloc(sizeof(node*));
		strcpy_s(n->word,11, word);
		n->next = a[index];
		n->count = 1;
		a[index] = n;
	}
	else{
		p->count++;
	}
}

struct node *findNode(char *word, node* a[255]) {
	node *p;
	p = a[hash(word)];
	while (p && strcmp(p->word, word))
		p = p->next;
	return p;
}

void prntable(struct node *a[255]){
	int i;
	node *p;
	for (i = 0; i < 256; i++){
		p = a[i];
		while (p){
			printf("%s %d\n", p->word, p->count);
			p = p->next;
		}
	}
}

void prntable_f(struct node *a[255], FILE *f){
	int i;
	node *p;
	for (i = 0; i < 256; i++){
		p = a[i];
		while (p){
			fprintf(f,"%s %d\n", p->word, p->count);
			p = p->next;
		}
	}
}

int poscinstr(char *str, char c)
{
	unsigned int i;
	for (i = 0; i < strlen(str); i++){
		if (str[i] == c){
			return i;
		}
	}
	return -1;
}


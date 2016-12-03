#ifndef HASHHEAD_H
#define HASHHEAD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
void insert(struct node *a[], char *word);
unsigned char hash(const char *str);
void prntable(struct node *a[255]);
void prntable_f(struct node *a[255], FILE *f);
struct node *findNode(char *word, struct node *a[]);
typedef struct node
{
	char word[11];
	int count;
	struct node *next;
}node;

int poscinstr(char *str, char c);
#endif /*HASHHEAD_H*/
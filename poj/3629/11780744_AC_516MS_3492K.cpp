#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
}Lnode, *Linklist;

int cmp ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n, k, p, i, j, count;
	int re[50000], cnt = 0;
	scanf("%d %d %d", &n, &k, &p);
	Linklist L = NULL, H = NULL,T, E;
	Lnode *s;
	for(i = k; i >= 1; i--) {
		s = (Lnode *)malloc(sizeof(Lnode));
		s->num = i;
		s->next = L;
		if(i == k)
			E = s;
		L = s;
	}
	H = L;
	count = k;
	for(i = 1; i <= k; i++) {
		if(i % n == 0)
			re[cnt++] = H->num;
		H = H->next;
		count--;
		if(count == 1)
			break;
		for(j = 1; j <= p; j++) {
			T = H;
			H = H->next;
			E->next = T;
			T->next = NULL;
			E = T;
		}
	}
	re[cnt++] = H->num;
	qsort(re, cnt, sizeof(int), cmp);
	for(i = 0; i < cnt; i++)
		printf("%d\n", re[i]);
	return 0;
}

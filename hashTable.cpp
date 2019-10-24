#include "stdafx.h"

#define N 10
//  node 
struct Node
{
	int key;
	struct Node *next;
};
int hash(int b) {
	return b % 10;
}
void hashInsert(int b, Node *root)
{
	root[hash(b)].key = b;
}
bool search(int b, Node *root) {
	if (b == root[hash(b)].key)
		return true;
	return false;
}


/* Driver program to test above function*/
int main()
{
	printf("Hey!!!!\n");
	struct Node root[N];
	for (int i = 0;i < N;i++) {
		root[i].key = -1;
		root[i].next = NULL;
	}
	hashInsert(5, root);
	hashInsert(10, root);
	hashInsert(11, root);
	search(10, root) ? printf("Found\n") : printf("Not Found\n");
	search(1, root) ? printf("Found\n") : printf("Not Found\n");
	return 0;
}
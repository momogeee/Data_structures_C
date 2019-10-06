#include "stdafx.h"
#include <iostream>
struct node
{
	int data;
	struct node *next;
};
void print_list(node* head)
{
	node* tmp = head;
	while (tmp != NULL)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("%s", "\n");
}
void insert(int n, node*& head)
{
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	tmp->next = head;
	head=tmp;
	delete tmp;
}
void main() {
	node *head = NULL;
	for (int i = 0; i < 5; i++)
		insert(5 - i, head);
	print_list(head);
}
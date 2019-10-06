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
int print_listR(node* head) {
	if (head->next != NULL) {
		printf("%d->", print_listR(head->next));
		return head->data;
	}
	else {
		printf("%d", head->data);
		return NULL;
	}
	//printf("%d", head->data);


}
void insertTail(int a, node *head) {
	node *list = head, *tmp = new node;
	tmp->data = a;
	while (list->next != NULL)
		list = list->next;
	printf("%d\n", list->data);
	list->next = tmp;
	list->next->next = NULL;
}
void insert(int n, node*& head)
{
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	tmp->next = head;
	head = tmp;
	//delete tmp;
}
void main() {
	node *head = NULL;
	for (int i = 0; i < 5; i++)
		insert(5 - i, head);
	print_list(head);
	insertTail(9, head);
	print_list(head);

}
//mmmm
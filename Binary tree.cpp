// BinTreee.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node* createNewNode(int data) {
	node *leaf = new node;
	leaf->data = data;
	leaf->left = NULL;
	leaf->right = NULL;
	return leaf;
}
void print(node* leaf)
{
	if (leaf != NULL)
	{
		printf(" %d ", leaf->data);
		print(leaf->left);
		print(leaf->right);

	}
}
struct node * insert(struct node * &leaf, int data)
{
	if (leaf == NULL)
	{
		return createNewNode(data);
	}
	else
	{
		if (data < leaf->data)
		{
			leaf->left = insert(leaf->left, data);
		}
		else if (data >= leaf->data)
		{
			leaf->right = insert(leaf->right, data);
		}
		return leaf;
	}
}
bool full(node *root) {
	if (root != NULL) {
		bool r = full(root->right);
		bool l = full(root->left);
		if (r != l)
			return false;
		return true;
	}

}
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int height(node* leaf)
{
	if (leaf == NULL)
		return 0;
	else
	{
		int height_l = height(leaf->left);
		int height_r = height(leaf->right);
		return 1 + max(height_l, height_r);
	}
}
bool completed(node *root) {
	if (root != NULL) {
		if (height(root->right) != height(root->left))
			return false;
		return completed(root->right)*completed(root->left) * true;
	}
}


void printGivenLevel(node* leaf, int level)
{
	if (leaf != NULL)
	{
		if (level == 1)
		{
			for (int i = 0; i < height(leaf); i++)
				printf("   ");
			printf("%d", leaf->data);
			for (int i = 0; i < height(leaf); i++)
				printf("   ");
		}
		else //if (level > 1)
		{
			printGivenLevel(leaf->left, level - 1);
			printGivenLevel(leaf->right, level - 1);
		}

	}
}
void Checktype(node *root) {
	if (full(root))
		if (completed(root))
			printf("Completed\n");
		else
			printf("Full\n");
	else
		printf("Not Full\n");
}
void printLevelorder(node* leaf)
{
	for (int i = 1; i < height(leaf) + 1; i++)
	{
		printGivenLevel(leaf, i);
		printf("\n");
	}

}
int main()
{
	node *root = NULL;
	root = insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 2);
	insert(root, 8);
	insert(root, 12);
	insert(root, 20);
	printLevelorder(root);
	Checktype(root);
	return 0;
}


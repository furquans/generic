#include<stdio.h>
#include<stdlib.h>

#include "tree.h"

void print_node(void *data)
{
	int *dataptr = (int *)data;
	printf("Data:%d\n",*dataptr);
}

void destroy_node(void *data)
{
	
}

int traverse(void *data,
	     char is_leaf)
{
	printf("data:%d\n",*(int *)data);
	if (is_leaf)
		return 0;
	return 1;
}

int main()
{
	struct tree_node *root;
	struct tree_node *left, *right;
	int i = 1,j=2,k=3;

	root = create_tree_node(&i);
	left = create_tree_node(&j);
	right = create_tree_node(&k);

	TREE_ADD(root, left, left);
	TREE_ADD(root, right, right);

	traverse_path(root,traverse);
	destroy_tree(root,destroy_node);
}

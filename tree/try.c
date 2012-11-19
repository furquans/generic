#include<stdio.h>
#include<stdlib.h>

#include "tree.h"

struct node {
	int *data;
	int myval;
};

int traverse(void *data,
	     int child)
{							
	struct node *dataptr = (struct node*)data;
	printf("data:%d\n",dataptr->myval);
	if (child == 0)
		return -1;
	if (dataptr->data[0] == 2)
		return 0;
	if (dataptr->data[2] == 7)
		return 2;
}

void destroy(void *data)
{
	struct node *dataptr = (struct node*)data;

	if(dataptr->data)
		free(dataptr->data);
	free(dataptr);
}

struct tree_node *create_node()
{
	struct node *node;
	struct tree_node *tmp;
	int num,i;
	static int count = 0;

	count++;

	node = malloc(sizeof(*node));
	printf("Enter number of children for %d:\n",count);
	scanf("%d",&num);
	node->data = NULL;
	if (num) {
		node->data = malloc(sizeof(int)*num);
	}
	node->myval = count;

	tmp = create_tree_node(node, num);

	for(i=0;i<num;i++) {
		node->data[i] = count+i+1;
		add_child(tmp,create_node());
	}
	return tmp;
}

int main()
{
	struct tree_node *root;
	int i = 1;

	root = create_node();

	traverse_path(root,traverse);

	destroy_tree(root,destroy);
}

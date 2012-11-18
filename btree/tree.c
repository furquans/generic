/*
 * File : tree.c
 * Desc : Generic implementation of a binary tree
 * Auth : Furquan Shaikh
 * Date : 11/18/2012
 */
#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

struct tree_node *create_tree_node(void *data)
{
	struct tree_node *tmp = malloc(sizeof(*tmp));
	tmp->left = tmp->right = NULL;
	tmp->data = data;

	return tmp;
}

void inorder_tree(struct tree_node *node,
		  tree_fn fnptr)
{
	if (node) {
		inorder_tree(node->left,fnptr);
		if (fnptr) {
			fnptr(node->data);
		}
		inorder_tree(node->right,fnptr);
	}
}

void preorder_tree(struct tree_node *node,
		   tree_fn fnptr)
{
	if (node) {
		if (fnptr) {
			fnptr(node->data);
		}
		preorder_tree(node->left,fnptr);
		preorder_tree(node->right,fnptr);
	}
}

void postorder_tree(struct tree_node *node,
		    tree_fn fnptr)
{
	if (node) {
		postorder_tree(node->left,fnptr);
		postorder_tree(node->right,fnptr);
		if (fnptr) {
			fnptr(node->data);
		}
	}
}

void traverse_path(struct tree_node *node,
		   tree_trav_fn fnptr)
{
	int ret;

	if (fnptr == NULL) {
		return;
	}

	do {
		if (node) {
			ret = fnptr (node->data,
				     (node->left || node->right)?0:1);
			if (ret == 1) {
				node = node->right;
			} else if (ret == -1) {
				node = node->left;
			}
		} else {
			ret = fnptr (NULL, 0);
		}
	} while (ret);
}

void destroy_tree(struct tree_node *node,
		  tree_fn fnptr)
{
	if (node) {
		struct tree_node *left = node->left, *right = node->right;
		if (fnptr) {
			fnptr(node->data);
		}
		free(node);
		destroy_tree(left,fnptr);
		destroy_tree(right,fnptr);
	}
}


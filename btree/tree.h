/*
 * File : tree.h
 * Desc : Header file for generic implementation of a binary tree
 * Auth : Furquan Shaikh
 * Date : 11/18/2012
 */

#ifndef __TREE_H__
#define __TREE_H__

struct tree_node {
	struct tree_node *left, *right;
	void *data;
};

#define TREE_ADD(p,c,d) p->d = c
#define TREE_CHILD(p,d) p->d

typedef void (*tree_fn)(void *);
typedef int (*tree_trav_fn)(void *,char);

struct tree_node *create_tree_node(void *);
void inorder_tree(struct tree_node *,tree_fn);
void preorder_tree(struct tree_node *,tree_fn);
void postorder_tree(struct tree_node *,tree_fn);
void traverse_path(struct tree_node *,tree_trav_fn);
void destroy_tree(struct tree_node *,tree_fn);

#endif //__TREE_H__

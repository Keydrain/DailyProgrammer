/*
Binary Tree for C
Author: Keydrain
Date:   03/26/15

Nodes contain an id, pointer to data, left and right children.
*/

#ifndef HEAD
#define HEAD

struct node{
	int id;
	struct cell *data;
	struct node *left;
	struct node *right;
};

void insert(int id, struct node **leaf, struct cell *data){
	if (*leaf == 0){
		*leaf = (struct node*) malloc(sizeof(struct node));
		(*leaf)->id = id;
		(*leaf)->left = 0;
		(*leaf)->right = 0;
		(*leaf)->data = data;
	} else if (id < (*leaf)->id){
		insert(id, &(*leaf)->left, data);
	} else if (id > (*leaf)->id){
		insert(id, &(*leaf)->right, data);
	}
};

struct node *search(int id, struct node *leaf){
	if (leaf != 0){
		if (id == leaf->id){
			return leaf;
		} else if (id < leaf->id){
			return search(id, leaf->left);
		} else if (id > leaf->id){
			return search(id, leaf->right);
		} else {
			return 0;
		}
	} else {
		return 0;
	}
};

void destroy(struct node *leaf){
	if (leaf != 0){
		destroy(leaf->left);
		destroy(leaf->right);
		free(leaf->data);
		free(leaf);
	}
};

#endif
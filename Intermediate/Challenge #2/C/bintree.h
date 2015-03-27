/*
Binary Tree header for C
Author: Keydrain
Date:   03/26/15

Nodes contain an id, description, left and right children.
*/

#ifndef HEAD
#define HEAD

struct node{
	int id;
	//char description[180]; // Note: rather than this, have a pointer that points to a node of a linked list of heterogeneous types. 
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
		(*leaf)->data = 0;
		//strcpy((*leaf)->description, description);
	} else if (id < (*leaf)->id){
		insert(id, &(*leaf)->left, (*leaf)->data);
	} else if (id > (*leaf)->id){
		insert(id, &(*leaf)->right, (*leaf)->data);
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

/* char *read(struct node *leaf){
	return leaf->description;
} */

struct cell *read(struct node *leaf){
	return leaf->data;
}

void destroy(struct node *leaf){
	if (leaf != 0){
		destroy(leaf->left);
		destroy(leaf->right);
		free(leaf);
	}
};

#endif
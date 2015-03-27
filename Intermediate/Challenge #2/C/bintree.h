#ifndef HEAD
#define HEAD

struct node{
	int id;
	char description[180];
	struct node *left;
	struct node *right;
};

void insert(int id, struct node **leaf, char *description){
	if (*leaf == 0){
		*leaf = (struct node*) malloc(sizeof(struct node));
		(*leaf)->id = id;
		(*leaf)->left = 0;
		(*leaf)->right = 0;
		strcpy((*leaf)->description, description);
	} else if (id < (*leaf)->id){
		insert(id, &(*leaf)->left, (*leaf)->description);
	} else if (id > (*leaf)->id){
		insert(id, &(*leaf)->right, (*leaf)->description);
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

char *read(struct node *leaf){
	return leaf->description;
}

void destroy(struct node *leaf){
	if (leaf != 0){
		destroy(leaf->left);
		destroy(leaf->right);
		free(leaf);
	}
};

#endif
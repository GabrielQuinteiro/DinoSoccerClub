#ifndef _BINTREE_H_
#define _BINTREE_H_

typedef struct node{
	char* data;
	struct node* left, * right;
}Node;

typedef struct{
	Node* root;
}Bin_tree;

void insert_left(Node* node, char* data);
void insert_right(Node* node, char* data);
void insert(Bin_tree* tree, char* data);

void print_tree(Node* node);

#endif // !_BINTREE_H_

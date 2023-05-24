#ifndef _BINTREE_H_
#define _BINTREE_H_

#define MAX_CHAR 256

typedef struct node {
	//Precisa limitar uma quantidade fixa de caracters, sen�o vai ter que fazer aloca��o din�mica!
	char data[MAX_CHAR];
	struct node* left, * right;
}Node;

typedef struct {
	Node* root;
}Bin_tree;

void insert_left(Node* node, char* data);
void insert_right(Node* node, char* data);
void insert(Bin_tree* tree, char* data);
Node* inserir(Node* root, char* data);

void print_tree(Node* node);

#endif // !_BINTREE_H_

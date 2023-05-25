#ifndef _BINTREE_H_
#define _BINTREE_H_

#define MAX_CHAR 256

typedef struct {
	char nome[MAX_CHAR];
	char posicao[MAX_CHAR];
	int idade;
	int habilidade;
	int camisa;
}Dino;

typedef struct node {
	Dino* dino;
	struct node* left, * right;
}Node;

typedef struct {
	Node* root;
}Bin_tree;

typedef struct search_result {
	int found;
	char* data;
} SearchResult;

void insert_left(Node* node, char* data);
void insert_right(Node* node, char* data);
void insert(Bin_tree* tree, char* data);
Node* inserir(Node* root, char* data);

void print_tree(Node* node);

SearchResult buscar(Node* root, char* data);

#endif // !_BINTREE_H_

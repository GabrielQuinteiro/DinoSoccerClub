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
	char* nome;
} SearchResult;

void insert(Bin_tree* tree, char* data);
Node* inserir(Node* root, char* data);

void print_tree(Node* node);

Node* buscar(Node* root, char* data);

#endif // !_BINTREE_H_

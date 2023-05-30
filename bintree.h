#ifndef _BINTREE_H_
#define _BINTREE_H_

#ifdef __unix__
#include <stdlib.h>
#include <unistd.h>

#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#endif

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

void formulario_dino(Dino* dino);
Node* inserir(Node* root, Dino* dino);

Node* buscar(Node* root, char* nome_jogador);
Node* remover(Node* root, char* nome_jogador);

void print_dino(Dino* dino);
void print_tree(Node* node);


#endif // !_BINTREE_H_

#include "bintree.h"
#include <string.h>

//Funcoes estaticas so funcionam dentro desse arquivo
static Node* insert_sub(Dino* dino) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node)
	{
		memset(new_node, 0, sizeof(Node));
		new_node->dino = dino;		
	}
	else
	{
		printf("Erro ao alocar novo no");
	}
	return new_node;
}

Node* inserir(Node* root, Dino* dino)
{
	if (root == NULL)
	{
		Node* new_node = insert_sub(dino);
	}
	else
	{
		int compare = strcmp(dino->nome, root->dino->nome);
		if (compare < 0)
		{
			root->left = inserir(root->left, dino);
			
		}
		else if (compare > 0)
		{
			root->right = inserir(root->right, dino);
		}
		else
		{
			printf("Já existe");
		}

		return root;
	}
}

Node* buscar(Node* root, char* nome_jogador)
{
	if (root == NULL)
	{
		return root;
	}
	else
	{
		int compare = strcmp(nome_jogador, root->dino->nome);
		if (compare == 0)
		{
			return root;
		}
		else if (compare < 0)
		{
			return buscar(root->left, nome_jogador);
		}
		else
			return buscar(root->right, nome_jogador);
	}
}

void print_dino(Dino* dino) 
{
	printf("Nome: %s | Posicao: %s | Idade: %d | Habilidade: %d | Camisa: %d \n", dino->nome, dino->posicao, dino->idade, dino->habilidade, dino->camisa);
	
}

void print_tree(Node* node)
{
	if (node != NULL)
	{
		print_tree(node->left);
		printf("Nome: %s | Posicao: %s | Idade: %d | Habilidade: %d | Camisa: %d \n", node->dino, node->dino->posicao, node->dino->idade, node->dino->habilidade, node->dino->camisa);
		print_tree(node->right);
	}
}

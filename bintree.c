#include "bintree.h"
#include <string.h>

//Fun��es est�ticas s� funcionam dentro desse arquivo
static Node* insert_sub(Dino* dino) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	//memset(new_node, 0, sizeof(Node));
	//strcpy(&new_node->dino->nome, dino.nome);
	if (new_node)
	{
		new_node->dino = dino;
		new_node->left = NULL;
		new_node->right = NULL;
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

/* SearchResult buscar(Node* root, char* data)
{
	SearchResult result = { 0 };

	if (root == NULL)
	{
		return result;
	}
	else
	{
		int compare = strcmp(data, root->data);
		if (compare == 0)
		{
			result.found = 1;
			result.data = malloc(strlen(root->data) + 1);  // aloca memória para a string
			strcpy(result.data, root->data);
			return result;
		}
		else if (compare < 0)
		{
			return buscar(root->left, data);
		}
		else
			return buscar(root->right, data);
	}
}
*/
void print_dino(Dino* dino) 
{
	printf("Nome: %s | Posicao: %s | Idade: %d | Habilidade: %d | Camisa: %d ", dino->nome, dino->posicao, dino->idade, dino->habilidade, dino->camisa);
	
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

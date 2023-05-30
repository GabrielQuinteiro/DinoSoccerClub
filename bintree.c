#include "bintree.h"
#include <string.h>

void formulario_dino(Dino* dino)
{
	memset(dino, 0, sizeof(Dino));

	printf("\nDigite o nome: ");
	scanf("%256[^\n]", dino->nome);
	getchar();

	printf("Infomre a posição: ");
	scanf("%256[^\n]", dino->posicao);
	getchar();

	printf("Digite a idade: ");
	scanf("%d", &dino->idade);

	printf("Informe a habilidade: ");
	scanf("%d", &dino->habilidade);

	printf("Informe o numero da camiseta: ");
	scanf("%d", &dino->camisa);
	printf("\n");
}

/* Funcoes estaticas so funcionam dentro desse arquivo */
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
			printf("\nDinossauro já cadastrado\n");
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

Node* remover(Node* root, char* nome_jogador)
{
	if (root == NULL)
	{
		printf("Jogador nao encontrado.");
		return NULL;
	}
	else
	{
		int compare = strcmp(nome_jogador, root->dino->nome);
		if (compare == 0)
		{
			/* remove nós sem filhos(folhas) */
			if (root->left == NULL && root->right == NULL)
			{
				free(root);
				printf("\nJogador %s removido com sucesso.\n", nome_jogador);
				return NULL;
			}
			else
			{
				/* remove nós que apenas possuem 1 filho */
				if (root->left == NULL || root->right == NULL)
				{
					Node* aux;

					if (root->left != NULL)
						aux = root->left;
					else
						aux = root->right;

					free(root);
					return aux;
				}
				/* remove nós que possuem 2 filhos */
				else
				{
					Node* aux = root->left;
					while (aux->right != NULL)
					{
						aux = aux->right;
					}

					Dino* d; 
					d = root->dino;
					root->dino = aux->dino;
					aux->dino = d;

					root->left = remover(root->left, nome_jogador);
					return root;
				}
			}
		}
		else
		{
			if (compare < 0)
				root->left = remover(root->left, nome_jogador);
			else
				root->right = remover(root->right, nome_jogador);

			return root;
		}
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
		printf("Nome: %s | Posicao: %s | Idade: %d | Habilidade: %d | Camisa: %d \n", node->dino->nome, node->dino->posicao, node->dino->idade, node->dino->habilidade, node->dino->camisa);
		print_tree(node->right);
	}
}

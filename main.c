#include <stdio.h>
#include "bintree.h"

int main()
{
	int opcao;
	Dino* dino;
	Bin_tree tree;
	tree.root = NULL;
	Node* result;

	do
	{
		printf("*******************************************************\n");
		printf("*                    DinoSoccerClub                   *\n");
		printf("*******************************************************\n");

		printf("=======================================================\n");
		printf("|                 Escolha uma opção                   |\n");
		printf("|=====================================================|\n");
		printf("| 1. Inserir                                          |\n");
		printf("|-----------------------------------------------------|\n");
		printf("| 2. Imprimir                                         |\n");
		printf("|-----------------------------------------------------|\n");
		printf("| 3. Buscar por nome                                  |\n");
		printf("|-----------------------------------------------------|\n");
		printf("| 0. Sair                                             |\n");
		printf("=======================================================\n");
		printf("Digite sua opção: ");
		scanf("%d", &opcao);
		getchar();


		if (opcao == 0)
		{
			printf("\nSaindo...\n");
		}
		else if (opcao == 1)
		{
			dino = malloc(sizeof(Dino));
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

			tree.root = inserir(tree.root, dino);
		}
		else if (opcao == 2)
		{
			printf("\n\nLista de Jogadores: \n\n");
			print_tree(tree.root);
			printf("\n");
		}
		else if (opcao == 3)
		{
			char nome_jogador[MAX_CHAR];
			printf("\nDigite o nome do jogador que deseja buscar: ");
			scanf("%256[^\n]", &nome_jogador);
			getchar();

			result = buscar(tree.root, nome_jogador);
			if (result)
				print_dino(result->dino);
			else
				printf("Jogador %s não encontrado.\n", nome_jogador);
		}
		else
		{
			printf("\nOpção invalida\n");
		}
	} while (opcao != 0);

	return 0;
}

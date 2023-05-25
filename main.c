#include <stdio.h>
#include "bintree.h"

int main()
{
	int opcao;
	Dino* dino;
	Bin_tree tree;
	SearchResult result;
	tree.root = NULL;

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


		switch (opcao)
		{
		case 0:
			printf("\nSaindo...\n");
			break;

		case 1:
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
			//insert(&tree, data);
			break;
		case 2:
			printf("\n\nLista de Jogadores: \n\n");
			print_tree(tree.root);
			printf("\n");
			break;
		case 3:
			/* printf("Digite o nome: ");
			scanf("%256[^\n]", &data);
			result = buscar(tree.root, data);
			if (result.found)
				printf("Dado encontrado: %s\n", result.data);
			else
				printf("Dado não encontrado.\n");
			*/
			break;
			
		default:
			printf("\nOpção invalida\n");
		}
	} while (opcao != 0);

	return 0;
}

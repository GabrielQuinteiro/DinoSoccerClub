#include <stdio.h>
#include "bintree.h"

int main()
{
	int op;
	char data[MAX_CHAR];
	Bin_tree tree;
	SearchResult result;
	tree.root = NULL;

	do
	{
		printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Buscar por nome\n");
		scanf("%d", &op);
		fflush(stdin);

		switch (op)
		{
		case 0:
			printf("\nSaindo...\n");
			break;

		case 1:
			printf("Digite um valor: ");
			scanf("%255[^\n]", data);
			tree.root = inserir(tree.root, data);
			//insert(&tree, data);
			break;
		case 2:
			printf("\nImpressão da Árvore Binária: \n");
			print_tree(tree.root);
			break;
		case 3:
			printf("Digite o nome: ");
			scanf("%255[^\n]", data);
			result = buscar(tree.root, data);
			if (result.found)
				printf("Dado encontrado: %s\n", result.data);
			else
				printf("Dado não encontrado.\n");
			break;

		default:
			printf("\nOpção invalida\n");
		}
	} while (op != 0);

	return 0;
}

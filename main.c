#include <stdio.h>
#include "bintree.h"

int main()
{
	int op;
	char data[40];
	Bin_tree tree;
	tree.root = NULL;

	do
	{
		printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n");
		scanf("%d", &op);

		switch (op)
		{
		case 0:
			printf("\nSaindo...\n");
			break;

		case 1:
			printf("Digite um valor: ");
			scanf("%s", &data);
			insert(&tree, data);
			break;
		case 2:
			printf("\nImpressão da Árvore Binária: \n");
			print_tree(tree.root);
			break;
		default:
			printf("\nOpção invalida\n");
		}
	} while (op != 0);

	return 0;
}

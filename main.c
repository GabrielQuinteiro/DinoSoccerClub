#include <stdio.h>
#include "bintree.h"

#ifdef __unix__
#include <stdlib.h>
#include <unistd.h>

#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#endif

int main()
{
	int opcao;
	Dino* dino;
	Bin_tree tree;
	tree.root = NULL;
	Node* result;

	do
	{
		#ifdef OS_Windows
		system("cls");
		#else
		system("clear");
		#endif

		printf("*******************************************************\n");
		printf("*                    DinoSoccerClub                   *\n");
		printf("*******************************************************\n");

		printf("=======================================================\n");
		printf("|                 Escolha uma opção                   |\n");
		printf("|=====================================================|\n");
		printf("| 1. Cadastrar novo jogador                           |\n");
		printf("|-----------------------------------------------------|\n");
		printf("| 2. Exibir jogadores                                 |\n");
		printf("|-----------------------------------------------------|\n");
		printf("| 3. Buscar jogador                                   |\n");
		printf("|-----------------------------------------------------|\n");
		printf("| 4. Remover jogador                                  |\n");
		printf("|-----------------------------------------------------|\n");
		printf("| 0. Sair                                             |\n");
		printf("=======================================================\n");
		printf("Digite sua opção: ");
		scanf("%d", &opcao);
		getchar();


		if (opcao == 0)
		{
			printf("=======================================================\n");
			printf("|                  Fim do Programa!                   |\n");
			printf("=======================================================\n");
		}
		else if (opcao == 1)
		{
			dino = (Dino*)malloc(sizeof(Dino));
			formulario_dino(dino);

			tree.root = inserir(tree.root, dino);

			printf("Jogador salvo com sucesso!\n\n");

			#ifdef OS_Windows
			system("pause");
			#else
			system("echo 'Pressione enter para continuar...'; read dummy;");
			#endif
		}
		else if (opcao == 2)
		{
			#ifdef OS_Windows
			system("cls");
			#else
			system("clear");
			#endif

			printf("\n\nLista de Jogadores: \n\n");
			print_tree(tree.root);
			printf("\n");

			#ifdef OS_Windows
			system("pause");
			#else
			system("echo 'Pressione enter para continuar...'; read dummy;");
			#endif
		}
		else if (opcao == 3)
		{
			char nome_jogador[MAX_CHAR];
			printf("\nDigite o nome do jogador que deseja buscar: ");
			scanf("%256[^\n]", &nome_jogador);
			getchar();

			#ifdef OS_Windows
			system("cls");
			#else
			system("clear");
			#endif
			result = buscar(tree.root, nome_jogador);
			if (result)
				print_dino(result->dino);
			else
				printf("Jogador %s não encontrado.\n", nome_jogador);

			printf("\n");

			#ifdef OS_Windows
			system("pause");
			#else
			system("echo 'Pressione enter para continuar...'; read dummy;");
			#endif
		}
		else if (opcao == 4)
		{
			char nome_jogador[MAX_CHAR];
			printf("Informe o nome do jogador a ser removido: ");
			scanf("%256[^\n]", &nome_jogador);
			getchar();

			remover(tree.root, nome_jogador);
			#ifdef OS_Windows
			system("pause");
			#else
			system("echo 'Pressione enter para continuar...'; read dummy;");
			#endif
		}
		else
		{
			printf("\nOpção invalida\n");
			#ifdef OS_Windows
			system("pause");
			#else
			system("echo 'Pressione enter para continuar...'; read dummy;");
			#endif
		}
	} while (opcao != 0);

	return 0;
}

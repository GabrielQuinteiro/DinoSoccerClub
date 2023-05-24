#include "bintree.h"
#include <string.h>

//Fun��es est�ticas s� funcionam dentro desse arquivo
static Node* insert_sub(char* data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	memset(new_node, 0, sizeof(Node));
	strcpy(&new_node->data, data);
	return new_node;
}
/* 
void insert_left(Node* node, char* data)
{
	if (node->left == NULL)
	{
		Node* new_node = insert_sub(data);
		node->left = new_node;
	}
	else
	{
		int compare = strcmp(data, node->left->data);
		if (compare < 0)
		{
			insert_left(node->left, data);
		}
		else
		{
			insert_right(node->left, data);
		}
	}
}

void insert_right(Node* node, char* data)
{
	if (node->right == NULL)
	{
		Node* new_node = insert_sub(data);
		node->right = new_node;
	}
	else
	{
		int compare = strcmp(data, node->right->data);
		if (compare > 0)
		{
			insert_right(node->right, data);
		}
		else
		{
			insert_left(node->right, data);
		}
	}
}


void insert(Bin_tree* tree, char* data)
{
	if (tree->root == NULL)
	{
		Node* new_node = insert_sub(data);
		tree->root = new_node;
	}
	else
	{
		int compare = strcmp(data, tree->root->data);
		if (compare < 0)
		{
			insert_left(tree->root, data);
		}
		else
		{
			insert_right(tree->root, data);
		}
	}
}*/

Node* inserir(Node* root, char* data)
{
	if (root == NULL)
	{
		Node* new_node = insert_sub(data);
	}
	else
	{
		int compare = strcmp(data, root->data);
		if (compare < 0)
		{
			root->left = inserir(root->left, data);
			
		}
		else if (compare > 0)
		{
			root->right = inserir(root->right, data);
		}
		else
		{
			printf("Já existe");
		}

		return root;
	}
}

int buscar(Node* root, char* data)
{
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		int compare = strcmp(data, root->data);
		if (compare == 0)
		{
			return 1;
		}
		else
		{
			if (compare < 0)
				return buscar(root->left, data);
			else
				return buscar(root->right, data);
		}
	}
}

void print_tree(Node* node)
{
	if (node != NULL)
	{
		print_tree(node->left);
		printf("%s ", node->data);
		print_tree(node->right);
	}
}

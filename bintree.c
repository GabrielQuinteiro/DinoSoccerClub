#include "bintree.h"
#include <string.h>

//Fun��es est�ticas s� funcionam dentro desse arquivo
static Node* insert_sub(char* data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	memset(new_node, 0, sizeof(Node));
	strcpy(&new_node->data, data);
	return new_node;
}

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

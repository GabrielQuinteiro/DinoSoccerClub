#include "bintree.h"
#include <string.h>

void insert_left(Node* node, char* data)
{
	if (node->left == NULL)
	{
		Node* new_node = (Node*)malloc(sizeof(Node));
		strcpy(new_node->data, data);
		new_node->left = NULL;
		new_node->right = NULL;
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
		Node* new_node = (Node*)malloc(sizeof(Node));
		strcpy(new_node->data, data);
		new_node->left = NULL;
		new_node->right = NULL;
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
		Node* new_node = (struct node*)malloc(sizeof(struct node));
		memset(tree, 0, sizeof(struct node));
		strcpy(new_node->data, data);
		/*new_node->left = NULL;
		new_node->right = NULL;*/
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
		printf("%s ", node->left);
		print_tree(node->right);
	}
}

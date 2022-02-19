#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define TREE_IS_NULL -1

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} node_t;

typedef struct Tree
{
	struct Node *root;
	unsigned int size;
} tree_t;

int get_random_number(int min, int max)
{
	return ((rand() % (max - min)) + min);
}

tree_t *createTree()
{
	tree_t *tree = (tree_t *)malloc(sizeof(tree_t));
	if (tree)
	{
		tree->root = NULL;
		tree->size = 0;
	}
	else
	{
		printf("MemoryAllocationError: Failed to create tree\n");
	}
	return tree;
}

node_t *createNode(int data)
{
	node_t *node = (node_t *)malloc(sizeof(node_t));
	if (node)
	{
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		printf("MemoryAllocationError: Tree node creation failed\n");
	}
	return node;
}

unsigned int getTreeSize(tree_t *tree)
{
	if (tree)
	{
		return tree->size;
	}
	else
	{
		return TREE_IS_NULL;
	}
}

bool isTreeEmpty(tree_t *tree)
{
	if (tree != NULL && tree->root == NULL && tree->size == 0)
	{
		return true;
	}
	return false;
}

node_t *addNode(tree_t *tree, node_t *root, node_t *node)
{
	if (root->data > node->data)
	{
		if (root->left == NULL)
		{
			root->left = node;
		}
		else
		{
			addNode(tree, root->left, node);
		}
	}
	if (root->data < node->data)
	{
		if (root->right == NULL)
		{
			root->right = node;
		}
		else
		{
			addNode(tree, root->right, node);
		}
	}
	if (root->data == node->data)
	{
		// free(node);
		// node = NULL;
		addNode(tree, root->right, node);
	}
	return node;
}

node_t *insertTreeNode(tree_t *tree, int data)
{
	node_t *node = NULL;
	if (tree)
	{
		node = createNode(data);
		if (node)
		{
			// printf("%d\n",data);
			if (isTreeEmpty(tree))
			{
				tree->root = node;
				tree->size++;
				return node;
			}
			else
			{
				node_t *n = addNode(tree, tree->root, node);
				if (n) // Increment when n is not null
					tree->size++;
			}
		}
		else
		{
			printf("Inserting node failed\n");
		}
	}
	else
	{
		printf("InvalidArgumentError: tree can not be null to insert a node\n");
	}
	return node;
}

void printPreOrderTree(node_t *root)
{
	if (root)
	{
		if (root->data)
			printf("%d\t", root->data);
		else
			printf("\t");
		printPreOrderTree(root->left);
		printPreOrderTree(root->right);
	}
	else
	{
		return;
	}
}

void printInOrderTree(node_t *root)
{
	if (root)
	{
		printInOrderTree(root->left);
		printf("%d\t", root->data);
		printInOrderTree(root->right);
	}
	else
	{
		return;
	}
}

void printPostOrderTree(node_t *root)
{
	if (root)
	{
		printPostOrderTree(root->left);
		printPostOrderTree(root->right);
		printf("%d\t", root->data);
	}
	else
	{
		return;
	}
}

void printRightNodeLeft(node_t *root)
{
	if (root)
	{
		printPostOrderTree(root->right);
		printf("%d\t", root->data);
		printPostOrderTree(root->right);
	}
	else
	{
		return;
	}
}

node_t* smallest(node_t *root)
{
	if (root->left != NULL)
	{
		return smallest(root->left);
	}
	else
	{
		return root;
	}
}

node_t* largest(node_t *root)
{
	if (root->right != NULL)
	{
		return largest(root->right);
	}
	else
	{
		return root;
	}
}

node_t *searchBST(node_t *root, int key)
{
	if (root)
	{
		if (key < root->data)
		{
			return searchBST(root->left, key);
		}
		else if (key > root->data)
		{
			return searchBST(root->right, key);
		}
		else
		{
			return root;
		}
	}
	else
	{
		// Not found scenario
		return NULL;
	}
}


bool delete (node_t *parent, node_t *root, int key)
{
	bool result = false;
	if (root)
	{
		/**
		 * Following use cases are possible while running delete operation
		 * 1) The node to be deleted has no children
		 * 2) the node to be deleted has only right subtree
		 * 3) the node to be deleted has only left subtree
		 * 4) the node to be deleted has both left and right subtree
		 *    It is possible to delete a node from a middle of a tree but the result
		 *    tends to create very unbalanced trees.
		 *    rather than simply delete the node, it is adviced to maintain the existing
		 *    strucutr as much as possible by finding data to take the place of deleted node.
		 *    this can be done in 2 ways
		 * 			a) we can find the lartest node in the deleted node's left subtree and move
		 * 			   its data to replace node's data.
		 * 			b) we can find smallest node on deleted node's right subtree and move its
		 * 			   data to replace the deleted node's data.
		 */

		if (key < root->data)
		{
			return delete (root,root->left, key); // go to left subtree
		}
		else if (key > root->data)
		{
			return delete (root,root->right, key); // go to right subtree
		}
		else if(key == root->data) // found node where key is equal to root-data
		{
			if((root->left == NULL) && (root->right == NULL)) //No left or right subtree
			{
				if(parent->left == root)
				{
					parent->left = NULL;
				}
				if(parent->right == root)
				{
					parent->right = NULL;
				}
				free(root);
				result = true;
			}

			else if((root->left == NULL) && (root->right != NULL)) // No left subtree
			{
				if(parent->left == root)
				{
					parent->left = root->right;
				}
				if(parent->right == root)
				{
					parent->right = root->right;
				}
				free(root);
				result = true;
			}

			else if((root->left !=NULL) && (root->right == NULL)) // No right subtree
			{
				if(parent->left == root)
				{
					parent->left = root->left;
				}
				if(parent->right == root)
				{
					parent->right = root->left;
				}
				free(root);
				result = true;
			}
			else if((root->left != NULL) && (root->right != NULL)) // root has left and right both subtree
			{
				//find largest left sub tree node
				node_t *lefty = root->left;
				node_t *leftyParent = lefty;
				while(lefty->right)
				{
					lefty = lefty->right;
					leftyParent = lefty;
				}
				//Perform data exchange
				if(parent->left == root)
				{
					parent->left = lefty;
				}
				if(parent->right == root)
				{
					parent->right = lefty;
				}
				leftyParent->right = NULL;
				free(root);
				result = true;
			}
		}
		else
		{
			result = false; //did not find
		}
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		const int size = atoi(argv[1]);
		tree_t *tree = createTree();
		if (tree)
		{
			for (int i = 0; i < size; i++)
			{
				int r = get_random_number(1, size + 1);
				insertTreeNode(tree, r);
			}
			printPreOrderTree(tree->root);
			printf("\n");
			printInOrderTree(tree->root);
			printf("\n");
			printPostOrderTree(tree->root);
			printf("\n");
			printf("smallest = %d\n", smallest(tree->root)->data);
			printf("largest = %d\n", largest(tree->root)->data);

			printf("\n");
			printRightNodeLeft(tree->root);
			printf("\n");
			int key = get_random_number(1, (size + 1) * 2);
			node_t *result = searchBST(tree->root, key);
			if (result)
			{
				printf("\nkey %d is found in tree, address %p and value %d\n", key, result, result->data);
			}
			else
			{
				printf("\nKey %d not found\n", key);
			}
		}
		else
		{
			printf("Tree creation failed\n");
		}
		return EXIT_SUCCESS;
	}
	else
	{
		printf(" ----- invalid input ---- : ./tree <Input Sample Size>\n");
		printf("lets lets delete scenario\n");
		tree_t *tree = createTree();
		if (tree)
		{
			// insert nodes
			insertTreeNode(tree, 17);
			insertTreeNode(tree, 23);
			insertTreeNode(tree, 9);
			insertTreeNode(tree, 22);
			insertTreeNode(tree, 20);
			insertTreeNode(tree, 21);
			insertTreeNode(tree, 11);
			insertTreeNode(tree, 5);
			insertTreeNode(tree, 17);

			printInOrderTree(tree->root);
			printf("\n");
			/*if(delete(NULL,tree->root,23))
			{
				tree->size--;
			}
			
			if(delete(NULL,tree->root,5))
			{
				tree->size--;
			}*/
			if(delete(NULL,tree->root,20))
			{
				tree->size--;
			}
			printInOrderTree(tree->root);
			printf("\n");
		}
		printf("tree size = %d\n", getTreeSize(tree));
		return EXIT_FAILURE;
	}
}

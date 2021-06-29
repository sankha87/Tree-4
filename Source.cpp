#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

Node* createNode(int new_data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void addToTree(char choice, struct Node *root, struct Node *new_node)
{
	if (choice == 'R')
		root->right = new_node;
	if (choice == 'L')
		root->left = new_node;
}

void Traverse_Inorder(struct Node *root)
{
	if (root == NULL)
		return;
	else
	{
		Traverse_Inorder(root->left);
		printf(" %d ", root->data);
		Traverse_Inorder(root->right);
	}
}

void Traverse_Preorder(struct Node *root)
{
	if (root == NULL)
		return;
	else
	{
		printf(" %d ", root->data);
		Traverse_Preorder(root->left);
		Traverse_Preorder(root->right);
	}
}

void Traverse_Postorder(struct Node *root)
{
	if (root == NULL)
		return;
	else
	{
		Traverse_Postorder(root->left);
		Traverse_Postorder(root->right);
		printf(" %d ", root->data);
	}
}

void main()
{
	struct Node *root1, *node1, *node2, *node3, *node4, *node5, *node6;
	root1 = createNode(2);
	node1 = createNode(3);
	addToTree('L', root1, node1);
	node2 = createNode(4);
	addToTree('R', root1, node2);
	node3 = createNode(5);
	addToTree('L', node1, node3);
	node4 = createNode(6);
	addToTree('R', node1, node4);
	node5 = createNode(7);
	addToTree('L', node2, node5);
	node6 = createNode(8);
	addToTree('R', node2, node6);
	printf("Inorder Traversal of Tree 1 : \n");
	Traverse_Inorder(root1);
	printf("\n\nPreorder Traversal of Tree 1 : \n");
	Traverse_Preorder(root1);
	printf("\n\nPostorder Traversal of Tree 1 : \n");
	Traverse_Postorder(root1);

	struct Node *root2, *node7, *node8, *node9, *node10, *node11, *node12;
	root2 = createNode(20);
	node7 = createNode(21);
	addToTree('L', root2, node7);
	node8 = createNode(22);
	addToTree('R', root2, node8);
		node9 = createNode(23);
		addToTree('L', node7, node9);
		node10 = createNode(24);
		addToTree('R', node7, node10);
		node11 = createNode(25);
		addToTree('L', node8, node11);
		node12 = createNode(26);
		addToTree('R', node8, node12);
	printf("\n\nInorder Traversal of Tree 2 : \n");
	Traverse_Inorder(root2);
	printf("\n\nPreorder Traversal of Tree 2 : \n");
	Traverse_Preorder(root2);
	printf("\n\nPostorder Traversal of Tree 2 : \n");
	Traverse_Postorder(root2);

	struct Node *root3 = createNode(1);
	addToTree('L', root3, root1);
	addToTree('R', root3, root2);
	printf("\n\nInorder Traversal of Main Tree : \n");
	Traverse_Inorder(root3);
	printf("\n\nPreorder Traversal of Main Tree : \n");
	Traverse_Preorder(root3);
	printf("\n\nPostorder Traversal of Main Tree : \n");
	Traverse_Postorder(root3);	Traverse_Inorder(root3);

	_getch();
}
//AVL tree
#include <iostream>
using namespace std;
typedef struct Node
{
	Node(int d)
	{
		left = NULL;
		right = NULL;
		data = d;
		height = 0;
	}
	Node * left;
	Node * right;
	int data;
	int height;
}Node;
int Height(Node * n)
{
	if (n==NULL)
		return -1;
	return n->height;
}
Node * RightRotate(Node * a)
{
	Node * b = a->left;
	a->left = b->right;
	b->right = a;
	a->height = max(Height(a->left),Height(a->right)) + 1;
	b->height = max(Height(b->left),Height(b->right)) + 1;
	return b;
}
Node * LeftRotate(Node * a)
{
	Node * c = a->right;
	a->right = c->left;
	c->left = a;
	a->height = max(Height(a->left),Height(a->right)) + 1;
	c->height = max(Height(c->left),Height(c->right)) + 1;
	return c;
}
Node * LeftRightRotate(Node * a)
{
	a->left = LeftRotate(a->left);
	return RightRotate(a);
}
Node * RightLeftRotate(Node * a)
{
	a->right = RightRotate(a->right);
	return LeftRotate(a);
}
void printTree(Node * root)
{
	if (root!=NULL)
	{
		cout << root->data << " ";
		printTree(root->left);
		printTree(root->right);
	}
}
Node * insert(int x, Node * node)
{
	if (node == NULL)
	{
		node = new Node(x);
	}
	else if (x < node->data)
	{
		node->left = insert(x, node->left);
		if (Height(node->left) - Height(node->right) >= 2)
		{
			if (x < node->left->data)
				node = RightRotate(node);
			else
				node = LeftRightRotate(node);
		}
	}
	else
	{
		node->right = insert(x, node->right);
		if (Height(node->right)-Height(node->left) >= 2)
		{
			if (x > node->right->data)
				node = LeftRotate(node);
			else
				node = RightLeftRotate(node);
		}
	}
	node->height = max(Height(node->left), Height(node->right)) + 1;
	return node;
}
int main()
{
	int k;
	cin >> k;
	Node * node=NULL;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		node = insert(a,node);
	}
	cout << node->data << endl;
}
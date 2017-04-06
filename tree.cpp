#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void printPostorder(struct node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->data <<' ';
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << ' ';
	printInorder(node->right);
}

void printPreorder(struct node* node)
{
	if (node == NULL)
		return;
	cout << node->data << ' ';
	printPreorder(node->left);
	printPreorder(node->right);
}

struct node* minim(struct node* root)
{
	struct node* x = NULL;
	while(root->left != NULL)
	{
		x = root->left;
		root = root->left; 
	}	
	return x;
}


struct node* search(struct node* root, int data)
{
	if (root == NULL) return NULL;
	else if (root->data == data) return root;
	else if (root->data < data) return search(root->right, data);
	else return search(root->left, data);
	return root;
}

struct node* Getsuccessor(struct node* root, int data) {
	// Search the Node - O(h)
	struct node* current = search(root, data);
	if(current == NULL) return NULL;
	if(current->right != NULL)  //Case 1: Node has right subtree
		return minim(current->right); // O(h)
	else 
	{   //Case 2: No right subtree  - O(h)
		struct node* successor = NULL;
		struct node* ancestor = root;
		while(ancestor != current) 
		{
			if(current->data < ancestor->data) 
			{
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

struct node* Insert(node *root, int data) 
{
	if(root == NULL) {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

struct node* maxim(struct node* root)
{
	struct node* x = NULL;
	while(root->right != NULL)
	{
		x = root->right;
		root = root->right; 
	}	
	return x;
}

// left root and right
vector<int> inorderTraversal(struct node *root) 
{
	vector<int> vec;
	stack<node*> stack;
	struct node* current = root;
	struct node* p;

	while(!stack.empty() || current)
	{
		if (current)
		{
			stack.push(current);
			current = current->left;
		}
		else
		{
			p = stack.top();
			vec.push_back(p->data);
			stack.pop();
			current = p->right;
		}
	}
	return vec;
}

// root left and right
vector<int> preorderTraversal(struct node *root) 
{
	vector<int> vec;
	stack<node*> stack;
	struct node* current = root;
	struct node* p;

	while(!stack.empty() || current)
	{
		if (current)
		{
			stack.push(current);
			current = current->right;
		}
		else
		{
			p = stack.top();
			vec.push_back(p->data);
			stack.pop();
			current = p->left;
		}
	}
	return vec;
}

void postorder(struct node* root, vector<int> &nodes)
{
	if (root == NULL) 
		return;
	postorder(root->left, nodes);
	postorder(root->right, nodes);
	nodes.push_back(root->data);
}

vector<int> post(struct node* root)
{
	vector<int> nodes;
	postorder(root, nodes);
	return nodes;
}

int main()
{
	struct node* root = newNode(3);
	root->left        = newNode(2);
	root->right       = newNode(4);
	root->left->left  = newNode(1);
	root->left->right = newNode(5);
	root->right->right = newNode(8);
	root->right->left = newNode(0);
	root->right->left->right = newNode(13);

	vector<int> b = post(root);
	for (int i = 0; i < sizeof(b)/sizeof(int); i++)
		cout << b[i] << ' ';
	//struct node* a = minim(root);
}








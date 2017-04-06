#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// in binary not a binary search tree
int findMax(struct node* root)
{
	if (root == NULL)
		return INT_MIN;
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}

// in binary tree not a binary search tree
int findMin(struct node* root)
{
	if (root == NULL)
		return INT_MAX;
    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
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
vector<int> preorderTraversal(struct node* root)
{
	stack<struct node*> stack;
	vector<int> result;
	struct node* p; 

	if (root == NULL)
		return result;
	stack.push(root);

	while(!stack.empty())
	{
		p = stack.top();
		result.push_back(p->data);
		stack.pop();
		if (p->right)
			stack.push(p->right);

		if (p->left)
			stack.push(p->left);
	}
	return result;
}

// left right and root
void postorder(struct node* root, vector<int>& nodes) {
    if (!root) return; 
    postorder(root -> left, nodes);
    postorder(root -> right, nodes);
    nodes.push_back(root -> data);
    
}
vector<int> postorderTraversal(struct node* root) {
    vector<int> nodes;
    postorder(root, nodes);
    return nodes;
} 
// root left and right
int main()
{
	struct node* root = newNode(3);
	root->left        = newNode(2);
	root->right       = newNode(4);
	root->left->left  = newNode(1);
	root->left->right = newNode(5);
	root->right->right = newNode(8);
	root->right->left = newNode(3);
	root->right->left->right = newNode(13);
	vector<int> a = postorderTraversal(root);
	vector<int> b = inorderTraversal(root);
	vector<int> c = preorderTraversal(root);
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
	for(int i = 0; i < b.size(); i++)
		cout << b[i] << ' ';
	cout << endl;
	for(int i = 0; i < c.size(); i++)
		cout << c[i] << ' ';
	cout << endl;


}








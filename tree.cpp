#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

node* newnode(int value)
{
	node* newnode = new(node);
	newnode->val = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

// return the height of root node
int height(node* root)
{
	int h = 0;
	if (root != NULL)
	{
		int l = height(root->left);
		int r = height(root->right);
		h = max(l, r) + 1;
	}
	return h;
}

// a single left rotation
node* rr_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left Rotation and single right rotation
node* ll_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

 // Left - Right Rotation
node* lr_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

// Right- Left Rotation
node* rl_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

// the difference between right and left
int diff(node* root)
{
	int l = height(root->left);
	int r = height(root->right);
	return l - r;
}

node* balance(node *temp)
{
    int bal_factor = diff(temp);
    // left heavy
    if (bal_factor > 1)
    {
    	// left sub tree is left heavy
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);

        // left sub tree is left heavy 
        else
            temp = lr_rotation(temp);
    }
    // righy heavy
    else if (bal_factor < -1)
    {
    	// right sub tree is left heavy
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

// tree implementation is a execellent example for recursive
node* insert(node* root, int data)
{
	if(root == NULL) 
		root = newnode(data);

	else if(data < root->val)
		root->left = insert(root->left,data);
	else 
		root->right = insert(root->right,data);
	return root;
}

int countnode(node* root)
{
	if (root == NULL)
		cout << "The tree is empty" << endl;
	else
	{
		int count = 1;
		count += countnode(root->left);
		count += countnode(root->right);
		return count;
	}
}

void printvec(vector<int> vec)
{
	int n = vec.size();
	for (int i = 0; i < n; i++)
		cout << vec[i] << ' ';
	cout << endl;
}

int minim(node* root)
{
	if (root == NULL)
		cout << "The tree is empty" << endl;
	int min;
	while (root->left != NULL)
	{
		root = root->left;
		min = root->val;
	}
	return min;
}

node* search(node* root, int value)
{
	if (root == NULL || root->val == value)
		return root;

	else if (root->val < value)
		 search(root->right, value);
	else
		 search(root->left, value);
}

void inorder(node* root, vector<int> &re)
{
	if (root == NULL)
		return;
	inorder(root->left, re);
	
	inorder(root->right, re);
	re.push_back(root->val);
}
vector<int> inorder_out(node* root)
{
	vector<int> re;
	inorder(root, re);
	return re;
}

int main()
{
	struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    //insert(root, 80);
    printvec(inorder_out(root)); 
}





#include <iostream>
using namespace std;


struct node{
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree() 
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	head = (node*)malloc(sizeof(struct node)); // allocate 3 nodes in the heap
	second = (node*)malloc(sizeof(struct node));
	third = (node*)malloc(sizeof(struct node));
	head->data = 1; // setup first node
	head->next = second; // note: pointer assignment rule
	second->data = 2; // setup second node
	second->next = third;
	third->data = 3; // setup third link
	third->next = NULL;
	return head;
}

void appendnode(struct node** headRef, int num)
{
	struct node* current = *headRef;
	struct node* newNode;

	newNode = (node*)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;

	if (current == NULL)
	{
		*headRef = newNode;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void Push(struct node** headRef, int data) 
{
	struct node* newNode = (node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *headRef; // The '*' to dereferences back to the real head
	*headRef = newNode; // ditto
}

struct node* AddAtHead() 
{
	struct node* head = NULL;
	int i;
	for (i=1; i<10; i++) {
	Push(&head, i);
	}
	// head == {5, 4, 3, 2, 1};
	return(head);
}

int Leng(struct node* head)
{
	struct node* current = head;
	int count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

void printlist(struct node* head)
{
	struct node* p = head;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

struct node* copylist(struct node* head)
{
	struct node* current = head;
	struct node* newlist = NULL;
	struct node* tail = NULL;

	while (current != NULL)
	{
		if (newlist == NULL)
		{
			newlist = (node*)malloc(sizeof(struct node));
			newlist->data = current->data;
			newlist->next = NULL;
			tail = newlist;
		}
		else
		{
			tail->next = (node*)malloc(sizeof(struct node));
			tail = tail->next;
			tail->data = current->data;
			tail->next = NULL;
		}
		current = current->next;
	}
	return newlist;
}

// normal way
void reverse(struct node** head_ref)
{
	// current means the node to be appended at the first place
    struct node* current = *head_ref;
    struct node* pre = NULL;
    struct node* next = NULL;
    while (current != NULL)
    {
    	next = current->next;
    	current->next = pre;
    	pre = current;
    	current = next;
    }
    *head_ref = pre;
}

void reverseUtil(node *curr, node *prev, node **head);

void reverse_better(node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

void reverseUtil(node *curr, node *prev, node **head)
{
    /* If last node mark it head*/
    if (!curr->next)
    {
        *head = curr;
 
        /* Update next to prev node */
        curr->next = prev;
        return;
    }
 
    /* Save curr->next node for recursive call */
    node *next = curr->next;
 
    /* and update next ..*/
    curr->next = prev;
 
    reverseUtil(next, curr, head);
}

void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  
     
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}

node* swapPairs(node* head)
{
	node** p = &head;
	node* a = head;
	node* b;
	while ((a = *p) && (b = a->next))
	{
		a->next = b->next;
		b->next = a;
		*p = b;
		p = &(a->next);
	}
	return head;
}

int main()
{
	struct node* mylist = AddAtHead();
	int len = Leng(mylist);
	cout << len << endl;
	recursiveReverse(&mylist);
	printlist(mylist);
}










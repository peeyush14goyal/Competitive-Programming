/* Find middle element in LL using Two Pointers*/
/*GeeksforGeeks Example*/
#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};
// We can create LL backwards
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(struct Node* ptr)
{
	while(ptr != NULL)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<"NULL\n";
}
// M 2 
/* Initialise two pointers one slow and other fast
at each iteration increment slow pointer ny one node and fast pointer by two nodes
when fast pointer will reach end then slow pointer will be at middle element
*/
/*
void printMiddleElement(struct Node* head)
{
	struct Node* slow_ptr = head;
	struct Node* fast_ptr = head;
	
	if(head!=NULL)
	{
		while(fast_ptr!=NULL&&fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
		cout<<"The middle element is "<<slow_ptr->data<<"\n\n";
	}
}
*/


//M 3
/* This method is almost same as M2. Difference comes that we use just one pointer in this
and increment that pointer only when index+1 of the Node is odd
*/

void printMiddleElement3(struct Node* head)
{
	struct Node* temp;
	temp = head;
	int count=0;
	while(head!=NULL)
	{
		if(count%2==1)
		{
			temp = temp->next;
		}
		head = head->next;
		count++;
	}
	cout<<"The middle element is "<<temp->data<<"\n\n";
}
int main()
{
	struct Node* head = NULL;
	
	for(int i=5;i>0;i--)
	{
		push(&head, i);
		printList(head);
		//printMiddleElement(head);
		printMiddleElement3(head);
	}	
}

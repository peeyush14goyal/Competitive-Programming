/*Recursive Version of Checking LL is Pallindrome */
/* Time Complexity: O(n) and Auxillary Space is O(n) considering the stack space otherwise O(1) */
#include<bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	struct Node* next;
};

bool isPallindromeUtil(struct Node** left, struct Node* right)
{
	if(right==NULL)
	{
		return true;
	}
	
	/* If sub-list is not Pallindrome, then no need to check
	for current left and right and return false
	*/
	bool isp = isPallindromeUtil(left, right->next);
	if(isp == false)
	{
		return false;
	}
	
	bool isp1 = (right->data == (*left)->data);
	
	*left = (*left)->next;
	
	return isp1;
}

bool isPallindrome(struct Node* head)
{
	isPallindromeUtil(&head, head);
}

/* Push a node to LL.Note this function changes the head*/
void push(struct Node** head_ref, char new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void printList(struct Node* ptr)
{
	while(ptr != NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<"NULL\n";
}

int main()
{
	struct Node* head = NULL;
	string str = "abaaba";
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		push(&head, str[i]);
		printList(head);
		isPallindrome(head) ? cout<<"LL is Pallindrome\n\n" : cout<<"LL is NOT Pallindrome\n\n";
	}
}

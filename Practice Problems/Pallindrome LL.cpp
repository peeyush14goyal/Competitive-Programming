/* Function to check if a singly LL is pallindrome */
/*
M1
Traverse the LL and copy all the elements in an array or stack and then find whether the LL is pallindrome
or not 
*/
/* M2
Reach the middle element of the LL and then reverse the LL
Compare the reversed half list to return true or false
Reverse again to get the original LL

Time Complexity: O(n) and O(1) extra space
*/
#include<iostream>
using namespace std;

struct Node {
	char data;
	struct Node* next;
};

void reverse(struct Node**);
bool compareLists(struct Node*, struct Node*);

bool isPallindrome(struct Node* head)
{
	struct Node *slow_ptr = head, *fast_ptr = head;
	struct Node *second_half, *prev_of_slow_ptr = head;
	struct Node* midNode = NULL;
	bool res = true;
	
	if(head!=NULL&&head->next!=NULL) {
		while(fast_ptr!=NULL&&fast_ptr->next!=NULL)
		{
			fast_ptr = fast_ptr->next->next;
			
			/*We need previous of the slow_ptr for
			LL with odd elements*/
			prev_of_slow_ptr = slow_ptr;
			slow_ptr = slow_ptr->next;
		}
		
		/*fast_ptr would become NULL when there are even elements in list.
		And not NULL for odd elements. We need to skip the middle node
		for odd case and store it somewhere so that we can restore the original list*/
		if(fast_ptr != NULL)
		{
			midNode = slow_ptr;
			slow_ptr = slow_ptr->next;
		}
		
	// Now reverse the seconf half and compre it with first half
		second_half = slow_ptr;
		prev_of_slow_ptr->next = NULL; // NULL terminate the first half
		reverse(&second_half);
		res = compareLists(head, second_half);
		
		/* Construct the original list back*/
		reverse(&second_half);
		
		/*If there was a mid node (odd size case) which
		was not part of either first half or seconf half*/
		if(midNode != NULL)
		{
			prev_of_slow_ptr->next = midNode;
			midNode->next = second_half;
		}
		else
		{
			prev_of_slow_ptr->next = second_half;
		}
	}
	return res;
}
/* Function to reverse the LL
Note that this function may change the head*/
void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

bool compareLists(struct Node* head1, struct Node* head2)
{
	struct Node* temp1 = head1;
	struct Node* temp2 = head2;
	
	while(temp1 && temp2)
	{
		if(temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
		{
			return 0;
		}
	}
	
	if(temp1 == NULL && temp2 == NULL)
	{
		return 1;
	}
	return 0;
}

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
		ptr = ptr->next;
	}
	cout<<"NULL\n";
}

int main()
{
	struct Node* head = NULL;
	string str = "abacaba";
	int i;
	
	for(i=0;str[i]!='\0';i++)
	{
		push(&head, str[i]);
		printList(head);
		isPallindrome(head) ? cout<<"LL is Pallindrome\n\n" : cout<<"NOT a Pallindrome\n\n";
	}
}

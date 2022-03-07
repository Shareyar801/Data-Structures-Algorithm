#include <iostream>
using namespace std;

//DOUBLE CIRCULAR LINKED LIST:
struct node
{
	int data;
	node* nxt_link;
	node* prev_link;
};

void print(node* head)
{
	node* temp = head;
	cout << "\nPrinting LL: ";
	do
	{
		cout << temp->data << "  ";;
		temp = temp->nxt_link;
	} while (temp != head);
	cout << "\n";
}

void head_insert(node** head, int val)
{
	node* new_node = new node();
	node* temp = *head;
	new_node->data = val;

	if (*head == NULL)
	{
		new_node->prev_link = new_node; //setting prev of new head null.
		new_node->nxt_link = new_node;  //setting nxt of new head is current head.
	}
	else if (*head != NULL) //for 2nd iteration when head will be containing value.
	{	
		new_node->nxt_link = *head; //setting nxt of new head is current head.
		//setting new node in current heads previous link, which will make current head 2nd node.
		(*head)->prev_link = new_node;

		while (temp->nxt_link != *head)
		{
			temp = temp->nxt_link;
		}
		temp->nxt_link = new_node;
		new_node->prev_link = temp;
	}
	*head = new_node;
}

void tail_insert(node** head, int val)
{
	node* new_node = new node();
	node* temp = *head;

	new_node->data = val;
	new_node->nxt_link = *head;	//new tail's nxt will be null.

	while (temp->nxt_link != *head)
	{	//finding last node of ll.
		temp = temp->nxt_link;
	}
	temp->nxt_link = new_node;	
	new_node->prev_link = temp;	//and saving temp in new tail prev.
	(*head)->prev_link = new_node;
}

void middle_insert(node** head1, node* head2, int val, int prev_val)
{
	print(head2); //calling print fun in same fun as mid insert to saving coding time and lines.

	node* new_node = new node();
	node* temp = *head1;	//it will contain next node of new_node.
	node* prev_temp = NULL;	//it will contain previous node of new_node.

	new_node->data = val;

	while (temp->data != prev_val)	//will run till temp is at previous node from insertion point.
	{
		prev_temp = temp;
		temp = temp->nxt_link;
	}

	//once it will reach insertion point we will move both pointers (temp & prev temp) in forward direction only once.
	prev_temp = temp;
	temp = temp->nxt_link;

	//now we will have previous node and next node of new_node of ll.
	//now we will connect all connection of dll.

	prev_temp->nxt_link = new_node;	//pre_node's next will be new_node.
	new_node->nxt_link = temp;		//new_node's next will be temp (which is new_node+1 rn).
	temp->prev_link = new_node;		//temp's previous will be new_node.
	new_node->prev_link = prev_temp;//next_node's preivous will be pre_node (which is new_node-1 rn).

	print(head2); //calling print fun in same fun as mid insert to saving coding time and lines.
}

void head_delete(node** head)
{
	node* new_head = (*head)->nxt_link;
	node* temp = *head;

	while (temp->nxt_link != *head)
	{	//finding last node of ll.
		temp = temp->nxt_link;
	}

	temp->nxt_link = new_head;
	new_head->prev_link = temp;
	*head = new_head;
}

void tail_delete(node** head)
{
	node* temp = *head;
	node* prev_temp = NULL;

	while (temp->nxt_link != *head)
	{	//finding last node of ll.
		prev_temp = temp;
		temp = temp->nxt_link;
	}

	prev_temp->nxt_link = *head;
	(*head)->prev_link = prev_temp;
	free(temp);
}

void middle_delete(node** head1, node* head2, int prev_val)
{
	print(head2); //calling print fun in same fun as mid insert to saving coding time and lines.

	node* temp = *head1;	//it will contain next node of new_node.
	node* prev_temp = NULL;	//it will contain previous node of new_node.


	while (temp->data != prev_val)	//will run till temp is at previous node from insertion point.
	{
		prev_temp = temp;
		temp = temp->nxt_link;
	}

	//once it will reach insertion point we will move both pointers (temp & prev temp) in forward direction only once.
	prev_temp = temp;
	temp = temp->nxt_link;

	//now we will have previous node and next node of new_node of ll.
	//now we will connect all connection of dll.

	prev_temp->nxt_link = temp->nxt_link;	//pre_node's next will be temp+1.
	temp->nxt_link->prev_link = prev_temp;	//temp's next node's previous will be prev_node(temp-1).
	cout << "The data " << temp->data << " has been deleted.";
	free(temp);	//deallocating memory pf temp variable.

	print(head2); //calling print fun in same fun as mid insert to saving coding time and lines.
}

int main()
{
	//DOUBLE CIRCULAR LINKED LIST:
	node* head = NULL;

	//INSERION:
	head_insert(&head, 50);
	head_insert(&head, 90);
	tail_insert(&head, 10);
	head_insert(&head, 40);
	tail_insert(&head, 29);
	middle_insert(&head, head, 99, 90);
	//4th parameter will contain certain value from ll, after that value position the insertion of node will take place. 
	//ll will be printed before insertion and after insertion be calling this function.

	//DELETION:
	head_delete(&head);
	print(head);
	tail_delete(&head);
	print(head);
	middle_delete(&head, head, 99);
	//3rd parameter will contain certain value from ll, after that value position the deletion of node will take place. 
	//ll will be printed before insertion and after insertion be calling this function.
}

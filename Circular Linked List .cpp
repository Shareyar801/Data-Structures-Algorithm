#include <iostream>
using namespace std;

//CIRCULAR LINKED LIST:
struct node
{
	int data;
	node* link;
};

void print(node* head)
{
	node* temp = head;
	cout << "\nPrinting LL: ";
	do
	{
		cout << temp->data << "  ";;
		temp = temp->link;
	} while (temp != head);
	cout << "\n";
}

void head_insert(node* &head, int val)
{
	node* new_node = new node();
	new_node->data = val;

	if (head == NULL)
	{
		new_node->link = new_node;
		head = new_node;
	}
	else
	{
		node* temp = head;
		while (temp->link != head)
		{
			temp = temp->link;
		}
		temp->link = new_node;
		new_node->link = head;
		head = new_node;
	}
}

void tail_insert(node* &head, int val)
{
	node* new_node = new node();
	node* temp = head;
	new_node->data = val;

	while (temp->link != head)
	{
		temp = temp->link;
	}

	temp->link = new_node;
	new_node->link = head;
}

//same insertion function as sll.
void middle_insert(node** head1, node* head2, int val, int prev_val)
{
	print(head2);
	//calling print fun in same fun as mid insert to saving coding time and lines.

	node* new_node = new node();    //creating obj of node struct
	node* temp = *head1;             //creating temp variable

	new_node->data = val;

	while (temp->data != prev_val)
	{
		temp = temp->link;
	}

	new_node->link = temp->link;
	temp->link = new_node;

	print(head2);
	//calling print fun in same fun as mid insert to saving coding time and lines.
}

void head_delete(node** head)
{
	if (*head == NULL)
	{
		cout << "\nLinked list is empty.\n";
		return;
	}

	node* temp = *head;
	node* new_head = (*head)->link;

	while (temp->link != *head)
	{
		temp = temp->link;
	}

	temp->link = new_head;
	*head = new_head;
}

void tail_delete(node** head)
{
	if (*head == NULL)
	{
		cout << "\nLinked list is empty.\n";
		return;
	}

	node* temp = *head;
	node* prev_temp = NULL;

	while (temp->link != *head)
	{
		prev_temp = temp;
		temp = temp->link;
	}

	prev_temp->link = *head;
	free(temp);
}

//same insertion as sll.
void middle_delete(node** head1, node* head2, int val)
{
	print(head2);
	//calling print fun in same fun as mid insert to saving coding time and lines.

	node* temp = *head1;             //creating temp variable of node struct.
	node* prev = NULL;              //creating another pointer variable of node struct.

	while (temp->data != val)  //loop will run untill desired value is found.
	{
		prev = temp;                //saving temp in prev
		temp = temp->link;          //moving node
	}
	prev->link = temp->link;        //once loop is ended, saving link of nxt node into previous node.
	
	print(head2);
	//calling print fun in same fun as mid insert to saving coding time and lines.
}

int main()
{
	//CIRCULAR LINKED LIST:
	node* head = NULL;

	//INSERION:
	head_insert(head, 50);
	head_insert(head, 90);
	tail_insert(head, 10);
	head_insert(head, 40);
	tail_insert(head, 29);
	middle_insert(&head, head, 99, 90); 
	//4th parameter will contain certain value from ll, after that value position the insertion of node will take place. 
	//ll will be printed before insertion and after insertion be calling this function.

	//DELETION:
	head_delete(&head);
	print(head);
	tail_delete(&head);
	print(head);
	middle_delete(&head, head, 99);
	//in this case middle delete will take deletion value. not previous value like dll.
	//ll will be printed before insertion and after insertion be calling this function.
}

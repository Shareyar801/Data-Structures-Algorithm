#include <iostream>
using namespace std;
struct node
{
	int data;
	node* link;
};
class head_as_front_of_queue
{
public:
	void enqueue(node** head)
	{	//insertion at tail
		node* new_node = new node();
		node* temp = *head;
		int val;

		cout << "Insert value: ";
		cin >> val;
		new_node->data = val;
		new_node->link = NULL;
		if (*head == NULL)
		{
			*head = new_node;
			//return;
		}
		else
		{
			while (temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = new_node;
		}

	}
	void dequeue(node** head)
	{	//deletion at head
		node* temp = *head;
		if (temp == NULL)
		{
			cout << "NOTE: Stack Underflow.";
		}
		else
		{
			*head = temp->link;
			free(temp);
		}
	}
	void display(node* head)
	{
		while (head != NULL)
		{
			cout << head->data << "  ";
			head = head->link;
		}

	}
};
class tail_as_front_of_queue
{
public:
	void enqueue(node** head)
	{	//insertion at head
		node* new_node = new node();
		int val;

		cout << "Insert value: ";
		cin >> val;
		new_node->data = val;
		new_node->link = *head;
		*head = new_node;

	}
	void dequeue(node** head)
	{	//deletion at tail
		node* temp = *head;
		node* prev_temp = NULL;

		if (temp == NULL)
		{
			cout << "NOTE: Stack Underflow.";
		}
		else
		{
			while (temp->link != NULL)
			{
				prev_temp = temp;
				temp = temp->link;
			}
			prev_temp->link = NULL;
			free(temp);
		}
	}
	void display(node* head)
	{
		while (head != NULL)
		{
			cout << head->data << "  ";
			head = head->link;
		}

	}
};
int main()
{
	head_as_front_of_queue q1; node* head = NULL;
	tail_as_front_of_queue q2; int ch1, ch2, ch3, num;
	bool loop_end2 = 0, loop_end3 = 0;

	cout << "===QUEUE THROUGH LINK LIST IMPLEMENTAION===\n";
	cout << "01.Suppose head of queue as front.\n02.Suppose tail of queue as front.\nChoice: ";
	cin >> ch1;
	switch (ch1)
	{
	case 01:
	{
		do
		{
			cout << "\n01.Enqueue\n02.Dequeue\n03.Display\n04.Exit\nChoice: ";
			cin >> ch2;
			switch (ch2)
			{
			case 01:
				cout << "\nEnter Number of values you want to enqueue: ";
				cin >> num;
				for (size_t sf = 0; sf < num; sf++) 
				{ 
					q1.enqueue(&head); 
				}
				break;
			case 02: q1.dequeue(&head); 
				break;
			
			case 03:
				cout << "\nPrinting Queue: ";
				q1.display(head); 
				break;

			case 04:
				loop_end2 = 1;
				break;

			default:
				cout << "\nNote: Invalid choice try again.\n"; break;
			}
		} while (!loop_end2);
	}break;
	case 02: {
		do {
			cout << "\n01.Enqueue\n02.Dequeue\n03.Display\n04.Exit\nChoice: ";
			cin >> ch3;
			switch (ch3) {
			case 01:
				cout << "\nEnter Number of values you want to enqueue: ";
				cin >> num;
				for (size_t sf = 0; sf < num; sf++) 
				{ 
					q2.enqueue(&head); 
				}
				break;
			case 02: q2.dequeue(&head); 
				break;

			case 03:
				cout << "\nPrinting Queue: ";
				q2.display(head); 
				break;

			case 04:
				loop_end3 = 1;
				break;

			default:
				cout << "\nNote: Invalid choice try again.\n"; break;
			}
		} while (!loop_end3);
	}break;

	default: cout << "\nNote: Invalid choice try again.\n"; break;
	}
}

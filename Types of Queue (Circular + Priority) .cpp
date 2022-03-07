#include <iostream>
#define size 5	//setting limit of array to 5
using namespace std;

//PRIORITY QUEUE:
//highest priority data will be processed first. as it doesnt follow fifo.
//so on that basis insertion and deletion will he done randomly. the program will decide where to insert node based on it's priority.
//priority can be decided on acsending or decending order.
//in this case i have set priority on ascending order.

class pqueue_LL
{
public:
		int data; float priority;
		pqueue_LL* link;
	

	void enqueue(pqueue_LL** head, int val, float priority_order)
	{
		pqueue_LL* new_node = new pqueue_LL();
		pqueue_LL* temp = *head;
		pqueue_LL* prev = NULL;

		new_node->data = val;
		new_node->priority = priority_order;


		if (*head == NULL || priority_order < temp->priority)
		{
			//insertion at head case. whenever node will be required to be inserted in head this case will be used.
			new_node->link = *head;
			*head = new_node;
			return;
		}

		//insertion at tail or middle case. 
		while ((temp != NULL) && (temp->priority <= priority_order))
		{
			prev = temp;
			temp = temp->link;
		}
		new_node->link = temp;
		prev->link = new_node;
	}

	void dequeue(pqueue_LL** head)
	{
		//highest priority data will be deleted first in any case.
		pqueue_LL* temp = *head;

		if (temp == NULL)
		{
			cout << "\nNOTE: QUEUE UNDERFLOW.\n";
			return;
		}

		cout << "\nNode has been deleted: data: " << temp->data << "\tpriority: " << temp->priority;
		*head = temp->link;
		free(temp);
	}

	void display(pqueue_LL* head)
	{
		if (head == NULL)
		{
			cout << "\nNOTE: QUEUE UNDERFLOW.\n";
			return;
		}
		cout << "\n\nPrinting Priority queue: ";
		while (head != NULL)
		{
			cout << "\ndata: " << head->data << "\tpriority: " << head->priority;
			head = head->link;
		}
		cout << endl << endl;
	}
};

class cqueue_array
{
public:
	int cqueue[size];
	int front = -1, rear = -1;

	void enqueue(int val)
	{
		if ((rear + 1) % size == front) //condition to check whether q is full or not.
		{
			cout << "NOTE: Queue Overflow!\n";
			return;
		}

		//checking whether queue is empty or not if it is then front & rear will move from -1 to 0.
		if (front == -1 && rear == -1)
		{
			front = 0;  rear = 0;
			cqueue[rear] = val;
			return;
		}

		rear = (rear + 1) % size;
		cqueue[rear] = val;
	}

	void dequeue()
	{
		int val;

		if (front == -1 && rear == -1) //checking whether queue is empty or not.
		{
			cout << "\nNOTE: Queue Underflow!\n";
			return;
		}

		//checking q is empty or not. 
		//as there will be a point where front and rear will be at same position. which will indicate that q is empty.
		if (front == rear)
		{
			front = -1; rear = -1;
			//as there are in middle of array and array is empty. we will return them into their default position.
			return;
		}

		cout << "Value has been deleted which was : " << cqueue[front] << ". \n";
		cqueue[front] = NULL;
		front = (front + 1) % size;
	}

	void display()
	{
		int i;

		if (front == -1 && rear == -1)  //checking whether queue is empty or not.
		{
			cout << "\nNOTE: Queue Underflow!\n";
			return;
		}

		cout << "\nDisplaying cqueue: \n";
		cout << "front = " << front << " rear = " << rear;
		cout << "\nCircular queue: ";
		for (i = front; i != rear; i = (i + 1) % size)
		{
			cout << cqueue[i] << " ";
		}
		cout << cqueue[i] << " ";
		cout << "\n\n";
	}

};

int main()
{
	int choice = 02;
	switch (choice)
	{
	case 01:
	{
		cout << "PRIORITY QUEUE THROUGH LINKED LIST:\n";
		pqueue_LL* head = NULL;
		pqueue_LL pq_ll;

		pq_ll.dequeue(&head); //error will be printed becoze there is no value in cq rn.

		pq_ll.enqueue(&head, 11, 1.1);
		pq_ll.enqueue(&head, 12, 2.2);
		pq_ll.enqueue(&head, 15, 5.5);
		pq_ll.enqueue(&head, 13, 3.3);
		pq_ll.enqueue(&head, 14, 4.4);
		pq_ll.display(head);

		pq_ll.enqueue(&head, 16, 6.6); //error will be printed becoze there is no space in cq rn.

		pq_ll.dequeue(&head);
		pq_ll.dequeue(&head);
		pq_ll.display(head);

		pq_ll.enqueue(&head, 17, 7.7);
		pq_ll.enqueue(&head, 18, 8.8);
		pq_ll.display(head);
	}	break;
	case 02:
	{
		cout << "NOTE: CIRCULAR QUEUE THROUGH ARRAY:\n";
		cqueue_array cq_array;

		cq_array.dequeue(); 
		//error will be printed becoze there is no value in cq rn.

		cq_array.enqueue(11);
		cq_array.enqueue(12);
		cq_array.enqueue(13);
		cq_array.enqueue(14);
		cq_array.enqueue(15);
		cq_array.display();

		cq_array.enqueue(16); 
		//error will be printed becoze there is no space in cq rn.

		cq_array.dequeue();
		cq_array.dequeue();
		cq_array.display();

		cq_array.enqueue(16);
		cq_array.enqueue(17);
		cq_array.display();
	} break;
	}
}

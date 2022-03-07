#include <iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};

void PUSH(node** head, int val)
{
    node* new_node = new node();
    new_node->data = val;

    if (*head == NULL)
    {
        new_node->link = *head;
        *head = new_node;
    }
    else
    {
        node* temp = *head;
        new_node->link = NULL;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new_node;
    }
}

void POP(node** head)
{
    if (*head == NULL)
    {
        cout << "Stack is empty.";
    }
    else
    {
        node* temp = *head;
        node* free_temp = NULL;
        while (temp->link != NULL)
        {
            free_temp = temp;
            temp = temp->link;
        }
        free_temp->link = NULL;
    }
}

void traverse(node* head)
{
    while (head != NULL)
    {
        cout << head->data << "  ";
        head = head->link;
    }
}

int main()
{
    node* head = NULL;
    int val;

    cout << "Stack through LL: \n";

    for (size_t sf = 0; sf < 5; sf++)
    {
        cout << "Push value: ";
        cin >> val;
        PUSH(&head, val);
    }
    
    cout << "\nPrinting Stack: ";
    traverse(head);

    for (size_t sf = 0; sf < 2; sf++)
    {
        cout << "\n\nNOTE:Perfroming POP! ";
        POP(&head);

        cout << "\nPrinting Stack: ";
        traverse(head);
    }

    cout << endl << endl;
}

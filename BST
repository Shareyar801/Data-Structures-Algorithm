//Intro, insert, traverse = //https://www.youtube.com/watch?v=ScdwdSCnXDU
//Search, delete = https ://www.youtube.com/watch?v=kU9Lv3e_kxs
//Visual understanding = https ://www.cs.usfca.edu/~galles/visualization/BST.html

#include  <iostream>
using namespace std;
struct node
{
    int data;
    node* left, * right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
node* insert_in_bst(node* root, int val)
{
    if (root == NULL)
    {
        //cout << "\nroot null";
        return new node(val);
    }
    if (val < root->data)
    {   //when value is smaller than current node's value then moving cursor to left sub tree.
        root->left = insert_in_bst(root->left, val);
    }
    else if (val > root->data)
    {   //when value is greater than current node's value then moving cursor to right sub tree.
        root->right = insert_in_bst(root->right, val);
    }
    return root;
}
node* in_order_successor(node* root)
{
    node* current = root;
    while (current && current->left != NULL)
    {   //moving cursor to last
        current = current->left;
    }
    return current;
}
node* delete_in_bst(node* root, int val)
{   //thoery:
    //the all operation in BST is simple. but in deletion there are 3 cases.
    //01.when deletion node is leave node.
    //02.when deletion node has 1 child.
    //03.when deletion node has 2 child.

    if (val < root->data)
    {   //when value is smaller than current node's value then moving cursor to left sub tree.
        root->left = delete_in_bst(root->left, val);
    }
    else if (val > root->data)
    {   //when value is greater than current node's value then moving cursor to right sub tree.
        root->right = delete_in_bst(root->right, val);
    }
    else
    {   //when value is found

        //to work for first 2 cases of deletion:
        //it will also work when deletion node is leave node. as we are making it's supposed null child its successor.
        if (root->left == NULL)
        {   //when left child is empty then make right child current node's successor.
            //and remember that current node is being deleted.
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {   //when right child is empty then make left child current node's successor.
            //and remember that current node is being deleted.
            node* temp = root->left;
            free(root);
            return temp;
        }
        else
        { //for case 3 when node has 2 childs.
            node* temp = in_order_successor(root->right);   //to get our successor for delete node.
            root->data = temp->data;    //saving successor's data into deletion node. bascially overwirting.
            root->right = delete_in_bst(root->right, temp->data);   //now deletion scuccessor as it has become new node/root using first 2 if else cases.
            return root;
        }
    }
    return root;
}
node* search_in_bst(node* root, int key)
{
    if (root == NULL)
    {   //when tree is empty or cursor hits leave node.
        return NULL;
    }
    if (root->data == key)
    {   //when value is found.
        return root;
    }
    if (root->data > key)
    {   //when value is smaller than current node's value then moving cursor to left sub tree.
        return search_in_bst(root->left, key);
    }
    else if (root->data < key)
    {   //when value is greater than current node's value then moving cursor to right sub tree.
        return search_in_bst(root->right, key);
    }
}
void traverseInOrder(node* root)
{   //preferance by left, node, right (LNR)
    if (root == NULL)
    {
        return;
    }
    traverseInOrder(root->left);
    cout << root->data << "  ";
    traverseInOrder(root->right);
}
void traversePreOrder(node* root)
{   //preferance by node, left, right (NLR)
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    traverseInOrder(root->left);
    traverseInOrder(root->right);
}
void traversePostOrder(node* root)
{   //preferance by left, right, node (LRN)
    if (root == NULL)
    {
        return;
    }
    traverseInOrder(root->left);
    traverseInOrder(root->right);
    cout << root->data << "  ";
}
int main()
{
    int search_key = 25, sz = 6, val;
    node* root = NULL;

    cout << "Enter values for BST: \n";
    for (size_t i = 0; i < sz; i++)
    {
        if (i == 0)
        { 
            cin >> val;
            root = insert_in_bst(root, val);
        }
        else
        {
            cin >> val;
            insert_in_bst(root, val);
        }
    }

    cout << "\nTraverse in order: ";
    traverseInOrder(root);
    cout << "\nTraverse pre order: ";
    traversePreOrder(root);
    cout << "\nTraverse post order: ";
    traversePostOrder(root);

    if (search_in_bst(root, search_key) == NULL)
    {   //when function hitted rock bottom but value didnt found.
        cout << "\nKey value " << search_key << " is not found in tree.";
    }
    else
    {   //when value is found.
        cout << "\nKey value " << search_key << " is found in tree.";
    }

    cout << "\nDeletion value " << search_key << " by in order successor.";
    root = delete_in_bst(root, search_key);

    cout << "\nTraverse in order: ";
    traverseInOrder(root);
    cout << "\n\n";
}

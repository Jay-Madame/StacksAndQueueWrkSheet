#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d, Node *n = NULL)
    {
        data = d;
        next = n;
    }
};

void printLL(Node *myTop)
{
    Node *temp;
    temp = myTop;
    while (temp != NULL)
    {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << endl;
}

Node *linearSearch(Node *myTop, int searchTerm)
{
    Node *returnNode = NULL;
    Node *temp, *nextNode;
    temp = myTop;
    nextNode = myTop->next;


    if ((temp->data) == searchTerm)
    {
        returnNode = temp;
        return returnNode;
    }

    if (temp == NULL)
    {
        return returnNode;
    }
    else
    {
        if (nextNode == NULL)
            return returnNode;
        else
        {
            linearSearch(nextNode, searchTerm);
        }
    }
    return returnNode;
}

int main()
{

    // Create a linked list manually (5,10,15,20)
    Node *node1 = new Node(5);
    Node *node2 = new Node(10);
    Node *node3 = new Node(15);
    Node *node4 = new Node(20);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printLL(node1);

    // Succesful search
    Node *foundNode = linearSearch(node1, 10);
    if (foundNode != NULL)
        cout << "Found node: " << foundNode->data << endl;
    else
        cout << "Unable to find node with data value = 10" << endl;

    // Failed search
    foundNode = linearSearch(node1, 100);
    if (foundNode != NULL)
        cout << "Found node: " << foundNode->data << endl;
    else
        cout << "Unable to find node with data value = 100" << endl;
    cin.get();
    return 0;
}
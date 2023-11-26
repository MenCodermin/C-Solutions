#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* NewNode(int data);
void PrintList(Node* node);


class Solution
{
public:
    Node* mergeTwoLists (Node* h1, Node* h2)
{
    if(!h1) return h2;
    if(!h2) return h1;
    
    if(h1->data < h2->data)
    {
        h1->next = mergeTwoLists(h1->next,h2);
        return h1;
    }
    else
    { 
        h2->next = mergeTwoLists(h1,h2->next);
        return h2;
    }
}
};




int main()
{
    Node* head1,*head2,*res;
    Solution sol;
    head1 = NewNode(1);
    head1->next = NewNode(3);
    head1->next->next = NewNode(5);
    head2 = NewNode(0);
    head2->next = NewNode(2);
    head2->next->next = NewNode(4);
    res = sol.mergeTwoLists(head1,head2);
    PrintList(res);
    return 0;
}

Node* NewNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void PrintList(Node* node)
{
    Node* temp = node;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


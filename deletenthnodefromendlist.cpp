#include <iostream>

using namespace std; 

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode * fast = head, *slow = head;
            for(int i = 0; i < n; ++i) fast = fast->next;
            if(!fast) return head->next;
            while(fast->next != NULL) fast = fast->next,slow = slow->next;
            slow->next = slow->next->next;
            return head;
        }
};

void Display(ListNode* node);
void Push(ListNode** node, int data);


int main()
{
    ListNode *list = new ListNode();
    Solution sol;
    for(int i = 1; i <= 10; ++i) Push(&list, i);
    Display(list);
    cout<<endl<<endl;
    sol.removeNthFromEnd(list,4);
    Display(list);
    return 0;
}

void Push(ListNode** node,int data)
{
    ListNode* new_node = new ListNode();
    new_node->val = data;
    new_node->next = *node;
    *node = new_node;
}

void Display( ListNode * node)
{
    ListNode* new_node = new ListNode();
    new_node = node;
    while(new_node->next != NULL)
    {
        cout<< new_node->val<<" ";
        new_node = new_node->next;
    }
    cout<<endl;
}
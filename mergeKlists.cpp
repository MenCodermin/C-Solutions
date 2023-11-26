#include <iostream>
#include <vector>
#include <queue>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
ListNode* NewNode(int data);
void PrintList(ListNode* node);

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<int,vector<int>,greater<int>> mp;
    ListNode* res = NewNode(0);
    ListNode* rem = res; 
    for(auto s : lists)
    {
        while(s != NULL)
        {
            mp.push(s->val);
            s = s->next;
        }
    }
    while(!mp.empty())
    {
        rem->next = NewNode(mp.top());
        mp.pop();
        rem = rem->next;
    }
    return res->next;
}
};



int main()
{
    Solution sol;
    vector<ListNode*> list(3);
    
    list[0] = NewNode(1);
    list[0]->next = NewNode(3);
    list[0]->next->next = NewNode(5);

    list[1] = NewNode(1);
    list[1]->next = NewNode(3);
    list[1]->next->next = NewNode(4);

    list[2] = NewNode(2);
    list[2]->next = NewNode(6);
    ListNode * res = sol.mergeKLists(list);
    PrintList(res);
    cout<<endl;
    return 0;
}


ListNode* NewNode(int data)
{
    ListNode* temp = new ListNode;
    temp->val = data;
    temp->next = NULL;
    return temp;
}

void PrintList(ListNode* node)
{
    ListNode* temp = node;
    while(temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


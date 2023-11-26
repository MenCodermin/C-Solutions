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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *curr=head;
        ListNode *second=head->next;
        ListNode *tempNext=second->next;
        head=second;
        second->next=curr;
        curr->next=tempNext;
        while(curr->next!=NULL && (curr->next)->next!=NULL){
            ListNode *currFirst=curr->next;
            ListNode *currSecond=currFirst->next;
            ListNode *currThird=currSecond->next;
            curr->next=currSecond;
            currSecond->next=currFirst;
            currFirst->next=currThird;
            curr=currFirst;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    ListNode* res = sol.swapPairs(node);
    while(res)
    {
        cout<<res->val<<endl;
        res = res->next;
    }
}
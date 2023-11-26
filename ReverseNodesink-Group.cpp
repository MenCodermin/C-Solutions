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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head, *curr = head, *prev = NULL, *next = NULL;
        for(int i = 0; i < k; ++i)
        {
            if(cursor == NULL )return head;
            cursor = cursor->next;
        }
        for(int i = 0; i < k; ++i)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};

int main()
{
    Solution sol;
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);
    ListNode* res = sol.reverseKGroup(node, 2);
    while(res != NULL)
    {
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
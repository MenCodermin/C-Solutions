#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x, ListNode *next) : val(x), next(next) {}
      ListNode(int x) : val(x), next(nullptr) {}    
      ListNode() : val(0), next(nullptr) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tot = new ListNode(0);
        ListNode* temp = tot;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int sum = 0; 
            sum = carry + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l1 = l1 != NULL ? l1->next : nullptr;
            l2 = l2 != NULL ? l2->next : nullptr;
        }
        return tot->next;
        
    }
};

int main()
{
    return 0;
}
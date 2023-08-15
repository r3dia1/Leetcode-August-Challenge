/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = NULL;
        ListNode* greater = NULL;
        ListNode* tail1;
        ListNode* tail2;
        ListNode* p = head;
        while(p != NULL)
        {
            if(p->val < x)
            {
                if(less == NULL)
                {
                    ListNode* temp = new ListNode(p->val);
                    less = temp;
                    tail1 = temp;
                }
                else
                {
                    ListNode* temp = new ListNode(p->val);
                    tail1 -> next = temp;
                    tail1 = temp;
                }
            }
            else
            {
                if(greater == NULL)
                {
                    ListNode* temp = new ListNode(p->val);
                    greater = temp;
                    tail2 = temp;
                }
                else
                {
                    ListNode* temp = new ListNode(p->val);
                    tail2 -> next = temp;
                    tail2 = temp;
                }
            }
            p = p -> next;
        }
        if(less != NULL)
            tail1 -> next = greater;
        else
            return greater;
        return less;
    }
};
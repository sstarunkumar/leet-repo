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
    ListNode *kthnode(ListNode* head, int k)
    {
        while(--k && head)
            head = head->next;
        return head;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        while(head)
        {
            ListNode *next = head->next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *dummy = new ListNode();

        ListNode *temp = dummy;
        while( head )
        {
            ListNode *last = kthnode(head, k);
            if(last == nullptr)
            {
                temp->next = head;
                break;
            }

            ListNode *next = last->next;
            last->next = nullptr;
            reverse(head);
            temp->next = last;
            temp = head;
            head = next;
        }
        return dummy->next;
    }
};
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
    int llsize(ListNode* head)
    {
        int ans = 0;
        while(head)
        {
            ans ++;
            head = head->next;
        }
        return ans;
    }
    ListNode* lltail(ListNode *head)
    {
        while(head -> next)
        {
            head = head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head)
            return head;
        int l = llsize(head);  
        k = k % l;

        if(k == 0 || l == 1)
            return head; 
        
        ListNode *tail = lltail(head);

        l = l - k;

        ListNode *temp = head;
        while( --l )
        {
            temp = temp->next;
        }
        ListNode *bot = temp->next;
        temp -> next = nullptr;
        tail->next = head;
        return bot;

    }
};
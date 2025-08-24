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
    ListNode *findkthnode(ListNode *head,int k)
    {
        while(--k && head)
            head=head->next;
        return head;
    }
    void reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        while(head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while(temp)
        {
            ListNode *kthnode = findkthnode(temp,k);
            if( !kthnode )
            {
                if(prev)
                    prev->next = temp;
                break;
            }
            ListNode *next = kthnode->next;
            kthnode->next = nullptr;
            reverse(temp);
            if(temp == head)
                head = kthnode;
            else
                prev->next = kthnode;
            prev = temp;
            temp = next;
        }
        return head;
    }
};
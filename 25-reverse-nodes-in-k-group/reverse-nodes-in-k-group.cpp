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
    void reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr)
        {
            ListNode *nest = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nest;
        }
    }
    ListNode *findkthnode(ListNode* head,int k)
    {
        while( --k && head)
        {
            head = head ->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        ListNode *nextnode = nullptr;
        ListNode *kthnode = nullptr;
        while(temp)
        {
            kthnode = findkthnode(temp,k);
            if(!kthnode)
            {
                if(prev)
                {
                    prev->next = temp;
                }
                break;
            }
            nextnode = kthnode->next;
            kthnode->next = nullptr;
            reverse(temp);
            if(head == temp)
            {
                head = kthnode;
            }
            else
            {
                prev->next = kthnode;
            }
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};
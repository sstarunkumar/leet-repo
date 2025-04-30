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
    ListNode *findk(ListNode *head,int k)
    {
        while(head && --k)
        {
            head = head->next;
        }
        return head;
    }
    void reverse(ListNode* head)
    {
        if(!head || !head->next)
            return ;
        ListNode *prev= nullptr,*curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *prev=nullptr,*newnode=nullptr,*temp =head;
        while(temp)
        {
            ListNode *kthnode = findk(temp,k);
            if(!kthnode)
            {
                if(prev==nullptr)
                {
                    break;
                }
                else
                {
                    prev->next = newnode;
                    break;
                }
            }
            newnode = kthnode->next;
            kthnode->next= nullptr;
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
            temp = newnode;
        }
        return head;
    }
};
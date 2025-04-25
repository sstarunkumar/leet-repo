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
    int length(ListNode *node)
    {
        int l = 0;
        while(node)
        {   node = node->next;l++;  }
        return l;
    }
    ListNode *reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextone;
        while(curr)
        {
            nextone = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextone;
        }
        return prev;
    }
    ListNode *skipped(ListNode *head,int n)
    {
        for(int i=0;i<n;i++)
            head = head->next;
        return head;
    }
    bool isPalindrome(ListNode* head) 
    {
        int l = length(head)/2;
        ListNode *node = skipped(head,l);
        node = reverse(node);
        while(node)
        {
            if(head->val!=node->val)
                return false;
            head = head->next;
            node = node->next;
        }
        return true;
    }
};
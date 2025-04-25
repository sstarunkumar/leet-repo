/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *node)
    {
        int l = 0;
        while(node)
        {
            l++;
            node = node->next;
        }
        return l;
    }
    ListNode *skipped(ListNode *node,int d)
    {
        for(int i=0;i<d;i++)
            node = node->next;
        return node;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int len1 = length(headA);
        int len2 = length(headB);
        int d = abs(len1-len2);
        if(len1 > len2)
            headA = skipped(headA,d);
        else if(len1 < len2)
            headB = skipped(headB,d);
        while(headA!=nullptr)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
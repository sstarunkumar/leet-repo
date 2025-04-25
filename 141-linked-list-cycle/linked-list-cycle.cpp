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
    bool hasCycle(ListNode *head) 
    {
        set<ListNode *> se;
        while(head)
        {
            if(se.count(head))
                return true;
            se.insert(head);
            head = head->next;
        }
        return false;
    }
};
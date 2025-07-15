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
    class compare
    {
        public:
        bool operator()(ListNode* a,ListNode* b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        int n = lists.size();
        for(int i=0;i<n;i++)
            if(lists[i])
                pq.push(lists[i]);

        ListNode *head = nullptr,*tail = nullptr;   
        if(!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            if(temp->next)
                pq.push(temp->next);
            head = tail = temp;
        }    
        while(!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next)
                pq.push(temp->next);
        }
        return head;
    }
};
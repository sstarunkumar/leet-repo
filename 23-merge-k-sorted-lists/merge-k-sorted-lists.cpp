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
        {
            if(lists[i])
                pq.push(lists[i]);
        }  
        ListNode *head = nullptr,*tail = nullptr;       
        while(!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            if(head == nullptr && tail == nullptr)
            {
                head = tail = temp;
                temp = temp ->next;
                if(temp)
                    pq.push(temp);
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
                temp = temp->next;
                if(temp)
                    pq.push(temp);
            }
        }
        return head;
    }
};
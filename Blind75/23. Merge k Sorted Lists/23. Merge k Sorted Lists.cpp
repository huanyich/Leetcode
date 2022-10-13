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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(auto it:lists){
            if(it)pq.push({it->val, it});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(!pq.empty()){
            auto pq_top = pq.top();
            pq.pop();
            curr->next = pq_top.second;
            curr = curr->next;
            pq_top.second = pq_top.second->next;
            if(pq_top.second){
                pq.push({pq_top.second->val, pq_top.second});
            }
        }
        return dummy->next;

    }
};

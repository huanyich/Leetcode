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
    //Solution 1. use extra space
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        while(head){
            ListNode* curr = new ListNode(head->val);
            v.push_back(curr);
            head = head->next;
        }
        
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for(int i=0; i<v.size(); i++){
            
            if(i==v.size()-n) continue;
            curr->next = v[i];
            curr = curr->next;
        }
        
        return dummy->next;
        
        
        
        
        
    }
    
    
};

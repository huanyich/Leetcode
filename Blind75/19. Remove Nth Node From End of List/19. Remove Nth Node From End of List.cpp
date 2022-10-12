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
// Solution 1. Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head = head->next;
        }

        int N = v.size();
        int target = N-n;
        cout<<target<<endl;
        if(target==0){
            if(N>1) return v[1];
            else return {};
        }
        if(target+1<N)v[target-1]->next =v[target+1];
        else v[target-1]->next = NULL;
        return v[0];
        
    }
};

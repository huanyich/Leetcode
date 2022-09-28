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
    //Solution 1. use extra space and two pass
class Solution {
public:

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
//Solution 2. two path with no extra space
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
	ListNode* dummy = head;

	//first path to know the length
	while(dummy){
		length++;
		dummy = dummy->next;
	}
	
	dummy = head;
	int target = length - n +1;
	int count = 1;
    
	if(target == 1){
		head = head->next;
		return head;
	}
        
	while(head){
		if(count+1==target){
			head->next = head->next->next;
		}else{
			head = head->next;
		}
        count++;
	}
	return dummy;    
    }  
};
//Solution 3. One pass, no extra space
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        ListNode* first = dummy;
        ListNode* second = dummy;
        dummy->next = head;
        for(int i=1; i<=n+1; i++){
            first = first->next;
        }
        while(first){
            second = second->next;
            first = first->next;
        }
        
        second->next = second->next->next;
        return dummy->next;
    }
    
};

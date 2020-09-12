#include <iostream>
using namespace std;

struct ListNode 
	int value;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public :
	ListNode* detectCycle(ListNode* head) {
		if (head == NULL) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)
                break;
        }
        
        if (fast == NULL || fast->next == NULL)
            return NULL;
        
		/*
        slow = head;
        
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }*/
        
        return fast;
	}

	ListNode *detectCycle(ListNode *head) {
		int i;
		while(head != NULL) {
			if( mp.find(head) != mp.end() )
				return head;
			else
				mp[head] = i;
				
			i++;
			head = head->next;
		}
		return NULL;
	}
}

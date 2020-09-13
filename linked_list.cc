#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
	void init() {
		val = 0;
		next = NULL;
	}
    
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        struct SinglyListNode* cur = head;
        while(index-- > 0){
            if (!cur) return -1;
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (head == NULL) {
            head = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
			head->init();
            head->val = val;
        } else {
            struct SinglyListNode* cur = (struct SinglyListNode*) malloc(sizeof(struct SinglyListNode));
			cur->init();

            cur->val = val;
            cur->next = head;
            head = cur;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        struct SinglyListNode* cur = head;
        struct SinglyListNode* newNode = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
		newNode->init();

        for (cur=head; cur->next!=NULL; cur=cur->next);
 
        newNode->val = val;
        cur->next = newNode;

    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        struct SinglyListNode* curNext = head->next;
        struct SinglyListNode* curPre = head;
        struct SinglyListNode* cur = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
		cur->init();

        int cnt = 0;
        if (index == 0){
            cur->val= val;
            cur->next = head;
            head = cur;
            return ;
        }

        for(cnt = 0; cnt < index; cnt++){
            if (!curNext) return;
            else {
                if (cnt == index - 1) {

					if (curNext == NULL){
						cur->val = val;
						curPre->next = cur;
						cur->next = NULL;
						return;
					} else {
						cur->val = val;
						cur->next = curNext;
						curPre->next = cur;
					}

                } else {
					curNext = curNext->next;
					curPre = curPre->next;
				}
            }
        }

    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        struct SinglyListNode* cur = head;
        struct SinglyListNode* curNext = head->next;

        if (index == 0) {
            head = head->next;
			if (cur!=NULL)
				free(cur);
        } 

        for(int i = 0; i < index; i++){
            if (!curNext) return;
            else {
                if (i == index - 1){
                    cur->next = curNext->next;
                    free(curNext);
					return;
                } else {
					cur = cur->next;
					curNext = curNext->next;
				}
                
            }
        }
    
    }

	struct SinglyListNode* getHead(){
		return this->head;
	}

private:

    struct SinglyListNode* head;
};

int main(){
    MyLinkedList* obj = new MyLinkedList();
	struct SinglyListNode *cur ;

	int index = 0;
	int val = 1;
    obj->addAtHead(val);

	for (cur = obj->getHead(); cur != NULL; cur = cur->next)
		cout << cur->val << "->" ;
	cout << endl;
	cout << "---------------------" << endl;

    int param_1 = obj->get(index);
	val = 2;
    obj->addAtTail(val);
	for (cur = obj->getHead(); cur != NULL; cur = cur->next)
		cout << cur->val << "->" ;
	cout << endl;
	cout << "---------------------" << endl;

	index = 1;
	val = 3;
    obj->addAtIndex(index,val);
	for (cur = obj->getHead(); cur != NULL; cur = cur->next)
		cout << cur->val << "->" ;
	cout << endl;
	cout << "---------------------" << endl;

    obj->deleteAtIndex(index);

	for (cur = obj->getHead(); cur != NULL; cur = cur->next)
		cout << cur->val << "->" ;
	cout << endl;

    return 0;
}

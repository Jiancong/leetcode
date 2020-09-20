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
		length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        struct SinglyListNode* cur = head;
        while(index-- > 0){
            if (!cur) return -1;
            cur = cur->next;
        }
		if (cur==NULL) return -1;
		else 
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
		length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        struct SinglyListNode* cur = head;
        struct SinglyListNode* newNode = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
		newNode->init();

        for (cur=head; cur->next!=NULL; cur=cur->next);
 
        newNode->val = val;
        cur->next = newNode;

		length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        struct SinglyListNode* curNext = NULL; 
        struct SinglyListNode* curPre = head;
        struct SinglyListNode* cur = (struct SinglyListNode*)malloc(sizeof(struct SinglyListNode));
		cur->init();

		if (head != NULL)
			curNext = head->next;

        int cnt = 0;
        if (index == 0){
            cur->val= val;
            cur->next = head;
            head = cur;
			length++;
            return ;
        }

		if (length == index) {
			addAtTail(val);
			return ;
		}

        for(cnt = 0; cnt < index; cnt++){
            if (!curNext) {

				return;
			}
            else {
                if (cnt == index - 1) {

					if (curNext == NULL){
						cur->val = val;
						curPre->next = cur;
						cur->next = NULL;
						length++;
						return;
					} else {
						cur->val = val;
						cur->next = curNext;
						curPre->next = cur;
						length++;
						return;
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
			if (cur!=NULL) {
				free(cur);
				length--;
				return ;
			}


        } 

        for(int i = 0; i < index; i++){
            if (!curNext) return;
            else {
                if (i == index - 1){
                    cur->next = curNext->next;
                    free(curNext);
					length--;
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

	int getLength(){
		return length;
	}

private:

    struct SinglyListNode* head;
	int length;
};

void printList(MyLinkedList* obj)
{
	struct SinglyListNode *cur ;

	for (cur = obj->getHead(); cur != NULL; cur = cur->next)
		cout << cur->val << "->" ;
	cout << endl;
	cout << "---------------------" << endl;

}

void testcase_4(){
	/*
	 * ["MyLinkedList","addAtHead","addAtIndex","addAtIndex","addAtHead","deleteAtIndex","addAtIndex","addAtHead","addAtTail","addAtHead","get"
	 * [[],[86],[1,54],[1,14],[83],[4],[3,18],[46],[3],[76],[5]
	 *
	 * [null,null,null,null,null,null,null,null,null,null,18,
	 * */
    MyLinkedList* obj = new MyLinkedList();

	int index = 0;
	int val = 86;
    obj->addAtHead(val);
	printList(obj);

	cout << "len:" << obj->getLength() << endl;

	index = 1;
	val = 54;
    obj->addAtIndex(index, val);
	printList(obj);

	cout << "len:" << obj->getLength() << endl;

	index = 1;
	val = 14;
    obj->addAtIndex(index, val);
	printList(obj);

	cout << "len:" << obj->getLength() << endl;

	val = 83;
    obj->addAtHead(val);
	printList(obj);

	cout << "len:" << obj->getLength() << endl;

	index = 4;
    obj->deleteAtIndex(index);
	printList(obj);

	cout << "len:" << obj->getLength() << endl;

	index = 3;
	val = 18;
    obj->addAtIndex(index, val);
	printList(obj);

	val = 46;
    obj->addAtHead(val);
	printList(obj);

	val = 3;
	obj->addAtTail(val);
	printList(obj);

	val = 76;
    obj->addAtHead(val);
	printList(obj);

    int ret = obj->get(5);
	cout << ret << endl;
	printList(obj);
}

void testcase_3(){
    MyLinkedList* obj = new MyLinkedList();

	int index = 0;
	int val = 4;
    obj->addAtHead(val);
	printList(obj);

    int ret = obj->get(1);
	cout << ret << endl;

	val = 1;
    obj->addAtHead(val);
	printList(obj);

	val = 5;
    obj->addAtHead(val);
	printList(obj);

	index = 3;
    obj->deleteAtIndex(index);
	printList(obj);

	val = 7;
    obj->addAtHead(val);
	printList(obj);

    ret = obj->get(3);
	cout << ret << endl;

    ret = obj->get(3);
	cout << ret << endl;

    ret = obj->get(3);
	cout << ret << endl;

	val = 1;
    obj->addAtHead(val);
	printList(obj);

	index = 4;
    obj->deleteAtIndex(index);
	printList(obj);
}

void testcase_2(){
	/*
	 *["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
	 [[],[0,10],[0,20],[1,30],[0]]
	 * */
    MyLinkedList* obj = new MyLinkedList();
	int index = 0;
	int val = 10;
    obj->addAtIndex(index,val);
	printList(obj);

	index = 0;
	val = 20;
    obj->addAtIndex(index,val);
	printList(obj);

	index = 1;
	val = 30;
    obj->addAtIndex(index,val);
	printList(obj);

	index = 0;
	int ret = obj->get(index);
	cout << ret << endl;
	printList(obj);

}

void testcase_1(){
    MyLinkedList* obj = new MyLinkedList();
	int index = 0;
	int val = 7;

    obj->addAtHead(val);

	printList(obj);

	val = 2;
	obj->addAtHead(val);

	printList(obj);

	val = 1;
	obj->addAtHead(val);

	printList(obj);

	index = 3;
	val = 0;
    obj->addAtIndex(index,val);

	printList(obj);

	index = 2;
    obj->deleteAtIndex(index);

	printList(obj);

	val = 6;
	obj->addAtHead(val);

	printList(obj);

	val = 4;
	obj->addAtTail(val);
/*
[
	"MyLinkedList",
	[],
	"addAtHead",
	[7],
	"addAtHead",
	[2],
	"addAtHead",
	[1],
	"addAtIndex",
	[3,0],
	"deleteAtIndex",
	[2],
	"addAtHead",
	[6],
	"addAtTail",
	[4],
	"get",
	[4],
	"addAtHead",
	[4],
	"addAtIndex",
	[5,0],
	"addAtHead"
	[6]
]
*/
	printList(obj);

	index = 4;
	int ret = obj->get(index);
	cout << ret << endl;

	printList(obj);

	val = 4;
	obj->addAtHead(val);

	printList(obj);

	val = 4;
	obj->addAtIndex(5, 0);

	printList(obj);

	val = 6;
	obj->addAtHead(val);

	printList(obj);
	
}

int main(){

	testcase_4();

    return 0;
}

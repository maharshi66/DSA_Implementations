#include <iostream>
using namespace std;

struct SinglyLinkedNode{
	int val;
	SinglyLinkedNode *next;
	SinglyLinkedNode() : val(0), next(nullptr) {}
};

class SinglyLinkedList{
	private:
	SinglyLinkedNode *head;
	SinglyLinkedNode *tail;
		
	public:
	SinglyLinkedList(): head(nullptr), tail(nullptr) {}
	
	int getLength(SinglyLinkedNode* head){
		if(!head){
			return 0;
		}
		int count = 0;
		SinglyLinkedNode* temp = head;
		while(head != nullptr){
			head = head->next;
			count++;
		}
		head = temp;
		return count;
	}

	void addAtHead(int val){
		SinglyLinkedNode* newNode = new SinglyLinkedNode();
		newNode->val = val;
		if(!head){
			head = newNode;
			tail = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
		return;
	}

	void addAtTail(int val){
		SinglyLinkedNode* newNode = new SinglyLinkedNode();
		newNode->val = val;
		if(!head){
			head = newNode;
			tail = newNode;
			return;
		}

		tail->next = newNode;
		tail = newNode;
		return;
	}

	void addAtIndex(int index, int val){
		if(index == 0){
			addAtHead(val);
			return; 
		}else if(!head && index != 0){
			return; 
		}
		
		if(index == getLength(head)){
			addAtTail(val);
			return;
		}else if(index > getLength(head)){
			return;
		}
		
		SinglyLinkedNode* newNode = new SinglyLinkedNode();
		newNode->val = val;
		int idx = 0;
		SinglyLinkedNode* temp = head;
		while(idx < index - 1){
			temp = temp -> next;
		}
        newNode->next = temp->next;
        temp->next = newNode;		
	}

	SinglyLinkedNode* getNodeAtIndex(int index){
		if(!head){
			return nullptr;
		}
		if(index > getLength(head)){
			return nullptr;
		}
		int idx = 0;
		SinglyLinkedNode* temp = head;
		while(head != nullptr)
		{
			if(idx == index){
				return head;
			}
			head = head->next;
			idx++;
		}

		return nullptr;
	}

    void deleteAtHead(){
        if(head == NULL){
            return;
        }
        SinglyLinkedNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    void deleteAtTail(){
        if(head == NULL){
            return ;
        }
        SinglyLinkedNode* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>= getLength(head)){
            return;
        }
        if(index == 0){
            deleteAtHead();
            return;
        }
        if(index == getLength(head)-1){
            deleteAtTail();
            return ;
        }
        int i=0;
        SinglyLinkedNode* temp = head;
        while(i < index-1){
            temp = temp->next;
            i++;
        }
        SinglyLinkedNode* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }

    void print(){
        if(head == nullptr){
            return;
        }
        SinglyLinkedNode* temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
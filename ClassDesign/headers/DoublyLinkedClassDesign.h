#include <iostream>
using namespace std;

struct DoublyLinkedNode{
	int val;

	DoublyLinkedNode *prev;
	DoublyLinkedNode *next;
	DoublyLinkedNode() : val(0), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList{
	private:
	DoublyLinkedNode* head;
	DoublyLinkedNode* tail;

	public:
	DoublyLinkedList(): head(nullptr), tail(nullptr) {}

	int getAtIndex(int index){
		if(index > getLength(head) || index < 0){
			cout<<"Incorrect index!"<<endl;
			return -1;
		}
		DoublyLinkedNode* temp = head;
		int idx = 0;
		while(idx != index){
			temp = temp->next;
			idx++;
			}
		return temp->val;
	}

	int getLength(DoublyLinkedNode* head){
		if(!head){
			return 0;
		}
		int count = 0;
		DoublyLinkedNode* temp = head;
		while(head != nullptr){
			head = head->next;
			count++;
		}
		head = temp;
		return count;
	}

	void addAtHead(int val){
		DoublyLinkedNode* newNode = new DoublyLinkedNode();
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
		DoublyLinkedNode* newNode = new DoublyLinkedNode();
		newNode->val = val;
		if(!head){
			head = newNode;
			tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = tail->next;
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

		int idx = 0;
        DoublyLinkedNode* temp = head;
        DoublyLinkedNode* newNode = new DoublyLinkedNode();
        int i=0;
        while(i < index-1){
            temp=temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;		
	}

	void deleteAtHead(){
        if(!head){
            return;
        }
        DoublyLinkedNode* temp = head;
        head = head->next;
        delete temp;
	}

	void deleteAtTail(){
        if(!head){
            return ;
        }
        DoublyLinkedNode* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
	}

	void deleteAtIndex(int index){
        if(index >= getLength(head)){
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
        DoublyLinkedNode* temp = head;
        while(i < index-1){
            temp = temp->next;
            i++;
        }
        DoublyLinkedNode* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
	}

	void print(){
        if(head == nullptr){
            return;
        }
        DoublyLinkedNode* temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
	}
};
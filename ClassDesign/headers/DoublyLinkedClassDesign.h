#include <iostream>
using namespace std;

/**
 * @brief      Doubly Linked Node Structure
 */
struct DoublyLinkedNode{
	int val;

	DoublyLinkedNode *prev;
	DoublyLinkedNode *next;
	DoublyLinkedNode() : val(0), next(nullptr), prev(nullptr) {}
};

/**
 * @brief      This class describes a doubly linked list.
 */
class DoublyLinkedList{
	private:
	DoublyLinkedNode* head;
	DoublyLinkedNode* tail;

	public:
	/**
	 * @brief      Constructs a new instance.
	 */
	DoublyLinkedList(): head(nullptr), tail(nullptr) {}

	/**
	 * @brief      Gets the at index.
	 *
	 * @param[in]  index  The index
	 *
	 * @return     The at index.
	 */
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

	/**
	 * @brief      Gets the length.
	 *
	 * @param      head  The head
	 *
	 * @return     The length.
	 */
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

	/**
	 * @brief      Adds an at head.
	 *
	 * @param[in]  val   The value
	 */
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

	/**
	 * @brief      Adds an at tail.
	 *
	 * @param[in]  val   The value
	 */
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

	/**
	 * @brief      Adds an at index.
	 *
	 * @param[in]  index  The index
	 * @param[in]  val    The value
	 */
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

	/**
	 * @brief      Deletes node at head
	 */
	void deleteAtHead(){
        if(!head){
            return;
        }
        DoublyLinkedNode* temp = head;
        head = head->next;
        delete temp;
	}

	/**
	 * @brief      Deletes node at tail
	 */
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

	/**
	 * @brief      Deletes node at index
	 *
	 * @param[in]  index  The index
	 */
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

	/**
	 * @brief      { function_description }
	 */
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
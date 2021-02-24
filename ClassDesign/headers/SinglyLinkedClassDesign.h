#include <iostream>
using namespace std;

struct SinglyLinkedNode{
	int val;
	SinglyLinkedNode *next;
	SinglyLinkedNode() : val(0), next(nullptr) {}
	SinglyLinkedNode(int val) : val(val), next(nullptr) {}
};

class SinglyLinkedList{		
	public:
	SinglyLinkedNode *head;
	SinglyLinkedNode *tail;

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
		SinglyLinkedNode* newNode = new SinglyLinkedNode(val);
		if(!head){
			head = newNode;
			tail = newNode;
			return;
		}

		tail->next = newNode;
		tail = tail->next;
		tail->next = nullptr;
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

   	SinglyLinkedNode* reverseList(){
      // Iterative approach  
   	  SinglyLinkedNode *prevNode, *currNode, *nextNode;
      if (head == nullptr || head->next == nullptr) 
      {
        return head;
      }

      prevNode = nullptr;
      currNode = head;
        
      while(currNode != nullptr)
      {
          nextNode = currNode->next;
          currNode->next = prevNode;
          prevNode = currNode;
          currNode = nextNode;
      }
        
        head = prevNode;
        return head;
   	}

   	void rotateList(int k){
		if(!head || k == 0){
			return;
		}
		SinglyLinkedNode* curr = head;
		int length, lastNode;
		
		//Get to the last node
		while(curr->next != nullptr){
			curr = curr->next;
		}

		length = getLength(head)  + 1; 
		k = k % length; //Optimization for when k is greater than length
		lastNode = length - k;

		//Make it circular by connecting last node to first node
		curr->next = head;
		while(lastNode--){
			curr = curr->next;	
		} 
		head = curr->next;
		curr->next = nullptr;
		return;
   	} 

   	//Deep Copy of a Linked List
   	SinglyLinkedNode* copyList(){
   		if(head == nullptr) return nullptr;
   		SinglyLinkedNode* curr = head;
   		SinglyLinkedNode* newList = nullptr;
   		SinglyLinkedNode* tail = nullptr;

   		while(curr !=  nullptr){
   			if(newList == nullptr){
   				newList = new SinglyLinkedNode(curr->val);
   				tail = newList;
   			}
   			else
   			{
   				tail->next = new SinglyLinkedNode(curr->val);
   				tail = tail->next;
   				tail->next = nullptr;
   			}
   			curr = curr->next;
   		}

   		return newList;
   	}
};

void printList(SinglyLinkedList* list){
        if(list->head == nullptr){
            return;
        }
        SinglyLinkedNode* temp = list->head;
        while(temp!=nullptr){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<endl;
}
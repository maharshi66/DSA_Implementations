#include <iostream>
using namespace std;

/**
 * @brief      Node structure
 */
struct SinglyLinkedNode{
	int val;
	SinglyLinkedNode *next;
	SinglyLinkedNode() : val(0), next(nullptr) {}
	SinglyLinkedNode(int val) : val(val), next(nullptr) {}
};


/**
 * @brief      This class describes a singly linked list .
 */
class SinglyLinkedList{		
	public:
	SinglyLinkedNode *head;
	SinglyLinkedNode *tail;

	/**
	 * @brief      Constructs a new instance.
	 */
	SinglyLinkedList(): head(nullptr), tail(nullptr) {}
	
	/**
	 * @brief      Gets the length.
	 *
	 * @param      head  The head
	 *
	 * @return     The length.
	 */
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

	/**
	 * @brief      Adds an at head.
	 *
	 * @param[in]  val   The value
	 */
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

	/**
	 * @brief      Adds an at tail.
	 *
	 * @param[in]  val   The value
	 */
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

	/**
	 * @brief      Gets the node at index.
	 *
	 * @param[in]  index  The index
	 *
	 * @return     The node at index.
	 */
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

    /**
     * @brief      { function_description }
     */
    void deleteAtHead(){
        if(head == NULL){
            return;
        }
        SinglyLinkedNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    /**
     * @brief      { function_description }
     */
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

    /** Delete the index-th node in the linked list, if the index is valid.
     *
     * @param[in]  index  The index
     */
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

   	/**
   	 * @brief      Reverses the linked list
   	 *
   	 * @return     Reversed List
   	 */
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

   	/**
   	 * @brief      Rotates the Linked List
   	 *
   	 * @param[in]  k     number of rotations
   	 */
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


   	/**
   	 * @brief      Makes a Deep Copy of the linked list
   	 *
   	 * @return     Copied List
   	 */
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

/**
 * @brief      Prints a list.
 *
 * @param      list  The list
 */
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
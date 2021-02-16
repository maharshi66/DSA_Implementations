#include "DoublyLinkedClassDesign.h"
int main(){

	 DoublyLinkedList* obj = new DoublyLinkedList();
	 obj->addAtHead(7);
	 obj->addAtTail(11);
	 obj->addAtIndex(2,16);
	 obj->addAtIndex(3,16);
	 obj->addAtIndex(4,17);
	 obj->addAtIndex(5,116);
	 obj->addAtIndex(6,216);
	 obj->addAtIndex(7,6);
	 obj->addAtIndex(8,96);
	 obj->addAtIndex(9,126);
	 obj->addAtIndex(10,1446);
	 obj->addAtIndex(11,126);
	 
	 //FIX DELETE AT INDEX! Incorrect O/P
	 obj->deleteAtIndex(3); 
	 obj->deleteAtIndex(4);
 	 obj->print();
 	 return 0;
}
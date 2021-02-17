#include <iostream>
#include "SinglyLinkedClassDesign.h"

int main(){
 	SinglyLinkedList* obj = new SinglyLinkedList();
 	obj->addAtHead(5);
 	obj->addAtTail(7);
 	obj->addAtIndex(2,9);
 	obj->addAtIndex(3,4);
 	obj->addAtIndex(4,0);
 	obj->addAtIndex(5,21);
 	obj->addAtIndex(6,17);
 	obj->addAtIndex(7,666);
 	obj->printList();
 	obj->reverseList();
	return 0;
}

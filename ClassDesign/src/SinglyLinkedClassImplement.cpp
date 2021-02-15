#include <iostream>
#include "SinglyLinkedClassDesign.h"

int main(){
 	SinglyLinkedList* obj = new SinglyLinkedList();
 	obj->addAtHead(5);
 	obj->addAtTail(7);
 	obj->addAtIndex(2,9);
 	obj->deleteAtIndex(1);
 	obj->print();
	return 0;
}

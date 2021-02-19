#include <iostream>
#include "SinglyLinkedClassDesign.h"

int main(){
 	SinglyLinkedList* obj = new SinglyLinkedList();

 	cout<<endl<<"========ADDING, DELETING========"<<endl;
 	obj->addAtHead(5);
 	obj->addAtTail(7);
 	obj->addAtIndex(2,9);
 	obj->addAtIndex(3,4);
 	obj->addAtIndex(4,0);
 	obj->addAtIndex(5,21);
 	obj->addAtIndex(6,17);
 	obj->addAtIndex(7,666);
 	printList(obj);
 	cout<<endl<<"========REVERSING========"<<endl;
 	obj->reverseList();
 	printList(obj);
 	
 	cout<<endl<<"========ROTATING========"<<endl;
 	SinglyLinkedList* obj_2 = new SinglyLinkedList();
 	obj_2->addAtHead(1);
 	obj_2->addAtIndex(1,2);
 	obj_2->addAtIndex(2,3);
 	obj_2->addAtIndex(3,4);
 	obj_2->addAtIndex(4,5);
 	obj_2->rotateList(17);
 	printList(obj_2);

 	cout<<endl<<"========DEEP COPY========"<<endl;
 	SinglyLinkedNode* list = obj_2->copyList();
 	SinglyLinkedList* newList = new SinglyLinkedList();
 	newList->head = list;
 	printList(newList);
	return 0;
}
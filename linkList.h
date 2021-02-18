#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stdlib.h>

#endif
typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate();//Initialize struct.
int myLinkedListGet(MyLinkedList* obj, int index);//Get the value of the index-th node in the linked list. If the index is invalid, return -1.
void myLinkedListAddAtHead(MyLinkedList* obj, int val);//Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void myLinkedListAddAtTail(MyLinkedList* obj, int val);//Append a node of value val to the last element of the linked list.
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);//Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);//Delete the index-th node in the linked list, if the index is valid.
void myLinkedListFree(MyLinkedList* obj);//free
void myLinkedListSelectionSort(MyLinkedList* obj); //Select sort the list.
int myLinkedListLength(MyLinkedList* obj); //Return the length of list.
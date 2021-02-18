#include "linkList.h"


/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->next = NULL; list->val = -1;
    return list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0) return -1;
    MyLinkedList *tmp = obj;
    while(tmp != NULL && index>=0){
        index--;
        tmp = tmp->next;
    }
    if(tmp==NULL|| index>=0) return -1;
    return tmp->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* head = obj;
    MyLinkedList* tmp = (MyLinkedList*)malloc(sizeof(MyLinkedList)); 
    tmp->val = val;
    tmp->next = head->next;
    head->next = tmp;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *cur = obj;
    MyLinkedList* tmp = (MyLinkedList*)malloc(sizeof(MyLinkedList)); 
    
    while(cur->next!=NULL)
        cur = cur->next;
    tmp->val = val; tmp->next=NULL;   
    cur->next = tmp;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* cur = obj; MyLinkedList* pre = NULL; MyLinkedList* tmp = NULL;
    while(cur != NULL && index>=0){
        pre = cur;
        cur = cur->next;
        index--;
    }
    if(cur==NULL && index>=0) return;//If index is greater than the length, the node will not be inserted.
    tmp = (MyLinkedList*)malloc(sizeof(MyLinkedList)); tmp->val = val;
    pre->next = tmp;
    tmp->next = cur;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index<0)return;
    MyLinkedList* cur = obj; MyLinkedList* pre = NULL;
    while(cur!=NULL && index>=0){
        pre = cur;
        cur = cur->next;
        index--;
    }
    //if index is invalid
    if(cur==NULL) return;
    pre->next = (cur->next==NULL)?NULL:cur->next;
    free(cur);
}

void myLinkedListFree(MyLinkedList* obj) {
    while(obj!=NULL){
        MyLinkedList *tmp = obj;
        obj = obj->next;
        free(tmp);
    }
}

/** Selection sort */
void myLinkedListSelectionSort(MyLinkedList* obj){
    if(obj->next == NULL || obj == NULL) return;

    MyLinkedList* tail = obj; //尾部指针,采用尾插法
    MyLinkedList* tmp = NULL; //获取排序后的最小指针

    while(tail!=NULL){
        tmp = selectMinNode(tail);//尾部指针作为新的‘头’节点
        //将最小节点尾插到tail后面
        if(tmp==NULL) break;//达到末尾，排序完毕
        tmp->next = tail->next;
        tail->next = tmp;
        tail = tmp;//更新尾部指针位置
    }
}

/** return minimun node*/
MyLinkedList* selectMinNode(MyLinkedList* obj){
    if(obj->next==NULL) return NULL;//达到末尾，排序完毕，返回NULL
    MyLinkedList* preMin = obj; //最小前置指针
    MyLinkedList* min = obj->next; //最小指针

    obj = obj->next;//指向第一个节点值
    //找到最小节点及其前置指针
    while (obj->next != NULL)
    {
        if(obj->next->val < min->val){
            min = obj->next;//比较取小
            preMin = obj;//记录前置
        } 
        obj = obj->next;
    }
    preMin->next = min->next; //将min摘出，使preMin指向min后置
    return min;
}
 /**Return the length of list*/
int myLinkedListLength(MyLinkedList* obj){
    int length=0; obj = obj->next;//指向第一个节点值
    while (obj!=NULL)
    {
        obj = obj->next;
        length++;
    }
    return length;
}
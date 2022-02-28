#include "linkStack.h"
#include <stdio.h>

linkStack::linkStack(){
    length = 0;
    head = new node;
    head->data = -1;
    head->next = nullptr;
}

linkStack::~linkStack(){
    delete head;
}

void linkStack::pushStack(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
    length++;
}

int linkStack::popStack(){
    int temp = head->next->data;
    node *temp1 = head->next;
    head->next = head->next->next;
    delete temp1;
    length--;
    return temp;
}

int linkStack::getlen(){
    return length;
}

int linkStack::queryStack(int position){
    if(position < 1 || position > length){
        perror("Query position is illegal!");
    }

    node *temp = head;
    for(int i = 0; i < position; ++i){
        temp = temp->next;
    }

    return temp->data;
}

void linkStack::printStack(){
    node *temp = head;
    for(int i = 0; i < length; ++i){
        temp = temp->next;
        printf("%d ", temp->data);
    }
}
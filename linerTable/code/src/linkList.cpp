#include "linkList.h"
#include <stdio.h>

linkList::linkList(){
    head = new node;
    head->data = 0;
    head->next = nullptr;
    length = 0;
}

linkList::~linkList(){
    delete head;
}

int linkList::getlen(){
    return length;
}

void linkList::insertList(int position, int elem){
    if(position < 1 || position > (length + 1)){
        perror("insert position is illegal");
    }
    node *temp;
    temp = head;
    for(int i = 0; i<(position - 1); ++i){
        temp = temp->next;
    }
    node *newnode;
    newnode = new node;
    newnode->data = elem;
    newnode->next = temp->next;
    temp->next = newnode;
    length++;
}

int linkList::deleteList(int position){
    if(position < 1 || position > length){
        perror("position delete is illegal!");
        return 0;
    }
    node *temp = head;
    for(int i = 0; i < position - 1; ++i){
        temp = temp->next;
    }
    node *deletenode = temp->next;
    temp->next = temp->next->next;
    int data = deletenode->data;
    delete deletenode;
    length--;
    return data;
}


void linkList::printList(){
    node *temp = head;
    for(int i = 0; i < length ; ++i){
        temp = temp->next;
        printf("%d ", temp->data);
    }
}

//查询功能，输入一个位置输出相应的数据，先判断是否有数据，设置中间量，循环找到正确位置
int linkList::queryList(int position){
    if(position < 1 || position > length){
        perror("position query is illegal!");
        return -1;
    }
    node *temp = head;
    for(int i = 0; i < position; ++i){
        temp = temp->next;
    }
    return temp->data;
}

//更改功能，输入位置及数据，更改相应位置的数据，先判断位置是否合法，然后设置中间量，循环找到位置，进行更改
void linkList::changeList(int position, int elem){
    if(position < 1 || position > length){
        perror("position change is illegal!");
    }
    node *temp = head;
    for(int i = 0; i < position; ++i){
        temp = temp->next;
    }
    temp->data = elem;
}

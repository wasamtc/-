#include "src/linkList.h"
#include <iostream>

int main(){
    linkList list;
    list.insertList(1,2);
    list.insertList(2,3);
    list.insertList(3,4);
    list.printList();
    return 0;
}
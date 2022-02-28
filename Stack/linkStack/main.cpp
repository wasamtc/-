#include "src/linkStack.h"
#include <iostream>

int main(){
    linkStack stack;
    stack.pushStack(1);
    stack.pushStack(2);
    std::cout<<stack.queryStack(2)<<' ';
    std::cout<<stack.popStack()<<' ';
    stack.printStack();
    return 0;
}
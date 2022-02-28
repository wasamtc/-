#ifndef SQLIST_H
#define SQLIST_H

template <typename T>
class sqList
{
private:
    int length;
    int maxSize;
    T *array;
public:
    sqList(int _maxSize);
    ~sqList();

    int getlen();
    void listInsert(int position, T elem);
    T listDelete(int position);
    T listQuery(int position);
    void print();
};

#include "sqList.h"
#include <stdio.h>
#include <iostream>

template <typename T>
sqList<T>::sqList(int _maxSize){
    length = 0;
    array = new T [_maxSize];
    maxSize = _maxSize;
}

template <typename T>
sqList<T>::~sqList(){
    delete [] array;
}

template <typename T>
void sqList<T>::listInsert(int position, T elem){
    if(position < 1 || position > (length + 1)){
        perror("List insert position is illegal!");
        return;
    }
    if(length == maxSize){
        perror("list has maxSize array!");
        return;
    }
    if((length + 1) != position) //插入位置不在表尾
    {
        for(int i = length; i >= position; --i){
            array[i] = array[i-1];
        }
    }

    array[position - 1] = elem;
    length++;
}

template <typename T>
T sqList<T>::listDelete(int position){
    if(position < 1 || position > length){
        perror("List delete position is illegal!");
    }
    T temp = array[position - 1];
    for(int i = position - 1; i < (length - 1); ++i){
        array[i] = array[i+1];
    }
    length--;
    return temp;
}

template <typename T>
T sqList<T>::listQuery(int position){
    return array[position -1];
}

template <typename T>
void sqList<T>::print(){
    for(int i = 0; i < length; ++i){
        std::cout<<array[i]<<' ';
    }
}
#endif

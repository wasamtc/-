#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MAXSIZE 100000
class hashTable
{
private:
    int a[MAXSIZE];
public:
    hashTable();
    ~hashTable();

    void insertTable(int);
    bool queryTable(int);
};

hashTable::hashTable(/* args */)
{
}

hashTable::~hashTable()
{
}

void hashTable::insertTable(int data){
    a[data % MAXSIZE] = data;
}

bool hashTable::queryTable(int data){
    if(a[data % MAXSIZE] == data)
        return true;
    return false;
}

#endif
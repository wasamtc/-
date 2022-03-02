#define MAXSIZE 100000
#include <vector>
#include <stdio.h>

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

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        hashTable temp;
        for(int i = 0; i < nums.size(); ++i){
            if(temp.queryTable(nums[i]))
                return true;
            temp.insertTable(nums[i]);
        }
        return false;
    }
};

int main(){
    std::vector<int> nums;
    int temp;
    while(scanf("%d", &temp) != EOF){
        nums.push_back(temp);
    }

    Solution solve;
    printf("%d", solve.containsDuplicate(nums));
}
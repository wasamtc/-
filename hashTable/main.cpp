#include "hashTable.h"
#include <stdio.h>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
        hashTable temp;
        for(int i = 0; i < nums.size(); ++i){
            if(temp.queryTable(nums[i]))
                return true;
            temp.insertTable(nums[i]);
        }
        return false;
    }

int main(){
    std::vector<int> nums;
    int temp;
    while(scanf("%d", &temp) != EOF){
        nums.push_back(temp);
    }
    printf("%d", containsDuplicate(nums));
}
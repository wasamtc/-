#include <vector>
#include <stdio.h>

int partition(std::vector<int> &nums, int low, int high){
    int pivot = nums[low];

    while (low < high)
    {
        while(low < high && nums[high] >= pivot) //这儿必须有等号，不然后陷入死循环
            high--;
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
        while(low < high && nums[low] <= pivot)
            low++;
        temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
    }

    return low;
}

void quickSort(std::vector<int> &nums, int low, int high){
    if(low < high){  //注意递归函数一定要加终止条件
        int pivot = partition(nums, low, high);
        quickSort(nums, low, pivot - 1); //递归的参数要一般化
        quickSort(nums, pivot + 1, high);
    }

}


int main(){
    int temp;
    std::vector<int> nums;
    while(scanf("%d", &temp) != EOF){ //判断输入是否终止可以这样写
        nums.push_back(temp);
    }
    int n = nums.size() - 1;
    quickSort(nums, 0, n);
    for(int i = 0; i < nums.size(); ++i){
        printf("%d ", nums[i]);
    }
}
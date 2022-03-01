#include <vector>
#include <stdio.h>

int partition(std::vector<int> &nums, int low, int high){
    int temp = nums[(low+high)/2];
    nums[(low+high)/2] = nums[low];
    nums[low] = temp; //必须要做一个交换，因为后面是与pivotkey进行比较，如果不交换只有nums[low]和nums[high]比较了
    int pivot = nums[low]; //这儿最好最好进行这样的一个操作，即把pivotkey的选取科学一点，别随便取，随便取效率很低的

    while (low < high)
    {
        while(low < high && nums[high] >= pivot) //这儿必须有等号，不然后陷入死循环
            high--;
        temp = nums[low];
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
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int indices[2];
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                indices[0] = i;
                indices[1] = j;
                *returnSize = 2;
                return indices;
            }
        }
    }
    
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    
    if (result != NULL) {
        printf("Output: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("No two elements sum up to the target.\n");
    }
    
    return 0;
}


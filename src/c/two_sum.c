#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate space for two indices.
    int* result = malloc(sizeof(int) * 2);
    if (!result) return NULL;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    // No solution.
    *returnSize = 0;
    free(result);
    return NULL;
}


int main(void) {
    int nums[] = {2,7,5,11,15};
    int target = 9;
    int returnSize = 0;

    int* indices = twoSum(nums, 4, target, &returnSize);

    if (indices && returnSize == 2) {
        printf("[%d, %d]", indices[0], indices[1]);
    } else {
        printf("Not found");
    }

    free(indices);
    return 0;
}
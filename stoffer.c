#ifndef _STDLIB_H_
#define _STDLIB_H_
    #include <stdlib.h>
#endif

#ifndef _STDBOOL_H_
#define _STDBOOL_H_
    #include <stdbool.h>
#endif
/**在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个
 * 数字重复了几次。请找出数组中任意一个重复的数字。
 */
int findRepeatNumber(int* nums, int numsSize){
    int *count = (int *)malloc(numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        if(count[nums[i]]++){
            free(count);
            return nums[i];
        }
    }
    return -1; //无重复
}

/**在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
int findNumberIn2DArray(int** matrix, int matrixRowSize, int* matrixColSize, int target){
    if(*matrixColSize==0 || matrixRowSize==0) return false;
    int i=0,j=*matrixColSize-1;
    //保证下标不越界，从右上角开始遍历，如果大于target，则下移一行；如果小于target，则左移一列
    while(i<matrixRowSize&&j>=0){
        if(matrix[i][j]==target) return 1;
        else if(matrix[i][j]>target)j--;
        else i++;
    }
    return 0;//没有找到
}


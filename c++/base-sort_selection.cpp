/**
 * Worst-case time complexity	O(N2)
 * Best-case time complexity	O(N2)
 * Average time complexity	    O(N2)
 * Worst-case space complexity  O(1)
 **/

#include <iostream>
#include <vector>
using namespace std;

// 选择排序算法通过从未排序的部分重复查找最小元素（考虑升序）并将其放在开头来对数组进行排序。

// Swap function
void swap(int *xp, int *yp)
{ // 交换两个不同地址指向的元素
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int *array, uint64_t ind_begin, uint64_t ind_end)
{
    int i, j, min_idx;

    // 一个个的从未排序的子数组中找到最小元素, 帮将其放到当前顺序迭代位置
    for (i = ind_begin; i < ind_end; i++)
    {

        // 在未排序子数组中遍历寻找最小值所在位置
        min_idx = i; // 记录当前位置
        for (j = i + 1; j <= ind_end; j++)
            if (array[j] < array[min_idx])
                min_idx = j; // 找到最小值

        if (min_idx != i)
            // 将当前迭代位置的元素与最小值元素交换位置.
            swap(&array[min_idx], &array[i]);
    }
}

// 稳定排序算法: 在排序的同时, 使得排序后的等大元素与排序前相同

void stableSelectionSort(int *array, uint64_t ind_begin, uint64_t ind_end)
{
    // 一个个的从未排序的子数组中找到最小元素, 帮将其放到当前顺序迭代位置
    for (int i = ind_begin; i < ind_end; i++)
    {
        // array 的前 i-1 元素都是排序好的
        // 在未排序子数组 array[i:n-1] 中遍历寻找最小值所在位置
        int min_idx = i;
        for (int j = i + 1; j < ind_end + 1; j++)
            if (array[min_idx] > array[j])
                min_idx = j;

        // 将第 i 到 min_idx-1 区间的元素右移一位, 为当前的最小值留出存放空间
        int key = array[min_idx];
        while (min_idx > i)
        {
            array[min_idx] = array[min_idx - 1];
            min_idx--;
        }
        array[i] = key;
    }
}

int main()
{
    // 获取输入容器所含的元素数量
    int size = 0;
    std::cout << "\n请输入容器大小: " << std::endl;
    std::cin >> size;
    while (size <= 0)
    {
        std::cout << "\n容器大小必须大于零" << std::endl;
        std::cin >> size;
    }
    int *array = new int[size]; // 在程序运行期间, 根据给定的容器大小, 临时分配一片对应大小的内存空间用于存放数据。
    int key = 0;

    std::cout << "\n输入容器值, 数量为: " << size << "" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    // 排序
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    stableSelectionSort(array, 0, size - 1);
    std::cout << "排序后的数组为: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    delete[] array; // 释放临时分配的内存空间
    return 0;
}
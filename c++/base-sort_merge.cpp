/**
 * Worst-case time complexity	O(N log(N))
 * Best-case time complexity	O(N log(N))
 * Average time complexity	    O(N log(N))
 * Worst-case space complexity  O(N)
 **/

#include <iostream>
#include <vector>
using namespace std;

// 合并排序
// 合并排序是稳定排序
// 合并排序是分而治之算法

void merge(int *array, int const ind_begin, int const ind_mid,
           int const ind_end)
{
    auto const subArrayOne = ind_mid - ind_begin + 1; // 计算输入 array 的左侧数据数量(包含中点)
    auto const subArrayTwo = ind_end - ind_mid;       // 计算输入 array 的右侧数据数量(不包含中点)

    // 创建两个临时的 array 存储输入 array 的左侧数据和右侧数据
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[ind_begin + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[ind_mid + 1 + j];

    auto indexOfSubArrayOne = 0,        // 初始化左侧数据的起始 index.
        indexOfSubArrayTwo = 0;         // 初始化右侧数据的起始 index.
    int indexOfMergedArray = ind_begin; // 初始化输入 array 的起始 index.

    // 左侧数据和右侧数据其自身都应该是排序好的, 这里将两侧数据按大小重新放进原输入 array.
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++; // 左侧数据放入输入 array 中, 然后进一.
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++; // 右侧数据放入输入 array 中, 然后进一.
        }
        indexOfMergedArray++; // 继续判断下一个数据应该放哪个
    }
    // 防止左右侧数据有剩余, 将剩余元素继续放到输入 array 中.
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int *array, uint64_t ind_begin, uint64_t ind_end)
{
    if (ind_begin >= ind_end) // 当递归到输入 array 只有一个值时
        return;               // 控制递归结束

    auto ind_mid = ind_begin + (ind_end - ind_begin) / 2; // 计算输入 array 的中点位置
    mergeSort(array, ind_begin, ind_mid);                 // 左段计算
    mergeSort(array, ind_mid + 1, ind_end);               // 右段计算
    merge(array, ind_begin, ind_mid, ind_end);            // 正向递归结束, 开始逐步返回, 融合每段结果
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
    mergeSort(array, 0, size - 1);
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
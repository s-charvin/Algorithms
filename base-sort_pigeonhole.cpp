/**
 * Worst-case time complexity	O()
 * Best-case time complexity	O()
 * Average time complexity	    O()
 * Worst-case space complexity  O()
 **/

#include <iostream>
#include <vector>
using namespace std;

// 鸽巢排序

void pigeonholeSort(int *array, uint64_t begin, uint64_t end)
{
    // 寻找最小值和最大值
    auto min = array[0], max = array[0];
    for (int i = begin + 1; i < end + 1; i++)
    {
        if (array[i] < min)
            min = array[i];
        if (array[i] > max)
            max = array[i];
    }
    int range = max - min + 1;     // 计算 array 中的数值范围
    int *holes = new int[range](); // 创建一个 range 大小的数组, 其中每个位置匹配 array 中可能包含的不同值。

    // 初始化 holes
    for (int i = 0; i < range; i++)
    {
        holes[i] = 0;
    }

    // Traverse through input array and put every element in its respective hole
    // 遍历 array, 并利用 holes 的位置记录 array 中每个元素出现的次数
    for (int i = begin; i < end + 1; i++)
        holes[array[i] - min]++;

    // 遍历 holes 按照顺序和记录的每个值出现的次数, 取出与 array 相匹配的元素并放入数组中。
    int index = begin;              // 记录当前正在处理的 array 中元素的位置
    for (int i = 0; i < range; i++) // 遍历 holes 中的所有出现的次数
    {
        while (holes[i] > 0) // 只要出现次数大于零
        {
            array[index] = i + min; // 将当前 holes 次数位置对应的 array 值计算出来, 并放到新 array 中.
            holes[i]--;             // 将当前 holes 次数减一
            index++;
        }
    }
    delete[] holes;
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
    pigeonholeSort(array, 0, size - 1);
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
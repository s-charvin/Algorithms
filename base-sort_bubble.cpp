/**
 * Worst-case time complexity	O(N2) n(n-1)/2
 * Best-case time complexity	O(N2)
 * Average time complexity	    O(N2)
 * Worst-case space complexity  O(1)
 **/

#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序从前两个元素开始, 两个两个的比较, 每次迭代将最大值冒到最右侧.
// 冒泡排序本身就是稳定排序, 无需进一步完善
// 冒泡排序无需其他数据结构, 因此是就地排序

// void bubbleSort(int *array, int size)
// {
//     int i, j;
//     // 冒出的值依次顺序放在最右侧开始的位置, 共需 n 个值
//     for (i = size - 1; i >= 0; i--)

//         // 从左到右, 每次比较两个值, 如果左值大, 则交换位置
//         for (j = 0; j < i; j++)
//             if (array[j] > array[j + 1])
//                 swap(array[j], array[j + 1]);
// }
// 冒泡排序, 添加停止算法
void bubbleSort(int *array, uint64_t ind_begin, uint64_t ind_end)
{

    int i, j;
    bool swapped;
    for (i = ind_end; i >= uint64_t(ind_begin); i--)
    {
        swapped = false;
        for (j = ind_begin; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

// 冒泡查找, 递归实现
// 因为排序号的值都放在最右侧,
// 因此可以通过 size 参数, 间接调整每次函数的输入 array
void rec_bubblesort(int *array, uint64_t ind_begin, uint64_t ind_end)
{
    auto size = ind_end - ind_begin + 1;
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int i = ind_begin; i < ind_end; i++) // 对当前 size 指定的区域进行一次冒泡操作
    {
        if (array[i] > array[i + 1])
        {
            swap(array[i], array[i + 1]); // 最终最大值会放置到 size-1 位置
        }
    }
    rec_bubblesort(array, ind_begin, ind_end - 1); // 通过 end-1 去除已经排序好的数据
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
    rec_bubblesort(array, 0, size - 1);
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
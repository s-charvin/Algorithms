/**
 * Worst-case time complexity	O()
 * Best-case time complexity	O()
 * Average time complexity	    O()
 * Worst-case space complexity  O()
 **/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 计数排序
// 不是基于比较的算法，它对临时计数数组中的值进行哈希处理并使用它们进行排序。
// 快速排序是非就地算法, 使用了临时数组，
// 具体原理是预先假设输入数据值范围为有界的实数, 然后通过元素界限创建辅助数组, 存储输入数据中每个元素出现的次数

void countSort(int *array, int64_t ind_begin, int64_t ind_end)
{
    int range = 255, i = 0, j = 0;
    // 创建一个初始化为 0 的计数数组来存储个体的计数
    // 这里预先假设了输入数据的大小为 [0-255]
    int count[range + 1] = {}; // memset(count, 0, sizeof(count)); 或 fill(a,a+ind_end,0)

    // 存储每个元素值的计数
    for (i = ind_begin; i <= ind_end; ++i)
        ++count[array[i]];

    // 将所有数据填充到原来数组中的正确位置
    for (i = 0; i <= range && j <= ind_end; ++i)
    {
        while (count[i] > 0)
        {
            array[j++] = i;
            count[i]--;
        }
    }
}

vector<int> countingSort(vector<int> vec)
{
    int n = vec.size();
    map<int, int> count; // map 数据结构
    // 初始化每个元素的记数为 0
    for (int i = 0; i < n; count[i] = 0, i++)
        ;
    // 存储每个元素值的计数
    for (int i = 0; i < n; count[vec[i]]++, i++)
        ;
    vector<int> sortedArr;
    int i = 0;
    while (n > 0)
    {
        // 从小到大顺序取出元素
        if (count[i] == 0)
        {
            i++;
        }
        // Here we are inserting the element into the
        // sortedArr decrementing count[element] and n by 1
        else
        {
            sortedArr.push_back(i);
            count[i]--;
            --n;
        }
    }
    return sortedArr;
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

    std::cout << "\n输入容器值, 数量为: " << size << "" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    // 排序
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    countSort(array, 0, size - 1);
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
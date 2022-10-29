/******************************************************************************
 * 最坏时间复杂度   O(n)
 * 最好时间复杂度   O(1)
 * 平均时间复杂度   O(n)
 * 最坏空间复杂度   O(1)/O(n), 用于使用递归堆栈空间
 ******************************************************************************/
#include <iostream>
using namespace std;

/// @brief 线性搜索
/// @param array
/// @param size
/// @param key
/// @return
int linearSearch(const int *array, int size, int key)
{
    for (int i = 0; i < size; ++i) // 遍历容器的所有数据
    {
        if (array[i] == key) // 将容器中元素按顺序与 key 值比较
        {
            return i; // 返回 key 值所在位置索引
        }
    }
    return -1; // key 与任何元素都不匹配
}

/// @brief 线性搜索
/// @param array
/// @param size
/// @param key
/// @return
int rec_linearSearch(const int *array, int size, int key)
{

    // - 从 array[] 最右边的元素开始, 即 [size - 1] 索引位置
    // - 先判断是否递归结束
    // - 然后判断当前元素与 key 是否匹配, 如果 key 与元素匹配，则返回当前元素的索引位置。
    // - 继续比较下一个
    if (size == 0)
    {
        return -1; // 容器内没有元素了
    }
    else if (array[size - 1] == key)
    {
        return size - 1; // 找到匹配的值了
    }
    else
    {
        int ans = rec_linearSearch(array, size - 1, key);
        return ans;
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

    std::cout << "\n输入容器值, 数量为: " << size << " ." << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    std::cout << "\n输入要搜索的值: ";
    std::cin >> key;
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    int result = linearSearch(array, size, key);
    (result == -1)
        ? cout << "容器中不存在此值."
        : cout << "元素存在于索引 [" << result << "] 处.";
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    delete[] array; // 释放临时分配的内存空间
    return 0;
}

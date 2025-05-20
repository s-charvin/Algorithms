/**
 * Worst-case time complexity	O（√n）
 * Best-case time complexity	O(1)
 * Average time complexity	    O（√n）
 * Worst-case space complexity  O(1)
 **/

// 跳跃查找基本思想是通过按固定步跳过元素, 以减少遍历的的元素数目。
// 在最坏的情况下, 需要跳跃 n(容器大小)/m(跳跃步数)次，然后执行 m-1 次比较。总数为 （（n/m） + m-1）。因此当 m = √n 时，函数 （（n/m） + m-1） 的值最小。
// 跳跃查找查找的时间复杂度为O（√ n）, 介于线性查找（O（n）和二分查找（O（Log n））之间。

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/// @brief 跳跃查找 迭代实现
/// @param array
/// @param key
/// @param step
/// @return

uint64_t jumpSearch(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{

    uint64_t size = high + 1;              // 获取容器大小
    uint64_t step = std::sqrt(high - low); // 计算最佳跳跃步数, m = √n, 小浮点数会强制转换成整数
    uint64_t step_i = low + step;          // 记录跳跃到第 i 步的位置
    uint64_t prev = low;                   // 记录第 i-1 步的位置, 减少计算量
    // 通过将 key 值与 step_i 的值进行比较, 确认 key 值所在的区域(如果元素存在)
    // min(step_i, size)是为了防止 step_i 大小溢出
    while (array[std::min(step_i, size) - 1] < key) // 判断 key 值是否依旧大于 step_i 点值, 即在 step_i 点右侧
    {
        if (step_i >= size) // 已知 key 值一定在 step_i 右侧, 如果 step_i 位置超出或等于了容器大小
            return -1;      // 则表示没找到 key 值可能出现的区域
        prev = step_i;      // 保留当前 step_i 点位置
        step_i += step;     // step_i 向右跳跃 step 步
    }

    if (step_i > size)
        step_i = size;
    // 找到 key 值可能出现的区域(prev, step_i/size], 对其进行线性搜索, 进一步精确寻找 key 值是否存在.
    while (array[prev] < key)
    {
        prev++;
        if (prev == step_i)
            return -1; // 没找到 key 值, 且 key 值比此区域的所有值都大
    }
    //
    if (array[prev] == key)
        return prev;

    return -1; // 没找到 key 值, 且 key 值大小在此区域之间
}

int main()
{

    int64_t *ptemp = new int64_t;
    std::vector<int64_t> array;

    std::cout << "\n以空格为分隔输入容器值: ";
    do
    {
        std::cin >> *ptemp;
        array.push_back(*ptemp);
    } while (getchar() != '\n');

    delete ptemp; // 释放临时分配的内存空间

    int key = 0;
    std::cout << "\n输入要查找的值: ";
    std::cin >> key;
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    uint64_t low = 0;                 // 设置 vector 的初始最小索引.
    uint64_t high = array.size() - 1; // 设置 vector 的初始最大索引.
    int result = jumpSearch(array, low, high, key);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    return 0;
}
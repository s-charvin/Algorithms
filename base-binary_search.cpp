/**
 * Worst-case time complexity	O(log2 n)
 * Best-case time complexity	O(1)
 * Average time complexity	    O(log2 n)
 * Worst-case space complexity  0(1)/ O(log n)
 **/

#include <iostream>
#include <vector>
using namespace std;

// 最初以整个数组作为搜索区间, 从最中间位置元素开始,
// 如果此元素与 key 值匹配，则返回此元素的索引位置。
// 或者，如果 key 值小于此元素，将搜索区间缩小到下半部分。
// 否则，请将其缩小到上半部分。
// 以缩小后的搜索区间中间位置元素开始, 继续与 key 值匹配。

/// @brief 二分搜索 迭代实现
/// @param array
/// @param key
/// @return

uint64_t binarySearch(std::vector<int64_t> array, int64_t key)
{
    uint64_t low = 0;                 // 设置 vector 的初始最小索引.
    uint64_t high = array.size() - 1; // 设置 vector 的初始最大索引.

    while (low <= high && key >= array[low] && key <= array[high]) // 区间正确, 且 key 必须在区间内, 通过修改 [low high] 进行迭代
    {
        uint64_t mid = low + (high - low) / 2; // 设置二分点位置(搜索区间的中间位置)

        if (key == array[mid]) // 如果二分点位置与 key 值匹配, 则返回它
        {
            return mid;
        }

        else if (key < array[mid]) // 否则, 如果二分点位置值大于 key 值, 则缩小到下半部分区间[low, mid-1]
        {
            high = mid - 1;
        }
        else // 否则, 如果二分点位置值小于 key 值, 则缩小到上半部分区间 [mid-1, high]
        {
            low = mid + 1;
        }
    }
    return -1; // if val is not in the array, return -1.
}

/// @brief 二分搜索 迭代实现 每次都是最坏搜索
/// @param array
/// @param key
/// @return
uint64_t binarySearch2(std::vector<int64_t> array, int64_t key)
{
    uint64_t low = 0;                 // 设置 vector 的初始最小索引.
    uint64_t high = array.size() - 1; // 设置 vector 的初始最大索引.
    while (high - low > 1)
    {
        uint64_t mid = (high + low) / 2; // 设置二分点位置(搜索区间的中间位置)
        if (array[mid] < key)            // 将搜索区间逼近到结果域
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (array[low] == key)
    {
        return low;
    }
    else if (array[high] == key)
    {
        return high;
    }
    else
    {
        return -1;
    }
}

/// @brief 二分搜索 递归实现
/// @param array
/// @param key
/// @param low
/// @param high
/// @return

// 通过限定不同的搜索区间, 使用递归实现
uint64_t rec_binarySearch(std::vector<int64_t> array, int64_t key, uint64_t low, uint64_t high)
{

    if (low <= high && key >= array[low] && key <= array[high]) // 区间正确, 且 key 必须在区间内, 然后通过不同的 [low high] 进行递归
    {
        uint64_t mid = low + (high - low) / 2; // 设置二分点位置(搜索区间的中间位置)
        if (key == array[mid])                 // 如果二分点位置与 key 值匹配, 则返回它
        {
            return mid;
        }

        else if (key < array[mid]) // 否则, 如果二分点位置值大于 key 值, 则缩小到下半部分区间[low, mid-1]
        {
            return rec_binarySearch(array, key, low, mid - 1);
        }
        else // 否则, 如果二分点位置值小于 key 值, 则缩小到上半部分区间 [mid-1, high]
        {
            return rec_binarySearch(array, key, mid + 1, high);
        }
    }
    return -1;
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
    std::cout << "\n输入要搜索的值: ";
    std::cin >> key;
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    uint64_t low = 0;                 // 设置 vector 的初始最小索引.
    uint64_t high = array.size() - 1; // 设置 vector 的初始最大索引.
    int result = rec_binarySearch(array, key, low, high);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    return 0;
}
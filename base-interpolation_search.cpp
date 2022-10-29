/**
 * Worst-case time complexity	O(n) (指数分布)
 * Best-case time complexity
 * Average time complexity	    O(log2(log2 n))
 * Worst-case space complexity  O(1)
 **/

// 插值查找算法, 将二分查找算法中的二分点 mid 位置修改为由公式 Mid = low + ( (high - low) / (array[high] - array[low]) ) * (key - array[low]) 得到
// 当要搜索的元素更接近 array[high] 时，返回更高的pos值。当接近 array[low]时，pos值较小.
// 可知, 当容器中的元素呈现均匀分布时, 插值查找算法的查找效率要要优于二分查找算法.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

uint64_t linearInterpolationSearch(const std::vector<int64_t> &array,
                                   int64_t key)
{
    uint64_t size = array.size();
    uint64_t low = 0, high = (size - 1);
    // 区间正确, 且 key 必须在区间内, 通过修改 [low high] 区间进行迭代
    while (low <= high && key >= array[low] && key <= array[high])
    {
        if (low == high)
        {
            if (array[low] == key)
            {
                return low;
            }
            return -1;
        }
        // 考虑数据是均匀分布的情况下, 设置二分点位置(通过 key 值计算出合适的区间比例)
        uint64_t pos =
            low +
            (((double)(high - low) / (array[high] - array[low])) *
             (key - array[low]));

        if (array[pos] == key) // 如果二分点位置与 key 值匹配, 则返回它
        {
            return pos;
        }
        // 否则, 如果二分点位置值小于 key 值, 则缩小到上半部分区间 [pos + 1, high]
        if (array[pos] < key)
        {
            low = pos + 1;
        }
        // 否则, 如果二分点位置值大于 key 值, 则缩小到下半部分区间[low, pos - 1]
        else
        {
            high = pos - 1;
        }
    }
    return -1;
}

/// @brief 线性插值查找 递归实现
/// @param array
/// @param key
/// @param low
/// @param high
/// @return
uint64_t rec_linearInterpolationSearch(std::vector<int64_t> array, int64_t key, uint64_t low, uint64_t high)
{
    // 区间正确, 且 key 必须在区间内, 通过不同的 [low high] 进行递归
    if (low <= high && key >= array[low] && key <= array[high])
    {

        // 考虑数据是均匀分布的情况下, 设置二分点位置(通过 key 值计算出合适的区间比例)
        uint64_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (key - array[low]));

        if (array[pos] == key) // 如果二分点位置与 key 值匹配, 则返回它
        {
            return pos;
        }

        // 否则, 如果二分点位置值小于 key 值, 则缩小到上半部分区间 [pos + 1, high]
        else if (array[pos] < key)
        {
            return rec_linearInterpolationSearch(array, key, pos + 1, high);
        }

        // 否则, 如果二分点位置值大于 key 值, 则缩小到下半部分区间[low, pos - 1]
        else
        {
            return rec_linearInterpolationSearch(array, key, low, pos - 1);
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
    int result = rec_linearInterpolationSearch(array, key, low, high);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    return 0;
}
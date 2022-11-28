/**
 * Worst-case time complexity	O(log2 n)
 * Best-case time complexity	O(1)
 * Average time complexity	    O(log2 n)
 * Worst-case space complexity  O(1)/ O(log n)
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
/// @param array 被查找的容器
/// @param low 初始最小索引位置.
/// @param high 初始最大索引位置.
/// @param key 被查找的值
/// @return

uint64_t binarySearch(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{

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

/// @brief 二分搜索 迭代实现 每次都是最坏搜索, 但是减小了比较次数
/// @param array 被查找的容器
/// @param low 初始最小索引位置.
/// @param high 初始最大索引位置.
/// @param key 被查找的值
/// @return
uint64_t binarySearch2(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    while (high - low > 1)
    {
        uint64_t mid = low + (high - low) / 2; // 设置二分点位置(搜索区间的中间位置)
        if (array[mid] < key)                  // key 值肯定在二分点右侧
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
/// @param array 被查找的容器
/// @param low 初始最小索引位置.
/// @param high 初始最大索引位置.
/// @param key 被查找的值
/// @return
// 通过限定不同的搜索区间, 使用递归实现
uint64_t rec_binarySearch(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
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

/// @brief 利用二分查找的思想, 寻找容器中最接近指定 key 值的下限值
/// @param array
/// @param low
/// @param high
/// @param key
/// @return
int64_t FloorSearch(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    uint64_t mid;

    while (high - low > 1) // 一步步缩紧区间
    {
        mid = low + (high - low) / 2;

        if (array[mid] <= key)
            low = mid;
        else
            high = mid;
    }

    return array[low]; // 返回最终区间范围的最小值
}

/// @brief 利用二分查找的思想, 寻找重复元素的最右值位置
/// @param array
/// @param low
/// @param high
/// @param key
/// @return
uint64_t GetRightPosition(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    uint64_t mid;

    while (high - low > 1)
    {
        mid = low + (high - low) / 2;

        if (array[mid] <= key)
            low = mid;
        else
            high = mid;
    }

    return low;
}

/// @brief 利用二分查找的思想, 寻找重复元素的最左值位置
/// @param array
/// @param low
/// @param high
/// @param key
/// @return
uint64_t GetLeftPosition(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    uint64_t mid;

    while (high - low > 1)
    {
        mid = low + (high - low) / 2;

        if (array[mid] >= key)
            high = mid;
        else
            low = mid;
    }

    return high;
}

/// @brief 利用二分查找的思想, 寻找重复值所在位置区间
/// @param array
/// @param size
/// @param key
/// @return
int64_t CountOccurances(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    uint64_t left = GetLeftPosition(array, -1, high, key);
    uint64_t right = GetRightPosition(array, 0, high + 1, key);
    return (array[left] == key && key == array[right]) ? (right - left + 1) : 0;
}

/// @brief 利用二分查找的思想, 在一个经过排序后, 并在某一未知位置又做了次旋转的数组中, 查找其最小元素。
/// @param array
/// @param low
/// @param high
/// @return
uint64_t BinarySearchIndexOfMinimumRotatedArray(std::vector<int64_t> array, uint64_t low, uint64_t high)
{
    uint64_t mid;

    // 当 array[low] <= array[high]时, 最小值在最左侧
    if (array[low] <= array[high])
        return low;

    while (low <= high) // 区间中较小值在右侧
    {
        // Termination condition (low will eventually falls on high, and high always point minimum possible value)
        // 终止条件（低最终将变为高，高始终为最小可能值）
        if (low == high)
            return low;

        mid = low + (high - low) / 2; // 'mid' 可能落在旋转后的两个上升区间或两者中间.

        if (array[mid] < array[high])
            // 如果 mid 小于 high, 说明 mid 刚好在右侧较小值区间内, 则 min 在 mid 左侧(或相等).
            high = mid;
        else
            // 如果 mid 大于等于 high, 说明 mid 刚好在左侧较大值区间内, 则 min 一定在 mid 右侧.
            low = mid + 1;
    }

    return -1;
}

/// @brief 二分查找, 查找递增函数的指定值的位置或右侧位置(值不存在)
/// @param func
/// @param low
/// @param high
/// @param key
/// @return
uint64_t binarySearch(int64_t (*func)(int64_t), uint64_t low, uint64_t high, int64_t key)
{
    if (high >= low)
    {
        uint64_t mid = low + (high - low) / 2; /* mid = (low + high)/2 */

        if (func(mid) > key && (mid == low || func(mid - 1) <= key))
            return mid; // 判断当前 f(mid) 值是否大于指定的 key 值, 且 f(mid-1)也小于 key 值

        // 如果 f(mid) 值小于等于 key 值, 说明 key 值可能在右侧区间[(mid + 1), high]
        if (func(mid) <= key)
            return binarySearch(func, (mid + 1), high, key);
        else // 如果 f(mid) 值大于 key 值, 说明 key 值可能在右侧区间[(mid + 1), high]
            return binarySearch(func, low, (mid - 1), key);
    }

    /* Return -1 if there is no
    positive value in given range */
    return -1;
}

/// @brief 查找无界递增函数的指定值的位置或右侧位置(值不存在时)
/// @param func
/// @param key
/// @return
int findFirstValue(int64_t (*func)(int64_t), int64_t key)
{
    // 验证输入为 0 的值
    if (func(0) > key)
        return 0;

    // 指数查找法, 寻找递增函数中零点所在区间范围
    int i = 1;
    while (func(i) <= key)
        i = i * 2;
    return binarySearch(func, i / 2, i, key);
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
    int result = rec_binarySearch(array, low, high, key);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

    return 0;
}
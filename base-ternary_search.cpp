/**
 * Worst-case time complexity	O(log3 n)
 * Best-case time complexity	O(1)
 * Average time complexity	    O(log3 n)
 * Worst-case space complexity  O(1)/O(log3 n)
 **/

#include <iostream>
#include <vector>
using namespace std;

// 首先，我们将 key 值与 第一个三分点中的元素进行比较。如果找到相等，我们将返回 mid1。
// 如果不是，则我们将键与 mid2 处的元素进行比较。如果发现相等，我们将返回 mid2。
// 如果不是，那么我们检查键是否小于mid1处的元素。如果是，则重复到第一部分。
// 如果不是，那么我们检查键是否大于mid2处的元素。如果是，则重复到第三部分。
// 如果没有，那么我们回到第二个（中间）部分。

/// @brief 三分查找 递归实现
/// @param array
/// @param key
/// @param low
/// @param high
/// @return

uint64_t ternarySearch(std::vector<int64_t> array, int64_t key, uint64_t low, uint64_t high)

{

    while (low <= high && key >= array[low] && key <= array[high]) // 区间正确, 且 key 必须在区间内, 通过修改 [low high] 进行迭代
    {

        // Find the mid1 and mid2
        uint64_t mid1 = low + (high - low) / 3;  // 三分的左点
        uint64_t mid2 = high - (high - low) / 3; // 三分的右点

        // 如果任一三分点位置与 key 值匹配, 则返回它
        if (array[mid1] == key)
        {
            return mid1;
        }
        if (array[mid2] == key)
        {
            return mid2;
        }

        if (key < array[mid1]) // 如果 key 值小于左分点, 则缩小到最左侧区间[low, high =mid1-1]
        {

            high = mid1 - 1;
        }
        else if (key > array[mid2]) // 如果 key 值大于右分点, 则缩小到最右侧区间[low = mid2 + 1, high]
        {

            low = mid2 + 1;
        }
        else // 如果 key 值在左右分点之间, 则缩小到中间区间[low = mid1 + 1, high = mid2 - 1]
        {

            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

uint64_t rec_ternarySearch(std::vector<int64_t> array, int64_t key, uint64_t low, uint64_t high)
{
    if (low <= high && key >= array[low] && key <= array[high]) // 区间正确, 且 key 必须在区间内, , 通过不同的 [low high] 进行递归
    {

        uint64_t mid1 = low + (high - low) / 3;  // 三分的左点
        uint64_t mid2 = high - (high - low) / 3; // 三分的右点

        // 如果任一三分点位置与 key 值匹配, 则返回它
        if (array[mid1] == key)
        {
            return mid1;
        }
        if (array[mid2] == key)
        {
            return mid2;
        }

        if (key < array[mid1]) // 如果 key 值小于左分点, 则缩小到最左侧区间[low, mid1-1]
        {

            // The key lies in between l and mid1
            return rec_ternarySearch(array, key, low, mid1 - 1);
        }
        else if (key > array[mid2]) // 如果 key 值大于右分点, 则缩小到最右侧区间[mid2 + 1, high]
        {

            // The key lies in between mid2 and r
            return rec_ternarySearch(array, key, mid2 + 1, high);
        }
        else // 如果 key 值在左右分点之间, 则缩小到中间区间[mid1 + 1, mid2 - 1]
        {

            // The key lies in between mid1 and mid2
            return rec_ternarySearch(array, key, mid1 + 1, mid2 - 1);
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
    int result = rec_ternarySearch(array, key, low, high);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    return 0;
}
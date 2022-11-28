/**
 * Worst-case time complexity	O(log i)
 * Best-case time complexity    O(1)
 * Average time complexity
 * Worst-case space complexity  O(1)
 **/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 指数查找算法, 对于数组大小无限的无限搜索特别有用。对于有界数组，它比二分查找算法效果更好，并且当要搜索的元素接近第一个元素时更是如此。
uint64_t rec_binarySearch(std::vector<int64_t>, uint64_t, uint64_t, int64_t);
uint64_t binarySearch(std::vector<int64_t>, uint64_t, uint64_t, int64_t);

uint64_t exponentialSearch(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    if (array[low] == key)
        return 0;
    uint64_t i = 1;
    while (i <= high && array[i] <= key) // 通过指数级位置2^{i}, 确定元素所在范围[2^{j-1}=i/2，2^j=i]
        i = i * 2;
    return binarySearch(array, i / 2, std::min(i, high), key); // 在元素所在范围内执行二分查找算法。
}

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
    cout << "测试越界索引值: " << array[array.size()];
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    uint64_t low = 0;                 // 设置 vector 的初始最小索引.
    uint64_t high = array.size() - 1; // 设置 vector 的初始最大索引.
    int result = exponentialSearch(array, low, high, key);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    return 0;
}
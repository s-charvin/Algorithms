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

uint64_t binarySearch1D(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
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
uint64_t binarySearch1D2(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
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
uint64_t rec_binarySearch1D(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
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
            return rec_binarySearch1D(array, key, low, mid - 1);
        }
        else // 否则, 如果二分点位置值小于 key 值, 则缩小到上半部分区间 [mid-1, high]
        {
            return rec_binarySearch1D(array, key, mid + 1, high);
        }
    }
    return -1;
}

/// @brief 利用二分查找的思想, 寻找第一个*等于*目标值的元素
/// @param array
/// @param low
/// @param high
/// @param key
/// @return
uint64_t GetLeftFirstPosition1D(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{

    if (low <= high && key <= array[high])
    {
        uint64_t mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (array[mid] > key)
                high = mid - 1; /* 选择左侧小于等于 key 的区域 */
            else if (array[mid] < key)
                low = mid + 1; /* 选择右侧大于等于 key 的区域, 直至到最后一个元素 */

            else /* 如果中值刚好等于 key */
            {
                /** 如果中值等于 key, 且是第一个元素
                 * 或 mid 左侧的数不为目标数时返回其位置
                 */
                if ((mid == 0) || (array[mid - 1] != key))
                    return mid;
                /* 否则选择左侧小于等于 key 的区间 */
                high = mid - 1;
            }
        }
    }
    /* 当找不到值时, 即 high<0 或 low >= array.size() 或 high<low 时, 返回 -1 */
    return -1;
}

/// @brief 利用二分查找的思想, 寻找最后一个等于目标值的元素
/// @param array
/// @param low
/// @param high
/// @param key
/// @return
uint64_t GetRightLastPosition1D(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{

    if (low <= high && key <= array[high])
    {
        uint64_t mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (array[mid] > key)
                high = mid - 1; /* 选择左侧小于等于 key 的区域 */
            else if (array[mid] < key)
                low = mid + 1; /* 选择右侧大于等于 key 的区域 */
            else
            {
                /* 如果中值等于 key, 且是最后一个元素
                    或 mid 右侧的数不为目标数时返回其位置
                  */
                if ((mid == array.size() - 1) || (array[mid + 1] != key))
                    return mid;
                /* 否则选择右侧大于等于 key 的区间 */
                low = mid + 1;
            }
        }
    }
    /* 当找不到值时, 即 high<0 或 low >= array.size() 或 high<low 时, 返回 -1 */
    return -1;
}

/// @brief 利用二分查找的思想, 寻找第一个*大于等于*目标值的元素
/// @param array
/// @param low
/// @param high
/// @param key
/// @return

int64_t GetCeilPosition1D(std::vector<int64_t> array, int64_t low, int64_t high, int64_t key)
{
    /* 解决输入区域和数值是否存在问题 */
    if (low <= high && key <= array[high])
    {
        int64_t mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2;
            /* 找的值大于等于 key */
            if (array[mid] >= key) /* 中间值大于等于 key */
            {
                /** 如果中值等于 key, 且是第一个元素
                 * 或 mid 左侧的数不为目标数时返回其位置
                 */
                if ((mid == 0) || (array[mid - 1] < key))
                    return mid;
                high = mid - 1; /* 选取左侧区域*/
            }
            else /* 中间值小于 key */
            {
                low = mid + 1; /* 选取右侧区域*/
            }
        }
    }
    /* 当找不到值时, 即 high<0 或 low >= array.size() 或 high<low 时, 返回 -1 */
    return -1;
}

/// @brief 利用二分查找的思想, 寻找最后一个*小于等于*目标值的元素
/// @param array
/// @param low
/// @param high
/// @param key
/// @return
int64_t GetFloorPosition1D(std::vector<int64_t> array, int64_t low, int64_t high, int64_t key)
{
    if (low <= high)
    {
        int64_t mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2; /* 记录区间中间点 */
            if (array[mid] <= key)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (high >= 0 && array[high] <= key)
            return high; /* 正确返回时, low 一定是指向第一个*大于等于*目标值的元素 */
    }
    /* 当找不到值时, 即 high<0 或 low >= array.size() 或 high<low 时, 返回 -1 */
    return -1;
}

/// @brief 利用二分查找的思想, 寻找重复值所在位置区间
/// @param array
/// @param size
/// @param key
/// @return
int64_t CountOccurances1D(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    uint64_t left = GetLeftFirstPosition1D(array, low, high, key);
    uint64_t right = GetRightLastPosition1D(array, left < 0 ? 0 : left, high, key);

    return (array[left] == key && key == array[right]) ? (right - left + 1) : 0;
}

/// @brief 利用二分查找的思想, 寻找二位数组中指定列第一个*大于等于*目标值的元素
int64_t GetVericalCeilPosition2D(vector<vector<int>> &matrix, int64_t col, int64_t low, int64_t high, int64_t key)
{
    int64_t size = high - low + 1;

    if (low <= high)
    {
        int64_t mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2;
            if (matrix[mid][col] >= key) /* 中间值大于等于 key */
            {
                high = mid - 1; /* 选取左侧区域*/
            }
            else /* 中间值小于 key */
            {
                low = mid + 1; /* 选取右侧区域*/
            }
        }
        if (low <= size && matrix[low][col] >= key)
            return low; /* 正确返回时, low 一定是指向第一个*大于等于*目标值的元素 */
    }
    /* 当找不到值时, 即  high<low 时, 返回 -1 */
    return -1;
}

/// @brief 利用二分查找的思想, 寻找二维数组中指定列后一个*小于等于*目标值的元素
int64_t GetVericalFloorPosition2D(vector<vector<int>> &matrix, int64_t col, int64_t low, int64_t high, int64_t key)
{
    int64_t size = high - low + 1;

    if (low <= high)
    {
        int64_t mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2;
            if (matrix[mid][col] <= key) /* 中间值小于等于 key */
            {
                low = mid + 1; /* 选取右侧区域*/
            }
            else /* 中间值小于 key */
            {
                high = mid - 1; /* 选取左侧区域*/
            }
        }
        if (high >= 0 && matrix[high][col] <= key)
            return high; /* 正确返回时, low 一定是指向第一个*小于等于*目标值的元素 */
    }
    /* 当找不到值时, 即  high<low 时, 返回 -1 */
    return -1;
}

/// @brief 利用二分查找的思想, 寻找二维数组中指定行后一个*小于等于*目标值的元素
int64_t GetHorizonCeilPosition2D(vector<vector<int>> &matrix, int64_t row, int64_t low, int64_t high, int64_t key)
{

    int64_t size = high - low + 1;

    if (low <= high)
    {
        int64_t mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2;
            if (matrix[row][mid] >= key) /* 中间值大于等于 key */
            {
                high = mid - 1; /* 选取左侧区域*/
            }
            else /* 中间值小于 key */
            {
                low = mid + 1; /* 选取右侧区域*/
            }
        }
        if (low <= size && matrix[row][mid] >= key)
            return low; /* 正确返回时, low 一定是指向第一个*大于等于*目标值的元素 */
    }
    /* 当找不到值时, 即  high<low 时, 返回 -1 */
    return -1;
}

/// @brief 利用二分查找的思想, 寻找二维数组中指定行最后一个*小于等于*目标值的元素
int64_t GetHorizonFloorPosition2D(vector<vector<int>> &matrix, int64_t row, int64_t low, int64_t high, int64_t key)
{
    int64_t size = high - low + 1;

    if (low <= high)
    {
        int64_t mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2;
            if (matrix[row][mid] <= key) /* 中间值小于等于 key */
            {
                low = mid + 1; /* 选取右侧区域*/
            }
            else /* 中间值小于 key */
            {
                high = mid - 1; /* 选取左侧区域*/
            }
        }
        if (high >= 0 && matrix[row][mid] <= key)
            return high; /* 正确返回时, low 一定是指向第一个*小于等于*目标值的元素 */
    }
    /* 当找不到值时, 即  high<low 时, 返回 -1 */
    return -1;
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
    vector<int64_t> nums = {1, 3, 5, 7, 9, 10, 10, 10, 17, 17, 17, 20, 30, 50, 60, 70};

    cout << "Test: [";
    for (auto num : nums)
        cout << num << " ";
    cout << "]" << endl
         << "Need: -5   "
         << "But: " << GetFloorPosition1D(nums, 0, nums.size() - 1, -5) << endl;

    cout << "Test: [";
    for (auto num : nums)
        cout << num << " ";
    cout << "]" << endl
         << "Need: 1   "
         << "But: " << GetFloorPosition1D(nums, 0, nums.size() - 1, 1) << endl;

    cout << "Test: [";
    for (auto num : nums)
        cout << num << " ";
    cout << "]" << endl
         << "Need: 16   "
         << "But: " << GetFloorPosition1D(nums, 0, nums.size() - 1, 16) << endl;

    vector<int64_t> nums2 = {1};
    cout << "Test: [";
    for (auto num : nums2)
        cout << num << " ";
    cout << "]" << endl
         << "Need: 1   "
         << "But: " << GetFloorPosition1D(nums2, 0, nums2.size() - 1, 1) << endl;

    vector<int64_t> nums3 = {1, 1, 1, 1, 1};
    cout << "Test: [";
    for (auto num : nums3)
        cout << num << " ";
    cout << "]" << endl
         << "Need: 1   "
         << "But: " << GetFloorPosition1D(nums3, 0, nums3.size() - 1, 1) << endl;
    cout << "Test: [";
    for (auto num : nums3)
        cout << num << " ";
    cout << "]" << endl
         << "Need: 2   "
         << "But: " << GetFloorPosition1D(nums3, 0, nums3.size() - 1, 1) << endl;
    vector<int64_t> nums4 = {};
    cout << "Test: [";
    for (auto num : nums4)
        cout << num << " ";
    cout << "]" << endl
         << "Need: 1   "
         << "But: " << GetFloorPosition1D(nums4, 0, nums4.size() - 1, 1) << endl;

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
    int result = GetFloorPosition1D(array, low, high, key);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n 元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

    return 0;
}
/**
 * Worst-case time complexity	 O(log3(n))
 * Best-case time complexity	O(1)
 * Average time complexity	     O(log3(n))
 * Worst-case space complexity   O(1)
 **/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 斐波那契数列具有和黄金分割类似的性质, 其内部从第3项开始，每一项都是前两项的之和. F(n)=F(n-1)+F(n-2)
// 斐波那契查找就是在二分查找的基础上根据斐波那契数列进行分割区域.
// 二分搜索使用除法运算符来划分范围。斐波那契搜索不使用 /，而是使用 + 和 -。在某些 CPU 上，除法运算符的成本可能很高。
// 斐波那契搜索在后续步骤中检查相对接近的元素。因此，当输入数组很大，无法容纳在 CPU 缓存甚至 RAM 中时，斐波那契搜索可能很有用。
// 1. 在斐波那契数列找一个等于或略大于容器中元素个数的斐波那契数值 (F >= size)。
// 2. 将原容器, 通过重复最大值的方式, 填充 size 到长度为 F。
// 3. 完成后进行斐波那契分割, 即所有 F[n] 个元素分割为前 F[n-1] 个元素，后 F[n-2] 个元素。分割点公式为 mid = low + F(n-1) — 1.
// 4. 判断 mid 值和 key 值的关系，确定更新策略, 最终直至 fibM 变为 1, fibMm2 变为 0。
// 5. 时间复杂度分析:

/// @brief
/// @param array
/// @param key
/// @param size
/// @return
int fibMonaccianSearch(std::vector<int64_t> array, uint64_t low, uint64_t high, int64_t key)
{
    // 初始化斐波那契数列
    uint64_t fibMMm2 = 0;              // 第 (m-2) 个 斐波那契数值.
    uint64_t fibMMm1 = 1;              // 第 (m-1) 个 斐波那契数值.
    uint64_t fibM = fibMMm2 + fibMMm1; // 第   m   个 斐波那契数值, m >= 3.
    uint64_t size = high - low + 1;

    while (fibM < size) // 得到适合的三个斐波那契数值, 其中 fibM 限制为大于或等于 size 的最小斐波那契数值.
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    uint64_t offset = -1;

    /* while there are elements to be inspected.
    Note that we compare array[fibMm2] with key.
    而存在待检查的元件。请注意，我们将数组[fibMm2]与键进行比较。*/

    while (fibM > 1) // 循环直至 fibM 变为 1, fibMm2 变为 0
    {
        // fibM > 1, fibMMm2 > 0
        // 循环最初, offset = -1, 用来修正位置到 [0, fibMMm2-1]
        uint64_t mid = std::min(offset + fibMMm2, size - 1); // 选取 mid 位置为 fibMm2 所涵盖范围的最后一个元素.

        // 通过 mid 将原 [0 , fibM + offset] 的范围分割为 [0, fibMMm2 + offset] 和 [fibMMm2,  fibMMm2 + fibMMm1 + offset] 两个范围
        // 如果 key 值大于 fibMm2 范围的最后一个元素值, 表示其可能在 [fibMMm2,  fibMMm2+fibMMm1] 范围之内
        if (array[mid] < key)
        {
            fibM = fibMMm1;           // [fibMMm2,  fibMMm2+fibMMm1] 范围内只有 fibMMm1 个值了
            fibMMm1 = fibMMm2;        // 前一个 fibMMm2 变成当前的 fibMMm1
            fibMMm2 = fibM - fibMMm1; // 计算当前的 fibMMm2
            offset = mid;             // 更新 offset 以适应最新的计算区域起始点
        }

        // 如果 key 值小于 fibMm2 范围的最后一个元素值, , 表示其可能在 [0, fibMMm2 + offset] 范围之内
        else if (array[mid] > key)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            //最新的计算区域起始点不变, 因此 offset 也不变
        }
        else
            return mid;
    }

    // 如果 key 刚好不在所有 mid 点上, 则最终会把计算区域压缩到 fibM = 1,  fibMMm2 = 0.
    // 此时 key 值一定在 fibMMm1 区域内, 也就是 offset + 1 位置.
    if (fibMMm1 && array[offset + 1] == key)
        return offset + 1;

    return -1; // 没有找到值
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
    int result = fibMonaccianSearch(array, low, high, key);
    (result == -1)
        ? cout << "\n容器中不存在此值."
        : cout << "\n元素存在于索引 [" << result << "] 处." << std::endl;
    // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
    return 0;
}
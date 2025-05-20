/**
 * Worst-case time complexity	O(N2)  [始终选择最大或最小的元素为分界点]
 * Best-case time complexity	O(NLogN) [始终选择中间元素为分界点]
 * Average time complexity	    O()
 * Worst-case space complexity  O()
 **/

#include <iostream>
#include <vector>
using namespace std;

// 快速排序
// 快速排序是分而治之算法
// 默认实现不是稳定算法。
// 快速排序是就地算法
// 具体原理是通过选取其中的一个元素作为分界点, 然后将其余元素按照大小分区

/**
 * @brief 给定两个元素的地址, 交换两个地址的值
 *
 * @param a
 * @param b
 */
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief 此函数将最后一个元素作为分区比较点, 并将所有比此元素小的放在其左侧, 所有比此元素大的放在其右侧
 *
 * @param array 输入数组
 * @param ind_begin 需要分区的数组索引起始位置
 * @param ind_end 结束位置
 * @return int 返回此区域最后一个元素所在的正确位置索引
 */
int64_t partition_lomuto(int *array, int64_t ind_begin, int64_t ind_end)
{
    int pivot = array[ind_end]; // 保存最后位置的元素值
    int64_t i = ind_begin;
    // 初始化一个索引位置, 用来指向选定值应该在的正确位置
    // 可以很容易看出, 这个位置是从数组分区的最左侧开始的,
    // 也就是说, 预先假设所有值都比选定值大
    for (int j = ind_begin; j <= ind_end - 1; j++)
    { // 遍历区域内的所有数据(不包括最后一个元素)
        // 如果存在元素比选定值小
        if (array[j] < pivot)
        {
            swap(&array[i], &array[j]); // 将此元素与选定值应该在的位置的原有元素进行交换
            i++;                        // 选定值应该在的位置右移
        }
    }
    swap(&array[i], &array[ind_end]); // 将选定值与其应该在的位置的原有元素进行交换
    return i;
}

void quickSort_lomuto(int *array, int64_t ind_begin, int64_t ind_end)
{
    if (ind_begin < ind_end) // 用于终止递归(当pi - 1 或 pi + 1 超出边界时)
    {
        // 首先对输入数组, 按照选定的最后一个元素, 进行分区
        // 这里的分区是将数据分成两个区域, 一个只有小于分界值的元素,
        // 一个只有大于等于分界值的元素.
        int64_t pi = partition_lomuto(array, ind_begin, ind_end);
        // 根据上面得到的选定值的所在位置, 分别对区前和区后的元素再次进行分区排序
        // 这里因为分界值的位置是确定已经排序好的, 因此无需再次输入
        quickSort_lomuto(array, ind_begin, pi - 1); // 输入左区域, 不包含分区点
        quickSort_lomuto(array, pi + 1, ind_end);   // 输入右区域, 不包含分区点
    }
}

/**
 * @brief 快速排序的一个迭代版本
 *
 * @param array
 * @param ind_begin
 * @param ind_end
 */
void quickSortIterative(int *array, int64_t ind_begin, int64_t ind_end)
{
    // Create an auxiliary stack
    int stack[ind_end - ind_begin + 1];

    // initialize top of stack
    int64_t top = -1;

    // push initial values of ind_begin and ind_end to stack
    stack[++top] = ind_begin;
    stack[++top] = ind_end;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop ind_end and ind_begin
        ind_end = stack[top--];
        ind_begin = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition_lomuto(array, ind_begin, ind_end);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > ind_begin)
        {
            stack[++top] = ind_begin;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < ind_end)
        {
            stack[++top] = p + 1;
            stack[++top] = ind_end;
        }
    }
}

/**
 * @brief 此函数将第一个元素作为分区比较点,
 * 不同的是, 这里使用了左右两个索引来更高效的对数据分区,
 * 利用两个索引不断的将两侧大于等于(左)或小于等于(右)分界值的元素交换位置
 * 即最终在左索引点左侧只会保留小于等于分界值的元素,
 * 同时在右索引点右侧只会保留大于等于分界值的元素
 *
 * @param array 输入数组
 * @param ind_begin 需要分区的数组索引起始位置
 * @param ind_end 结束位置
 * @return int 返回右侧索引最终所在的位置
 */
int64_t partition_hoare(int *array, int64_t ind_begin, int64_t ind_end)
{
    int pivot = array[ind_begin]; // 保存第一个位置的元素值
    int64_t i = ind_begin - 1, j = ind_end + 1;
    // 初始化两个索引位置, 用来分别指向左区域的终点和右区域的起点
    // 可以很容易看出, 这两个位置是从输入数组分区的溢出点开始的
    while (true)
    {
        // 从左向右遍历寻找第一个大于等于分界值的元素位置
        while (array[++i] < pivot)
            ;
        // 从右向左遍历寻找第一个小于等于分界值的元素位置
        while (array[--j] > pivot)
            ;
        // 直至左右两个索引位置产生了交错, 此时分区结束, 返回右索引位置
        if (i >= j)
        {
            return j;
        }
        // 将两个呆错位置的元素交换位置到正确区域
        swap(array[i], array[j]);
        // 通过遍历会不断的将左侧大于等于分界值的元素与右侧小于等于分界值的元素交换位置
        // 直至 i 的左侧都是小于等于分界值的元素, j 的右侧都是大于等于分界值的元素
    }
}

void quickSort_hoare(int *array, int64_t ind_begin, int64_t ind_end)
{
    if (ind_begin < ind_end) // 用于终止递归(当pi - 1 或 pi + 1 超出边界时)
    {
        // 首先对输入数组, 按照选定的第一个元素, 进行分区
        // 这里的分区是将数据分成两个区域, 一个只有小于等于分界值的元素,
        // 一个只有大于等于分界值的元素.
        int64_t pi = partition_hoare(array, ind_begin, ind_end);
        // 根据上面得到的选定值的所在位置, 分别对区前和区后的元素再次进行分区排序
        quickSort_hoare(array, ind_begin, pi);   // 输入左区域, 不包含分区点
        quickSort_hoare(array, pi + 1, ind_end); // 输入右区域, 不包含分区点
    }
}

/**
 * @brief 此函数将最后一个元素作为分区比较点, 并利用与 hoare 算法相同的思想,
 * 利用两个索引对输入数组进行分区, 不同的是
 * 这里将输入数组分成三个区域, 最终的 j 左侧为小于分界值的元素,
 * i 的右侧为大于分界值的元素, j, i 之间为等于分界值的元素
 *
 * @param array
 * @param ind_begin 需要分区的数组索引起始位置
 * @param ind_end 结束位置
 * @return int 返回此区域最后一个元素所在的正确位置索引
 */
void partition_3way(int *array, int64_t ind_begin, int64_t ind_end, int64_t &i, int64_t &j)
{
    i = ind_begin - 1, j = ind_end;
    int64_t p = ind_begin - 1, q = ind_end;

    int pivot = array[ind_end]; // 保存最后一个位置的元素值为分界值

    while (true)
    {

        // 从左边向右找到第一个大于或等于分界值的元素所在位置, 保存在 i
        // 此循环肯定会终止，因为分界值初始化为最后一个元素
        while (array[++i] < pivot)
            ;
        // 从右向左找到第一个小于或等于分界值的元素, 直至到起始位置, 保存在 j
        while (pivot < array[--j])
            if (j == ind_begin)
                break;

        // 直至左右两个索引位置产生了交错, 此时分区结束
        if (i >= j)
            break;

        // 通过遍历会不断的将左侧大于等于分界值的元素与右侧小于等于分界值的元素交换位置
        // 直至 i 的左侧都是小于等于分界值的元素, j 的右侧都是大于等于分界值的元素
        swap(array[i], array[j]);

        // 将 i 左侧出现的所有与分界值相同的元素存放在数组开头, 数量由 p 记录
        if (array[i] == pivot)
        {
            p++;
            swap(array[p], array[i]);
        }

        // 将 j 右侧出现的所有与分界值相同的元素存放在数组开头, 数量由 q 记录
        if (array[j] == pivot)
        {
            q--;
            swap(array[j], array[q]);
        }
    }

    // 以上分区操作与 hoare 算法类似, 只是添加了将与分界值相等的元素放到指定位置的操作
    // 因此之后可以继续将与分界值相等的元素移动到其正确的索引区域, 即

    // 将最后一个元素与第 i 个元素交换位置, 以 i 位置作为分界区域(如果分界值有重复)的中心
    // 注意, 这里的最后一个元素一定是初始的分界值,
    // 而 i,j 索引位置产生了交错, 因此第 i 个元素是大于等于分界值的
    swap(array[i], array[ind_end]);

    // 将所有左边与分界值相等的元素移动到 array[i] 的相邻位置
    j = i; // 这里用 j 保存分界值区域的左起始点
    for (int k = ind_begin; k < p; k++)
    {
        j--;
        swap(array[k], array[j]);
    }

    // 将所有右边与分界值相等的元素移动到 array[i] 的相邻位置
    i = i; // 这里用 i 保存分界值区域的右终止点
    for (int k = ind_end - 1; k > q; k--)
    {
        i++;
        swap(array[i], array[k]);
    }
}

void quicksort_3way(int *array, int64_t ind_begin, int64_t ind_end)
{
    if (ind_end <= ind_begin)
        return;

    int64_t i, j;
    // 因为 C++ 默认函数返回值只能是一个值, 这里用传引用的方式
    partition_3way(array, ind_begin, ind_end, i, j);

    // Recur
    quicksort_3way(array, ind_begin, j - 1);
    quicksort_3way(array, i + 1, ind_end);
}

// https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
// https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/
// https://www.geeksforgeeks.org/quicksort-for-linked-list/
// https://www.geeksforgeeks.org/iterative-quick-sort/

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

    std::cout << "\n输入容器值, 分隔符为空格, 数量为: " << size << "" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    // 排序
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    quicksort_3way(array, 0, size - 1);
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
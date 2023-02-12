/**
 * Worst-case time complexity	O()
 * Best-case time complexity	O()
 * Average time complexity	    O(N log N)
 * Worst-case space complexity  O(1)
 **/

#include <iostream>
#include <vector>
using namespace std;

// 堆排序
// 堆排序算法不是稳定的算法
// 堆排序不是分而治之的算法

void heapify(int *array, uint64_t N, uint64_t i)
{
    // 将指定节点 i 及其子叶, 子叶节点 .... 构造成最大堆的形式

    // 初始化最大值为节点值
    int largest = i;

    // 计算左叶子在数组中的位置
    int l = 2 * i + 1;
    // 计算右叶子在数组中的位置
    int r = 2 * i + 2;

    // 如果左叶子有数据, 且其值大于当前节点值和右叶子值
    if (l < N && array[l] > array[largest])
        largest = l; // 设置最大值位置为左叶子位置
    // 如果右叶子有数据, 且其值大于当前节点值和左叶子值
    if (r < N && array[r] > array[largest])
        largest = r; // 设置最大值位置为右叶子位置

    // 如果最大值位置不是当前节点位置, 即当前节点值及其某个叶子值不符合最大堆结构
    if (largest != i)
    {
        // 将节点位置与最大值位置的数据进行交换
        swap(array[i], array[largest]);
        // 因为交换后当前节点的某个叶子值变小了, 为了防止此叶子的后续叶节点不再满足最大堆结构, 需要重新堆化被更改的子叶子后的最大堆

        heapify(array, N, largest); // 递归堆化值被改变的叶子及其后续数据(如果有)
    }
}

void heapSort(int *array, uint64_t ind_begin, uint64_t ind_end)
{
    // 初始先重新排列数组, 构造一个降序堆结构
    for (int64_t i = (ind_end - ind_begin + 1) / 2 - 1; i >= int64_t(ind_begin); i--)
        // 需要从下往上多次的原因是, 因为已经预先假设输入数组不是最大堆结构,
        // 然而这里的堆化递归操作, 每次堆化只能保证将当前节点值与其所有下层一级子叶值中的最大值放到节点位置.
        // 但是并不保证在更改了当前节点值后, 其所有上层父节点值(如果有)和当前节点值是否还满足最大堆结构.
        // 也就是未成功堆化的值大小是未知的, 可能存在比其父节点值更大的值
        // 而从下往上做堆化, 就能解决这一问题.(先做最下层子节点的堆化, 然后做其父节点的堆化, 层层递推)
        heapify(array, (ind_end - ind_begin + 1), i); // 从最后一个非叶节点开始, 从下往上构造最大堆

    // for (int64_t i = begin; i <= end; i++)
    // {
    //     cout << array[i] << " ";
    // }
    // cout << endl;
    // 从数组最后开始迭代
    for (int64_t i = ind_end; i > int64_t(ind_begin); i--)
    {
        swap(array[ind_begin], array[i]); // 一个个的将最大堆顶部的最大值放到合适的位置 i 处

        // 因为最顶部最大值被去掉了, 需要对剩余的未排序的堆重新进行堆化.
        // 只需要一次的原因是,当前数组除了更改的根部节点为小值外, 其余的都满足最大堆结构了,
        // 因此只需要自上而下的, 将这个最小值不断的与其子叶比较, 和局部最大值交换位置, 最终传递到合适的位置即可.
        heapify(array, i, ind_begin);
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

    std::cout << "\n输入容器值, 数量为: " << size << "" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    // 排序
    // // // // // // // // // // // // // // // // // // // // // // // // // // //
    heapSort(array, 0, size - 1);
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
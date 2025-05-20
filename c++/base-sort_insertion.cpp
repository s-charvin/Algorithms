/**
 * Worst-case time complexity	O(N2)
 * Best-case time complexity	O(N2)
 * Average time complexity	    O(N2)
 * Worst-case space complexity  O(1)
 **/

#include <iostream>
#include <vector>
using namespace std;

// 插入排序, 不断的将当前迭代元素与所有前置元素进行对比, 只要两者位置不匹配, 则前置元素右移.
// 插入排序是就地排序算法
// 插入排序是稳定排序算法

void insertionSort(int *array, uint64_t begin, uint64_t end)
{
    int i, key, j;
    for (i = begin; i < end + 1; i++) // 总共 end - begin + 1; 个元素, 最差的情况就是 end - begin + 1; 个元素全倒序
    {
        key = array[i]; // 记录当前位置的元素值
        j = i - 1;

        while (j >= begin && array[j] > key) // 将当前位置的元素值 与所有前置元素进行比较, 然后右移不匹配的前置元素

        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key; // 直到当前元素值找到其合适的位置
    }
}

// 定义简单的链表格式
struct Node
{
public:
    int val;
    struct Node *next;
    Node(int x) // 定义初始化新节点的函数
    {
        val = x;
        next = NULL;
    }
};

// 链表的插入排序
void insertionSort(Node *headref)
{
    Node *sorted = NULL; // 定义一个空链表, 用来保存排序好的链表

    Node *current = headref; // 首先从链表的头部节点开始

    while (current != NULL) // 遍历给定的链表, 直至最后一个节点
    {
        // 存储当前节点后面的链表方便进一步迭代
        Node *next = current->next;
        // 将当前节点值有序插入到 sorted 链表中
        sortedInsert(current, sorted); // 将当前节点值通过有序插入的方式, 放到 sorted 中
        current = next;                // 进入链表的下一个节点
    }
    // 更新输入链表为排序后的链表
    headref = sorted;
}

void sortedInsert(Node *newnode, Node *sorted)
{
    /* 对于头部的第一个节点, 或者比 sorted 链表所有节点值都要小的值, 只需将新节点放到 sorted 链表最前面即可*/
    if (sorted == NULL || sorted->val >= newnode->val)
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else // 如果 新节点的值比 sorted 链表的最小值大
    {
        Node *current = sorted;
        /* 遍历已经排序好的链表, 找到合适的插入位置(某个节点的值刚好小于新值, 就放在这个节点的 next 中)
        如果遍历完都没找到, 说明新值是最大值, 会放到最后面
         */
        while (current->next != NULL && current->next->val < newnode->val)
        {
            current = current->next;
        }
        newnode->next = current->next; // 将小于新值的节点后的链表赋值给新节点
        current->next = newnode;       // 将将小于新值的节点后的链表重置为包含新节点的链表
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
    insertionSort(array, 0, size - 1);
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
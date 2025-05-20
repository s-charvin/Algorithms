/**
 * @file spo-q22-链表中倒数第k个节点.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-19
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：链表中倒数第k个节点
 * - 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯,
 * 本题从 1 开始计数, 即链表的尾节点是倒数第 1 个节点.
 * 例如，一个链表有 6 个节点，从头节点开始, 它们的值依次
 * 是 1、2、3、4、5、6. 这个链表的倒数第 3 个节点是值为 4 的节点.
 * 链接:
 * - https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 * 考察:
 * - 双指针
 * 基本注意点
 * -
 * 高阶注意点
 * -
 */
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int _val)
    {
        val = _val;
        next = NULL;
    }
};

/**
 * 遍历链表, 通过双指针的其中一个记录当前指针往前数第 K 个节点的地址, 直到遍历到最后
 */

ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *prek = head, *cur = head;
    int i = 0;
    while (cur != NULL)
    {
        if (i < k)
        {
            cur = cur->next;
            i++;
            continue;
        }
        prek = prek->next;
        cur = cur->next;
    }
    if (i = k)
        return prek;
    return NULL;
}

/**
 * 回溯法()递归
 *
 */
ListNode *getKthFromEnd(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
}

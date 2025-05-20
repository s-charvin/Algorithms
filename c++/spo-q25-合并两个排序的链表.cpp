/**
 * @file spo-q25-合并两个排序的链表.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-19
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：合并两个排序的链表
 * - 输入两个递增排序的链表, 合并这两个链表并使新链表中的节点仍然是递增排序的.
 * 链接:
 * - https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
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
 * 使用两个指针分别指向两个链表中的值, 然后分别遍历两个链表
 * 一个个的将这两个指针中指向的最小的值放到新链表中.
 * 放入新链表时, 也需要一个指针, 指向最新位置
 *
 */

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)

{
    ListNode *node1 = l1, *node2 = l2;
    ListNode head(NULL), *cur = &head;
    while (node1 != NULL && node2 != NULL) /* 两个链表一起遍历, 直到其中一个被遍历完 */
    {
        if (node1->val < node2->val)
        {
            cur->next = node1;
            node1 = node1->next;
        }
        else
        {
            cur->next = node2;
            node2 = node2->next;
        }
        cur = cur->next;
    }
    cur->next = node1 != NULL ? node1 : node2; /* 当遍历完其中一个后, 处理剩余的另一条链表 */
    return head.next;
}

/**
 * 回溯法
 *
 */

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)

{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
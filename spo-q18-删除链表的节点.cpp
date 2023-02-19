/**
 * @file spo-q18-删除链表的节点.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-19
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：删除链表的节点
 * - 给定单向链表的头指针和一个要删除的节点的值, 定义一个函数删除该节点. 返回删除后的链表的头节点.
 * 链接:
 * - https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/
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

/**遍历
 * 寻找要删除的节点, 使用两个指针分别去记录此节点上一节点的地址和下一节点的地址
 */
ListNode *deleteNode(ListNode *head, int val)
{

    if (head->val == val && head->next == NULL)
        return NULL;
    if (head->val == val)
        return head->next;

    ListNode *pre = head, *next = head;

    while (next != NULL)
    {
        if (next->val == val)
        {
            pre->next = next->next;
            break;
        }
        pre = next;
        next = next->next;
    }
    return head;
}

ListNode *deleteNode(ListNode *head, int val)
{
    if (head->val == val)
        return head->next;
    ListNode *pre = head, *cur = head->next;
    while (cur != nullptr && cur->val != val)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur != nullptr)
        pre->next = cur->next;
    return head;
}

/**
 * 递归解法
 *
 */
ListNode *deleteNode(ListNode *head, int val)
{

    if (head == NULL)
    {
        return NULL;
    }
    if (head->val == val)
    {
        return head->next;
    }
    head->next = deleteNode(head->next, val);
    return head;
}
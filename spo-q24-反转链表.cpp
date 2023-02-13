/**
 * @file spo-q24-反转链表.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：
 * * 定义一个函数, 输入一个链表的头节点,
 * * 反转该链表并输出反转后链表的头节点。
 * 链接:
 * * https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=cuzoj2j
 * 考察:
 * * 栈(先进后出)
 * 基本注意点
 * *
 * 高阶注意点
 * *
 */

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

// 官方题解

/**
 * 题解思路:
 * 在遍历链表时, 将当前节点的 next 指针改为指向前一个节点。
 * 过程中必须必须事先存储当前节点的前一个节点和后一个节点。
 *
 *
 */

struct ListNode
{
    ListNode(int x) : val(x), next(NULL) {}
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;  //  保存当前节点指向的上一个节点
        ListNode *curr = head; //  保存当前迭代到的节点, 初始为头节点
        ListNode *next = NULL;

        while (curr)
        {
            // 下一节点的存储放在这里, 是因为要防止输入为空
            next = curr->next; //  保存当前节点指向的下一个节点
            next = curr->next; // 保存当前节点的下一个节点
            curr->next = pre;  // 将当前节点指向上一个节点
            pre = curr;        // 保存当前节点为下一个节点的上层节点
            curr = next;       // 进入下一个节点
        };
        return pre;
    }
};

// 官方题解
/**
 * 题解思路:
 * 想使用递归法求解, 需要找到几个终点
 * - 函数输入值 i
 * - 函数的递推公式: F(i) = F(i-1)+?
 * - 函数的终止条件 i?
 * 递推公式:
 * F(node)=F(node.next)+ (令 node.next 的 next 指向 node) && (node 的 next 指向null)
 */

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 终止条件为递归到了链表最底部或者本身输入就为空
        if (!head || !head->next)
        {
            return head;
        }
        // 函数递归调用
        ListNode *newHead = reverseList(head->next);

        // 单次函数处理数据
        head->next->next = head; // 将当前节点的下一节点的下一节点指向当前节点
        head->next = nullptr;    //将当前节点的下一节点指向为空
        return newHead;          // 返回原链表的最后一个非空节点
    }
};

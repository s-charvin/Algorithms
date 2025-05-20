/**
 * @file spo-q52-两个链表的第一个公共节点.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-20
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：两个链表的第一个公共节点
 * - 输入两个链表，找出它们的第一个公共节点
 *
 * 链接:
 * -
 * 考察:
 * -
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
 * 双指针哈希集存储法, 先把其中一个链表中出现的节点都存储起来
 * 然后遍历另一个链表, 判断已经出现过的第一个节点
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)

{

    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode *cur1 = headA, *cur2 = headB;
    set<ListNode *> state;

    while (cur1 != NULL)
    {
        state.insert(cur1);
        cur1 = cur1->next;
    };

    while (cur2 != NULL && state.find(cur2) == state.end())
    {
        cur2 = cur2->next;
    };
    return cur2;
}

/**
 * 双指针遍历等值法
 * 使用两个指针分别从两个链表头部开始遍历, 遍历完当前链表后, 继续遍历另一个链表.
 * 两个指针虽然起点不同, 但是想要达到第一个公共节点要走的步数是相同的
 * - 如果没有重合部分, 两指针会均指向链表最末端的 NULL
 * - 如果有重合部分, 两指针会指向第一个公共节点
 * 你变成我，走过我走过的路。
 * 我变成你，走过你走过的路。
 * 我们终会再次相遇于那一天
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *cur1 = headA, *cur2 = headB;
    while (cur1 != cur2)
    {
        cur1 = cur1 != NULL ? cur1->next : headB;
        cur2 = cur2 != NULL ? cur2->next : headA;
    }
    return cur1;
}

/**
 * 双指针遍历插值计算法
 * 使用两个指针分别从两个链表头部开始遍历, 遍历完当前链表后, 计算两个链表的长度差
 * 然后长的先走完多余的部分, 之后一起走, 直到走到第一个公共节点
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *cur1 = headA, *cur2 = headB;
    int len1 = 0, len2 = 0;
    while (cur1 != NULL)
    {
        len1++;
        cur1 = cur1->next;
    }
    while (cur2 != NULL)
    {
        len2++;
        cur2 = cur2->next;
    }

    int d = len1 - len2;
    cur1 = headA, cur2 = headB;

    if (d > 0)
    {
        while (d-- > 0)
            cur1 = cur1->next;
    }
    else if (d < 0)
    {
        d = -d;
        while (d-- > 0)
            cur2 = cur2->next;
    }
    while (cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    return cur1;
}

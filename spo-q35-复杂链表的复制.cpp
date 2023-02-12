/**
 * @file spo-q35-复杂链表的复制.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：复杂链表的复制
 * * 请实现 `copyRandomList` 函数，复制一个复杂链表。
 * * 在复杂链表中，每个节点除了有一个 `next` 指针指向下一个节点，
 * * 还有一个 `random` 指针指向链表中的任意节点或者 `null`。
 *
 * 链接: https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=cuzoj2j
 * 考察: 链表
 * 基本注意点
 * *
 *
 * 高阶注意点
 * *
 *
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// 官方题解
/**
 * 题解思路:
 * 这里链表复制明显是普通单向链表深拷贝的升级版本,( 深拷贝: 创建新内存空间, 并将数据拷贝过来 )
 * 复制一个单向链表, 可以按照顺序遍历的方式一个个创建新节点.
 *
 * 但是对于此例复杂链表, 因为有随机指针的存在, 当顺序复制新节点时,
 * 当前新节点的后继节点和随机节点均可能有两种状态, 1: 已经被创建, 2: 等待被创建
 *
 * 利用回溯的方式, 每个节点的拷贝操作相互独立. 即在复制完当前节点后, 直接创建后继节点和随机节点, 并保存其指针
 *
 */

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

unordered_map<Node *, Node *> cachedNode;

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (!cachedNode.count(head))
    {
        Node *headNew = new Node(head->val);
        cachedNode[head] = headNew;
        headNew->next = copyRandomList(head->next);
        headNew->random = copyRandomList(head->random);
    }
    return cachedNode[head];
}
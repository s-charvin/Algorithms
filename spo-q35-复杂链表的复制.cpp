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
 * 链接:
 * * https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=cuzoj2j
 * 考察:
 * * 链表
 * 基本注意点
 * *
 * 高阶注意点
 * *
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//     }
// };

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

/**
 * 题解思路:
 * 这里链表复制明显是普通单向链表深拷贝的升级版本,( 深拷贝: 创建新内存空间, 并将数据拷贝过来 )
 * 拷贝一个单向链表, 可以按照顺序遍历的方式一个个创建新节点, 然后修改指针指向即可
 *
 * 但是对于此例复杂链表, 因为有随机指针的存在, 当顺序拷贝新节点时,
 * 当前新节点的后继节点和随机节点均可能有三种状态, 1: 已经被拷贝, 2: 等待被拷贝, 3: 空
 * 考虑到上面这点, 我们需要通过一种方式去记录下, 有哪些节点已经被拷贝了,
 * 并且还要能轻松的查找到它的位置, 便于被其他节点重复链接.
 */

/**哈希表回溯法,
 * 将每个节点的拷贝操作看作是相互独立的, 与普通单向链表的深拷贝操作类似,
 * 利用哈希表的查询特点，考虑构建所有 原节点 和 新节点 地址的键值对映射关系.
 * 每次需要拷贝节点时, 都去判断哈希表中当前节点的拷贝状态,
 */

unordered_map<Node *, Node *> cachedNode; /* 构建哈希表, 存储节点的拷贝状态 */

Node *copyRandomList(Node *head)
{ /* 输入一个需要被拷贝的节点指针, 比如从链表头指针开始 */
    if (head == nullptr)
    {
        return nullptr; /* 处理空节点, 即空节点无需拷贝, 返回其本身即可 */
    }

    /* 判断当前节点是否被拷贝过, 即判断当前指针存储的地址是否是哈希表中一个 key */
    if (!cachedNode.count(head))
    {
        /* 未被拷贝过, 则直接创建新节点, 然后将当前节点值拷贝到新节点中 */
        Node *headNew = new Node(head->val);
        /* 记录当前节点的拷贝状态 */
        cachedNode[head] = headNew;

        /* 继续处理当前节点的后继节点和随机节点, 遇到没被拷贝的就新建节点, 被拷贝过的就从哈希表中获取记录 */
        headNew->next = copyRandomList(head->next);
        headNew->random = copyRandomList(head->random);
        /* 每次新建拷贝节点都将此节点的地址返回, 这样方便将当前拷贝节点与对应的上级节点的后继指针和随机指针建立引用 */
    }
    /* 返回哈希表中指向当前节点的拷贝节点的指针 */
    return cachedNode[head];
}

/**哈希表暴力解法,
 * 先迭代将所有节点都拷贝一份, 并通过哈希表记录 原节点 和 新节点 地址的键值对映射关系.
 * 然后迭代以原链表的连接关系, 建立所有拷贝节点之间的联系
 */

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == nullptr)
            return nullptr; /* 若头节点 head 为空节点，直接返回 null */

        Node *cur = head;                         /* 初始化当前节点 */
        unordered_map<Node *, Node *> cachedNode; /* 初始化哈希表 */

        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while (cur != nullptr)
        {
            cachedNode[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while (cur != nullptr)
        {
            cachedNode[cur]->next = cachedNode[cur->next];
            cachedNode[cur]->random = cachedNode[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return cachedNode[head];
    }
};

/**原地记录
 * Todo:
 * 具体实现:
 * ref: https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/fu-za-lian-biao-de-fu-zhi-by-leetcode-so-9ik5/
 */

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    // 1. 复制各节点，并构建拼接链表
    for (Node *node = head; node != nullptr; node = node->next->next)
    {
        Node *nodeNew = new Node(node->val);
        nodeNew->next = node->next;
        node->next = nodeNew;
    }
    // 2. 构建各新节点的 random 指向
    for (Node *node = head; node != nullptr; node = node->next->next)
    {
        Node *nodeNew = node->next;
        nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
    }
    // 3. 拆分两链表
    Node *headNew = head->next;
    for (Node *node = head; node != nullptr; node = node->next)
    {
        Node *nodeNew = node->next;
        node->next = node->next->next;
        nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
    }
    return headNew; // 返回新链表头节点
}

/**
 * @file spo-q28-对称的二叉树.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：对称的二叉树
 * - 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 * 链接:
 * - https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/** 递归(回溯)
 * 想要确认二叉树是否对称, 可以通过两个指针去遍历二叉树中所有的对称节点, 然后确认值是否一致即可
 * 想要依靠递归方法遍历对称节点, 需要依赖一个对称节点的特性: 两个对称节点的左右节点也刚好互相对称, 可以获得两个对称子节点
 * 即: 对于对称节点 (l_node, r_node), l_node 的左节点和 r_node 的右节点互相对称. 反之也是如此.
 */
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr) /* 处理空节点 */
        return true;
    /* 输出根节点的左右节点(对称的), 通过递归(回溯), 遍历所有对称节点, 判断二叉树是否是对称的 */
    return check(root->left, root->right);
}

bool check(TreeNode *l_node, TreeNode *r_node)
{
    /**
     * 如果对称节点 (l_node, r_node) 都指向了空节点, 说明当前遍历的对称分支已经遍历到了最底部,
     * 且两分支没有不对称的值, 可以返回 true 了
     */
    if (l_node == nullptr && r_node == nullptr)
        return true;
    /* 判断对称节点 (l_node, r_node) 的值是否相等, 不等代表一定不对称 */
    if (l_node == nullptr || r_node == nullptr || l_node->val != r_node->val)
        return false;

    /* 继续由当前的对称节点 (l_node, r_node) 进入下一层的两个对称节点, 判断值是否相等 */
    return check(l_node->left, r_node->right) && check(l_node->right, r_node->left);
}

/**迭代(遍历)
 * 想要确认二叉树是否对称, 需要遍历二叉树中所有的对称节点, 并且记住其对应位置, 方便判断对称节点的值是否相等
 * 又因为对称节点的特性: 两个对称节点的左右节点也刚好互相对称, 可以获得两个对称子节点
 * 即: 对于对称节点 (l_node, r_node), l_node 的左节点和 r_node 的右节点互相对称. 反之也是如此
 *
 * 因此可以将迭代获取到的对称节点, 一对对的放到队列中, 然后再一对对的判断两个值是否相等即可
 */

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;

    /* 初始化最初的对称节点和存储队列 */
    TreeNode *l_node{root->left}, *u_node{root->right};
    queue<TreeNode *> q;
    q.push(l_node);
    q.push(u_node);

    while (!q.empty())
    {
        /* 获取队列中的一对对称节点, 然后判断这俩节点值是否相同 */
        l_node = q.front();
        q.pop();
        u_node = q.front();
        q.pop();
        if ((l_node == nullptr || u_node == nullptr) || (l_node->val != u_node->val))
            return false;

        /* 对于对称的空节点来说, 就不用放进去了, 不然会无限循环 */
        if (l_node == nullptr && u_node == nullptr)
            continue;

        q.push(l_node->left);
        q.push(u_node->right);

        q.push(l_node->right);
        q.push(u_node->left);
    }
    return true;
}

/**
 *
 */
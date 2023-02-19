/**
 * @file spo-q27-二叉树的镜像.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：二叉树的镜像
 * - 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 * 链接:
 * - https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/
 * 考察:
 * - 二叉树
 * - 深度优先回溯(递归)
 * - 广度优先(遍历)
 * - 前序遍历
 * - 中序遍历
 * - 后续遍历
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
 * 想要获得一个二叉树的镜像, 把每个节点的子节点存放的指针交换即可
 *
 */
TreeNode *mirrorTree(TreeNode *root)
{
    if (root == nullptr) /* 终止条件为遍历到了二叉树分支的底部 */
        return nullptr;
    /* 交换当前节点的左右节点 */
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    /* 进入左右节点继续处理 */
    mirrorTree(root->right);
    mirrorTree(root->left);
    return root;
}

/** 遍历(迭代)
 * 想要获得一个二叉树的镜像, 把每个节点的子节点存放的指针交换即可
 * 辅助栈(队列)
 *
 */
TreeNode *mirrorTree(TreeNode *root)
{
    if (root == nullptr) /* 处理空节点 */
        return nullptr;
    /* 初始化队列, 放入根节点 */
    stack<TreeNode *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        TreeNode *node = stack.top();
        stack.pop();
        /* 每次都从队列中拿一个节点，并交换这个节点的左右子树 */
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;

        /* 将此节点的左右子节点放入队列中等待处理, 空节点就不用放进去了, 不然会无限循环 */
        if (node->left != nullptr)
            stack.push(node->left);
        if (node->right != nullptr)
            stack.push(node->right);
    }
    return root;
}

/**
 * @file spo-q26-树的子结构.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：树的子结构
 * - 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
 * - B 是 A 的子结构， 即 A中有出现和B相同的结构和节点值。
 * 链接:
 * - https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/
 * 考察:
 * - 二叉树
 * - 回溯(递归)
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

/** 想要判断 B 是否是 A 的子结构, 可以通过遍历 A 的所有节点,
 * 然后首先判断此节点是否是 B 的根节点, 如果是再判断其后续所有子节点是否与 B 的子节点相同即可.
 */

bool isSubStructure(TreeNode *A, TreeNode *B)
{
    /** 终止遍历的条件, 即遍历到最后都已经是空节点了, 还没遇到与 B 相同的子结构
     * 这里默认如果输入的为空节点, 则不是子结构
     */
    if (A == NULL || B == NULL)
        return false;
    /** 这里首先判断当前节点是否是 B 的根节点, 且后续结构也相同 sameSubStructure()
     * 判断失败后则继续进入左右子节点继续进行重复判断, 直至寻找到与 B 匹配的子结构
     */
    return sameSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

bool sameSubStructure(TreeNode *A_node, TreeNode *B_node)
{
    /** 这里如果 B 的节点为空，
     * 说明 B 的当前分支已经访问完了,
     * 且中途遇到的所有节点值与 A 中对应的的分支匹配 */
    if (B_node == NULL)
        return true;

    /** B 不是 A
     * 如果 B 的节点不为空, 但是 A 的节点为空了, 说明 B 不是 A 的子结构
     * 如两节点都不为空, 但是这两个节点值不同, 说明 B 不是 A 的子结构
     */
    if (A_node == NULL || A_node->val != B_node->val)
        return false;

    /* 当前节点比较完之后还要继续判断左右子节点, 只有当所有分支都相同时, 才回溯返回 true */
    return sameSubStructure(A_node->left, B_node->left) && sameSubStructure(A_node->right, B_node->right); //返回值：继续在对应位置递归判断
}

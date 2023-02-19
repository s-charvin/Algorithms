/**
 * @file spo-q32-从上到下打印二叉树II.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：从上到下打印二叉树 II
 * - 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
 * 链接:
 * - https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
 * 考察:
 * - 搜索与回溯算法
 *
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

/**队列先入先出
 * 从头节点开始遍历二叉树, 将所有节点从左到右的放入队列中
 * 因为队列先入先出的特性, 可以在遍历过程中每次向队列添加节点的同时,
 * 处理队列头部的节点, 将它的值按照顺序放入向量列表中
 */

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result; /* 定义变量保存最终结果 */

    if (root == NULL) /* 空值判定 */
        return result;

    queue<TreeNode *> q; /* 定义队列用于存储指向节点数据的指针 */
    q.push(root);

    while (!q.empty()) /* 遍历结束的条件是, 队列中存储的所有节点数据都被放到向量列表中 */
    {
        vector<int> tmp; /* 通过一个临时向量列表, 存储遇到的每一层的节点值 */
        TreeNode *node;
        int size = q.size();           /* 计算出当前层节点数量 */
        for (int i = 0; i < size; i++) /* 遍历当前层的所有节点 */
        {
            node = q.front();         /* 获取队列中最先进去的当前层的节点 */
            q.pop();                  /* 将最先进去的当前层的节点从队列中弹出 */
            tmp.push_back(node->val); /* 保存获取的节点的值到当前层的临时向量列表中 */

            /** 当节点的子节点不为空时, 将下一层的子节点以先左后右的顺序放入队列中等待读取
             * 注意: 因为 for 循环已经指定了当前层的节点数量, 因此在遍历完当前层的所有节点后
             * 就会停止当前层的遍历, 到那时队列中剩余的节点都是这里保存的下一层的节点
             */
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        /**
         * 如果左右子节点都为空, 则继续处理队列中剩余的节点
         */}
        result.push_back(tmp);
    }
    return result;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};

    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    bool rev = false;
    while (!q.empty())
    {
        int node_num = q.size();
        vector<int> cur_level(node_num);
        for (int i = 0; i < node_num; ++i)
        {
            auto cur = q.front();
            q.pop();
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
            cur_level[rev ? node_num - 1 - i : i] = cur->val;
        }
        rev = !rev;
        ans.push_back(cur_level);
    }
    return ans;
}

/**回溯法(递归法)
 *
 *
 */
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    dfs(root, result, 0);
    return result;
}
void dfs(TreeNode *root, vector<vector<int>> &result, int level)
{
    if (!root)
        return;
    if (level >= result.size())
        result.emplace_back(vector<int>()); /* 判断是否到下一层级了, 如果是则新建一个空向量列表来存储下一层节点的值 */
    result[level].emplace_back(root->val);
    dfs(root->left, result, level + 1);
    dfs(root->right, result, level + 1);
}

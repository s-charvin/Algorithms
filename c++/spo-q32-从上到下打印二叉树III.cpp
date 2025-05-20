/**
 * @file spo-q32-从上到下打印二叉树III.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：从上到下打印二叉树
 * - 请实现一个函数按照之字形顺序打印二叉树，
 * 即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
 * 第三行再按照从左到右的顺序打印，其他行以此类推。
 * 链接:
 * - https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 * 考察:
 * - 搜索与回溯算法
 * - 广度优先搜索（BFS）
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

/**
 * 通过双向列表, 每一层以不同的存放顺序存储节点, 间接实现目标
 */

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result; /* 定义变量保存最终结果 */

    if (root == NULL) /* 空值判定 */
        return result;

    /** 通过标志变量, 控制每一层的节点存放顺序
     * true: 从左向右存放
     * false: 从右向左存放
     * 初始为从左向右存放
     */
    bool flag = true;
    deque<TreeNode *> dq; /* 定义双向队列用于存储指向节点数据的指针 */
    dq.push_back(root);

    while (!dq.empty()) /* 遍历结束的条件是, 队列中存储的所有节点数据都被放到向量列表中 */
    {
        vector<int> tmp; /* 通过一个临时向量列表, 存储遇到的每一层的节点值 */
        TreeNode *node;
        int size = dq.size();          /* 计算出当前层节点数量 */
        for (int i = 0; i < size; i++) /* 遍历当前层的所有节点 */
        {
            if (flag) /* 前取后放：从左向右打印，所以从前边取，后边放入 */
            {
                node = dq.front();
                dq.pop_front();
                if (node->left)
                    dq.push_back(node->left); // /* 下一层顺序存放至尾 */
                if (node->right)
                    dq.push_back(node->right);
            }
            else /* 后取前放： 从右向左，从后边取，前边放入 */
            {
                node = dq.back();
                dq.pop_back();
                if (node->right)
                    dq.push_front(node->right); // 下一层逆序存放至首
                if (node->left)
                    dq.push_front(node->left);
            }
            tmp.push_back(node->val); /* 保存获取的节点的值到当前层的临时向量列表中 */
        }
        flag = !flag; /* 顺序状态取反, 即下一层节点存放顺序变更 */
        result.push_back(tmp);
    }
    return result;
}

/**回溯法(递归法)
 * Todo
 */

unordered_map<int, deque<int>> map;
int max_num = -1;

vector<vector<int>> levelOrder(TreeNode *root)
{
    dfs(root, 0);
    vector<vector<int>> result;
    for (int i = 0; i <= max_num; i++)
        result.push_back(vector<int>{map[i].begin(), map[i].end()});
    return result;
}
void dfs(TreeNode *root, int depth)
{
    if (root == NULL)
        return;
    max_num = max_num > depth ? max_num : depth;

    dfs(root->left, depth + 1);

    deque<int> dq;
    if (depth % 2 == 0)
        dq.push_back(root->val);
    else
        dq.push_front(root->val);

    map.insert({depth, dq});
    dfs(root->right, depth + 1);
}

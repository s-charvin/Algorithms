/**
 * @file spo-q06-从尾到头打印链表.cpp
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
 * * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 * 链接:
 * * https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=cuzoj2j
 * 考察:
 * 基本注意点
 * *
 * 高阶注意点
 * *
 */

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode
{
    ListNode(int x) : val(x), next(NULL) {}
    int val;
    ListNode *next;
};

// 题解
/**
 * 题解思路:
 * 先顺序取出数据到数组中, 然后利用新建一个新数组反转数组.
 *
 */
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> data;
        ListNode *next = head;
        while (next != NULL)
        {
            data.push_back(next->val);
            next = next->next;
        }
        vector<int> out = data;
        long num = data.size();
        for (int i = num - 1; i >= 0; i--)
        {
            out[num - 1 - i] = data[i];
        };
        return out;
    }
};

// 题解
/**
 * 题解思路:
 * 先顺序取出数据到数组中, 然后利用交换数据反转数组.
 *
 */
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> data;
        ListNode *next = head;
        while (next != NULL)
        {
            data.push_back(next->val);
            next = next->next;
        }

        // reverse(data.begin(), data.end());
        long num = data.size();
        int temp = 0;
        for (int i = 0; i < num / 2; i++)
        {
            temp = data[num - i - 1];
            data[num - i - 1] = data[i];
            data[i] = temp;
        };
        return data;
    }
};

// 题解
/**
 * 题解思路:
 * 利用递归先走至链表末端, 回溯时依次将节点值加入列表
 * 这样就可以实现链表值的倒序输出.
 *
 */
class Solution
{
private:
    vector<int> arr;

public:
    vector<int> reversePrint(ListNode *head)
    {
        if (!head) // 递归终止判断
            return arr;
        reversePrint(head->next); // 利用递归先走至链表末端
        arr.push_back(head->val); // 从最末端开始, 将数据一个个的放入列表中
        return arr;               // 这里以第一次调用返回的列表为最终结果
    }
};

// 题解
/**
 * 题解思路:
 * 先反转链表, 然后顺序将数据放到数组中
 *
 */
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        vector<int> out;
        while (pre)
        {
            out.push_back(pre->val);
            pre = pre->next;
        }
        return out;
    }
};

// 题解
/**
 * 题解思路:
 * 利用栈的先入后出特性, 反序输出数据到数组
 *
 */

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        /* 根据返回值定义存储结果的变量 */
        vector<int> result;
        /* 因为要反向输出值所以先把数据放入栈里面然后在拿出来 */
        stack<int> st;
        ListNode *cur = head;
        /* 将数据压入栈 */
        while (cur != NULL)
        {
            st.push(cur->val);
            cur = cur->next;
        }
        /* 将栈中的数据弹出 利用栈的性质可以反向输出结果 */
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

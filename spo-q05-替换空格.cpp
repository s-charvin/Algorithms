/**
 * @file spo-q05-替换空格.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：替换空格
 * * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * 链接:
 * * https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
 * 考察:
 * * 字符串
 * 基本注意点
 * *
 * 高阶注意点
 * *
 */

/**
 * 题解思路:
 *
 *
 *
 */

/**暴力迭代法
 * 新建一个 string 类型变量,
 * 然后将原字符串的字符一个个的顺序放入其中,
 * 遇到空格, 则放入 "%20"
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

string replaceSpace(string s)
{
    string array;
    for (char &c : s)
    {
        if (c == ' ')
        {
            array.push_back('%');
            array.push_back('2');
            array.push_back('0');
            continue;
        }
        array.push_back(c);
    }
    return array;
}

/**原地扩容法
 * 通过原字符串的空格数量, 预先计算好扩容后的内存占用大小,
 * 然后扩容原字符串内存, 再从后往前将元素向后移动, 遇到空格就替换
 *
 */

string replaceSpace(string s)
{
    int count = 0, old_len = s.size();
    /* 计算字符串中空格的数量 */
    for (char c : s)
    {
        if (c == ' ')
            count++;
    }
    /* 修改字符串长度, "%20" 的长度为 3 */
    s.resize(old_len + 2 * count);
    /**倒序遍历修改
     * 这里通过 i 从原字符串尾部向头部遍历元素,
     * 通过 j 从新字符串尾部向头部遍历元素.
     */
    for (int i = old_len - 1, j = s.size() - 1; i < j; i--, j--)
    {
        if (s[i] != ' ') /* 当 s[i] 不为空格时, 直接将原字符串元素放到新位置 */
        {
            s[j] = s[i];
            continue;
        }
        /* 当 s[i] 为空格时,  将 "%20" 依次放到对应的新位置*/
        s[j - 2] = '%';
        s[j - 1] = '2';
        s[j] = '0';
        j -= 2;
    }
    /* 当 i = j 时跳出, 此时表示左方已经没有空格了 */
    return s;
}
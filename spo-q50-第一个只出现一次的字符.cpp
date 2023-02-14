/**
 * @file spo-q50-第一个只出现一次的字符.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：
 * * 第一个只出现一次的字符
 * 链接:
 * * https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 * 考察:
 * * 查找算法
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

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**使用哈希表存储多次出现频数(状态)
 *
 */

char firstUniqChar(string s)
{
    unordered_map<int, int> frequency;
    for (char ch : s)
    {
        ++frequency[ch]; /* 统计出字符串中每个字符出现的次数 */
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (frequency[s[i]] == 1)
        {
            return s[i]; /*  获取第一个只出现一次的字符 */
        }
    }
    return ' ';
}
char firstUniqChar(string s)
{
    unordered_map<char, bool> dic;
    for (char c : s)
        dic[c] = dic.find(c) == dic.end();
    for (char c : s)
        if (dic[c])
            return c;
    return ' ';
}

/**使用哈希表存储索引
 * 将遍历字符串转换成遍历哈希表
 *
 */
char firstUniqChar(string s)
{
    unordered_map<char, int> first_pos;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (first_pos.count(s[i]))
        {
            first_pos[s[i]] = -1; /* 如果当前字符出现过, 则 -1  */
        }
        else
        {
            first_pos[s[i]] = i; /* 存储当前字符第一次出现的索引 */
        }
    }
    int first = n;
    for (auto [_, pos] : first_pos)
    {
        if (pos != -1 && pos < first)
        {
            first = pos; /*  获取第一个只出现一次的字符 */
        }
    }
    return first == n ? ' ' : s[first];
}

/**使用哈希表有序存储索引
 * 将遍历字符串转换成遍历哈希表
 *
 */
char firstUniqChar(string s)
{
    vector<char> keys;
    unordered_map<char, bool> dic;
    for (char c : s)
    {
        if (dic.find(c) == dic.end())
            keys.push_back(c);
        dic[c] = dic.find(c) == dic.end();
    }
    for (char c : keys)
    {
        if (dic[c])
            return c;
    }
    return ' ';
}
